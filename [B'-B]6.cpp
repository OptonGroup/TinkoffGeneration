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
vector <int> used, cnt(110000), por, use;
int ver;

void dfs(int v, int dist){
	used[v] = ver+10;
	if (dist > 2 && !use[v]) cnt[v]++;
	for (auto &u: g[v]){
		if (used[u] != ver+10) dfs(u, dist+1);
	}
	return;
}

// 485525898

void dfs_get_v(int v){
	used[v] = 1;
	por.push_back(v);
	for (auto &u: g[v]){
		if (!used[u])
			dfs_get_v(u);
	}
	return;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
// #endif // !ONLINE_JUDGE
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n-1; ++i){
		int f, t;
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}

	used = vector<int> (n+1, 0);
	for (int i = 1; i <= n; ++i){
		if (g[i].size() == 1){
			dfs_get_v(i);
			break;
		}
	}

	use = vector<int> (n+1, 0);
	ll res = 1;
	if (n == 1) res = m;
	for (int i = 0; i < por.size(); ++i){
		ver = por[i];
		use[ver] = 1;
		dfs(ver, 0);
		res *= max(0LL, m-i+cnt[ver]);
		res %= 1000000007;
	}
	cout << res;

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}