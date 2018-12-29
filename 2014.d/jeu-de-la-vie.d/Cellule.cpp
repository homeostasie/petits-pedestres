#include <iostream>
#include <vector>
#include <iterator>

/** 
 * Classe de base du programme. 
 *  Elle définit une cellule qui évolue au cours du temps. 
 */
class Cellule {
private:
      int vie;

public:
      /**
       * Constructeur par défaut
       */
      Cellule():vie(0) {}

      /*
       * Constructeur standart
       * @param i valeur booléenne à appliquer
       */
      Cellule(const int tonInt):vie(tonInt) {}

      /**
       * Constructeur par copie
       * @param c autre cellule à copier
       */
      Cellule(const Cellule& cell): vie(cell.statut()) {}



      /*
       * Destructeur par défaut
       */
      ~Cellule() {}

private:
      /**
       * Accéder au statut.
       * @return le statut de la cellule.
       */
      bool statut() const { return vie == 1?true:false; }

      int presence() const{ return vie;}

public:

      /**
       * Accéder au statut
       */
      bool Estenvie() const { return vie == 1?true:false; }
      int EstPresent() const{ return vie;}

      /**
       * Sortie standart pour une cellule
       */
      Cellule operator+(const Cellule cell) {
	    return (Cellule(vie + cell.presence()));
      }
      Cellule operator+=(const Cellule cell) {
	    vie += cell.presence();
	    return( *this );
      }


      /**
       * Sortie standart pour une cellule
       */
      friend std::ostream& operator<<(std::ostream& out, const Cellule& cell ) {
	    if (cell.statut() == false)
	    {
		  out << "o";
	    }
	    else
	    {
		  out << "+";
	    }
	    return(out);
      }

};
