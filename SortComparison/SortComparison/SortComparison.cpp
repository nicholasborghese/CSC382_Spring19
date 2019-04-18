#include "pch.h";
#include <iostream>
#include <iomanip>
using namespace std;
const int max = 200000;
int B[max];
int C[max];
int D[max];
void InsertionSort(int A[], int n) {
	int temp;
	for (int i = 1; i < n; i++) {
		int j = i;
		while (C[j] < C[j - 1]) {
			temp = C[j];
			C[j] = C[j - 1];
			C[j - 1] = temp;
			j--;
		}
	}
}
void Merge(int A[], int first, int mid, int last) {
	int i = first;
	int j = mid + 1;
	int p;
	int k = first;
	while ((i <= mid) && (j <= last)) {
		if (A[i] <= A[j]) {
			B[k] = A[i];
			i++;
		}
		else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (p = j; p <= last; p++) {
			B[k] = A[p];

			k++;
		}
	}
	else {
		for (p = i; p <= mid; p++) {
			B[k] = A[p];
			k++;
		}
	}
	for (i = first; i <= last; i++) {
		A[i] = B[i];
	}
}
void MergeSort(int A[], int first, int last) {
	int mid;
	if (first < last) {
		mid = (first + last) / 2;
		MergeSort(A, first, mid);
		MergeSort(A, mid + 1, last);
		Merge(A, first, mid, last);
	}
}
void FixHeap(int A[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 1;
	if (l < n && A[l] > A[largest])
		largest = l;
	if (r < n && A[r] > A[largest])
		largest = r;
	if (largest != i) {
		swap(A[i], A[largest]);
		FixHeap(A, n, largest);
	}
}
void HeapSort(int A[], int n) {
	int temp;
	for (int i = (n / 2); i >= 1; i--)
		FixHeap(A, n, i);
	for (int i = n - 1; i >= 1; i--) {
		temp = A[i + 1];
		FixHeap(A, i, 1);
		A[i + 1] = temp;

	}
}
void timer(int num) {
	int bound = 500000;
	int random;
	int Sequence[max];
	for (int i = 0; i < num; i++) {
		random = rand() % bound;
		Sequence[i] = random;
	}
	cout << setw(10) << num << fixed;
	double clock1, clock2, clock3, clock4, clock5, clock6;
	for (int i = 0; i < num; i++) {
		C[i] = Sequence[i];
	}
	clock1 = clock();
	InsertionSort(C, num);
	clock2 = clock();
	cout << setw(14) << setprecision(3) << (clock2 - clock1) / CLOCKS_PER_SEC;
	for (int i = 0; i < num; i++) {
		D[i] = Sequence[i];
	}
	clock3 = clock();
	MergeSort(D, 0, num - 1);
	clock4 = clock();
	cout << setw(17) << setprecision(3) << (clock4 - clock3) / CLOCKS_PER_SEC;
	clock5 = clock();
	HeapSort(Sequence, num);
	clock6 = clock();
	cout << setw(14) << setprecision(3) << (clock6 - clock5) / CLOCKS_PER_SEC <<
	endl;
}
int main() {
	cout << setw(12) << "Input Size\t" << setw(10) << "Insertion Sort\t" << setw(12) <<
		"Merge Sort";
	cout << setw(14) << "Heap Sort" << endl;
	int data[] = { 100, 1000, 10000, 50000, 100000, 200000 };
	int value = *(&data + 1) - data;
	long length;
	for (int i = 0; i < value; i++) {
		length = data[i];

		timer(length);
	}
	return 0;
}