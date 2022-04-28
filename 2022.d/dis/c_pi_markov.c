#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
      double nombre = 24589 ;

      double compteur = nombre ;

      int i = 1 ;

      
      while(compteur >= 10)
      {

	      compteur = compteur / 10 ;
            i = i + 1;

      }
            printf("%d \n",i);

}
