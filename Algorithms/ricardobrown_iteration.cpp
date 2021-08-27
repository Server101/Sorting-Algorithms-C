#include <fstream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

//Ricardo brown iTERATION AND RECURSION Assingment
// Iteration.cpp
//Prof. Janki Bhimani

using namespace std;

const size_t length = 1000000;
long len = 1000;
const long max_length = 1000000;
int list[max_length];



//Generate data intergers
int read()
{

	int r;
	int array[length];
	for (long i = 0; i < length; i++)
	{

		array[i] = (rand() % 100) + 1;
		//vector<int> vect(array, array + len);



	}


	return 0;
}


//============================================
//ITERATIVE Binary Search
//============================================

int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;


		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}
//============================================
//HEAP Sort
//============================================
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	//for (long j = 0; j < len; j++)
	// {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
	// }
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

//++++++++++++++++++++++++++++++++++++
// MAIN METHOD
int main()
{
	int r;
	int x;
	int arr[length];
	for (long i = 0; i < length; i++)
	{

		arr[i] = (rand() % 100) + 1;
		vector<int> vect(arr, arr + len);

		//cout << array[i];
	}

	//Iterative Sort Loop
	int *A;
	ios_base::sync_with_stdio(false);
	srand(time(0));
	int key;

	// The 5 iteration loops to find average time
	for (int k = 0; k < 5; k++) {
		key = rand();




		int n = sizeof(arr) / sizeof(arr[0]);
		int s = len;
		int p = sizeof(arr) / sizeof(arr[0]);
		int arr_size = sizeof(arr) / sizeof(arr[0]);
		double t1, t2;

		heapSort(arr, n);

		for (len = 1000; len <= max_length; )
		{



			cout << "\nLength\t: " << len << '\n';

			read();
			heapSort(arr, n);
			t1 = clock();
			binarySearch(arr, 0, n - 1, x);
			t2 = clock();
			cout << "Iterative\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";






			switch (len)
			{
			case 1000:
				len = 4000;
				break;
			case 4000:
				len = 8000;
				break;
			case 8000:
				len = 10000;
				break;
			case 10000:
				len = 40000;
				break;
			case 40000:
				len = 80000;
				break;
			case 80000:
				len = 100000;
				break;
			case 100000:
				len = 400000;
				break;
			case 400000:
				len = 800000;
				break;
			case 800000:
				len = 1000000;
				break;
			case 1000000:
				len = 1000001;
				break;
			}
		}

		return 0;
	}
}







