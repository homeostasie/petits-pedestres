/**
 * Thomas LAFOND, Hecham A.
 * This file must be used under the term of the GPLv3
 * Decomposition LU séquentielle
 */

#include <stdio.h>
#include <math.h>

#define NRA 15              /* number of rows in matrix A */

// ligne pour compiler
// gcc LU-seq.c -o LU-seq

//Matrice de départ
double a_mat[NRA][NRA];
double b_mat[NRA];

//Décomposition de A
double l_mat[NRA][NRA];
double u_mat[NRA][NRA];

//Vecteur colonne résultat
double y_mat[NRA];
double x_mat[NRA];


/*****************************************
*					 *
*	Création des matrices de tests	 *
*					 *
******************************************/


void creactionmatrice(void)
{
	int i = 0;

	while (i < NRA -1)
	{
		b_mat[i] = i+2;

		a_mat[i][0] = 1;
		a_mat[i][i+1] = i+1;

		u_mat[i][0] = 1;
		u_mat[i][i+1] = i+1;

		l_mat[i][i]=1;
	
		i = i + 1;
	}
	b_mat[NRA - 1] = 1;
	a_mat[NRA - 1][0] = 1;
	u_mat[NRA - 1][0] = 1;
	l_mat[NRA - 1][NRA - 1] = 1;
 
}


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
  printf("\n************matrice B************:\n");
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
  printf("\n************matrice X************:\n");
  printf("\n");

  for (j=0;j<NRA;j++)
  {
  	printf("%lf ",x_mat[j]);
	printf("\n");
  }

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
	k = j + 1;
	//Calcul de la j-eme colonne de L
	while(k < NRA)
	{
		l_mat[k][j] = u_mat[k][j] / u_mat[j][j];
		//printf("Calcul de L : j = %d, i = %d, k = %d",j,i,k);printf("\n");
		k++;

	}
	i = j + 1;
	//Calul pour la i-eme ligne de U
	while(i < NRA)
	{
		k=j;
		//Calcul pour les différents coeff de cette i-eme ligne
		while(k < NRA)
		{
			u_mat[i][k] = u_mat[i][k] - l_mat[i][j] * u_mat[j][k];
			//printf("Calcul de U : j = %d, i = %d, k = %d",j,i,k);printf("\n");
			k++;
		}

		i++;
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

	//On calcul Le premier terme de la remonté, comme 1 sur la diagonale
	y_mat[0] = b_mat[0];
	double tmp;

	// on fait une descente
	while( j < NRA)
	{	
		tmp = 0.0;
		i = 0;
		while( i < j)
		{
			tmp = tmp + y_mat[i]*l_mat[j][i];
			i++;
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
		i = j+1;
		while( i <= NRA -1)
		{
			tmp = tmp + x_mat[i]*u_mat[j][i];
			i++;

		}
		x_mat[j] = (y_mat[j] - tmp)/u_mat[j][j];
		j--;
	}

}



int main()
{

	//Création des matrices
	creactionmatrice();
	
	//Décomposition de A en LU
	decompmatriceA();

	//On résoud le système linéaire
	resolution();
	
	//On affiche le résultat
	mat_display();  

  return(0);
}
