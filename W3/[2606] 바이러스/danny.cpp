// 1초, 128MB, 바이러스
// 바이러스 걸리는 컴퓨터 수 출력
// n 컴퓨터 수 : <= 100
// m 네트워크 번호쌍

int board[101][101];
int visit[101];

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
    // stack<pair<int, int>> s;
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int t = s.top(); s.pop();
        if(visit[t] == 1) continue;
        visit[t] = 1; cnt++;
        for(int i = 1; i<=n; i++){
            if(board[t][i] == 0 || visit[i] == 1) continue;
            s.push(i);
        }
    }
    cout << cnt - 1;
    return 0;
}
