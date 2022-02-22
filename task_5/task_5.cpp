/*
5. Пользователь вводит дату (по отдельности день, месяц, год).
Определить день недели, соответствующий введенной дате. При
написании программы следует исходить из того, что 01.01.01 – это
Понедельник.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool IsItALeapYear(int year) // Функция, проверяющая является ли год високосным.
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false;
}

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

bool DateValidationCheck(int day, int month, int year) // Функция, проверяющая корректность введенных значений даты.
{
	if (year > 0)
	{
		if (month > 0 && month < 13)
		{
			if (
				((IsItALeapYear(year))
					&& (month == February) && (day == 29)) // Если 29 февраля в високосном году.
				|| ((IsItALeapYear(year))
					&& (month == February) && (day > 0 && day < 29)) // Если 1-28 февраля, високосный год.
				|| (!(IsItALeapYear(year))
					&& (month == February) && (day > 0 && day < 29)) // Если 1-28 февраля, обычный год.
				|| ((month == January
					|| month == March
					|| month == May
					|| month == July
					|| month == August
					|| month == October
					|| month == December) && (day > 0 && day < 32)) // Все месяца, в которых 31 день.
				|| ((month == April
					|| month == June
					|| month == September
					|| month == November) && (day > 0 && day < 31)) // Все месяца, в которых 30 дней.
				)
			{
				return true; // Все введённые значения корректны.
			}
			else
				return false; // Введен не корректный день.
		}
		else
			return false; // Введен не корректный месяц. 
	}
	else
		return false; // Введен не корректный год. 
}

int Get_DOW(int year, int month, int day) // Функция определяет день недели.
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;

	return d ? d : 7;
}

int main()
{
	setlocale(LC_ALL, ""); // работает только с потоком вывода

	int day{  }, month{  }, year{  }; // дата (день, месяц, год) 
	cout << "Введите дату (по отдельности день, месяц, год):\n";
	cin >> day >> month >> year;

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

	if (DateValidationCheck(day, month, year) == true)
	{
		int dow = Get_DOW(year, month, day);
		cout << day << '.' << month << '.' << year << " года - ";
		if (dow == Monday)
			cout << "понедельник.\n";
		else if (dow == Tuesday)
			cout << "вторник.\n";
		else if (dow == Wednesday)
			cout << "среда.\n";
		else if (dow == Thursday)
			cout << "четверг.\n";
		else if (dow == Friday)
			cout << "пятница.\n";
		else if (dow == Saturday)
			cout << "суббота.\n";
		else if (dow == Sunday)
			cout << "воскресенье.\n";
	}
	else if (DateValidationCheck(day, month, year) == false)
		cout << "Такой даты не существует.\n";

	return 0;
}