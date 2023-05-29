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
	* @brief Определяет сколько дней в месяце
	* @param month: месяц
	* @returns 0 - 30 дней, -1 - Февраль, 1 - 31 день
	*/
	int MonthType(int month);

	/*
	* @brief Возвращает день
	* @returns m_day
	*/
	int GetDay();

	/*
	* @brief Возвращает месяц
	* @returns m_month
	*/
	int GetMonth();

	/*
	* @brief Возвращает год
	* @returns m_year
	*/
	int GetYear();

	/*
	* @brief Проверяет не выходит-ли номер дня за пределы месяца
	* @param day: номер дня
	* @param month: месяц
	* @param year: год
	* @returns true - выходит, false - не выходит
	*/
	bool CheckOverflow(int day, int month, int year);

	/*
	* @brief Возвращает дату измененую на некоторое кол-во дней
	* @param days: количество дней
	* @return res - новая дата
	*/
	Date operator+(int days);
	
	/*
	* @brief Возвращает дату измененую на некоторое кол-во дней
	* @param days: количество дней
	* @return res - новая дата
	*/
	Date operator-(int days);

	/*
	* @brief Возвращает разницу между двумя датами в днях
	* @param date: дата
	* @returns days - разница
	*/
	int operator-(const Date& date);

	/*
	* @brief Сравнивают две даты
	* @param date: дата
	* @returns true/false
	*/
	bool operator!=(const Date& date) const;
	
	/*
	* @brief Сравнивают две даты
	* @param date: дата
	* @returns true/false
	*/
	bool operator>(const Date& date);
};

