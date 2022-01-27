/*
2. Определить, является ли введённое число любой разрядности
палиндромом (например, 1234321 – палиндром, 12345 – не
палиндром).
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	cout << "Введите число: " << endl;
	long long unsigned int number{ 0 };
	cin >> number;

	int number_2{ 0 };
	int temp = number;
	for (; number > 0; ) // переворачиваем число 
	{
		number_2 = number_2 * 10 + (number % 10);
		number = number / 10;
	}
	temp == number_2 ? // и сравниваем с введенным
		cout << "Введенное число палиндром." :
		cout << "Введенное число не палиндром." << endl;

	return 0;
}