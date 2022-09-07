#pragma GCC optimize("O3")
// Botat' every day
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;
ll LINF = 2LL << 32LL;
int INF = 2 << 28;

string del_left(string s){
	if (s == "") return "";
	string ns = "", max_s = "";
	max_s += s.back();

	int ind = 0;
	while (ind < s.size()){
		ns = "";
		int pl = 0;
		while (ind+pl < s.size()-pl-1 && s[ind+pl] == s[s.size()-pl-1]){
			ns += s[ind+pl];
			pl++;
		}
		if (ns.size() > 0 && ind+pl >= s.size()-pl-1 && max_s.size() <= ns.size()*2-1){
			max_s = ns;
			if (ind+pl == s.size()-pl-1)
				max_s += s[ind+pl];

			for (int i = ns.size()-1; i >= 0; --i){
				max_s += ns[i];
			}
		}
		ind++;
	}

	return max_s;
}

string del_right(string s){
	if (s == "") return "";
	string ns = "", max_s = "";
	max_s += s[0];

	int ind = s.size()-1;
	while (ind >= 0){
		ns = "";
		int pl = 0;
		while (pl < ind-pl && s[pl] == s[ind-pl]){
			ns += s[pl];
			pl++;
		}
		if (ns.size() > 0 && pl >= ind-pl && max_s.size() <= ns.size()*2-1){
			max_s = ns;
			if (pl == ind-pl)
				max_s += s[pl];

			for (int i = ns.size()-1; i >= 0; --i){
				max_s += ns[i];
			}
		}
		ind--;
	}

	return max_s;
}

void solve(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	string max_s = "";
	max_s += s[0];
	string ns = "";
	
	// Delete middle
	int ind = 0;
	while (ind < s.size()-ind-1 && s[ind] == s[s.size()-ind-1]){
		ns+=s[ind];
		ind++;
	}
	
	string a = "";
	for (int i = ind; i <= s.size()-ind-1; ++i) a += s[i];

	string pns1 = del_left(a), pns2 = del_right(a), pns;
	if (pns1.size() >= pns2.size()) pns = pns1;
	else pns = pns2;

	if (max_s.size() <= ns.size()*2+pns.size()-1){
		max_s = ns;
		if (ind == s.size()-ind-1)
			max_s.pop_back();
		max_s += pns;
		for (int i = ns.size()-1; i >= 0; --i){
			max_s += ns[i];
		}
	}
	
	pns = del_left(s);
	if (max_s.size() <= pns.size()){
		max_s = pns;
	}

	pns = del_right(s);
	if (max_s.size() <= pns.size()){
		max_s = pns;
	}
	
	cout << max_s << endl;
}

int main() {
	ll n;
	cin >> n;
	while (n--)
		solve();
	
	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
