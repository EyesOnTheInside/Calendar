#include "Date.h"

Date::Date(int day, int month, int year)
{
	bool ch = true;

	if (year > 0)
	{
		if (month >= 1 && month <= 12)
			ch = !CheckOverflow(day, month, year);
		else
			ch = false;
	}
	else
		ch = false;

	if (ch)
	{
		m_day = day;
		m_month = month;
		m_year = year;
	}
	else
	{
		m_day = 1;
		m_month = 1;
		m_year = 1970;
	}
}

Date::Date(const Date& date)
{
	m_day = date.m_day;
	m_month = date.m_month;
	m_year = date.m_year;
}

void Date::operator=(const Date& date)
{
	m_day = date.m_day;
	m_month = date.m_month;
	m_year = date.m_year;
}

int Date::MonthType(int month)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 0;
	else if (month == 2)
		return -1;
	else
		return 1;
}

int Date::GetDay()
{
	return m_day;
}

int Date::GetMonth()
{
	return m_month;
}

int Date::GetYear()
{
	return m_year;
}

bool Date::CheckOverflow(int day, int month, int year)
{
	bool ch = false;

	switch (MonthType(month))
	{
	case 1:
		if (day < 1 || day > 31)
			ch = true;

		break;
	case 0:
		if (day < 1 || day > 30)
			ch = true;

		break;
	default:
		if (year % 4 && (day < 1 || day>28))
			ch = true;
		else if (day < 1 || day>29)
			ch = true;

		break;
	}

	return ch;
}

Date Date::operator+(int days)
{
	if (days < 0)
		return *this - (days * -1);

	int day = m_day + days;
	int month = m_month;
	int year = m_year;

	while (CheckOverflow(day, month, year))
	{
		switch (MonthType(month))
		{
		case 1:
			day -= 31;

			if (month == 12)
			{
				month = 1;
				year++;
			}
			else
				month++;

			break;
		case 0:
			day -= 30;
			month++;
			break;
		default:
			if (year % 4)
				day -= 28;
			else
				day -= 29;

			month++;
			break;
		}
	}

	Date res(day, month, year);
	return res;
}

Date Date::operator-(int days)
{
	if (days < 0)
		return *this + (days * -1);

	int day = m_day - days;
	int month = m_month;
	int year = m_year;

	while (CheckOverflow(day, month, year))
	{
		switch (MonthType(month - 1))
		{
		case 1:
			day += 31;

			if (month == 1)
			{
				month = 12;
				year--;
			}
			else
				month--;

			break;
		case 0:
			day += 30;
			month--;
			break;
		default:
			if (year % 4)
				day += 28;
			else
				day += 29;

			month--;
			break;
		}
	}

	Date res(day, month, year);
	return res;
}

int Date::operator-(const Date& date)
{
	int days = 0;
	Date temp(date);
	bool ch = temp > *this;

	while (*this != temp)
	{
		if (ch)
		{
			if (m_year != temp.m_year)
			{
				days += temp.m_day;
				temp = temp - temp.m_day;
			}
			else if (m_month != temp.m_month)
			{
				days += temp.m_day;
				temp = temp - temp.m_day;
			}
			else if (m_day != temp.m_day)
			{
				days += temp.m_day - m_day;
				temp = *this;
			}
		}
		else
		{
			if (m_year != temp.m_year)
			{
				for (int temp_month = temp.m_month; temp_month == temp.m_month;)
				{
					days += 1;
					temp = temp + 1;
				}
			}
			else if (m_month != temp.m_month)
			{
				for (int temp_month = temp.m_month; temp_month == temp.m_month;)
				{
					days += 1;
					temp = temp + 1;
				}
			}
			else if (m_day != temp.m_day)
			{
				for (; m_day != temp.m_day;)
				{
					days += 1;
					temp = temp + 1;
				}
			}
		}
	}

	return days;
}

bool Date::operator!=(const Date& date) const
{
	bool res = true;

	if (res)
		res = m_year != date.m_year;
	if (!res)
		res = m_month != date.m_month;
	if (!res)
		res = m_day != date.m_day;

	return res;
}

bool Date::operator>(const Date& date)
{
	if (m_year > date.m_year)
		return true;
	else if (m_year == date.m_year)
	{
		if (m_month > date.m_month)
			return true;
		else if (m_month == date.m_month)
		{
			if (m_day > date.m_day)
				return true;
		}
	}

	return false;
}
