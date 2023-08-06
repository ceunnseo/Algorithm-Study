
// 0.15초, 128MB 1로 만들기
// 1. X 3으로 나눠지면 나눔
// 2. X 2로 나눠지면 나눔
// 3. -1
// 정수 N (<= 10^6)
// 정수 N 연산 3가지 이용 -> 1 만들기, 사용 연산 횟수 최소값 출력

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    // dp[1] = 0, dp[t] = min(dp[t/3]+1, dp[t/2]+1, dp[t-1]+1)
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1; // -1
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1); // % 2
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1); // % 3
    }
    cout << dp[n];
    return 0;
}
