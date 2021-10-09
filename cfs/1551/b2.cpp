using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e5+19;

void solve() {
	int n, k; 
	cin >> n >> k;

	int a[n+1];	
	vector<int> v[n+1];

	for (int i = 0; i < n; i++) {
	  	cin >> a[i];
	  	v[a[i]].push_back(i);
	}

	vector<int> res(n, -1);
	for (auto c : res) c = -1;
	// for (auto c : res) cout << c << " " ;
	// cout << "\n";

	vector<int> e;
	for (int i=1; i<=n; ++i) {
		if (v[i].size() < k) {
			for (int x : v[i]) {
	      		e.push_back(x);
	      		if (e.size() >= k) {
		        	int id = 0;
		        	for (int j : e) {
		          		res[j] = id++;
		        	}
		        	e.clear();
	      		}
	    	}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].size() >= k) {
	    	for (int j = 0; j < k; j++) {
	      		res[v[i][j]] = j;
	    	}
	  	}
	}
	for (int c : res) cout << c + 1 << ' ';
	cout << "\n";
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

 return 0;	
}