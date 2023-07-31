// 2초, 128MB, 숨바꼭질
// n 수빈 (2 ≤ n ≤ 100,000)
// k 동생 (2 ≤ m ≤ 100,000)
// 걷기(x-1,x+1), 순간이동(2*x)
// 움직일수 있는 범위는 10만보다 클 수 있음

int dist[1000002];
int n,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    fill(dist, dist+100001, -1);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while(dist[k] == -1){
        int cur = q.front(); q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            q.push(nxt);
        }
    }

    cout << dist[k];
}
