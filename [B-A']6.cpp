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

void solve(){
	string s;
	cin >> s;
	string max_s = "";
	max_s += s[0];
	string ns = "";
	cout << "#1 Best Result: " << max_s << endl;
	// Delete middle
	int ind = 0;
	while (ind < s.size()-ind-1 && s[ind] == s[s.size()-ind-1]){
		ns+=s[ind];
		ind++;
	}
	cout << ns << endl;
	// Delete start
	int temp = ind;
	string pns = "";
	while (ind < s.size()-temp){
		if (s[ind] == s[s.size()-temp-1]){
			int pl = 1;
			pns = "";
			pns += s[ind];
			while (s.size()-temp-pl-1 >= ind+pl && s[s.size()-temp-pl-1] == s[ind+pl]){
				pns+=s[ind+pl];
				pl++;
			}
			if (max_s.size() <= ns.size()*2+pns.size()){
				max_s = ns;
				max_s += pns;
				if (pl % 2 == 1) pns.pop_back();
				reverse(all(pns));
				max_s += pns;
				reverse(all(ns));
				max_s+= ns;
			}
		}
		ind++;
	}
	
	cout << "#2 Best Result: " << max_s << endl;
	
	// Delete End
	ind = s.size()-temp-1;
	while (ind >= temp){
		if (s[temp] == s[ind]){
			int pl = 1;
			pns = "";
			pns += s[0];
			while (temp+pl <= ind-pl && s[temp+pl] == s[ind-pl]){
				pns+=s[temp+pl];
				pl++;
			}
			if (max_s.size() <= ns.size()*2+pns.size()){
				max_s = ns;
				max_s += pns;
				if (pl % 2 == 1) pns.pop_back();
				reverse(all(pns));
				max_s += pns;
				reverse(all(ns));
				max_s+= ns;
			}
		}
		ind--;
	}
	cout << "#3 Best Result: " << max_s << endl;

	
	// Delete End
	ind = s.size();
	while (ind--){
		if (s[0] == s[ind]){
			int pl = 1;
			ns = "";
			ns += s[0];
			while (pl < ind-pl && s[pl] == s[ind-pl]){
				ns+=s[pl];
				pl++;
			}
			if (max_s.size() <= ns.size()*2){
				max_s = ns;
				if (pl == ind-pl)
					max_s += s[pl];
				reverse(all(ns));
				max_s+= ns;
			}
		}
	}
	cout << "#3 Best Result: " << max_s << endl;
	
	// Delete start
	ind = 0;
	while (ind < s.size()){
		if (s[ind] == s[s.size()-1]){
			int pl = 1;
			ns = "";
			ns += s[ind];
			while (s.size()-pl-1 > ind+pl && s[s.size()-pl-1] == s[ind+pl]){
				ns+=s[ind+pl];
				pl++;
			}
			if (max_s.size() <= ns.size()*2){
				max_s = ns;
				if (s.size()-pl-1 == ind+pl)
					max_s += s[ind+pl];
				reverse(all(ns));
				max_s+= ns;
			}
		}
		ind++;
	}
	
	cout << "#4 Best Result: " << max_s << endl;
}

int main() {
	ll n;
	cin >> n;
	while (n--)
		solve();
	
	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
