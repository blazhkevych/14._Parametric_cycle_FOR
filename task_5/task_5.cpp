/*
5. Пользователь вводит дату (по отдельности день, месяц, год).
Определить день недели, соответствующий введенной дате. При
написании программы следует исходить из того, что 01.01.01 – это
Понедельник.
*/

/*
http://rusoul.ru/vychislenie-dnia-nedeli-po-date/ Тренируем мозги (ВЫЧИСЛЕНИЕ ДНЯ НЕДЕЛИ ПО ДАТЕ)
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	// Возьмем дату — 20.11.1957 года
	int date_day{ 20 }, date_month{ 11 }, date_year{ 1957 }; // дата (день, месяц, год) 

	cout << "Введите дату (по отдельности день, месяц, год):\n";
	//cin >> date_day >> date_month >> date_year;

	double the_last_two_digits_of_the_year{ 0 }; // индекс года
	the_last_two_digits_of_the_year = date_year % 100; // 57

	int whole{ 0 }; // целых от деления the_last_two_digits_of_the_year на 12
	whole = the_last_two_digits_of_the_year / 12; // 4 // 1-е число

	int remainder{ 0 }; // остаток от деления the_last_two_digits_of_the_year на 12
	remainder = the_last_two_digits_of_the_year - whole * 12; // 9 // 2-е число

	int rest{ 0 }; // 3-е число
	if (remainder > whole) // если остаток больше целых
	{
		//for (; remainder > whole;)
		rest = remainder / whole; // 2
	}

	double index_of_the_year{ 0 }; // индекс года
	index_of_the_year = whole + remainder + rest; // 4+9+2=15

	int century_index{ 0 }; // индекс века
	if (date_year / 100 == 19)
		century_index = 1;

	int leap_year_index{ 0 }; // индекс високосного года
	if (date_year % 400 == 0 || (date_year % 100 != 0 && date_year % 4 == 0) && date_month == 1 ||
		date_year % 400 == 0 || (date_year % 100 != 0 && date_year % 4 == 0) && date_month == 2)
		leap_year_index = -1;

	cout << "Вычислим день недели для даты " << date_day << '.' << date_month << '.' << date_year << " года\n"
		<< "Сложим все индексы:\n"
		<< "Индекс года = " << index_of_the_year << '(' << whole << " + " << remainder << " + " << rest << ')' << endl;

	enum Months
	{
		January = 1, // Январь, 31 день
		February = 2, // Февраль, 28 дней (В високосные годы вводится дополнительный день — 29 февраля.)
		March = 3, // Март, 31 день 
		April = 4, // Апрель, 30 дней 
		May = 5, // Май, 31 день 
		June = 6, // Июнь, 30 дней 
		July = 7, // Июль, 31 день 
		August = 8, // Август, 31 день 
		September = 9, // Сентябрь, 30 дней 
		October = 10, // Октябрь, 31 день 
		November = 11, // Ноябрь, 30 дней 
		December = 12 // Декабрь, 31 день 
	};

	int month_index{ 0 }; // индекс месяца

	if (date_month == May)
		month_index = 0;
	else if (date_month == August)
		month_index = 1;
	else if (date_month == February || date_month == March || date_month == November)
		month_index = 2;
	else if (date_month == June)
		month_index = 3;
	else if (date_month == September || date_month == December)
		month_index = 4;
	else if (date_month == April || date_month == July)
		month_index = 5;
	else if (date_month == January || date_month == October)
		month_index = 6;

	cout << "Индекс месяца = " << month_index << endl
		<< "Просто дата = " << date_day << endl
		<< "Индекс века = " << century_index << endl
		<< "Итак, " << index_of_the_year << " + " << month_index << " + " << date_day << " + " << century_index << ", получится ";
	int sum_of_all_indices = index_of_the_year + month_index + date_day + century_index;
	cout << sum_of_all_indices << endl
		<< "Результат делится на 7, в нашем случае " << sum_of_all_indices << " / " << " на 7 = ";
	int sum_of_all_indices_Whole_part = sum_of_all_indices / 7; // целая часть от деления суммы всех индексов на 7
	int sum_of_all_indices_Remainder_part = sum_of_all_indices_Remainder_part - sum_of_all_indices_Whole_part * 7; // остаток от деления суммы всех индексов на 7
	cout << sum_of_all_indices_Whole_part << " и " << sum_of_all_indices_Remainder_part << " в остатке.\n"
		<< "Неделя начинается с понедельника, это число 1, а число " << sum_of_all_indices_Remainder_part << " соответствует ";
	enum Days_of_the_week
	{
		Monday = 1, // понедельник
		Tuesday = 2, // вторник
		Wednesday = 3, // среда
		Thursday = 4, // четверг
		Friday = 5, // пятница
		Saturday = 6, // суббота
		Sunday = 7 // воскресенье
	};
	if (sum_of_all_indices_Remainder_part == Monday)
		cout << "понедельнику.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "вторнику.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "среде.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "четвергу.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "пятнице.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "субботе.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "воскресенью.\n";
	cout << "Итого: " << date_day << '.' << date_month << '.' << date_year << " года - ";
	if (sum_of_all_indices_Remainder_part == Monday)
		cout << "понедельник.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "вторник.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "среда.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "четверг.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "пятница.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "суббота.\n";
	else if (sum_of_all_indices_Remainder_part == Monday)
		cout << "воскресенье.\n";

	return 0;
}