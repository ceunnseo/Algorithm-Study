// [1463] ��� : C++, �޸� (KB) : 5928 , �ð�(ms) : 12

#include <bits/stdc++.h>
using namespace std;

int d[1000001]; //���̺� ����, d[i] = i�� 1�� ����� ���� �ּҿ���Ƚ��
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0; // �ʱⰪ ����, �ʱⰪ�� ���� �� ���ؾ��� (�ʱⰪ�� �Ѱ��� �ƴ� �� ����)
    
    for (int i = 2; i <= n; i++) { // ��ȭ���� ������� �ݺ����� ���� �迭�� ä��
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
