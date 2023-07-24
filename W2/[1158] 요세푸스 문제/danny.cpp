
// 0.15초, 128mb
// N : 원을 이루는 사람수 <= 100,000
// K : 양의정수 <= N
// 순서대로 k번째 사람 제거

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, cnt = 0;
    cin >> n >> k;
    vector <int> _v, _ans;
    for(int i = 1; i<=n; i++)
        _v.push_back(i);
    
    for( int  i = 0; _ans.size() < n; i++){ // 정답 차면 종료
        if(i % k == k - 1){
            _ans.push_back(_v[i]); // k번째 사람
            continue;
        }
        _v.push_back(_v[i]);
    }
    cout << '<' << _ans[0];
    for(int i = 1; i<n; i++){
        cout << ", " << _ans[i];
    }
    cout << '>';
}
