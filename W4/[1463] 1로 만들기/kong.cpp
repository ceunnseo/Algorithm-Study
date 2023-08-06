// [1463] 언어 : C++, 메모리 (KB) : 5928 , 시간(ms) : 4

#include <bits/stdc++.h>
using namespace std;

int d[1000001]; //테이블 정의, d[i] = i를 1로 만들기 위한 최소연산횟수
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0; // 초기값 정의, 초기값의 범위 잘 정해야함 (초기값이 한개가 아닐 수 있음)
    
    for (int i = 2; i <= n; i++) { // 점화식을 기반으로 반복문을 돌려 배열을 채움
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) {
            d[i] = min(d[i], d[i / 2] + 1); 
        }
        if (i % 3 == 0) {
            d[i] = min(d[i], d[i / 3] + 1);

        }
    }

    cout << d[n];

    return 0;
}
