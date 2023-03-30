#pragma once
#include <iostream>

class Date
{
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day = 1, int month = 1, int year = 1970);
	Date(const Date& date);

	void operator=(const Date& date);

	/*
	* @brief ќпредел€ет сколько дней в мес€це
	* @param month: мес€ц
	* @returns 0 - 30 дней, -1 - ‘евраль, 1 - 31 день
	*/
	int MonthType(int month);

	/*
	* @brief ¬озвращает день
	* @returns m_day
	*/
	int GetDay();

	/*
	* @brief ¬озвращает мес€ц
	* @returns m_month
	*/
	int GetMonth();

	/*
	* @brief ¬озвращает год
	* @returns m_year
	*/
	int GetYear();

	/*
	* @brief ѕровер€ет не выходит-ли номер дн€ за пределы мес€ца
	* @param day: номер дн€
	* @param month: мес€ц
	* @param year: год
	* @returns true - выходит, false - не выходит
	*/
	bool CheckOverflow(int day, int month, int year);

	/*
	* @brief ¬озвращает дату измененую на некоторое кол-во дней
	* @param days: количество дней
	* @return res - нова€ дата
	*/
	Date operator+(int days);
	
	/*
	* @brief ¬озвращает дату измененую на некоторое кол-во дней
	* @param days: количество дней
	* @return res - нова€ дата
	*/
	Date operator-(int days);

	/*
	* @brief ¬озвращает разницу между двум€ датами в дн€х
	* @param date: дата
	* @returns days - разница
	*/
	int operator-(const Date& date);

	/*
	* @brief —равнивают две даты
	* @param date: дата
	* @returns true/false
	*/
	bool operator!=(const Date& date) const;
	
	/*
	* @brief —равнивают две даты
	* @param date: дата
	* @returns true/false
	*/
	bool operator>(const Date& date);
};

