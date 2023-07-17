// 언어 C++, 메모리 2412KB 시간 12ms

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> x;

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << count << '\n';

    return 0;
}
