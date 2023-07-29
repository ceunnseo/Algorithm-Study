#define x first
#define y second
// 2초, 128MB
// n 세로 크기 (1 ≤ n ≤ 500)
// m 가로 크기 (1 ≤ m ≤ 500)
// 0 색칠X, 1 색칠

int visit[502][502] = {0,};
int board[501][501] = {0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    queue<pair<int, int>> q;    
    int max = 0, cnt = 0;
    int dir1[] = {1,0,-1,0};
    int dir2[] = {0,1,0,-1};

    cin >> n >> m;
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=m;j++){
            cin >> board[i][j];
        }
    }
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=m;j++){
            if(board[i][j] == 0 || visit[i][j] == 1)    continue;
            cnt++;
            int count = 0;
            q.push({i,j});
            while(!q.empty()){
                pair<int, int> t = q.front(); q.pop();
                
                if(board[t.x][t.y] == 0 || visit[t.x][t.y] == 1) continue;
                visit[t.x][t.y] = 1;
                count++;
                if(count > max) max = count;

                for(int k = 0; k<4; k++){
                    pair<int, int> t2 = {t.x+dir1[k],t.y+dir2[k]};
                    if(board[t2.x][t2.y] == 0 || visit[t2.x][t2.y] == 1) continue;
                    
                    q.push(t2);
                }
            }
        }
    }
    cout << cnt << '\n' << max;
}
