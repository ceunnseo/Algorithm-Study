#define x first
#define y second

// 2초, 192MB, 벽 부수고 이동하기
// N*M 행렬 맵
// 0 : 이동 가능, 1 : 이동X
// (1,1) -> (N,M) / 벽 한개까지 부시기 가능
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용
// (x,y)가 벽이라서 부수는 경우 포함

char board[1000][1000];
int dist[1000][1000][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
queue<tuple<int, int, int>> q;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    char in;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> in;
            board[i][j] = in - '0';
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1; // 거리 초기화
    dist[0][0][0] = dist[0][0][1] = 1;
    q.push({0, 0, 0});
    
    while (!q.empty())
    {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        if (x == n - 1 && y == m - 1){
            cout << dist[x][y][broken]; // 도착한것이 가장 빠른것
            return 0;
        }
        q.pop();
        int nextdist = dist[x][y][broken] + 1;
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[nx][ny] == 0 && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = nextdist;
                q.push({nx, ny, broken});
            }
            // (nx, ny)를 부수는 경우
            if (!broken && board[nx][ny] == 1 && dist[nx][ny][1] == -1){
                dist[nx][ny][1] = nextdist;
                q.push({nx, ny, 1});
            }
        }
    }
    cout << -1;
    return 0;
}
