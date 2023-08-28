// 2초, 192MB
// 2412KB, 8ms
// N : 로프 개수 (1 ≤ N ≤ 100,000)
// k개 로프로 중량 w(,=10,000) 들어올릴때 각 로프 w/k 중량 걸림
// k개 로프로 최대 중량 몇까지 가능한가

int n;
int weight[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    // first 기준 정렬위해 끝시간을 first로
    for (int i = 1; i <= n; i++){
        int in;
        cin >> in;
        weight[i] = -in;
    }
    sort(weight+1, weight+n+1); // 무게순 내림차순
    int total = 0;

    for(int i = 1; i<=n; i++){
        total = max(total, -weight[i]*i);
    }
    cout << total;
}
