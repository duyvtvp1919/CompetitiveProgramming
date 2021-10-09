//nnd
using namespace std;
#include<bits/stdc++.h>


int n, k;
int a[1000];
string u[1000], p[1000];

int main() {

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> u[i];
		cin >> p[i];
	}
	cin >> k;
	for (int i=1; i<=k; ++i) {
		string u1, p1;
		cin >> u1 >> p1;
		for (int j=1; j<=n; ++j) {
			if (u1 == u[j] && p1 == p[j]) a[j]++;
		}
	}
	for (int i=1; i<=n; ++i) cout << a[i] << " ";

 return 0;    
}