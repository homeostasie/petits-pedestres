#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double fpimarkov(int nDisk, int nPoint)
{
      srand(time(NULL)); //Random seed

      double coor[2]; //Point coordonate    
     
      int pCount;   // Point counter   
      int dCount; // disk counter
      
      int pIndisk = 0; // Point in disk
      
      double aPi;

      for(dCount = 0; dcount< nDisk; dCount++)
      {

	    for(pCount = 0; pCount < nPoint; pCount++)
	    {
		  // rand() belong to [0, RAND_MAX].
		  // coor is a point with random coordonate in [-1,1]x[-1,1].
		  coor[0] = rand()/(double)RAND_MAX;
		  coor[1] = rand()/(double)RAND_MAX;

		  // if the point belong to the disk
		  if(coor[0]*coor[0] + coor[1]*coor[1] < 1.0){
			pIndisk += 1;
		  }
	    }
      
      aPi = 4.*(double)pIndisk / nPoint;
      printf("%f \n",aPi);


}

int main(void)
{
      srand(time(NULL)); //Random seed

      double coor[2]; //Point coordonate    
     
      int pCount;   // Point counter
      int nPoint = 1000; // Max Points
      
      int pIndisk = 0; // Point in disk
      
      double aPi;

      for(pCount = 0; pCount < nPoint; pCount++)
      {
	    // rand() belong to [0, RAND_MAX].
	    // coor is a point with random coordonate in [-1,1]x[-1,1].
	    coor[0] = rand()/(double)RAND_MAX;
	    coor[1] = rand()/(double)RAND_MAX;

	    // if the point belong to the disk
	    if(coor[0]*coor[0] + coor[1]*coor[1] < 1.0){
		  pIndisk += 1;
	    }
      }
      
      aPi = 4.*(double)pIndisk / nPoint;
      printf("%f \n",aPi);

}
