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
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	cout << "Введите высоту: " << endl;
	int side{ 0 };
	cin >> side;

	int i{ 0 }, j{ 0 };

	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			if (i == j
				)
			{
				int symbol = 219;
				cout << (char)symbol;
			}
			else
				cout << "  ";
		}
		cout << "\n";
	}

	return 0;
}
//
//int main()
//{
//	int code;
//	cin >> code;
//	cout << (char)code;
//	return 0;
//}