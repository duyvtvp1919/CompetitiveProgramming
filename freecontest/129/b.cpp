using namespace std;
#include<bits/stdc++.h>

const int maxN = 2e5+19;

int n;
long long a[maxN];

void sub1() {
	int cnt = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=i+1; j<=n; ++j) if ((j-i+1)%2 == 0) {
			int mid = (i+j-1)/2;
			long long temp1 = a[i];
			for (int ii = i+1; ii<=mid; ++ii) temp1 ^= a[ii];
			long long temp2 = a[mid+1];
			for (int jj = mid+2; jj<=j; ++jj) temp2 ^= a[jj];
			if (temp1 == temp2) cnt++;
		}
	}
	cout << cnt << "\n";
}

int main() {

	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	sub1();

 return 0;	
}