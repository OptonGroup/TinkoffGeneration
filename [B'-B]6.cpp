// Botat' every day
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
ll LINF = 2LL << 32LL;
int INF = 2 << 18;

ll n, m;
ll res = 1;
vector<vector<int>> g(110000);
vector <int> used;

void dfs(int v, pair<int, int> cnt){
	res *= max(0LL, m - cnt.first - cnt.second);
	res %= 1000000007;
	
	used[v] = 1;
	cnt.second = cnt.first;
	cnt.first = 1;
	for (auto &u: g[v]){
		if (!used[u]){
			dfs(u, cnt);
			cnt.second++;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n-1; ++i){
		int f, t;
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}

	used = vector<int> (n+1, 0);
	
	dfs(1, {0, 0});
	cout << res;	

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
