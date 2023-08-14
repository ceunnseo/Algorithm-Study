// 1초, 256MB, 하노이 탑 이동 순서
// 2020kb	124ms
// 장대 3개, 탑 n개
// 1번 장대에 n개 -> 3번 장대로
// 1 <= n <= 20
// 출력 횟수, 수행 과정 A -> B 장대로 옮김(맨위 원판)

void func(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> k;
    cout << (1<<k) - 1 << '\n';
    func(1, 3, k);
    return 0;
}