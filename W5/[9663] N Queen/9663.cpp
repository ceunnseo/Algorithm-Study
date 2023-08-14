// 10초, 128MB, N-Queen
// 2020kb	1752ms
// N*N 체스판위 퀸 N개 서로 공격X 하게 만들기
// 1 <= N <= 15

int visit_row[16]; // 줄
int visit_col[16]; // 칸
int visit_other1[41]; // 대각선
int visit_other2[41]; // 대각선2
int n, cnt;

void func(int cur){
    if(cur == n){
        cnt++;
    }else{
        for(int i = 1; i<=n; i++){
            if (visit_row[i] || visit_col[i] || visit_other1[i+cur] || visit_other2[cur-i+n-1]) continue;
            visit_row[i] =
                visit_col[i] =
                visit_other1[i+cur] = 
                visit_other2[cur-i+n-1] = 1;
            func(cur+1);
            visit_row[i] =
                visit_col[i] =
                visit_other1[i+cur] = 
                visit_other2[cur-i+n-1] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}