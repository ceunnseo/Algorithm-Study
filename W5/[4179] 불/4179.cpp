// 동시에 상호작용이 필요하다면 이렇게 분리 해서 하는것은 불가능 -> 백트랙킹
#define x first
#define y second

// 1초, 256MB, 불
// 10956kb	56ms
// 지훈, 불 매 분 한칸 수평,수직 이동(벽 통과X)
// 불 각 지점 네방향
// 탈출지점 : 미로 가장자리 접한 공간
// 1 <= R, C <= 1000
// R : 미로 행 / C : 열
// # 벽 / . 길 / J 지훈 / F 불
// 빠른 탈출 시간 출력 / 불가시 IMPOSSIBLE
char board[1002][1003];
int dist1[1002][1002]; // 불 전파 시간
int dist2[1002][1002]; // 지훈 이동 시간
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    for(int i = 0; i < n; i++)
        cin >> board[i];

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == 'F'){
                q1.push({i,j});
                dist1[i][j] = 0;
            }else if(board[i][j] == 'J'){
                q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }

    // 불 BFS
    while(!q1.empty()){
        auto cur = q1.front(); q1.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
            q1.push({nx, ny});
        }
    }
    // 지훈 BFS
    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 탈출 성공
                cout << dist2[cur.x][cur.y]+1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist1[nx][ny] != -1 && 
                dist1[nx][ny] <= dist2[cur.x][cur.y]+1) continue;
            // 불 전파 시간 조건 추가
            dist2[nx][ny] = dist2[cur.x][cur.y]+1;
            q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}