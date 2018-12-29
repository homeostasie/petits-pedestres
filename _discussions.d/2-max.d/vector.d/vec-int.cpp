#include <iostream> 
#include <vector>

class coordonnate
{
	public:
	int x;
	int y;
	int z;
};


int main()
{
	coordonnate myCoor;
		
	std::vector<coordonnate> myvec;
	
	myvec.push_back (myCoor);
	
	
	std::cout<<"OK"<<std::endl;
	return(0);
}
