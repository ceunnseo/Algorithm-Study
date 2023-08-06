// [2748] 언어 : C++, 메모리 (KB) : 2020 , 시간(ms) : 0

#include <bits/stdc++.h>
using namespace std;

// 테이블 정의
long long d[91]; // 피보나치 수의 범위가 커지면 int를 넘어갈 수 있음

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    //초기값 정의
    d[0] = 0;
    d[1] = 1;

    //점화식 d[i] = d[i-1] + d[i-2]
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    
    cout << d[n];

    return 0;
}
