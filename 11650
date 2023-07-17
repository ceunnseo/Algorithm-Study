// 언어 C++, 메모리 3688KB 시간 48ms

#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;


int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	

	for (int i = 0; i < n; i++) {
		cout << v[i].first <<" "<<  v[i].second << '\n';
	}
	return 0;
}
