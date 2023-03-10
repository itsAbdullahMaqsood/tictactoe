#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{	
	srand(time(0));
	for (int i = 5; i < 30; i++) {
		cout << rand() % 9 << "\t";

	}





	return 0;
}
