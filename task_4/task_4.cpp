/*
4. В цикле с клавиатуры вводится 15 целых чисел. Необходимо найти
самую длинную неубывающую цепочку чисел. На экран вывести
найденную максимальную длину цепочки и порядковый номер того
числа, с которого цепочка началась.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	cout << "Введите 15 целых чисел:" << endl;

	int current_number{ 0 }, previous_number{ 0 },
		start_position{ 0 }, max_start_position{ 0 },
		amount_of_numbers{ 0 }, max_amount_of_numbers{ 0 }, i{ 0 };

	for (i = 0; i < 15; i++)
	{
		cin >> current_number;
		if (current_number >= previous_number)
			amount_of_numbers++;
		else
		{
			if (amount_of_numbers > max_amount_of_numbers)
			{
				max_amount_of_numbers = amount_of_numbers;
				max_start_position = start_position;
			}
			amount_of_numbers = 1;
			start_position = i;
		}
		previous_number = current_number;
	}
	if (amount_of_numbers > max_amount_of_numbers) // для цепочки в конце
	{
		max_amount_of_numbers = amount_of_numbers;
		max_start_position = start_position;
	}
	cout << "Максимальная длина цепочки: " << max_amount_of_numbers << endl;
	cout << "Порядковый номер того числа, с которого цепочка началась : " << max_start_position << endl;

	return 0;
}