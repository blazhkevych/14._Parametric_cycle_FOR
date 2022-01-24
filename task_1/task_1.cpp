/*
1. Вывести на экран шахматную доску, используя пробел и символ с
кодом 219.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int i{ 0 }, j{ 0 }, symbol{ 219 }, side{ 21 };

	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			if (i % 2 == 0 && j % 2 == 0 
				|| i % 2 != 0 && j % 2 != 0)
			{
				cout << (char)symbol;
			}
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}