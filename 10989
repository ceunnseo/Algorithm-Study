// 언어 C++, 메모리 2060KB 시간 1952ms

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10001] = {0};


int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}
	
	for(int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}
