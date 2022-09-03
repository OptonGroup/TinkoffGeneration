// Botat' every day
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;
ll LINF = 2LL << 32LL;
int INF = 2 << 18;

int main() {
	string s;
	cin >> s;
	map <char, int> cnt;
	map <char, vector<int>> pl;
	for (int i = 0; i < s.size(); ++i){
		cnt[s[i]]++;
		pl[s[i]].push_back(i);
	}
	
	vector<char> v;
	int mx = -1;
	for (auto u: cnt){
		if (mx < u.second){
			mx = u.second;
			v = {u.first};
		}else if(mx == u.second)
			v.push_back(u.first);
	}
	
	vector <pair<int, char>> pr;
	for (auto u: v)
		pr.push_back({pl[u][0], u});
	sort(all(pr));
	
	int max_len = 1;
	for(int i = 0; i < pr.size(); ++i){
		string ns = "";
		ns += pr[i].second;
	
		int nr = 1;
		
		int j;
		bool ok = true;
		for (j = i+1; j < pr.size(); ++j){
			if (!ok) break;
		
			for (int k = 0; k < mx; ++k){
				if (pl[pr[i].second][k]+1 != pl[pr[j].second][k]){
					ok = false;
					break;
				}
				
			}
			if (ok){
				nr++;
				ns += pr[j].second;
				i++;
			}
		}
		
		//cout << ns << endl;
		max_len = max(max_len, nr);
	}
	cout << max_len;

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}