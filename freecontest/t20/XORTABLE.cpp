//nnd
using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e3;
int n;
int a[maxN][maxN];

int main() {

	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[1][i];	
	for (int i=2; i<=n; ++i) {
		for (int j=1; j<=n; ++j) a[i][j] = a[1][i] ^ a[1][j];
	}
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) cout << a[i][j] << " ";
		cout << "\n";
	}

 return 0;    
}