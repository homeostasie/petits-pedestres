/**
 * Thomas LAFOND, Hecham A.
 * This file must be used under the term of the GPLv3
 * Decomposition LU parallélisé avec OpenMP
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NRA 10                 /* number of rows in matrix A */

// ligne pour compiler
// gcc -fopenmp LU-parallele-openmp.c

//Matrice et vecteur de départ
double a_mat[NRA][NRA];
double b_mat[NRA];

//Décomposition de A en deux matrices L et U
double l_mat[NRA][NRA];
double u_mat[NRA][NRA];

//Vecteurs colonnes résultats
double y_mat[NRA];
double x_mat[NRA];

//Matrice pour vérifiée la décomposition
double lu_mat[NRA][NRA];

/*****************************************
*					 *
*	Création des matrices de tests	 *
*					 *
******************************************/

void creactionmatrice(void)
{
	int i;
	int tid;
	#pragma omp parallel for shared(a_mat, b_mat, l_mat, u_mat) private(i,tid)
	for (i=0; i < NRA -1;i++)
	{
		tid = omp_get_thread_num();
		printf("Thread=%d did row=%d\n",tid,i);
		b_mat[i] = i+2;

		a_mat[i][0] = 1;
		a_mat[i][i+1] = i+1;

		u_mat[i][0] = 1;
		u_mat[i][i+1] = i+1;

		l_mat[i][i]=1;
	
		
	}
	b_mat[NRA - 1] = 1;
	a_mat[NRA - 1][0] = 1;
	u_mat[NRA - 1][0] = 1;
	l_mat[NRA - 1][NRA - 1] = 1;
 
}

//Pour vérifié la décomposition 
/*void prodmat()
{
     int i,j,k, tid;

     #pragma omp parallel for shared(lu_mat, l_mat, u_mat) private(i,j,k,tid)
     for (i=0;i<=NRA;i++)
     {
         for (j=0;j<=NRA;j++)
        {
             lu_mat[i][j]=0;
             for (k=0;k<NRA;k++)
             {
                   lu_mat[i][j]+=l_mat[i][k]*u_mat[k][j];
             }
        }
    }
}*/


/*******************************************
*					   *
*	affichage des matrices             *
*					   * 
********************************************/

void mat_display(void)
{
  int i,j=0;

  printf("**************matrice A************:\n");
  printf("\n");
  for(j=0; j < NRA; j++)
  {
  	for (i=0; i < NRA; i++)
		{
    			printf("%lf ",a_mat[j][i]);
  		}
	printf("\n");
  }
  printf("\n");
  printf("\n************Vecteur b************:\n");
  printf("\n");

  for (j=0;j<NRA;j++)
  {
  	printf("%lf ",b_mat[j]);
	printf("\n");
  }
  
  printf("\n");
  printf("**************matrice L************:\n");
  printf("\n");
  for(j=0; j < NRA; j++)
  {
  	for (i=0; i < NRA; i++)
		{
    			printf("%lf ",l_mat[j][i]);
  		}
	printf("\n");
  }

  printf("\n");
  printf("**************matrice U************:\n");
  printf("\n");
  for(j=0; j < NRA; j++)
  {
  	for (i=0; i < NRA; i++)
		{
    			printf("%lf ",u_mat[j][i]);
  		}
	printf("\n");
  }

  printf("\n");
  printf("\n************Vecteur x************:\n");
  printf("\n");
  for (j=0;j<NRA;j++)
  {
  	printf("%lf ",x_mat[j]);
	printf("\n");
  }


  /*printf("\n");
  printf("**************matrice LU************:\n");
  printf("\n");
  for(j=0; j < NRA; j++)
  {
  	for (i=0; i < NRA; i++)
		{
    			printf("%lf ",lu_mat[j][i]);
  		}
	printf("\n");
  }*/

}

/*******************************************
*					   *
*	décomposition de A                 *
*					   * 
********************************************/

void decompmatriceA(void)
{

int i = 0;
int j = 0; 
int k;

while(j < NRA - 1)
{
	//Calcul de la j-eme colonne de L
	#pragma omp parallel for shared(l_mat, u_mat,j) private(k)
	for(k =j+1;k< NRA;k++)
	{
		l_mat[k][j] = u_mat[k][j] / u_mat[j][j];
		//printf("Calcul de L : j = %d, i = %d, k = %d",j,i,k);printf("\n");

	}
	//Calul pour la i-eme ligne de U
	#pragma omp parallel for shared(u_mat, l_mat,j) private(i,k)
	for(i=j+1; i< NRA;i++)
	{
		k=j;
		//Calcul pour les différents coeff de cette i-eme ligne
		while(k < NRA)
		{
			u_mat[i][k] = u_mat[i][k] - l_mat[i][j] * u_mat[j][k];
			//printf("Calcul de U : j = %d, i = %d, k = %d",j,i,k);printf("\n");
			k++;
		}

		
	}
	j++;

}

}

/*******************************************
*					   *
*	Résolution du problème             *
*					   * 
********************************************/
void resolution(void)
{
	

	//Ly = b
	int i;
	int j = 1;
	//int tid;
	//On calcul Le premier terme de la remonté, comme 1 sur la diagonale
	y_mat[0] = b_mat[0];
	double tmp;

	// on fait une descente
	while( j < NRA)
	{	
		tmp = 0.0;
		//On somme les termes non-nulles
		#pragma omp parallel for shared(y_mat, l_mat,j,tmp) private(i)
		for( i=0;i < j;i++)
		{
			tmp = tmp + y_mat[i]*l_mat[j][i];
			
		}
		y_mat[j] = b_mat[j] - tmp;
		j++;
	}

	j = NRA -2;
	//Ux = b

	//On calcul Le premier terme de la remonté,
	x_mat[NRA - 1] = y_mat[NRA-1]/u_mat[NRA-1][NRA-1];
	tmp = 0.0;

	// on fait une remonté
	while( j >= 0)
	{	
		tmp = 0.0;
		//On somme les termes non-nulles
		#pragma omp parallel for shared(y_mat, l_mat,j,tmp) private(i)
		for( i=j+1; i<= NRA -1;i++)
		{
			
			tmp = tmp + x_mat[i]*u_mat[j][i];
		

		}
		x_mat[j] = (y_mat[j] - tmp)/u_mat[j][j];
		j--;
	}

}



int main()
{

	/*   Appel des procédures    */

//On crée la matrice de l'exemple
	creactionmatrice();

//On la décompose en LU
	decompmatriceA();

//On vérifie la décomposition
	//prodmat();	

//On résoud le système	
	resolution();

//On affiche toutes les matrices
	mat_display();  

  return(0);
}
