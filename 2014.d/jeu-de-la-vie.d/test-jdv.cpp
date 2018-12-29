#include "Cellule.cpp"
#include "Plateau.cpp"

void testCellule()
{
      Cellule cell;
      std::cout << "Sortie standart pour une cellule : "<< cell << std::endl;
      Cellule cell1(0);
      std::cout << "Sortie standart pour une cellule morte : "<< cell1 << std::endl;
      Cellule cell2(1);
      std::cout << "Sortie standart pour une cellule en vie : "<< cell2 << std::endl;
      Cellule cell3 = cell2;
      std::cout << "Sortie standart pour une cellule en vie à partir de la copie : "<< cell2 << std::endl;
}


int main()
{
      testCellule();

      Plateau p1(3);
      Plateau p2(true);
	
      p2.show();
      p2.showTotal();	
      
      std::cout << "p2" << std::endl;
      std::copy(p2.plateau.begin(), p2.plateau.end(), std::ostream_iterator<Cellule>(std::cout, ", ") );
      std::cout << std::endl; 
      
      Plateau p3 = p2.Evolution();
    
      std::cout << "Expected" << std::endl;
      std::copy(p3.plateau.begin(), p3.plateau.end(), std::ostream_iterator<Cellule>(std::cout, ", ") );
      std::cout << std::endl; 
    
      p3.showTotal();	
      p3.show();

      p3 = p2.Evolution(2);
        
      std::cout << "Expected" << std::endl;
      std::copy(p3.plateau.begin(), p3.plateau.end(), std::ostream_iterator<Cellule>(std::cout, ", ") );
      std::cout << std::endl; 
    
      p3.showTotal();	
      p3.show();

}
