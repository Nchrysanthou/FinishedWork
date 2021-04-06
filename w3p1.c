/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Nicholas Chrysanthou
	ID     : 161264197
	Email  : NChrysanthou@myseneca.ca
	Section: IPC_NEE
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define MAX_YEAR 2021
#define MIN_YEAR 2010

char *MonthName(const int month)
{
	switch (month)
	{
	case 1:
		return "JAN";
	case 2:
		return "FEB";
	case 3:
		return "MAR";
	case 4:
		return "APR";
	case 5:
		return "MAY";
	case 6:
		return "JUN";
	case 7:
		return "JUL";
	case 8:
		return "AUG";
	case 9:
		return "SEP";
	case 10:
		return "OCT";
	case 11:
		return "NOV";
	case 12:
		return "DEC";
	}
}

int main(void)
{
	const int JAN = 1, DEC = 12;
	int year, month;
	bool valid = true;

	printf("General Well-being Log\n");
	printf("======================\n");
	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		if (month < JAN || month > DEC)
		{
			printf("ERROR: Jan.(1) - Dec.(12)\n");
			valid = false;
		}
		else if (year < MIN_YEAR || year > MAX_YEAR)
		{
			printf("ERROR: The year must be between 2010 and 2021 inclusive\n");
			valid = false;
		}
		else
			valid = true;

	} while (!valid);

	printf("\n*** Log date set! ***\n");
	printf("Log starting date: %d-%s-01\n", year, MonthName(month));

	return 0;
}