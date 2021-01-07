#include <iostream>
#include <time.h>
using namespace std;
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}
void selectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
void insertionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int key = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > key)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = key;
	}
}
void binaryInsertionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int key = a[i];
		int l = 0;
		int r = i - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (key < a[mid])
				r = mid - 1;
			else l = mid + 1;
		}
		for (int j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = key;
	}
}
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void shakerSort(int a[], int n)
{
	int l = 0;
	int r = n - 1;
	int pos;
	while (l < r)
	{
		for (int i = l; i < r; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				pos = i;
			}
		}
		r = pos;
		for (int i = r; i > l; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				pos = i;
			}
		}
		l = pos;
	}
}
void shellSort(int a[], int n)
{
	int interval, temp;
	for (interval = n / 2; interval > 0; interval = interval / 2)
	{
		for (int i = interval; i < n; i++)
		{
			temp = a[i];
			int j;
			for (int j = i; j >= interval && a[j - interval] > temp; j = j - interval)
			{
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<r && a[l]>a[largest])
		largest = l;
	if (r<n && a[r]>a[largest])
		largest = r;
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
void countingSort(int a[], int n)
{
	int countArr[MAX_SIZE] = { 0 };
	for (int i = 0; i < n; i++)
		countArr[a[i]]++;
	int outputIndex = 0;
	for (int j = 0; j < MAX_SIZE; j++)
		while (countArr[j]-- < 0)
			a[outputIndex++] = j;
}
void radixSort(int a[], int n)
{
	int i, b[MAX_SIZE], m = a[0], exp = 1;
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}
void quickSort(int a[], int l, int r)
{
	int p = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j) {
		while (a[i] < p) {
			i++;
		}
		while (a[j] > p) {
			j--;
		}
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r) {
		quickSort(a, i, r);
	}
	if (l < j) {
		quickSort(a, l, j);
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	/* Tạo các mảng tạm */
	int* L = new int[n1];
	int* R = new int[n2];
	/* Copy dữ liệu sang các mảng tạm */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* Gộp hai mảng tạm vừa rồi vào mảng arr*/
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
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

	/* Copy các phần tử còn lại của mảng L vào arr nếu có */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy các phần tử còn lại của mảng R vào arr nếu có */
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
		// Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
		int m = l + (r - l) / 2;

		// Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}