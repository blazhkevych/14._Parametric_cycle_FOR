/*
4. В цикле с клавиатуры вводится 15 целых чисел. Необходимо найти
самую длинную неубывающую цепочку чисел. На экран вывести
найденную максимальную длину цепочки и порядковый номер того
числа, с которого цепочка началась.
*/

// В задании один цикл fot, а внтури ифы, больше ничего.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	cout << "Введите 15 целых чисел:" << endl;

	int number{ 0 }, temp{ 0 }, position{ 0 }, start_position{ 0 }, finish_position{ 0 }, count{ 0 };

	for (int i = 0; i < 15; i++)
	{
		cin >> number;

		int temp = number;

		if (temp >= number)
		{
			start_position = 15-i;
			count++;

		}
	}
	cout << "Максимальная длина цепочки: " <<count << endl;
	cout << "порядковый номер того
		числа, с которого цепочка началась : " <<count << endl;


	return 0;
}