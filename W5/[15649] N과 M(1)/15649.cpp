// 1초, 512MB, N과 M(1)
// 2020kb	28ms
// 자연수 N, M (1<= N,M <= 8)
// 1~N 자연수 중 M개 고른 수열(중복X)

int n, m;
int arr[10]; // 선택 index들
int pick[10]; // 1 고름, 0 안고름

void func(int k){
    // cout << k << ": \n";
    if(k == m){
        for(int i = 1; i<= m; i++) cout << arr[i-1] << (i == m ? '\n' :' ');
        return;
    }
    for(int i = 1; i <= n; i++){
            if(!pick[i]){ // 안 고른거면
                // cout << i << " 선택\n";
                arr[k] = i; // 인덱스 저장
                pick[i] = 1; // 
                func(k+1); // 다음 픽
                pick[i] = 0;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    stack<int> s;
    func(0);
    return 0;
    s.push(0);
    while(!s.empty()){
        int k = s.top(); // 픽 갯수
        cout << k << ": \n";
        if(k == m){
            for(int i = 1; i<= m; i++) cout << arr[i-1] << (i == m ? '\n' :' ');
            s.pop();
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(!pick[i]){ // 안 고른거면
                cout << i << " 선택\n";
                arr[k] = i; // 인덱스 저장
                pick[i] = 1; // 
                s.push(k+1); // 다음 픽
                continue;
                pick[i] = 0;
            }
        }
    }
    
    return 0;
}