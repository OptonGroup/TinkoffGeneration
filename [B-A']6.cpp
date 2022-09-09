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

struct polindrom_tree {
	const int maxn = 10, k = 26;

	vector<int> s, len, link;
	vector<vector<int>> to;

	int n, last, sz;

	polindrom_tree() {
		n = 0;
		last = 1;
		s[n++] = -1;
		link[0] = 1;
		len[1] = -1;
		sz = 2;
	}

	int get_link(int v) {
		while (s[n - len[v] - 2] != s[n - 1])
			v = link[v];
		return v;
	}

	void add_letter(int c) {
		c -= 'a';
		s[n++] = c;
		last = get_link(last);
		if (!to[last][c]) {
			len[sz] = len[last] + 2;
			link[sz] = to[get_link(link[last])][c];
			to[last][c] = sz++;
		}
		last = to[last][c];
	}

	int max_letter() {
		return len[last];
	}
};

void solve() {
	string s;
	cin >> s;
	int len = s.size();
	string max_s = "";

	string ns = "";
	int ind = 0;
	while (ind < len - ind - 1 && s[ind] == s[len - ind - 1]) {
		ns += s[ind];
		ind++;
	}

	// del middle left
	string a = "";
	for (int i = ind; i < len - ind; ++i) a += s[i];
	polindrom_tree pt1;
	for (auto u : a)
		pt1.add_letter(u);
	if (max_s.size() < ns.size() * 2 + pt1.max_letter()) {
		max_s = ns;
		for (int i = 1; i <= pt1.max_letter(); ++i) {
			max_s += a[a.size() - i];
		}
		reverse(all(ns));
		max_s += ns;
		reverse(all(ns));
	}

	// del middle right
	reverse(all(a));
	polindrom_tree pt2;
	for (auto u : a)
		pt2.add_letter(u);
	if (max_s.size() < ns.size() * 2 + pt2.max_letter()) {
		max_s = ns;
		for (int i = 1; i <= pt2.max_letter(); ++i) {
			max_s += a[a.size() - i];
		}
		reverse(all(ns));
		max_s += ns;
		reverse(all(ns));
	}

	// del left
	polindrom_tree pt3;
	for (auto u : s)
		pt3.add_letter(u);
	if (max_s.size() < pt3.max_letter()) {
		max_s = "";
		for (int i = 1; i <= pt3.max_letter(); ++i) {
			max_s += s[s.size() - i];
		}
	}

	// del right
	reverse(all(s));
	polindrom_tree pt4;
	for (auto u : s)
		pt4.add_letter(u);
	if (max_s.size() < pt4.max_letter()) {
		max_s = "";
		for (int i = 1; i <= pt4.max_letter(); ++i) {
			max_s += s[s.size() - i];
		}
	}

	cout << max_s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		solve();

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
