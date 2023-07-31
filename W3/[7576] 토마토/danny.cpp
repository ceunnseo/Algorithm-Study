// 1초, 256MB, 토마토
// n 세로 크기 (2 ≤ n ≤ 1000)
// m 가로 크기 (2 ≤ m ≤ 1000)
// 1 익토, 0 안익토, -1 노토
// O(N^2M^2)

int board[1002][1002];
int dist[1002][1002];
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    cin >> m >> n;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                q.push({i,j});
            if(board[i][j] == 0)
                dist[i][j] = -1;
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.x][cur.y]+1;
            q.push({nx,ny});
        }
    }
    int ans = 0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}
