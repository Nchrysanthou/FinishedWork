/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Nicholas Chrysanthou
	ID     : 161264197
	Email  : NChrysanthou@myseneca.ca
	Section: IPC_NEE
*/
#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define LOG_DAYS 3

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

double GetMorningRating()
{
	double rating = 0.00;
	bool valid = false;
	do
	{
		printf("Morning rating (0.0-5.0): ");
		scanf("%lf", &rating);
		if (rating < 0.0 || rating > 5.0)
		{
			printf("ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			valid = false;
		}
		else
		{
			valid = true;
			return rating;
		}
	} while (!valid);
}
double GetEveningRating()
{
	double rating = 0.00;
	bool valid = false;
	do
	{
		printf("Evening rating (0.0-5.0): ");
		scanf("%lf", &rating);
		if (rating < 0.0 || rating > 5.0)
		{
			printf("ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			valid = false;
		}
		else
		{
			valid = true;
			return rating;
		}
	} while (!valid);
}

int main(void)
{
	const int JAN = 1, DEC = 12;
	int year, month, i;
	bool valid = true;
	double totalMorningRating = 0.00, totalEveningRating = 0.00, totalOverallRating = 0.00;
	double avgMorningRating = 0.00, avgEveningRating = 0.00, avgOverallRating = 0.00;
	double mRating[LOG_DAYS], eRating[LOG_DAYS];

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

	printf("\n*** Log date set! ***\n\n");

	for (i = 0; i < LOG_DAYS; i++)
	{
		printf("%d-%s-%0d\n", year, MonthName(month), i + 1);
		mRating[i] = GetMorningRating();
		eRating[i] = GetEveningRating();
		printf("\n");
	}

	for (i = 0; i < LOG_DAYS; i++)
	{
		totalMorningRating += mRating[i];
		totalEveningRating += eRating[i];
	}
	totalOverallRating = totalMorningRating + totalEveningRating;
	avgMorningRating = totalMorningRating / LOG_DAYS;
	avgEveningRating = totalEveningRating / LOG_DAYS;
	avgOverallRating = (avgMorningRating + avgEveningRating) / LOG_DAYS * 2;

	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", totalMorningRating);
	printf("Evening total rating: %.3lf\n", totalEveningRating);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n", totalOverallRating);
	printf("\n");
	printf("Average morning rating: %.1lf\n", avgMorningRating);
	printf("Average evening rating: %.1lf\n", avgEveningRating);
	printf("----------------------------\n");
	printf("Average overall rating: %.1lf\n", avgOverallRating);

	return 0;
}