#include "pch.h"
#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

int FiboR(int n) {// array of size n
	if (n == 0 || n == 1)
		return (n);
	else return (FiboR(n - 1) + FiboR(n - 2));
}
int FiboNR(int n) {// array of size n
	int F[200];
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i <= n; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	return (F[n]);
}
int main() {
	int array[13] = { 1,5,10,15,20,25,30,35,40,45,50 };
	int start, stop1, stop2, value1, value2;
	cout << "Integer" << setw(25) << "FiboR (seconds)" << setw(25) << "FiboNR (seconds)"
		<< setw(25) << "Integer" << endl;
	for (int i = 0; i < 13; i++) {
		start = clock();
		value1 = FiboR(array[i]);
		stop1 = clock();
		value2 = FiboNR(array[i]);
		stop2 = clock();
		cout << left << setw(25) << array[i] << left << setw(25) << (stop1 - start) /
			CLOCKS_PER_SEC << left << setw(25) << (stop2 - stop1) /
			CLOCKS_PER_SEC << left << setw(25) << value1 << endl;

	}
	return 0;
}