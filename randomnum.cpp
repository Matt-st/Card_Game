#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;
int main()
{	int i = 0;
	int rnum;
	srand(time(0));
	srand( (unsigned)time(NULL));
	
	while (i < 51)
	{
	rnum = rand() % 52;
		cout << rnum << "  ";
		i++;
	};
	cout << endl;



return 0;
}
