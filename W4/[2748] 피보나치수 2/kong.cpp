// [2748] ��� : C++, �޸� (KB) : 2020 , �ð�(ms) : 0

#include <bits/stdc++.h>
using namespace std;

// ���̺� ����
long long d[91]; // �Ǻ���ġ ���� ������ Ŀ���� int�� �Ѿ �� ����

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    //�ʱⰪ ����
    d[0] = 0;
    d[1] = 1;

    //��ȭ�� d[i] = d[i-1] + d[i-2]
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    
    cout << d[n];

    return 0;
}
