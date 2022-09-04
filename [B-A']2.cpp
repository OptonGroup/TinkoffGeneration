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
int INF = 2 << 28;

ll n;
vector <vector<pair<ll, ll>>> g(500);
vector <pair<ll, ll>> cnt(500, {INF, 0});
vector <ll> oosp(500, 1), pred(500, -1), csp(500, 1);

int main() {
	cin >> n;
	for (ll i = 0; i < n; ++i){
		for (ll j = 0; j < n; ++j){
			ll v;
			cin >> v;
			if (v != -1 && i != j) g[i].push_back({j, v});
		}
	}
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 0});
	cnt[0] = {0, 1};
	oosp[0] = 1;
	while (pq.size()){
		ll v = pq.top().second,
			 dist = pq.top().first;
		for (auto u: g[v]){
			if (cnt[u.first].first > dist + u.second){
				cnt[u.first].first = dist + u.second;
				cnt[u.first].second = 1;
				oosp[u.first] = 1;
				pred[u.first] = v;
				pq.push({cnt[u.first].first, u.first});
			}else if(cnt[u.first].first == dist + u.second){
				cnt[u.first].second++;
				oosp[u.first] = 0;
			}
		}
		pq.pop();
	}
	
	for (int i = 0; i < n; ++i)
	 	cout << i+1 << " " << cnt[i].first << " " << cnt[i].second << endl;
	
	csp[0] = 0;
	for (ll i = 0; i < n; ++i){
		if (oosp[i]){
			ll v = i;
			while (v != 0 && pred[v] != -1){
				csp[pred[v]]++;
				v = pred[v];
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
		cout << i+1 << " " << csp[i] << endl;
	
	ll mx = 0;
	for (auto u: g[0])
		mx = max(mx, csp[u.first]);
	
	cout << mx;

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}