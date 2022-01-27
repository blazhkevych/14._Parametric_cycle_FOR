/*
3. Осуществить циклический сдвиг введённого числа на N разрядов.
Направление сдвига задает пользователь. Например, при сдвиге
числа 12345 влево на 3 разряда получится число 45123. При сдвиге
числа 12345 вправо на 3 разряда получится число 34512.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	cout << "Введите число N:" << endl;
	int  number{ 0 };
	cin >> number;

	cout << "На сколько разрядов осуществлять циклический сдвиг ?" << endl;
	int n{ 0 };
	cin >> n;

	cout << "Выберите направление сдвига:" << endl
		<< "1 <--- циклический сдвиг влево;" << endl
		<< "2 ---> циклический сдвиг вправо;" << endl;
	int choice{ 0 };
	cin >> choice;

	enum UserChoice
	{
		cyclic_shift_to_the_left = 1,
		cyclic_shift_to_the_right = 2
	};

	int divider{ 1 }; // определяем отрезаемое кол-во цифр от введенного числа
	for (; number / (divider * 10);)
		divider *= 10;

	switch (choice) // по выбору направления циклического сдвига числа
	{
	case cyclic_shift_to_the_left: // - циклический сдвиг влево		
		for (int i = 0; i < n; i++) // формируем новое число
		{
			int temp = number % divider; // отделяем левую часть
			number = temp * 10 + number / divider; // формируем новое число(правая часть + левая часть числа)
		}
		cout << number << endl;
		break;
	case cyclic_shift_to_the_right: // - циклический сдвиг вправо
		int temp = 0;
		for (int i = 0; i < n; i++) // формируем новое число
		{
			temp = number % 10; // отделяем правую часть
			number /= 10; // удаляем крайнее правое число
			number = temp * divider + number; // формируем новое число(правая часть + левая часть числа)
		}
		cout << number << endl;
		break;
	}

	return 0;
}