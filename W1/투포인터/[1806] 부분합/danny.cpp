// N : 10,000 이하 자연수 길이 N짜리 수열 10 ≤ N < 100,000
// S : 부분합 이상  (0 < S ≤ 100,000,000)
// 부분합 중 S 이상, 가장 짧은 것 길이
// 128MB, 0.5초

int a[1000005];
int mn = 0x7fffffff;
int tot;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,s;
    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> a[i];
    tot = a[0];
    int en = 0;
    for(int st = 0; st < n; st++){
        while(en < n && tot < s){ // 누계가 부분합 크기 제한보다 작으면 en으로 계속 순회
            en++;
            if(en != n) tot += a[en]; // 누계
        }
        if(en == n) break; // en이 범위를 벗어날시 종료
        mn = min(mn, en - st + 1); // 가장 짧은 구간
        tot -= a[st];
    }
    if(mn == 0x7fffffff) mn = 0; // 발견하지 못하면 0
    cout << mn;
}
