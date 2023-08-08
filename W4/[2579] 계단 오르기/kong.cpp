// [2579] 언어 : C++, 메모리 (KB) : 2024 , 시간(ms) : 0

#include <bits/stdc++.h>
using namespace std;


int n;
int s[301];
int d[301][2]; // 테이블 정의 , d[i][j] = j개의 연속된 계단을 밟고 i번째 계단에 도달 시 최대점수


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    //초기값 정의
    d[1][0] = s[1];
    d[1][1] = 0;
    d[2][0] = s[2];
    d[2][1] = s[1]+ s[2];

    // 점화식 : D[i][1] = max(D[i-2][0], D[i-2][1]) + S[i] / D[i][1] = D[i-1][0] + S[i]
    for (int i = 3; i <= n; i++) {
        d[i][0] = max(d[i - 2][0], d[i - 2][1]) + s[i];
        d[i][1] = d[i - 1][0] + s[i];
    }
    
    cout << max(d[n][0],d[n][1]);

    return 0;
}
