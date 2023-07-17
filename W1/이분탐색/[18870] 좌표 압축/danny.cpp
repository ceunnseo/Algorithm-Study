
// N : 수직선 위 좌표 개수 1<= N <= 1,000,000
// -10^9 <= X1,...Xn <= 10^9

int n;
int x[1000005];
vector<int> tmp, uni; // unique
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        tmp.push_back(x[i]);
    }

    sort(tmp.begin(), tmp.end());  // logN
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || tmp[i - 1] != tmp[i])
            uni.push_back(tmp[i]); // 번호 부여 N
    }
    for (int i = 0; i < n; i++) // 인덱스 출력(압축번호) logN
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    return 0;
}
