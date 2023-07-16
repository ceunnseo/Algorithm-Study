// N : 수 개수, <= 1,000,000
// |val| <= 1,000,000
// 2초 256MB

int n, m;
int c[1000001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(c, c+n);  // log(N)
    for(int i = 0; i < n; i++) cout << c[i] << '\n';
}
