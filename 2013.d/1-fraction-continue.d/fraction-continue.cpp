/* Algorithme qui décompose un réel x en en fraction continue.
 * On récupère en sortie une suite d'entier qui sont les coefficients
 * de la fration continue.
 * On précise n le nombre d'occurence de la fration.
 * Par la suite une précision epsilon peut être envisagé
 *
 * CONTRIBUTEUR
 * LAFOND THOMAS
 *
 * LICENCE
 * GPLv3
 */
#include <iostream>
#include <math.h>

using namespace std;


// décomposition simple

void f1continue(double x, int n, int suite_a[])
{
	// suite_x représente la suite des nombres réels dont on cherche à 
	// approximer l'inverse
	double suite_x[n];

	// suite_a représente la suite des nombres entiers qui forme la
	// fraction continue
	

	// compteur i
	int i;
	
	// on affecte les premières valeurs
	// On se sert de la librairie math.h
	// pour trouver la partie entière avec 
	// la fonction floor
	
	suite_a[0] = floor(x);

	suite_x[0] = 1/(x - suite_a[0]);
	
	// on boucle jusqu'au n_e coefficents
	for (i=1; i<n; i++)
	{
		// On vérifie le bon nombre de tour
		// cout << i << endl;
		
		// On extrait la partie entière dans suite_a
		suite_a[i] = floor(suite_x[i - 1]);
		// on inverse le reste compris entre 0 et 1 pour y mettre sous forme 
		// de fraction
		suite_x[i] = 1/(suite_x[i - 1] - suite_a[i]); 

	}

}

// On test si le coefficient suite-x n'est pas entier
// auquelc cas, il faut terminer l'algo.
bool estentier(double x)
{
	return x == floor(x);
}

void f2continue(double x, int n, int suite_a[])
{
	// suite_x représente la suite des nombres réels dont on cherche à 
	// approximer l'inverse
	double suite_x[n];

	// suite_a représente la suite des nombres entiers qui forme la
	// fraction continue
	

	// compteur i
	int i;
	
	// on affecte les premières valeurs
	// On se sert de la librairie math.h
	// pour trouver la partie entière avec 
	// la fonction floor
	
	suite_a[0] = floor(x);

	suite_x[0] = 1/(x - suite_a[0]);
	
	// on boucle jusqu'au n_e coefficents
	for (i=1; i<n; i++)
	{
		// On vérifie le bon nombre de tour
		// cout << i << endl;
		
		// On extrait la partie entière dans suite_a
		suite_a[i] = floor(suite_x[i - 1]);
		// on inverse le reste compris entre 0 et 1 pour y mettre sous forme 
		// de fraction
		suite_x[i] = 1/(suite_x[i - 1] - suite_a[i]); 

		if (estentier(suite_x[i]) == 1)
		{

			for (i; i<n; i++)
			{
				suite_a[i] = -1;
			}
		}
	}

}


// calcul l'approximation
double fc_approx(int suite_a[], int n)
{
	// n nombre de coefficient
	// i compteur
	int i = n - 2;

	// approx = approximation
	double approx = suite_a[n-1];
	
	while (i>=0 && suite_a[i != -1])
	{
		// on calcul la dernière fraction et on remonte
		approx = 1/approx + suite_a[i];
		i--;
	}

	return(approx);
}


// affichage de la suite de coefficient
void fc_affiche(int suite_a[], int n)
{

	// n le nombre de coefficient
	// i compteur
	int i;

	cout << "a = [ ";
	for (i=0; i<n; i++)
	{
		cout << suite_a[i] << ", ";
	}
	cout << " ]" << endl;
	
	// on affiche l'approximation	
	cout << "Approximation : " << fc_approx(suite_a, n) << endl;
	

}


// Programme principal
int main()
{	
	// nombre d'occurence : n
	int n = 20;
	// nombre réel à décomposer
	double reel = 1.4142135;
	// resultat
	int suite_a[n];

	// appel de la première fonction
	f2continue(reel, n, suite_a);

	// affichage de la fonction	
	cout << "Fraction contine de "<< reel << " : " << endl;
	fc_affiche( suite_a, n);

	return(0);
}


