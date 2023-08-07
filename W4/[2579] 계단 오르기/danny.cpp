
// 1초, 128MB 계단 오르기
// 1. 계단은 1~2개씩 오를수 있음
// 2. 연속 3개 계단 모두 밟기 X
// 3. 마지막 계단 반드시 밟기
// 계단 누계의 최대값 구하기
// 300 >= n, stair_val >= 10,000

int steps[302];
long dp[302][3]; // 앞계단 두개 연속인지만 고려 [1] 아님 [2] 두개연속

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> steps[i];
    }
    dp[1][1] = dp[0][1] + steps[1];                 // 0 -> 1
    // dp[2][1] = max(dp[0][1],dp[0][2]) + steps[2];   // 0 -> 2
    // dp[2][2] = dp[1][1] + steps[2];                 // 0 -> 1 -> 2

    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = max(dp[i - 2][1],dp[i - 2][2]) + steps[i]; // 바로 i로 올라옴
        dp[i][2] = dp[i - 1][1] + steps[i];                   // 연속 i-1,i로 올라옴
    }

    cout << max(dp[n][1], dp[n][2]);

    return 0;
}
