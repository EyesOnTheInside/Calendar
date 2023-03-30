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
	* @brief ���������� ������� ���� � ������
	* @param month: �����
	* @returns 0 - 30 ����, -1 - �������, 1 - 31 ����
	*/
	int MonthType(int month);

	/*
	* @brief ���������� ����
	* @returns m_day
	*/
	int GetDay();

	/*
	* @brief ���������� �����
	* @returns m_month
	*/
	int GetMonth();

	/*
	* @brief ���������� ���
	* @returns m_year
	*/
	int GetYear();

	/*
	* @brief ��������� �� �������-�� ����� ��� �� ������� ������
	* @param day: ����� ���
	* @param month: �����
	* @param year: ���
	* @returns true - �������, false - �� �������
	*/
	bool CheckOverflow(int day, int month, int year);

	/*
	* @brief ���������� ���� ��������� �� ��������� ���-�� ����
	* @param days: ���������� ����
	* @return res - ����� ����
	*/
	Date operator+(int days);
	
	/*
	* @brief ���������� ���� ��������� �� ��������� ���-�� ����
	* @param days: ���������� ����
	* @return res - ����� ����
	*/
	Date operator-(int days);

	/*
	* @brief ���������� ������� ����� ����� ������ � ����
	* @param date: ����
	* @returns days - �������
	*/
	int operator-(const Date& date);

	/*
	* @brief ���������� ��� ����
	* @param date: ����
	* @returns true/false
	*/
	bool operator!=(const Date& date) const;
	
	/*
	* @brief ���������� ��� ����
	* @param date: ����
	* @returns true/false
	*/
	bool operator>(const Date& date);
};

