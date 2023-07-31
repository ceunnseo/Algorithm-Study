// 언어 C++, 메모리 2412KB 시간 0ms

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];

void quick_sort(int* arr, int start, int end)
{
    if (start >= end)
        return;

    int Key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j)
    {

        while (arr[i] <= arr[Key])
            i++;
        while (arr[j] >= arr[Key] && j > start)
            j--;

        if (i >= j) 
        {
            temp = arr[Key];
            arr[Key] = arr[j];
            arr[j] = temp;
        }
        else
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    quick_sort(arr, start, j - 1);
    quick_sort(arr, j + 1, end);

}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	quick_sort(arr,0,n-1);

	for(int i=0; i<n;i++){
		cout << arr[i] << '\n';
	}

	return 0;
}
