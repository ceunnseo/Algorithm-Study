// 언어 C++, 메모리 2288KB 시간 52ms

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

int n,m;
	int arr[100001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		int res = 0;
		int left = 0;
		int right = n-1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] > x) {
				right = mid - 1;
			}
			else if (arr[mid] < x) {
				left = mid + 1;
			}
			else {
				res = 1;
				break;
			}
		}	
		cout << res << "\n";
	}
}
