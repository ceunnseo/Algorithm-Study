#define X first
#define Y second

// 1 초	256 MB, 최단경로
// 9188KB	112ms
// 모든 간선 가중치 10 이하 자연수
// 정점 개수 V (1<= V <= 20,000)
// 간선 개수 E (1<= E <= 300,000)
// w(가중치) : u(정점)->v(정점) 가중치

int v,e,st;
const int INF = 1e9+10;
int d[20005]; // 최단 거리 테이블
vector<pair<int,int>> adj[20005]; // 비용, 정점 번호

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e >> st;
    fill(d, d+v+1, INF);
    while(e--){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    d[st] = 0;
    // 우선순위 큐에 (0, 시작점) 추가
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    for(int i = 1; i <= v; i++){
        cout << (d[i] == INF? "INF" : to_string(d[i])) << '\n';
    }
}
