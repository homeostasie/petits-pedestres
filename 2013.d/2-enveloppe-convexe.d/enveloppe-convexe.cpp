/*
 * Enveloppe convexe discrète
 * Fonctionis, algo et programme principale
 * CONTRIBUTEUR
 * LAFOND THOMAS
 *
 * LICENCE
 * GPLv3
 */

/*
 * Taille max de notre quadrillage
 */

#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

const int N = 20;
const int M = 16;

void set_point(int p[2], int x, int y)
{
	p[0] = x;
	p[1] = y;
}

void set_point(int p[2], int q[2])
{
	p[0] = q[0];
	p[1] = q[1];
}

void set_point(double p[2], int q[2])
{
	p[0] = (double)q[0];
	p[1] = (double)q[1];

}

void translation(int p[2], int q[2], int r[2])
{
	p[0] = q[0] + r[0];
	p[1] = q[1] + r[1];
}

void anti_translation(int p[2], int q[2], int r[2])
{
	p[0] = q[0] - r[0];
	p[1] = q[1] - r[1];
}

void oppose(int p[2], int q[2])
{
	p[0] = -q[0];
	p[1] = -q[1];
}

double f_produit_scalaire( double p[2], int q[2])
{
	return p[0]*(double)(q[0]) + p[1]*(double)(q[1]);
}


// On définit un quadrillage
void quadrillage(int quad[N*M][2])
{
	int i;
	int j;

	for (i=0; i<=M-1; i++)
	{
		for (j=0; j<=N-1; j++)
		{
			set_point(quad[j + N*i], j, i);
		}
	}

}

double f_carre(double x)
{
	return(x*x);
}

// On définit un disque discret
void cercle( double rayon, double centre[2], int disque[][2], int quad[N*M][2])
{
	int i;
	int j;

	int k = 0;
	
	for (i=0; i<=M-1; i++)
	{
		for (j=0; j<=N-1; j++)
		{
			if ( (f_carre(quad[j + N*i][0] - centre[0]) +
					       f_carre(quad[j +N*i][1] - centre[1])) 
					<= rayon*rayon)
			{
				set_point(disque[k], j, i);
				k++;
			}	
		}
	}
	
	while (k<N*M)
	{
		set_point(disque[k], -1, -1);
		k++;
	}
}

