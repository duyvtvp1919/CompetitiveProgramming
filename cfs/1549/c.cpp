using namespace std;
#include<bits/stdc++.h>

int m, n;

int main() {

	cin >> n >> m;
	set<int> s[n+1];
	for (int i=1; i<=m; ++i) {
		int u, v;
        cin >> u >> v;
        if (u > v) swap(u,v);
        s[u].insert(v);
	}
	int res = n;
	for (int i=1; i<=n; ++i) 
		if (!s[i].empty()) res--;
	//cout << res << "\n";
	int q;
	cin >> q;
	for (int i=1; i<=q; ++i) {
		int k;
		cin >> k;
		if (k == 1) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			if (s[u].empty()) res--;
            s[u].insert(v);
		}
		if (k == 2) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			s[u].erase(v);
			if (s[u].empty()) res++;
		}
		if (k == 3) {
			cout << res << "\n";
		}
	}

 return 0;	
}