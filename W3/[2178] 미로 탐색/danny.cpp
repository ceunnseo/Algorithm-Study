#define x first
#define y second
// 1초, 192MB, 미로 탐색
// (1,1) -> (N,M)
// n 세로 크기 (2 ≤ n ≤ 100)
// m 가로 크기 (2 ≤ m ≤ 100)

int visit[102][102] = {0,};
int board[102][102] = {0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, min = 20000;
    queue<pair<pair<int, int>, int>> q;
    int dir1[] = {1,0,-1,0};
    int dir2[] = {0,1,0,-1};


    cin >> n >> m;
    string in;
    getline(cin, in);
    for(int i = 1; i<=n;i++){
        getline(cin, in);
        for(int j = 1; j<=m;j++){
            board[i][j] = in[j-1]-'0';
        }
    }
    q.push({{1,1},0});
    while(!q.empty()){
        pair<pair<int, int>, int> t = q.front(); q.pop();
        pair<int, int> t2 = t.first;
        if(board[t2.x][t2.y] == 0 || visit[t2.x][t2.y] == 1)    continue;
        int cnt = t.second + 1;
        visit[t2.x][t2.y] = 1;
        if(t2.x == n && t2.y == m && cnt <= min) min = cnt;
        
        for(int k = 0; k<4; k++){
            pair<int, int> t3 = {t2.x+dir1[k],t2.y+dir2[k]};
            if(board[t3.x][t3.y] == 0 || visit[t3.x][t3.y] == 1) continue;
            
            q.push({{t3.x,t3.y}, cnt});
        }
    }
    cout << min;
}
