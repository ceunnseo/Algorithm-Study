// 3초, 512MB, 연결 요소의 개수
// 노드 N, 간선 M (1<=n<1000, 0<=m<n*(n-1)/2)
// 간선의 끝점 u,v (u!=v) 중복없음

int board[1001][1001], visit[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> x >> y;
        board[x][y] = board[y][x] = 1;
    }
    for(int i = 1; i<=n; i++){
        if(visit[i] == 1) continue;
        cnt++;
        stack<int> s;
        s.push(i);
        while(!s.empty()){
            int t = s.top(); s.pop();
            visit[t] = 1;
            for(int j = 1; j<=n; j++){
                if(visit[j] == 0 && board[t][j] == 1){
                    s.push(j);
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
