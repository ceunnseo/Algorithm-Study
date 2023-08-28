// 2초, 128MB 보물
// 2020KB, 0ms
// N : N길이 배열 (1 <= N <= 50)
// Ai, Bi (1 <= Ai, Bi <= 100)
// S = A[0] * B[0] + ... + A[N-1] * B[N-1]
// a배열 재배열하여, 최소값 min(s) 출력

int n;
int arr[2][51];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[0][i];
    for (int i = 1; i <= n; i++){
        int in;
        cin >> in;
        arr[1][i] = -in;
    }
    
    sort(&arr[0][1], &arr[0][1] + n); // a배열 오름차순
    sort(&arr[1][1], &arr[1][1] + n); // b배열 내림차순
    int total = 0;

    for(int i = 1; i<=n; i++){
        total += arr[0][i] * -arr[1][i];
    }
    cout << total;
}
