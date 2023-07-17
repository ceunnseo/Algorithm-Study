
// N : 배열 A 크기, <= 1,000,000
// m : 배열 b 크기
// 1.5초 256MB

int n, m;
int c[2000001];
vector<int> tmp, uni; // unique
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = n; i < n+m; i++) cin >> c[i];

    sort(c, c+n+m);  // log(N+M)
    for(int i = 0; i < n+m; i++) cout << c[i] << ' ';
}
