// 1초, 128MB, 촌수계산
// 부모-나 1촌, 조부모-나 2촌, 아버지형제-나 3촌
// n : 사람들 (1<=n<=100)
// m : 부모자식 관계
// x y : 자식, 부모

int n, me, other, m, x, y;
int cnt = 0;
int board[102][102];
int visit[102];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> me >> other;
    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> x >> y;
        board[x][y] = board[y][x] = 1;
    }

    q.push(me);
    while (!q.empty()){
        int t = q.front(); q.pop();
        
        for (int i = 1; i <= n; i++){ // 나랑 관련된 사람들 다 업데이트
            if (board[t][i] != 0 && !visit[i]){
                q.push(i); // 촌수 계산 안한사람들 다 다음 업데이트 후보로 넣음
                visit[i] = visit[t] + 1;
            }
        }
    }

    cout << (visit[other] == 0 ? -1 : visit[other]);
}
