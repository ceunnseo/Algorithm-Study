using verylong = long long;

// 2초, 256MB, 부분수열의 합
// 2020kb	4ms
// N개 정수 수열
// 부분수열(0개 이상) 원소 총합 = S인 경우의 수
// N : 정수 개수 (1 <= N <= 20)
// S : 목표값 (|S| <= 1,000,000)
// |정수| <= 100,000
// 부분수열 : 2^n - 1 (공집합 제외)
int arr[21];
int n, cnt;
verylong s;

void back(int cur, verylong sum){
    if(cur == n){
        if(sum == s) cnt++;
        return;
    }
    back(cur+1, sum); // 미선택
    back(cur+1, sum + arr[cur]); // 선택
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> arr[i];
    back(0, 0);
    if(s == 0) cnt--; // 공집합 제외
    cout << cnt;
    return 0;
}