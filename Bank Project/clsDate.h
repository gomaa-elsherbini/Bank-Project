#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "clsString.h"
using namespace std;



class clsDate
{
private:
	int _Day;
	int _Month;
	int _Year;

	static void DistributeMonthDays(int year, int month)
	{
		int days = NumberOfDaysInMonth(year, month);

		int firstDayOrder = OrderOfDay(year, month, 1);

		for (int i = 1; i <= firstDayOrder; i++)
			printf("     ");

		for (int x = 1; x <= days; x++)
		{
			printf("%5d", x);
			if ((x + firstDayOrder) % 7 == 0)
				cout << endl;
		}
		cout << endl;
	}
	enum enCompareTwoDates { After = 1, Before = -1, Equal = 0 };
	static enCompareTwoDates CheckTwoDates(clsDate Date1, clsDate Date2)
	{
		return (IsDate1AfterDate2(Date1, Date2) ? enCompareTwoDates::After :
			(IsDate1EqualDate2(Date1, Date2)) ? enCompareTwoDates::Equal :
			enCompareTwoDates::Before);
	}

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon+1;
		_Year = now->tm_year + 1900;
	}
	clsDate(int Day, int Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(string D)
	{
		vector<string>vDate = clsString::splitString(D, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}
	clsDate(int Days, int Year)
	{
		clsDate Date = DateFromNumberOfDays(Year, Days);

		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Year;
	}

	void SetDay(int Day)
	{
		_Day = Day;
	}
	int Day()
	{
		return _Day;
	}
	void SetMonth(int Month)
	{
		_Month = Month;
	}
	int Month()
	{
		return _Month;
	}
	void SetYear(int Year)
	{
		_Year = Year;
	}
	int Year()
	{
		return _Year;
	}

	__declspec(property(get = Day, put = SetDay))int day;
	__declspec(property(get = Month, put = SetMonth))int month;
	__declspec(property(get = Year, put = SetYear))int year;

	static void Print(clsDate Date)
	{
		cout << to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	void Print()
	{
		return Print(*this);
	}

	static clsDate DateFromNumberOfDays(int year, int numberOfDays)
	{
		clsDate Date; // 1/1/2022

		Date._Day = 1;
		Date._Month = 1;
		Date._Year = year;

		while (numberOfDays != 0)
		{
			Date = Date.IncreaseDateByOneDay();

			numberOfDays--;
		}

		return Date;
	}
	clsDate DateFromNumberOfDays(int numberOfDays)
	{
		return DateFromNumberOfDays(_Year, numberOfDays);
	}

	static bool IsLeapYear(int year)
	{
		return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static int NumberOfDaysInYear(int year)
	{
		return IsLeapYear(year) ? 366 : 365;
	}
	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}
	
	static int NumberOfHoursInYear(int year)
	{
		return (NumberOfDaysInYear(year) * 24);
	}
	int NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(int year)
	{
		return NumberOfHoursInYear(year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(int year)
	{
		return NumberOfMinutesInYear(year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static int NumberOfDaysInMonth(int year, int month)
	{
		if (month == 2)
		{
			if (IsLeapYear(year))
				return  29;
			else
				return  28;
		}

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			return  31;

		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;

		else
			return 0;
	}
	int NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Year, _Month);
	}

	static int NumberOfHoursInMonth(int year, int month)
	{
		return (NumberOfDaysInMonth(year, month) * 24);
	}
	int NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month);
	}

	static int NumberOfMinutesInMonth(int year, int month)
	{
		return NumberOfHoursInMonth(year, month) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Year, _Month);
	}

	static int NumberOfSecondsInMonth(int year, int month)
	{
		return NumberOfMinutesInMonth(year, month) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Year, _Month);
	}

	static int OrderOfDay(int year, int month, int day)
	{
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	int OrderOfDay()
	{
		return OrderOfDay(_Year, _Month, _Day);
	}

	static string NameOfDay(int year, int month, int day)
	{
		int order = OrderOfDay(year, month, day);
		string arrOfDaysNames[7] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrOfDaysNames[order];
	}
	string NameOfDay()
	{
		return NameOfDay(_Year, _Month, _Day);
	}

	static string NameOfMonth(int month)
	{
		string arrOfMonths[12] = { "Jan", "Feb", "Mar", "App", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return arrOfMonths[month - 1];
	}
	string NameOfMonth()
	{
		return NameOfMonth(_Month);
	}
	
	static void PrintMonthCalender(int year, int month)
	{
		cout << "\n  ______________ " << NameOfMonth(month) << " ______________\n\n";

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		DistributeMonthDays(year, month);

		cout << "  _________________________________\n";

	}
	void PrintMonthCalender()
	{
		return PrintMonthCalender(_Year, _Month);
	}

	static int DaysFromBeginningOfYear(int year, int month, int day)
	{
		int numberOfDays = 0;

		for (int mon = 1; mon < month; mon++)
			numberOfDays += NumberOfDaysInMonth(year, mon);
		
		numberOfDays += day;

		return numberOfDays;
	}
	int DaysFromBeginningOfYear()
	{
		return DaysFromBeginningOfYear(_Year, _Month, _Day);
	}

	static clsDate AddDaysToDate(clsDate Date, int numberOfDays)
	{
		return IncreaseDateByXDays(Date, numberOfDays);
	}
	clsDate AddDaysToDate(int numberOfDays)
	{
		return AddDaysToDate(*this, numberOfDays);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? (Date1._Day < Date2._Day) : false)) : false);
	}
	bool IsBeforeDate(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);;
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? Date1._Day == Date2._Day : false) : false;
	}
	bool IsEqualDate(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDayIsLastDay(clsDate Date)
	{
		return Date._Day == NumberOfDaysInMonth(Date._Year, Date._Month);
	}
	bool IsDayIsLastDay()
	{
		return IsDayIsLastDay(*this);
	}

	static bool IsMonthIsLastMonth(clsDate Date)
	{
		return Date._Month == 12;
	}
	bool IsMonthIsLastMonth()
	{
		return IsMonthIsLastMonth(*this);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsDayIsLastDay(Date))
		{
			if (IsMonthIsLastMonth(Date))
			{
				Date._Month = 1;
				Date._Year++;
			}
			else
				Date._Month++;

			Date._Day = 1;
		}
		else
			Date._Day++;

		return Date;
	}
	clsDate IncreaseDateByOneDay()
	{
		return IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseDateByXDays(clsDate Date, int numberDays)
	{
		for (int day = 1; day <= numberDays; day++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXDays(int numberDays)
	{
		return IncreaseDateByXDays(*this,numberDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		return IncreaseDateByXDays(Date, 7);
	}
	clsDate IncreaseDateByOneWeek()
	{
		return IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate Date, int numberWeeks)
	{
		for (int week = 1; week <= numberWeeks; week++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXWeeks(int numberWeeks)
	{
		return IncreaseDateByXWeeks(*this, numberWeeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
			Date._Month++;

		int monthDays = NumberOfDaysInMonth(Date._Year, Date._Month);

		Date._Day = (Date._Day > monthDays) ? monthDays : Date._Day;

		return Date;
	}
	clsDate IncreaseDateByOneMonth()
	{
		return IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate Date, int numberMonths)
	{
		for (int month = 1; month <= numberMonths; month++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXMonths(int numberMonths)
	{
		return IncreaseDateByXMonths(*this, numberMonths);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		return Date;
	}
	clsDate IncreaseDateByOneYear()
	{
		return IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate Date, int numberOfYears)
	{
		for (int year = 1; year <= numberOfYears; year++)
			Date = IncreaseDateByOneYear(Date);
		return Date;
	}
	clsDate IncreaseDateByXYears(int numberOfYears)
	{
		return IncreaseDateByXYears(*this, numberOfYears);
	}

	static clsDate IncreaseDateByXYearsFaster(clsDate Date, int numberOfYears)
	{
		Date._Year += numberOfYears;
		return Date;
	}
	clsDate IncreaseDateByXYearsFaster(int numberOfYears)
	{
		return IncreaseDateByXYearsFaster(*this, numberOfYears);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date._Year += 10;
		return Date;
	}
	clsDate IncreaseDateByOneDecade()
	{
		return IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate Date, int numberDecades)
	{
		for (int decade = 1; decade <= numberDecades; decade++)
			Date = IncreaseDateByOneDecade(Date);

		return Date;
	}
	clsDate IncreaseDateByXDecades(int numberDecades)
	{
		return IncreaseDateByXDecades(*this, numberDecades);
	}
	
	static clsDate IncreaseDateByXDecadesFaster(clsDate Date, int numberOfDecades)
	{
		Date._Year += numberOfDecades * 10;
		return Date;
	}
	clsDate IncreaseDateByXDecadesFaster(int numberOfDecades)
	{
		return IncreaseDateByXDecadesFaster(*this, numberOfDecades);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date._Year += 100;
		return Date;
	}
	clsDate IncreaseDateByOneCentury()
	{
		return IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMilinium(clsDate Date)
	{
		Date._Year += 1000;
		return Date;
	}
	clsDate IncreaseDateByOneMilinium()
	{
		return IncreaseDateByOneMilinium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInMonth(Date._Year, Date._Month);
			}
		}
		else
			Date._Day--;

		return Date;
	}
	clsDate DecreaseDateByOneDay()
	{
		return DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate Date, int numberOfDays)
	{
		for (int day = 1; day <= numberOfDays; day++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}
	clsDate DecreaseDateByXDays(int numberOfDays)
	{
		return DecreaseDateByXDays(*this, numberOfDays);
	}

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		return DecreaseDateByXDays(Date, 7);
	}
	clsDate DecreaseDateByOneWeek()
	{
		return DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate Date, int numberOfWeeks)
	{
		for (int week = 1; week <= numberOfWeeks; week++)
			Date = DecreaseDateByOneWeek(Date);

		return Date;
	}
	clsDate DecreaseDateByXWeeks(int numberOfWeeks)
	{
		return DecreaseDateByXWeeks(*this, numberOfWeeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;

		int monthDays = NumberOfDaysInMonth(Date._Year, Date._Month);
		Date._Day = (Date._Day > monthDays) ? monthDays : Date._Day;

		return Date;
	}
	clsDate DecreaseDateByOneMonth()
	{
		return DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, int numberOfMonths)
	{
		for (int month = 1; month <= numberOfMonths; month++)
			Date = DecreaseDateByOneMonth(Date);

		return Date;
	}
	clsDate DecreaseDateByXMonths(int numberOfMonths)
	{
		return DecreaseDateByXMonths(*this, numberOfMonths);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		return Date;
	}
	clsDate DecreaseDateByOneYear()
	{
		return DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate Date, int numberOfYears)
	{
		for (int year = 1; year <= numberOfYears; year++)
			Date = DecreaseDateByOneYear(Date);

		return Date;
	}
	clsDate DecreaseDateByXYears(int numberOfYears)
	{
		return DecreaseDateByXYears(*this, numberOfYears);
	}

	static clsDate DecreaseDateByXYearsFaster(clsDate Date, int numberOfYears)
	{
		Date._Year -= numberOfYears;
		return Date;
	}
	clsDate DecreaseDateByXYearsFaster(int numberOfYears)
	{
		return DecreaseDateByXYearsFaster(*this, numberOfYears);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date._Year -= 10;
		return Date;
	}
	clsDate DecreaseDateByOneDecade()
	{
		return DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate Date, int numberOfDecades)
	{
		for (int decade = 1; decade <= numberOfDecades; decade++)
			Date = DecreaseDateByOneDecade(Date);

		return Date;
	}
	clsDate DecreaseDateByXDecades(int numberOfDecades)
	{
		return DecreaseDateByXDecades(*this, numberOfDecades);
	}
	
	static clsDate DecreaseDateByXDecadesFaster(clsDate Date, int numberOfDecades)
	{
		Date._Year -= numberOfDecades * 10;
		return Date;
	}
	clsDate DecreaseDateByXDecadesFaster(int numberOfDecades)
	{
		return DecreaseDateByXDecadesFaster(*this, numberOfDecades);
	}
	
	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date._Year -= 100;
		return Date;
	}
	clsDate DecreaseDateByOneCentury()
	{
		return DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMilinium(clsDate Date)
	{
		Date._Year -= 1000;
		return Date;
	}
	clsDate DecreaseDateByOneMilinium()
	{
		return DecreaseDateByOneMilinium(*this);
	}

	static int DateDifference(clsDate Date1, clsDate Date2, bool isIncludeEndDay = false)
	{
		int numberOfDays = 0;

		if (Date1.IsAfterDate2(Date2))// 31/12/2022
			Date1.SwapDates(Date2);//    28/ 2/2023

		while (!Date1.IsEqualDate(Date2))
		{
			Date1 = Date1.IncreaseDateByOneDay();
			numberOfDays++;
		}

		return (isIncludeEndDay) ? ++numberOfDays : numberOfDays;
	}
	int DateDifference(clsDate Date2, bool isIncludeEndDay = false)
	{
		return DateDifference(*this, Date2);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate container;

		container = Date1;
		Date1 = Date2;
		Date2 = container;
	}
	void SwapDates(clsDate& Date2)
	{
		return SwapDates(*this, Date2);
	}

	static int DateDifferenceInDays(clsDate Date1, clsDate Date2, bool isIncludeEndDay = false)
	{
		int numberOfDays = 0;
		int flagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			flagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			numberOfDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (isIncludeEndDay) ? ++numberOfDays * flagValue : numberOfDays * flagValue;
	}
	int DateDifferenceInDays(clsDate Date2, bool isIncludeEndDay = false)
	{
		return DateDifferenceInDays(*this, Date2);
	}

	static void PrintYearCalender(int year)
	{
		cout << "  _________________________________\n\n";
		cout << "           Calender - " << year << "\n";
		cout << "  _________________________________\n\n";

		for (int month = 1; month <= 12; month++)
			PrintMonthCalender(year, month);
	}
	void PrintYearCalender()
	{
		return PrintYearCalender(_Year);
	}

	static bool IsValid(clsDate Date)
	{
		int day = Date._Day;
		int month = Date._Month;
		int year = Date._Year;

		if (month < 1 || month > 12)
			return false;

		else if (day < 1 || day>31)
			return false;

		else if (day > NumberOfDaysInMonth(year, month))
			return false;

		else
			return true;
	}
	bool IsValid()
	{
		return IsValid(*this);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth, bool isIncludeEndDay = true)
	{
		clsDate Date2;
		int numberOfDays = 0;

		for (int year = DateOfBirth._Year; year < Date2._Year; year++)
			numberOfDays += NumberOfDaysInYear(year);

		for (int month = DateOfBirth._Month; month < Date2._Month; month++)
			numberOfDays += NumberOfDaysInMonth(DateOfBirth._Year, month);

		numberOfDays += Date2._Day - DateOfBirth._Day;

		return (isIncludeEndDay) ? ++numberOfDays : numberOfDays;
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return OrderOfDay(Date._Year, Date._Month, Date._Day) == 6;
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		int dayOrder = OrderOfDay(Date._Year, Date._Month, Date._Day);
		return dayOrder == 5 || dayOrder == 6;
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static int DaysUntillTheEndOfWeek(clsDate Date)
	{
		return 6 - OrderOfDay(Date._Year, Date._Month, Date._Day);
	}
	int DaysUntillTheEndOfWeek()
	{
		return DaysUntillTheEndOfWeek(*this);
	}

	static int DaysUntillTheEndOfMonth(clsDate Date)//   23/9/2022
	{
		/*clsDate DateOfEndOfYear;

		DateOfEndOfYear._Day = NumberOfDaysInMonth(Date._Year, Date._Month);
		DateOfEndOfYear._Month = Date._Month;
		DateOfEndOfYear._Year = Date._Year;

		return DateDifference(Date, DateOfEndOfYear, 1);*/
		//return (numberOfDaysInMonth(Date.year, Date.month) - Date.day)+1;

		return Date.NumberOfDaysInMonth() - Date._Day;

	}
	int DaysUntillTheEndOfMonth()
	{
		return DaysUntillTheEndOfMonth(*this);
	}
	
	static int DaysUntillTheEndOfYear(clsDate Date)//   23/9/2022
	{
		clsDate DateOfEndOfYear;

		DateOfEndOfYear._Day = 31;
		DateOfEndOfYear._Month = 12;
		DateOfEndOfYear._Year = Date._Year;

		return DateDifference(Date, DateOfEndOfYear);
	}
	int DaysUntillTheEndOfYear()
	{
		return DaysUntillTheEndOfYear(*this);
	}

	static int ClaculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{//    1/9/2022    5/9/222
		int dateDifference = DateDifference(DateFrom, DateTo);

		for (int day = 1; day <= dateDifference; day++)
		{
			DateFrom._Day = day;
			if (IsWeekEnd(DateFrom))
				dateDifference--;
		}

		return dateDifference;
	}
	int ClaculateVacationDays(clsDate DateTo)
	{
		return ClaculateVacationDays(*this, DateTo);
	}

	static clsDate ReturnDateAfterVacationPeriod(clsDate startDate, int vPeriod)
	{
		while (vPeriod !=0)
		{
			if (!startDate.IsWeekEnd())
				vPeriod--;
			
			startDate = startDate.IncreaseDateByOneDay();
		}
		return startDate;
	}
	clsDate ReturnDateAfterVacationPeriod(int vPeriod)
	{
		return ReturnDateAfterVacationPeriod(*this, vPeriod);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static int CompareTwoDates(clsDate Date1, clsDate Date2)
	{
		return IsDate1AfterDate2(Date1, Date2) ? 1 : (IsDate1EqualDate2(Date1, Date2)) ? 0 : -1;
	}
	int CompareTwoDates(clsDate Date2)
	{
		return CompareTwoDates(*this, Date2);
	}

	static bool IsPeriod1OverlapPeriod2(clsDate P1SDate, clsDate P1EDate,
										clsDate P2SDate, clsDate P2EDate)
	{
		struct stPeriod
		{
			clsDate startDate;
			clsDate endDate;
		};

		stPeriod period1, period2, container;

		period1.startDate = P1SDate;
		period1.endDate = P1EDate;
		period2.startDate = P2SDate;
		period2.endDate = P2EDate;


		int isPeriod2AfterStartPeriod1 = CompareTwoDates(period2.startDate, period1.startDate);
		int isPeriod2BeforeEndOfPeriod1 = CompareTwoDates(period2.startDate, period1.endDate);

		if (isPeriod2AfterStartPeriod1 == -1)
		{
			container = period1;
			period1 = period2;
			period2 = container;
		}

		isPeriod2AfterStartPeriod1 = CompareTwoDates(period2.startDate, period1.startDate);
		isPeriod2BeforeEndOfPeriod1 = CompareTwoDates(period2.startDate, period1.endDate);

		if ((isPeriod2AfterStartPeriod1 == 1 || isPeriod2AfterStartPeriod1 == 0)
			&& (isPeriod2BeforeEndOfPeriod1 == -1 || isPeriod2BeforeEndOfPeriod1 == 0))
			return true;
		else
			return false;
	}

	static int periodLengthInDays(clsDate PSDate, clsDate PEDate, bool includeEndDay = false)
	{
		return DateDifference(PSDate, PEDate);
	}

	static bool IsDateWithinPeriod(clsDate PSDate, clsDate PEDate, clsDate Date)
	{
		struct stPeriod
		{
			clsDate startDate;
			clsDate endDate;
		};
		stPeriod period;

		period.startDate = PSDate;
		period.endDate = PEDate;



		if ((CheckTwoDates(Date, period.startDate) == enCompareTwoDates::After
			|| CheckTwoDates(Date, period.startDate) == enCompareTwoDates::Equal)
			&& (CheckTwoDates(Date, period.endDate) == enCompareTwoDates::Before
				|| CheckTwoDates(Date, period.endDate) == enCompareTwoDates::Equal))
			return true;
		else
			return false;
	}
	bool IsWithinPeriod(clsDate PSDate, clsDate PEDate)
	{
		return IsDateWithinPeriod(PSDate , PEDate , *this);
	}

	static int CountOverlapDays(clsDate P1SDate, clsDate P1EDate,
									clsDate P2SDate, clsDate P2EDate)
	{
		if (IsDateWithinPeriod(P2SDate, P2EDate, P1EDate) &&
			IsDateWithinPeriod(P1SDate, P1EDate, P2SDate))
        return DateDifference(P2SDate, P1EDate);

    else if (IsDateWithinPeriod(P1SDate, P1EDate, P2EDate) &&
		IsDateWithinPeriod(P2SDate, P2EDate, P1SDate))
        return DateDifference(P1SDate, P2EDate);

    else if (IsDateWithinPeriod(P2SDate, P2EDate, P1SDate) &&
		IsDateWithinPeriod(P2SDate, P2EDate, P1EDate))
        return DateDifference(P1SDate, P1EDate);

    else if (IsDateWithinPeriod(P1SDate, P1EDate, P2SDate) &&
		IsDateWithinPeriod(P1SDate, P1EDate, P2SDate))
        return DateDifference(P2SDate, P2EDate);
    else
        return 0;
	}

	static string ConvertDateToString(clsDate Date, char delim)
	{
		return (to_string(Date._Day) + delim + to_string(Date._Month) + delim + to_string(Date._Year));
	}
	string ConvertDateToString(char delim)
	{
		return ConvertDateToString(*this, delim);
	}

	static string FormatDate(clsDate Date, string format = "dd/mm/yyyy")
	{
		string formattedDate = "";

		formattedDate = clsString::replaceString(format, "dd", to_string(Date._Day));
		formattedDate = clsString::replaceString(formattedDate, "mm", to_string(Date._Month));
		formattedDate = clsString::replaceString(formattedDate, "yyyy", to_string(Date._Year));

		return formattedDate;
	}
	string FormatDate(string format = "dd/mm/yyyy")
	{
		return FormatDate(*this, format);
	}

	static string GetCurrentTime()
	{
		string Time="";
		time_t t = time(0);
		tm* now = localtime(&t);

		Time += to_string(now->tm_mday) + "/";
		Time += to_string(now->tm_mon + 1) + "/";
		Time += to_string(now->tm_year + 1900) + " - ";
		Time += to_string(now->tm_hour) + ":";
		Time += to_string(now->tm_min) + ":";
		Time += to_string(now->tm_sec);

		return Time;
	}


};
