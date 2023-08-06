// [1463] 언어 : C++, 메모리 (KB) :  , 시간(ms) : 

#include <bits/stdc++.h>
using namespace std;

int dist[1000001];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    queue<int> q;
    q.push(n); 

    fill(dist, dist + 1000001, -1);
    dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front(); 
        q.pop();
        if (dist[cur / 3] == -1 && cur % 3 == 0) {
            q.push(cur / 3);
            dist[cur / 3] = dist[cur] + 1;
        }
        if (dist[cur / 2] == -1 && cur % 2 == 0) {
            q.push(cur / 2);
            dist[cur / 2] = dist[cur] + 1;
        }
        if (dist[cur - 1] == -1 && cur - 1 >= 1) {
            q.push(cur - 1);
            dist[cur - 1] = dist[cur] + 1;
        }
    }

    cout << dist [1];

    return 0;
}
