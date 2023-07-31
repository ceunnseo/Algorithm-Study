// N : 수 개수, <= 1,000
// |val| <= 1,000
// 1초 128MB

int n, m;
int c[1001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(c, c+n);  // log(N)
    for(int i = 0; i < n; i++) cout << c[i] << '\n';
}
