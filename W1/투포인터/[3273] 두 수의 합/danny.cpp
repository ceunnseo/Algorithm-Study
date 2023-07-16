// N : 수열 길이 1 ≤ n ≤ 100000
// X : ai + aj = x (1 <= i < j <= n)
// ai != ai+1, 1 <= ai <= 1000000
// 128MB, 1초

int a[100005];
int chk[2000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (x - a[i] > 0 && chk[x - a[i]] == 1)
            cnt++;
        chk[a[i]] = 1;
    }
    cout << cnt;
}
