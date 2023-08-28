using namespace std;

// 2초, 128MB
// 2800KB, 24ms
// N : 회의 개수 (1 ≤ N ≤ 100,000)
// I : 각 회의 시작시간-끝시간 (0 <= I <= 2^31-1)
// 회의 겹치지 않게 회의실 사용할 수 있는 회의의 최대 개수
// 1시 끝나는 회의 바로 1시에 다른 회의 시작 가능

int n;
pair<int, int> meets[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> meets[i].second >> meets[i].first;
    sort(meets, meets+n);
    int t = 0, cnt = 0; // t 시작시간
    for(int i = 0; i<n; i++){
        if(t > meets[i].second) continue;
        t = meets[i].first;
        cnt++;
    }
    cout << cnt;
}
