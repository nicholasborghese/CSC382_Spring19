#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Find(int x, int A[], int n)
{
	int j;
	for (j = 0; j < n; j++) {
		if (x == A[j]) {
			return (j + 1);
		}
	}
	return 0;
}
void CalculatedAverage(int bound)
{
	int n = 50;
	int steps;
	int hits = 0, totalSteps = 0;
	int Sequence[50];
	double q, calculateAve, realAve;
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < 50; j++)
			Sequence[j] = rand() % bound;
		if (Find(25, Sequence, n))
		{
			steps = (Find(25, Sequence, n));
			totalSteps += steps;
			hits++;//if x equal to any of the numbers generated in the sequence
		}
		else
			totalSteps += n;

	}
	// Calculated Average A(n)
	q = (double)hits / (double)10000;

	calculateAve = n + (q / 2) - (50 * q);
	// Real Average A2(n)
	realAve = (double)totalSteps / (double)10000;
	if (bound == INT_MAX)
		cout << setw(10) << "Infinite" << setw(19) << calculateAve << setw(15) <<

		realAve << endl;
	else
		cout << setw(10) << bound << setw(19) << calculateAve << setw(15) << realAve

		<< endl;
}
int main()
{
	cout << setw(10) << "Bound" << setw(20) << "Calculated Average\t" << setw(10) <<
		"Real Average" << endl;
	CalculatedAverage(30);
	CalculatedAverage(50);
	CalculatedAverage(80);
	CalculatedAverage(100);
	CalculatedAverage(1000);
	CalculatedAverage(10000);
	CalculatedAverage(INT_MAX);
	return 0;
}