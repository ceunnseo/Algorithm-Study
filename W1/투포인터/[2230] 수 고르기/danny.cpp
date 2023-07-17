// N : 수열 개수 1 ≤ N ≤ 100,000
// M : 두 수 차이 0 ≤ M ≤ 2,000,000,000
// 0 ≤ |A[i]| ≤ 1,000,000,000
// 차이 M 이상, 제일 작은 경우
// 128MB, 2초
int arr[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    int mn = 2000000001;
    cin >> n >> m;
    for(int i = 0; i<n; i++)    cin >> arr[i];
    sort(arr, arr+n); // logN
    
    int en = 0;
    for(int st = 0; st<n; st++){ // N
        while(en < n && arr[en] - arr[st] < m) en++;
        if(en == n) break; // 종료
        mn = min(mn, arr[en] - arr[st]);
    }
    cout << mn;
    return 0;
}
