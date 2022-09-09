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
	int k, last;
	vector <int> len, link;
	vector <vector<int>> g;
	
	polindrom_tree(){
		s = "#";
		k = 0;
		last = 1;
		g.resize(2, vector<int>(35));
		len.push_back(0);
		len.push_back(0);
		
		link.push_back(0);
		link.push_back(0);
	}
	
	int find_link(int v){
		while (v > 0 && s[k-len[v]-1] != s[k]){
			v = link[v];
		}
		return v;
	}
	
	void add_letter(char c){
		k++;
		s += c;
		int q = find_link(last);
		if (g[q][c - 'a'] == 0){
			g.push_back(vector<int>(35, 0));
            int p = g.size()-1;
            len[p] = len[q]+2;
            g[q][c - 'a'] = 1;
            link.push_back(find_link(link[q]));
            last = p;
		}
	}

    int max_letter(){
        return len[last];
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
