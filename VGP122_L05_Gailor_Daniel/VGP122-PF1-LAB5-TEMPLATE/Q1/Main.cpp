/* Create a class called Date that includes three pieces of information as data members—a month
(type int), a day (type int) and a year (type int). Your class should have a constructor with three
parameters that uses the parameters to initialize the three data members. For the purpose of this
exercise, assume that the values provided for the year and day are correct, but ensure that the
month value is in the range 1–12; if it isn’t, set the month to 1. Provide a set and a get function for
each data member. Provide a member function displayDate that displays the month, day and year
separated by forward slashes (/). Write a test program that demonstrates class Date’s capabilities. */

#include <iostream>


using namespace std;




class date
{
	private:
		int month;
		int day;
		int year;

	public:
		date(int month, int day, int year)
		{
		setMonth(month);
		setDay(day);
		setYear(year);
		displayDate();
	}

		void setMonth(int month)
		{
			if (month < 1 || month > 12)
			{
			month = 1;
			}
		this->month = month;
	}

		void setDay(int day)
		{
		this->day = day;
	}

		void setYear(int year)
		{
		this->year = year;
	}

		int getMonth()
		{
		return month;
	}

		int getDay()
		{
		return day;
	}

		int getYear()
		{
		return year;
	}

		void displayDate()
		{
		cout << month << "/" << day << "/" << year << endl;
	}



};

int main()
{
	int month;
	int day;
	int year;

	cout << "Enter month: ";
	cin >> month;
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter year: ";
	cin >> year;

	date date1(month, day, year);



	return 0;
}

