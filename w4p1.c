/*
	==================================================
	Workshop #4 (Part-1):
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

double GetPrice(const int items)
{
	int i = 0;
	double price = 0.00;
	bool valid = false;

	do
	{
		printf("Item-%d Details:\n", i + 1);
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
char GetFinance(const int Items)
{
	bool valid = false;

	char yn = "\0";
	do
	{
		printf("Does this item have financing options? [y/n]: ");
		yn = getchar();

		if (yn != 'y' || yn != 'n')
		{
			printf("ERROR: Must be a lowercase \'y\' or \'n\'\n");
			valid = false;
		}
		else
			valid = true;
	} while (!valid);
	return yn;
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
		printf("%3d %5d %5c %11.2lf\n", i + 1, priority[i], financed[i], costs[i]);
	printf("                  $%11.2lf\n\n", totalCost);
}

int main(void)
{
	double Costs[MAX_ITEMS];
	int Priority[MAX_ITEMS];
	char Finance[MAX_ITEMS];
	bool valid = false;

	double income = 0.00;
	int items = 0, i = 0;

	PrintHeader();

	do
		income = GetIncome();
	while (income < INCOME_MIN || income >= INCOME_MAX);

	do
		items = GetItemsToForcast();
	while (items < MIN_ITEMS || items > MAX_ITEMS);

	for (i = 0; i < items; i++)
	{
		Costs[i] = GetPrice(items);
		Finance[i] = GetFinance(items);
	}
	PrintFormattedOutput(items, Costs, Priority, Finance, CalculateTotalCost(items, Costs));
	return 0;
}