// Affichage du quadrillage
void sortie_quad( int quad[N*M][2])
{
	int i;
	int j;
	
	cout << "-------Quad----------" << endl;
	
	for (i=0; i<=M-1; i++)
	{
		for (j=0; j<=N-1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

}

// Affichage du disque
void sortie_disk( int quad[N*M][2], int disk[N*M][2])
{
	int i;
	int j;

	int k = 0;
	
	cout << "-------Disk---------- (inversé) dans le sens des y" << endl;
	
	for (i=0; i<=M-1; i++)
	{
		for (j=0; j<=N-1; j++)
		{
			if ( disk[k][0] !=-1 && quad[j + N*i][0] == disk[k][0] &&
				       	quad[j + N*i][1] == disk[k][1])
			{
				cout << "+";
				k++;
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

// affichage d'un point
void sortie_point( int p[2] )
{
	cout << "[ " << p[0] << ", " << p[1] << " ]" << endl;
}


// affichage des points du disque
void sortie_points_disk( int disk[][2])
{
	int k = 0;
	cout << " { ";

	while (disk[k][0]!=-1 && disk[k][1] != -1 )
	{

	 	if( (disk[k][0]!=0 && disk[k][1]!=0) || k==0)
		{
			cout << "[ " << disk[k][0] << ", " << disk[k][1] << " ]" ;
		}
			k++;
	}

	cout << " }" << endl << endl;
}

// init enveloppe convexe
void init_convexe( int convexe[2*(N+M)][2])
{
	int k;
	for (k = 0; k < 2*(N+M); k++)
	{
		set_point(convexe[k], -1, -1);
	}

}


/*
 * mauvaise manière : brutal
 * On se demande si le point est contenu dans le domaine
 * On parcours tous le domaine
 *
 */
bool estcontenu( int p[2], int domaine[N*M][2])
{
	bool predicat = false;
	int k = 0;

	while (domaine[k][0] != -1)
	{
		if (p[0] == domaine[k][0] && p[1] == domaine[k][1])
			{
				return(true);
			}
		k++;
	}
	return (false);
}

/*
 * On regarde si le vecteur allant du point p au point q
 * intersecte le domaine D
 *
 */

bool intersecte( int p[2], int q[2], int domaine[N*M][2])
{
	if( estcontenu(p, domaine) == estcontenu(q, domaine))
		{return false;}
	else
		{return true;}
}


/*
 *  On regarde si les points sont confondus.
 *
 */
bool estconfondu(int p[2], int q[2])
{
	return (p[0] == q[0] && p[1] == q[1]);
}




void convexhull_v1( int p_domaine[N*M][2], int p_convexe[2*(N+M)][2])
{

	/*
	 * # Les ensembles
	 *
	 * On va se servir principalement de quatre ensembles.
	 *
	 * * Le domaine discret : p_domaine.
	 *   On munit cet ensemble d'un itérateur : k_domaine.
	 *
	 * * L'enveloppe discrète en construction : p_convexe.
	 *   On munit cet ensemble d'un itérateur : k_convexe.
	 * 
	 * * L'ensemble des points qui candidatent pour le 
	 * rôle de prochain sommet de l'ensemble convexe : 
	 * p_candidat.
	 *   On munit cet ensemble d'un itérateur : k_candidat.
	 *   On utilise également un vecteur de taille 1x2 pour 
	 *   savoir si l'on doit continuer l'algorithme.
	 *
	 *  * L'ensemble des points convergents calculés pour
	 *  chaque sommet de l'enveloppe convexe : p_convergent.
	 *    On se servira également des deux vecteurs v_-2 et v_-1 
	 *    et d'un troisième vecteur permettant de les inversés :
	 *    v_convergent.
	 *    On muni ces ensembles d'un itérateur : k_convergent.
	 *    On se munit également également d'un compteur qk pour
	 *    calculer l'intersection du rayon avec le domaine.
	 *  
	 *
	 *  L'indice des premiers éléments des tableaux est 0.
	 *  Même pour les "p_convergent[-2] -> p_convergent[0].
	 * 
	 */

	// Le domaine discret
	p_domaine;
	int k_domaine;

	// L'enveloppe convexe
	p_convexe;
	init_convexe(p_convexe);
	int k_convexe;

	// Les candidats
	int p_candidat[N*M][2]; // taille ???
	init_convexe(p_candidat);
	int k_candidat;
	int p_ray[N*M][2];
	init_convexe(p_ray);
	double produit_scalaire;
	double p_scalaire[2];

	// Les convergents
	int p_convergent[N*M][2];
	init_convexe(p_convergent);
	int v_convergent[N*M][2];
	init_convexe(v_convergent);
	int k_convergent;
	int qk;

	int test_p0[2];
	/*
	 * # Les variables de tests
	 *
	 *
	 * * L'algorithme est terminer, l'ensemble des points de
	 * l'enveloppe convexe discrète a été trouvé. On est
	 * revenu à notre point de départ p_convexe[0] : bool_convexe_fini.
	 * Par défaut bool_convexe_fini = false.
	 *
	 * * L'ensemble des candidats au poste de sommet 
	 * suivant de notre enveloppe convexe a été trouvé.
	 * Il faut maintenant faire le choix parmi eux en sélectionnant
	 * celui de plus grand angle : bool_candidat_fini.
	 *
	 */
 
	// L'enveloppe convexe
	bool bool_convexe_fini = false;

	// On a tous les candidats
	bool bool_candidat_fini = false;

	/*
	 * #1 - Initialisation de notre algorithme
	 * par la recherche de notre premier point 
	 * de l'enveloppe convexe.
	 *
	 * On part du point le plus bas.
	 *
	 */

	/* 
	 * Il serait sans doute sage d'en faire une procédure.
	 * Mais ce n'est pas le point de ce programme.
	 *
	 */
	
	k_domaine = 1;
	set_point(p_convexe[0], p_domaine[0]);

	while ( p_domaine[k_domaine][0] != -1 )
	{
		if ( p_domaine[k_domaine][1] < p_convexe[0][1])
		{	
			set_point(p_convexe[0], p_domaine[k_domaine]);
		}

		k_domaine++;
	}

	/*
	 * On a trouvé le premier point de notre enveloppe
	 * convexe.
	 *
	 * On crée également les deux premiers vecteurs
	 * v_-2 et v_-1 
	 *
	 */

	k_convexe = 1;

	set_point(v_convergent[0], 1,  0);
	set_point(v_convergent[1], 0,  1);


	/*
	 * On part maintenant du premier point de notre
	 * enveloppe convexe et on lance l'algo.
	 *
	 * #2 - On fait tourner l'algorithme jusqu'à qu'il
	 * se termine
	 *
	 */
	

	while ( !bool_convexe_fini )
	{
		/*
		 * On test maintenant si nos vecteurs v_-1 et v_-2
		 * sont correctement orientés. On crée nos points 
		 * p_-1 et p_-2.
		 *
		 * Pour cela on test l'appartenance de p_-1 à notre ensemble.
		 *
		 * Une procédure est utilisée. 
		 *
		 * #2.1 - On crée nos premiers convergents
		 */
	
		translation(p_convergent[0], p_convexe[k_convexe -1],
			       	v_convergent[0]);
		translation(p_convergent[1], p_convexe[k_convexe -1],
			       	v_convergent[1]);
		k_convergent = 2;
		
		if (!estcontenu(p_convergent[1], p_domaine) )
		{
			/*
			 * #2.1.1 - On vérifie nos vecteurs
			 *
			 * Si pm1 n'appartient pas au domaine, on effectue
			 * On effectue une rotation de nos deux vecteurs et
			 * une réactualisation de nos points p_-2 et p_-1.
			 *
			 * v_-2 devient  v_-1.
			 * v_-1 devient -v_-2 (l'ancien)
			 */
			
			set_point(v_convergent[2], v_convergent[0]);
			set_point(v_convergent[0], v_convergent[1]);
			oppose(v_convergent[1], v_convergent[2]);

		}
	
		/*
		 * Sinon, les vecteurs sont bien orientés pour chercher 
		 * p_convexe+1.
		 *
		 * On teste maintenant l'éventualité d'avoir tous les
		 * candidats au poste de p_convexe+1.
		 *
		 * #2.2 - On lance l'algo de la recherche du prochain
		 * point de l'enveloppe
		 *
		 */

		else 
		{
			// On test si p_-2 est candidat.
			// Alors on est sûr de translater vers lui.
			if (estcontenu(p_convergent[0], p_domaine))
			{
				set_point(p_candidat[k_candidat], p_convergent[0]);
				k_candidat++;
				bool_candidat_fini = true;
			}
			else // sinon on recherche le candidat
			{
				// p_-1 est candidat 
				set_point(p_candidat[k_candidat], p_convergent[1]);
				k_candidat++;
								
				/*
				 * On crée p_0.
				 *
				 */
			
				set_point(p_convergent[2], p_convergent[0]);
				set_point(v_convergent[2], v_convergent[0]);
				set_point(test_p0, p_convergent[1]);


				while (!estcontenu(p_convergent[2], p_domaine) && estcontenu(test_p0, p_domaine))
				{
					translation(p_convergent[2], p_convergent[2],
							v_convergent[1]);
					translation(test_p0, test_p0, v_convergent[1]);

					translation(v_convergent[2], v_convergent[2], 
							v_convergent[1]);
					
				}
				// On revient au dernier point.
				anti_translation(p_convergent[2], p_convergent[2],
						v_convergent[1]);

				anti_translation(v_convergent[2], v_convergent[2], v_convergent[1]);

				// On test si p_1 existe
				 
				qk = 0;
				set_point(p_ray[0], p_convergent[2]);

				translation(p_ray[1], p_convergent[2], v_convergent[1]);

				
				// On calcul qk tq l'intersection soit non nulle

				while (intersecte(p_ray[qk+1], p_ray[qk], p_domaine))
				{
					qk++;
					translation(p_ray[qk+1], p_ray[qk], v_convergent[qk-2]);
				}

				if (qk != 0 || estcontenu(p_ray[qk+1], p_domaine))
				{
					// on continue de calculer les convergents
					bool_candidat_fini = false;
					k_convergent++;

					if (estcontenu(p_ray[qk], p_domaine))
					{
						set_point(p_candidat[k_candidat], p_ray[qk]);
						k_candidat++;
					}
				}
				else // on a trouvé tous les candidats
				{
					bool_candidat_fini = true;
				}

				// On assure
				k_convergent = 3;
				while (!bool_candidat_fini)
				{
					/*
					 * On se pose maintenant la question de savoir si tous 
					 * les candidats sont présents
					 *
					 * On continue donc l'algo. On distingue le cas pair 
					 * du cas impair.
					 *
					 * On test ça en binaire : un nombre pair en binaire se termine 
					 * par 0. On aurait également pu faire %2 ==0 pour avoir le reste
					 * de la division euclidienne.
					 */

					if (k_convergent & 1) // pair
					{
						// On cherche k minimal tq l'intersection entre 
						// le rayon et le domaine soit non nulle.

						translation(p_convergent[k_convergent], 
								p_convergent[k_convergent-1], 
								v_convergent[k_convergent-2]);

						// On calcul le point p_k

						translation(v_convergent[k_convergent], 
								v_convergent[k_convergent - 2],
							       	v_convergent[k_convergent - 1]);

						while (estcontenu(p_convergent[k_convergent], p_domaine))
						{
							translation(p_convergent[k_convergent], 
									p_convergent[k_convergent], 
									v_convergent[k_convergent-1]);
							
							translation(v_convergent[k_convergent], 
									v_convergent[k_convergent],
									v_convergent[k_convergent-1]);
						}

						// on revient au point précédent
						anti_translation(p_convergent[k_convergent], 
								p_convergent[k_convergent], 
								v_convergent[k_convergent-1]);

						anti_translation(v_convergent[k_convergent], 
								v_convergent[k_convergent],
							       	v_convergent[k_convergent - 1]);
						// On test maintenant pour savoir si on continue la procédure.
						qk = 0;
						set_point(p_ray[qk], p_convergent[k_convergent-2]);

						translation(p_ray[qk+1], p_convergent[k_convergent-2], 
								v_convergent[k_convergent-1]);

						// On calcul qk tq l'intersection soit non nulle

						while (intersecte(p_ray[qk+1], p_ray[qk], p_domaine))
						{
							qk++;
							translation(p_ray[qk + 1], p_ray[qk],
									p_convergent[k_convergent-1]);
						}

						if (qk != 0)
						{
							// on continue de calculer les convergents
							bool_candidat_fini = false;
							k_convergent++;

							if (estcontenu(p_ray[qk], p_domaine))
							{
								set_point(p_candidat[k_candidat], p_ray[qk]);
								k_candidat++;
							}
						}
						else // on a trouvé tous les candidats
						{
							bool_candidat_fini = true;
						}

					} // fin pair

					else // impair
					{
						// On cherche k maximal tq l'intersection entre 
						// le rayon et le domaine soit non nulle.

						translation(p_convergent[k_convergent], 
								p_convergent[k_convergent-1], 
								p_convergent[k_convergent-2]);

						translation(v_convergent[k_convergent], 
								v_convergent[k_convergent-1], 
								v_convergent[k_convergent-2]);

						// On calcul le point p_k

						while (estcontenu(p_convergent[k_convergent], p_domaine)) 
						{// ! - on sort du domaine
							translation(p_convergent[k_convergent], 
									p_convergent[k_convergent], 
									p_convergent[k_convergent-1]);
							translation(v_convergent[k_convergent], 
									v_convergent[k_convergent], 
									v_convergent[k_convergent-2]);
						}

						// on revient au point précédent
						anti_translation(p_convergent[k_convergent], 
								p_convergent[k_convergent], 
								p_convergent[k_convergent-1]);
						anti_translation(v_convergent[k_convergent], 
								v_convergent[k_convergent], 
								v_convergent[k_convergent-2]);
							

						// On test maintenant pour savoir si on continue la procédure.
						qk = 0;
						set_point(p_ray[qk], p_convergent[k_convergent-2]);

						translation(p_ray[qk+1], p_convergent[k_convergent-2], 
								p_convergent[k_convergent-1]);

						// On calcul qk tq l'intersection devienne nulle

						while (!intersecte(p_ray[qk+1], p_ray[qk], p_domaine))
						{// ! - on test la plus grande
							qk++;
							translation(p_ray[qk + 1], p_ray[qk],
									p_convergent[k_convergent]-1);
						}

						if (qk != 0)
						{
							bool_candidat_fini = false;
							k_convergent++;

							if (estcontenu(p_ray[qk-1], p_domaine))
							{
								set_point(p_candidat[k_candidat], p_ray[qk-1]);
								k_candidat++;
							}
						}
						else
						{
							bool_candidat_fini = true;
						}

					} // fin impair
				} // fin du while candidat

			} // fin candidat 
			/*
			 * On a obtenu tous les candidats dans p_candidat.
			 * Il est temps savoir lequel est le bon.
			 * 
			 * On utilise la tangente : Plus la tangente est 
			 *
			 */
//cout << "candidat : "<< k_candidat << " - ";
//sortie_points_disk(p_candidat);
			if (k_candidat > 1)
			{	
				set_point(p_convexe[k_convexe], p_candidat[k_candidat-1]);
				set_point(p_scalaire, p_candidat[k_candidat-1]);

				produit_scalaire = 0.0;

				while (k_candidat > 1)
				{
					// on crée le vecteur [p_-2; p_candidat]
					set_point(p_scalaire, p_candidat[k_candidat-1]);
					p_scalaire[0] = p_scalaire[0] - (double)p_convergent[0][0];
					p_scalaire[1] = p_scalaire[1] - (double)p_convergent[0][1];
					
					// On test si son ordonnée est nulle
					if (p_scalaire[1] != 0)
					{
						// On normalise 
						p_scalaire[0] = p_scalaire[1]/p_scalaire[0]; 
						p_scalaire[1] = 1.0;
						
						if (produit_scalaire < f_produit_scalaire(
								p_scalaire, p_convergent[0]))
						{
							produit_scalaire = f_produit_scalaire(
									p_scalaire, p_convergent[0]);
							set_point(p_convexe[k_convexe], p_candidat[k_candidat-1]);
						}
					}
					k_candidat--;
				}
				k_convexe++;
			}
			else
			{
				set_point(p_convexe[k_convexe], p_candidat[k_candidat - 1]);

				k_convexe++;
				k_candidat--;	       
			}

			/*
			 * On test si l'algo est terminé.
			 * Le test consiste à savoir si le dernier point de l'enveloppe
			 * est le même que le premier.
			 */
			if (!estconfondu(p_convexe[0], p_convexe[k_convexe-1])) 
			{ // on continue l'algo en cherchant le prochain point de l'enveloppe
				bool_candidat_fini = false;
				bool_convexe_fini = false;
				k_candidat = 0;
				k_convergent = 0;
			}
			else
			{ // on a terminé
				bool_convexe_fini = true;
			}


		} // fin d'une extrémité de notre convexe, on tourne nos v_-2, v_-1
	} // on a fini de computer sur notre convexe.
} // fin de proc		





int main()
{
	// temps 
	clock_t exec;
	exec = clock();

	int quad[N*M][2];
	int disk[N*M][2];
	double rayon = 4.21;
	double centre[2];
	centre[0] = 8.1; centre[1] = 5.7;

	quadrillage(quad);
	cercle(rayon, centre, disk, quad);

	sortie_disk(quad, disk);
	sortie_points_disk(disk);	


	int disk_convexe[2*(N+M)][2];

	convexhull_v1(disk, disk_convexe);
	cout << "Convexe : "; sortie_points_disk(disk_convexe);

	cout << "ÉXEC : " << exec - clock() << " ms" <<endl;
	return(0);
}


