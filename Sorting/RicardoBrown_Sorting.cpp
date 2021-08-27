// C++ program for implementation of Heap Sort
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <set>
#include <vector>

//Ricardo Brown Sorting Algorithms project

using namespace std;

const size_t length = 1000000;
long len = 1000;
const long max_length = 1000000;
int list[max_length];
vector<int> vect(list, list + len);  // This is not used




int read()
{

	int r;
	int array[length];
	for (long i = 0; i < length; i++)
	{

		array[i] = (rand() % 100) + 1;
		vector<int> vect(array, array + len);

		//cout << array[i];


	}


	return 0;
}

//============================================
//bubble Sort
//============================================
void bubbleSort()
{
	int temp;
	for (long i = 0; i < len; i++)
	{
		for (long j = 0; j < len - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}


//========================================\


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


//============================================
//MERGE Sort
//============================================
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];


	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];


	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{


		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



//============================================
//INSERTION Sort
//============================================
void insertionSort()
{
	int temp;
	for (long i = 1; i < len; i++)
	{
		temp = list[i];
		long j;
		for (j = i - 1; j >= 0 && list[j] > temp; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = temp;
	}
}

long partition(long left, long right)
{
	int pivot_element = list[left];
	int lb = left, ub = right;
	int temp;

	while (left < right)
	{
		while (list[left] <= pivot_element)
			left++;
		while (list[right] > pivot_element)
			right--;
		if (left < right)
		{
			temp = list[left];
			list[left] = list[right];
			list[right] = temp;
		}
	}
	list[lb] = list[right];
	list[right] = pivot_element;
	return right;
}


//============================================
//QUICK Sort
//============================================
void quickSort(long left, long right)
{
	if (left < right)
	{
		long pivot = partition(left, right);
		quickSort(left, pivot - 1);
		quickSort(pivot + 1, right);
	}
}




//============================================
//SELECTION Sort
//============================================

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int *array, int size) {
	int i, j, imin;
	for (i = 0; i < size - 1; i++) {
		imin = i;   //get index of minimum data
		for (j = i + 1; j < size; j++)
			if (array[j] < array[imin])
				imin = j;
		//placing in correct position
		swap(array[i], array[imin]);
	}
}

/*
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}

}

  */


  //++++++++++++++++++++++++++++++++++++
  // MAIN METHOD
int main()
{
	int r;
	int arr[length];
	for (long i = 0; i < length; i++)
	{

		arr[i] = (rand() % 100) + 1;
		vector<int> vect(arr, arr + len);

		//cout << array[i];
	}


	int n = sizeof(arr) / sizeof(arr[0]);
	int s = len;
	int p = sizeof(arr) / sizeof(arr[0]);
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	double t1, t2;


	for (len = 1000; len <= max_length; )
	{


		cout << "\nLength\t: " << len << '\n';

		read();
		t1 = clock();
		bubbleSort();
		t2 = clock();
		cout << "Bubble Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";

		t1 = clock();
		insertionSort();
		t2 = clock();
		cout << "Insertion Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";


		t1 = clock();
		mergeSort(arr, 0, arr_size - 1);
		t2 = clock();
		cout << "Merge Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";


		t1 = clock();
		heapSort(arr, n);
		t2 = clock();
		cout << "Heap Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";

		t1 = clock();
		selectionSort(arr, s);
		t2 = clock();
		cout << "Selection Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";

		read();
		t1 = clock();
		quickSort(0, len - 1);
		t2 = clock();
		cout << "Quick Sort\t: " << (t2 - t1) / CLOCKS_PER_SEC << " sec\n";



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







