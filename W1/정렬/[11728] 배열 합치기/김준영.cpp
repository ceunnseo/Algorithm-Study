// 언어 C++, 메모리 22252KB 시간 512ms

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arrA(n);
    vector<int> arrB(m);

    for (int i = 0; i < n; ++i) {
        cin >> arrA[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> arrB[i];
    }

    vector<int> merged;
    int a = 0;
    int b = 0;

    while (a < n && b < m) {
        if (arrA[a] <= arrB[b]) {
            merged.push_back(arrA[a]);
            a++;
        } else {
            merged.push_back(arrB[b]);
            b++;
        }
    }

    while (a < n) {
        merged.push_back(arrA[a]);
        a++;
    }

    while (b < m) {
        merged.push_back(arrB[b]);
        b++;
    }

    for (int i = 0; i < merged.size(); ++i) {
        cout << merged[i] << ' ';
    }

    return 0;
}
