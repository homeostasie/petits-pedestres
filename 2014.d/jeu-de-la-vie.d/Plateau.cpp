class Plateau {
private:
      int dim;
public:
      std::vector<Cellule> plateau;

public:
      /*
       * Constructeur par défaut
       */
      Plateau(){
	    dim = 3;
      }

      /*
       * Constructeur standart
       * @param taDim est la dimension du plateau.
       */
      Plateau(const int taDim)
	    {
		  dim = taDim;
	    }

      /**
       * Constructeur Pour des tests rapides.
       */
      Plateau(const bool tonBool)
	    {
		  dim = 3;
		  int it;
		  for(it = 1 ;it<=11;it++) { plateau.push_back(0); }
		  for(it = 12;it<=14;it++) { plateau.push_back(1); }
		  for(it = 15;it<=25;it++) { plateau.push_back(0); }

	    }
      /**
       * Constructeur par copie
       * @param pla un autre plateau à copier
       */
      Plateau(const Plateau& pla)
	    {
		  dim = pla.dim;
		  int it;
		  for(it = 1 ;it<=(dim+2)*(dim+2);it++) {
			plateau.push_back(pla.plateau[it-1]); 
		  }
	    }


      /*
       * Destructeur par défaut
       */
      ~Plateau() {}



      /**
       * Montre le tableau ainsi que les bords vides
       * utiles aux calculs.
       */
      void showTotal()
	    {
		  // iterateur sur le vector du plateau.
		  std::vector<Cellule>::iterator itP = plateau.begin();
	    
		  int ligne = 1;
		  int colonne = 1;
   
		  // On rajoute une ligne en haut et 
		  // en bas et une colonne à gauche et à droite.
		  while( ligne <= dim + 2)
		  {
			std::cout<<"|---------|"<<std::endl<<"|";
			while( colonne <= dim + 2)
			{
			      std::cout<<*itP<<"|";
			      itP++;
			      colonne += 1;
			}
			std::cout<<std::endl;
			colonne = 1;
			ligne += 1;
		  }
		  std::cout<<"|---------|"<<std::endl;		  
	    }

      /**
       * Affiche le plus sobrement possible de plateau,
       * donc sans les lignes en haut et en bas et les colonnes à gauche et à droite.
       */
      void show()
	    {
		  // iterateur du plateau
		  std::vector<Cellule>::iterator itP = plateau.begin();

		  int ligne = 1;
		  int colonne = 1;

		  // première ligne
		  int i = 1;
		  while( i <= dim + 2)
		  {
			itP++;
			i++;
		  }
		  ligne +=1;
  	    
		  while( ligne <= dim +1)
		  {
			// on se déplace de 1 sur la colonne
			itP++;
			colonne ++;

			while(colonne <= dim +1)
			{
			      std::cout<<*itP;
			      itP++;
			      colonne += 1;
			}
			std::cout<<std::endl;
		  
			itP++;
			colonne = 1;
		  
			ligne += 1;
		  }
	    }



      Plateau Evolution()
	    {
		  // Évolution du plateau au temps t + 1.
		  Plateau pEvol(dim);
	    
		  const int dim2 = dim + 2;
		  int it = dim2 + 1 + 1;
		  int vois;
    
		  int ligne = 1;
		  int colonne = 1;
      

		  while( colonne <= dim2 + 2)
		  {
			pEvol.plateau.push_back(0);
			colonne++;
		  }
      
		  // Deuxième ligne, première colonne;
		  ligne +=1;
		  colonne = 2;

		  while( ligne <= dim +1)
		  {

			while(colonne <= dim +1)		  
			{
			      // On calcul la somme des voisins présents au 8 directions.
			      vois = plateau[it-dim2-1].EstPresent() + plateau[it-dim2].EstPresent()
				    + plateau[it-dim2+1].EstPresent() + plateau[it-1].EstPresent() 
				    + plateau[it+1].EstPresent() + plateau[it+dim2-1].EstPresent()
				    + plateau[it+dim2].EstPresent() + plateau[it+dim2+1].EstPresent();
			
			      // Si la cellule était morte
			      if(!plateau[it].Estenvie())
			      {
				    // Si le nombre de voisin est 3 => apparition de la vie.
				    if(vois == 3) { pEvol.plateau.push_back(1); }
				    else { pEvol.plateau.push_back(0); }
			      
			      }
			      else
			      {
				    // Si le nombre de voisin est 2 ou 3 => conservation de la vie.
				    if(vois == 2 || vois == 3) { pEvol.plateau.push_back(1); }
				    else { pEvol.plateau.push_back(0); }
			      }
			      it++;
			      colonne++;
			}
			ligne ++;
			colonne = 1;
		  }
	    
		  while( colonne <= dim2+2)
		  {
			pEvol.plateau.push_back(0);
			colonne++;
		  }
		  return pEvol;
	    }

      Plateau Evolution(int temps)
	    {
	    
		  if (temps > 0) { Evolution(temps - 1); }
		  return (*this);
	    }
      
};
