/* Calcul du pgcd par une méthode géométrique.
 * CONTRIBUTEUR
 * LAFOND THOMAS
 *
 * LICENCE
 * GPLv3
 */

#include <iostream>
#include <math.h>

using namespace std;

// on affiche notre rationnel de manière simple.

void aff_r( int r[2])
{
	cout << "[ " << r[0] << ", " << r[1] << " ]" << endl;
}

void aff_p( int p[][2], int n)
{
	
	for (int i =0; i < n+1; i++)
	{
		cout << "[ " << p[i][0] << ", " << p[i][1] << " ]" << endl;

	}
}


// algo simple

void geogcd( int r[2], int p[][2], int &n)
{
	// on passe n par référence pour affiner l'affichage
	// et connaitre le nombre d'itération

	// Valeur initiale
	p[0][0] = 1; p[0][1] = 0;
	p[1][0] = 0; p[1][1] = 1;
		
	// Compteur
	// i compte le nombre d'itérations
	int i = 2;


	// position correspond à si on doit être au dessus 
	// ou en dessous de la ligne l:y = r*x
	// on change à chaque fois en la multipliant par -1
	int position = 1;
	
	// booléen pour savoir si on a le pgcd
	bool gcd = false;

	// algo
	while ( i<(n+2) && gcd == false)
	{
		// on calcul p_i avec q_i = 1
		// p_i = q_i * p_i-1 + p_i-2
		p[i][0] = p[i-1][0] + p[i-2][0];
		p[i][1] = p[i-1][1] + p[i-2][1];
				
		// On teste notre position relative par rapport à l:y = r*x
		// et on teste le fait d'avoir trouvé le pgcd

		while( (p[i][1] - (((float)r[1])/r[0])*p[i][0]) * position <=0 && gcd == false)	
		{	
			// On se demande si on a le pgcd
			if ( (p[i][1] - (((float)r[1])/r[0])*p[i][0]) * position ==0 )
			{	
				// on est au pgcd
				// on en profite pour changer n	
				n = i;
				gcd = true;
				
			}
			// Sinon, on poursuit l'algo en incrémentant q_i 
			// Ce qui consiste à ajouter un p_i-1
			p[i][0] = p[i][0] + p[i-1][0];
			p[i][1] = p[i][1] + p[i-1][1];
						
		}
		// On est allé trop loin en dépassant l.
		// On revient à l'itération d'avant.
		p[i][0] = p[i][0] - p[i-1][0];
		p[i][1] = p[i][1] - p[i-1][1];

		// On met à jour la position
		position = position * -1;
		// On passe au convergent suivant
		i++;
	}
}



// Programme principal
int main()
{	
	int r[2];
	int n = 20;
	// pas très élégant de fixer le nombre de convergent à 20...
	int p[n][2];
	
	// cas 1
	r[0]=5; r[1]=8;
	
	geogcd(r, p, n);
	cout << "resul pour r =: ";
	aff_r(r);
	aff_p(p,n);

	// cas 2
	r[0]=3; r[1]=7;
	n = 20;

	geogcd(r, p, n);
	cout << "resul pour r =: ";
	aff_r(r);
	aff_p(p,n);
	
	// cas 3
	r[0]=5; r[1]=15;
	n = 20;

	geogcd(r, p, n);
	cout << "resul pour r =: ";
	aff_r(r);
	aff_p(p,n);
	
	return(0);
}



