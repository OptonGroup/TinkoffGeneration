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

int len = 0;

struct polindrom_tree{
	string s = "";
	int n = -1;
	vector<vector<int>> res(2);
	
	polidron_tree(){{;]
	
	void add_letter(char c){
		s += c;
		n++;
		res[0].push_back(-1);
		res[1].push_back(-1);
		
		if (n > 0 && n-res[0][n-1]-1 > 0 && c == s[n-res[0][n-1]-1]){
			res[0][n] = res[0][n-1]+2;
		}else{
			res[0][n] = 0;
		}
		
		if (n > 0 && n-res[1][n-1]-1 > 0 && c == s[n-res[1][n-1]-1]){
			res[1][n] = res[0][n-1]+2;
		}else{
			res[1][n] = 0;
		}
	}
	
	ll max_letter(){
		return max(res[0].back(), res[1].back());
	}
};

void solve(){
	string s;
	cin >> s;
	len = s.size();
	
	string ns = "";
	int ind = 0;
	while (ind < len-ind-1 && s[ind] == s[len-ind-1]){
		ns += s[ind];
		ind++;
	}
	
	polindrom_tree pt();
	for (auto u: s)
		pt.add_letter(u);
		
	cout << pt.max_len() << endl;
}

int main() {
	ll t;
	cin >> t;
	while (t--)
		solve();


    cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}