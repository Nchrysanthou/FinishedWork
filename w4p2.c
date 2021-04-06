/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : Nicholas Chrysanthou
	ID     : 161264197
	Email  : NChrysanthou@myseneca.ca
	Section: IPC_NEE
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define INCOME_MIN 500.00
#define INCOME_MAX 400000.00

#define MIN_ITEMS 1
#define MAX_ITEMS 10

#define PRIO_MIN 1
#define PRIO_MAX 3

void PrintHeader()
{
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	printf("\n");
}

double GetIncome()
{
	double income = 0;
	printf("Enter your monthly NET income: $");
	scanf("%lf", &income);
	if (income < INCOME_MIN)
		printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
	else if (income > INCOME_MAX)
		printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
	else
		return income;
	return 0;
}
int GetItemsToForcast()
{
	int items = 0;
	printf("How many wish list items do you want to forecast?: ");
	scanf("%d", &items);
	if (items < MIN_ITEMS || items > MAX_ITEMS)
	{
		printf("ERROR: List is restricted to between 1 and 10 items.\n");
		return 0;
	}
	return items;
}

double GetPrice(const int index)
{
	int i = 0;
	double price = 0.00;
	bool valid = false;

	do
	{
		printf("Item-%d Details:\n", index);
		printf("Item cost: $");
		scanf("%lf", &price);
		if (price < 100.00)
		{
			printf("ERROR: Cost must be at least $100.00\n");
			valid = false;
		}
		else
			return price;
	} while (!valid);
}

int GetPriority()
{
	int prio = 0;
	bool valid = false;
	do
	{
		printf("How important is it to you? [1=must have, 2=important, 3=want]: ");
		scanf("%d", &prio);

		if (prio < PRIO_MIN || prio > PRIO_MAX)
		{
			printf("ERROR: Value must be between 1 and 3\n");
			valid = false;
		}
		else
		{
			valid = true;
			return prio;
		}
	} while (!valid);
	return 0;
}

char GetFinance()
{
	bool valid = false;

	char yesNo;

	do
	{
		printf("Does this item have financing options? [y/n]: ");
		fflush(stdin);
		scanf("%c", &yesNo);

		if (yesNo == 'y' || yesNo == 'n')
			valid = true;

		else
		{
			printf("ERROR: Must be a lowercase \'y\' or \'n\'\n");
			valid = false;
		}
	} while (!valid);
	return yesNo;
}

double CalculateTotalCost(const int items, double costs[])
{
	int i = 0;
	double tCost = 0.00;
	for (i = 0; i < items; i++)
		tCost += costs[i];
	return tCost;
}

void PrintFormattedOutput(const int itemsToPrint, double costs[], int priority[], char financed[], const double totalCost)
{
	int i = 0;
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < itemsToPrint; i++)
		printf("%3d  %5d   %5c     %11.2lf\n", i + 1, priority[i], financed[i], costs[i]);
	printf("                      $%11.2lf\n\n", totalCost);
}
int GetForcastWish()
{
	int forcast = 0;
	bool valid = true;
	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf("1. All items (no filter)\n");
		printf("2. By priority\n");
		printf("0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &forcast);

		switch (forcast)
		{
		default:
		{
			printf("\nERROR: Invalid menu selection.\n");
			valid = false;
			break;
		}
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		}

	} while (!valid);
}
int CalculateForcast(const double income, const double amount)
{
	int years, months;
	years = (income / amount) * 12;
	months = years % 12;
	printf("Forecast: %d years, %d months\n", years, months);
}
int ForcastItem(const int forcast, const double income, const double amount)
{
	switch (forcast)
	{
	case 1:
		printf("\n====================================================\n");
		printf("Filter: All items\n");
		printf("Amount: $.2lf\n", amount);
		CalculateForcast(income, amount);
		printf("NOTE: Financing options are available on some items.\n");
		printf("      You can likely reduce the estimated months.\n");
		printf("\n====================================================\n");

		break;
	case 2:
		printf("\n====================================================\n");

		break;
	case 0:
		break;
	}
}
int main(void)
{
	double Costs[MAX_ITEMS];
	int Priority[MAX_ITEMS];
	char Finance[MAX_ITEMS];
	bool valid = false;

	double income = 0.00;
	int items = 0, forcast = 0, i = 0;

	PrintHeader();

	do
		income = GetIncome();
	while (income < INCOME_MIN || income >= INCOME_MAX);

	do
		items = GetItemsToForcast();
	while (items < MIN_ITEMS || items > MAX_ITEMS);

	for (i = 0; i < items; i++)
	{
		Costs[i] = GetPrice(i + 1);
		Priority[i] = GetPriority();
		Finance[i] = GetFinance();
	}
	PrintFormattedOutput(items, Costs, Priority, Finance, CalculateTotalCost(items, Costs));

	forcast = GetForcastWish();
	ForcastItem(forcast, income, totalCost);
	return 0;
}
