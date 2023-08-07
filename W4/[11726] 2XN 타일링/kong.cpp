// [11659] 언어 : C++, 메모리 (KB) :  , 시간(ms) : 

#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[100001], d[100001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    d[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = d[i - 1] + a[i];
    }
   
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i - 1] << '\n';
    }

    return 0;
}
