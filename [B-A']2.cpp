// Botat' every day
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <string>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;
ll LINF = 2LL << 32LL;
int INF = 2 << 18;


vector <pair<int, int>> g[1000];
vector<int> ans1(1000), ans2(1000), cnt, pr;
ll n;

struct structure{
	int from, to, dist;
	structure(){}
	structure(int from, int to, int dist) : 
		from(from), to(to), dist(dist) {}

	bool operator>(const structure& arg) const {
		return dist > arg.dist;
	}
};

vector<int> dijkstra(vector<int> ans){
	for (int i = 0; i < 1000; ++i){
		ans[i] = INF;
	}

	ans[1] = 0;

	priority_queue<structure, vector<structure>, greater<structure>> q;

    q.push({0, 1, 0});

    while (!q.empty()) {
        structure c = q.top();
        q.pop();

        int dst = c.dist, v = c.to, f = c.from;
		// if (f > 1)
			cnt[f]++;

        if (ans[v] < dst) {
            continue;
        }

        for (pair<int, int> e: g[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < ans[u]) {
                ans[u] = n_dst;
                q.push({v, u, n_dst});
				pr[u] = v;
            }
        }
    }

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	cnt.resize(n+1, 0); pr.resize(n+1, 0);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			int v;
			cin >> v;
			if (v > 0) g[i].push_back({j, v});
		}
	}

	ans1 = dijkstra(ans1);
	for (int i = 0; i <= n; ++i) cout << i << ": " << ans1[i] << " - " << cnt[i] << " - " << pr[i] << endl;

	cout << max_element(all(cnt)) - cnt.begin();

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
