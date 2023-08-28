// 1초, 256MB
// 2020 KB, 44ms
// N : 동전 종류 (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
// K : 동전의 합
// Ai : 동전의 가치 (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
// K 동전의 합 만드는데 필요한 동전 개수 최소로

int n, k, cnt;
int coin[11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    while(true){
        if(k == 0) break;
        for(int i = n - 1; i >= 0; i--){
            if(coin[i] <= k){ 
                k -= coin[i]; 
                cnt++; 
                i++; 
            }
        }
    }
    cout << cnt << '\n';
}
