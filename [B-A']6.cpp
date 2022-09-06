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

string get_max_str(string s){
	string ns = "", max_s = "";
	
	int ind = 0;
	// Delete Start
	while (ind < s.size()){
		if (s[ind] == s.back()){
			int pl = 0;
			ns = "";
			while (s[ind+pl] == s[s.size()-ind-pl] && ind+pl < s.size()-pl){
				ns += s[ind+pl];
				pl++;
			}
			
			if (ind+pl == s.size()-pl-1){
				if (max_s.size()<ns.size()*2-1){
					max_s = ns;
					max_s += s[ind+pl];
					reverse(all(ns));
					max_s += ns;
				}
			}else if (ind+pl > s.size()-pl-1){
				if (max_s.size()< ns.size()*2){
					max_s = ns;
					reverse(all(ns));
					max_s += ns;
				}
			}
		}
	
		ind++;
	}
	
	
	reverse(all(s));
	ind = 0;
	// Delete End
	while (ind < s.size()){
		if (s[ind] == s.back()){
			int pl = 0;
			ns = "";
			while (s[ind+pl] == s[s.size()-ind-pl] && ind+pl < s.size()-pl){
				ns += s[ind+pl];
				pl++;
			}
			
			if (ind+pl == s.size()-pl-1){
				if (max_s.size()<ns.size()*2-1){
					max_s = ns;
					max_s += s[ind+pl];
					reverse(all(ns));
					max_s += ns;
				}
			}else if (ind+pl > s.size()-pl-1){
				if (max_s.size()< ns.size()*2){
					max_s = ns;
					reverse(all(ns));
					max_s += ns;
				}
			}
		}
	
		ind++;
	}
	
	return max_s;
}

void solve(){
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
	
	string pns = "";
	pns = get_max_str(s.substr(ind, s.size()-ind-ind));
	if (max_s.size() <= ns.size()*2+pns.size()){
		max_s=ns;
		if (ind==s.size()-ind){
			max_s += s[ind];
		}
		max_s+=pns;
		reverse(all(ns));
		max_s += ns;
	}
	
	pns = get_max_str(s);
	if (max_s.size() <= pns.size()){
		max_s=pns;
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
