// N : 자연수 1 <= N <= 100,000, -2^31 <= A[n] < 2^31
// M : 찾을 자연수 1 <= M <= 100,000, -2^31 <= A[m] < 2^31

int n, m, in;
int a[100001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n); // logN
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> in;
        cout << (binary_search(a, a + n, in) ? 1 : 0) << '\n'; // m*logN
    }
}
