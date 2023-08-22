// [2579] ��� : C++, �޸� (KB) : 2024 , �ð�(ms) : 0

#include <bits/stdc++.h>
using namespace std;


int n;
int s[301];
int d[301][2]; // ���̺� ���� , d[i][j] = j���� ���ӵ� ����� ��� i��° ��ܿ� ���� �� �ִ�����


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    //�ʱⰪ ����
    d[1][0] = s[1];
    d[1][1] = 0;
    d[2][0] = s[2];
    d[2][1] = s[1]+ s[2];

    // ��ȭ�� : D[i][1] = max(D[i-2][0], D[i-2][1]) + S[i] / D[i][1] = D[i-1][0] + S[i]
    for (int i = 3; i <= n; i++) {
        d[i][0] = max(d[i - 2][0], d[i - 2][1]) + s[i];
        d[i][1] = d[i - 1][0] + s[i];
    }
    
    cout << max(d[n][0],d[n][1]);

    return 0;
}
