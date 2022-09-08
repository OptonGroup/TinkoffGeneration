// Botat' every day
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <string>
#include <iomanip>
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

struct polindrom_tree{
	string s;
	int n;
	vector<vector<int>> res;
	
	polindrom_tree(){
		s = "";
		n = -1;
		res.resize(2);
	}
	
	void add_letter(char c){
		s += c;
		n++;
		res[0].push_back(-1);
		res[1].push_back(-1);
		
		// Чётная длина
		if (n == 0){
			res[0][n] = 0;
		}else{
			if (c == s[n-res[0][n-1]-1] && res[0][n] < res[0][n-1]+2){
				res[0][n] = res[0][n-1]+2;
			}
			if (c == s[n-1] && res[0][n] < 2){
				res[0][n] = 2;
			}
			res[0][n] = max(res[0][n], 0);
		}

		// НеЧётная длина
		if (n == 0){
			res[1][n] = 1;
		}else{
			if (c == s[n-res[1][n-1]-1] && res[1][n] < res[1][n-1]+2){
				res[1][n] = res[1][n-1]+2;
			}
			if (c == s[n-res[0][n-1]-1] && res[1][n] < res[0][n-1]+1){
				res[1][n] = res[0][n-1]+1;
			}
			if (c == s[n-2] && res[1][n] < 3){
				res[1][n] = 3;
			}
			res[1][n] = max(res[1][n], 1);
		}
	}
	
	ll max_letter(){
		if (s.size() == 0) return 0;
		return max(res[0].back(), res[1].back());
	}
};

void solve(){
	string s;
	cin >> s;
	int len = s.size();
	string max_s = "";
	
	string ns = "";
	int ind = 0;
	while (ind < len-ind-1 && s[ind] == s[len-ind-1]){
		ns += s[ind];
		ind++;
	}

	// del middle left
	string a = "";
	for (int i = ind; i < len-ind; ++i) a += s[i];
	polindrom_tree pt1;
	for (auto u: a)
		pt1.add_letter(u);
	if (max_s.size() < ns.size()*2+pt1.max_letter()){
		max_s = ns;
		for (int i = 1; i <= pt1.max_letter(); ++i){
			max_s += a[a.size()-i];
		}
		reverse(all(ns));
		max_s += ns;
		reverse(all(ns));
	}

	// del middle right
	reverse(all(a));
	polindrom_tree pt2;
	for (auto u: a)
		pt2.add_letter(u);
	if (max_s.size() < ns.size()*2+pt2.max_letter()){
		max_s = ns;
		for (int i = 1; i <= pt2.max_letter(); ++i){
			max_s += a[a.size()-i];
		}
		reverse(all(ns));
		max_s += ns;
		reverse(all(ns));
	}
	
	// del left
	polindrom_tree pt3;
	for (auto u: s)
		pt3.add_letter(u);
	if (max_s.size() < pt3.max_letter()){
		max_s = "";
		for (int i = 1; i <= pt3.max_letter(); ++i){
			max_s += s[s.size()-i];
		}
	}

	// del right
	reverse(all(s));
	polindrom_tree pt4;
	for (auto u: s)
		pt4.add_letter(u);
	if (max_s.size() < pt4.max_letter()){
		max_s = "";
		for (int i = 1; i <= pt4.max_letter(); ++i){
			max_s += s[s.size()-i];
		}
	}
		
	cout << max_s << endl;
}

int main() {
	ll t;
	cin >> t;
	while (t--)
		solve();

    cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
