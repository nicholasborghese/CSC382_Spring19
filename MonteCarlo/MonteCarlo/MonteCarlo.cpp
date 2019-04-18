#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int InsertionMod(int A[], int n)
{
	int i, j, temp;
	int comparisons = 0;
	A[0] = -32768; //smallest possible integer using 2 bytes integer representation
	for (i = 1; i <= n; i++) {
		j = i;
		while (A[j] < A[j - 1]) {
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
			comparisons++;
		}
	}
	return comparisons;
}
int CalculatedAverage(int Nnum)
{
	int bound = 5000;
	long long totalSteps = 0, steps = 0;
	int realavg = 0;
	int Sequence[5000];
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < Nnum; j++) {
			Sequence[j] = rand() % bound;
		}
		totalSteps += InsertionMod(Sequence, Nnum);
	}
	realavg = (long long)totalSteps / 100000;
	return realavg;
}
int main()

{
	cout << setw(12) << "Input Size\t" << setw(20) << "Calculated Average\t" << setw(15)
		<< "Real Average" << endl;
	int data[] = { 100, 500, 1000, 2500, 3000, 3500 };
	int value;
	int a[6], b[6], size = sizeof(data);
	for (int i = 0; i < size - 1; i++) {
		value = data[i];
		a[i] = ((value * value) / 4) + (3 * value / 4);//A(n)
		b[i] = CalculatedAverage(value);//A2(n)
		cout << setw(7) << value << setw(20) << a[i] << setw(25) << b[i] << endl;
	}
	return 0;
}