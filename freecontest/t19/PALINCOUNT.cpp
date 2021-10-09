using namespace std;
#include<bits/stdc++.h>

int main() {

	int T;
	cin >> T;
	while (T--) {
		long long x, y;
		cin >> x >> y;
		long long ans = 0;
		ans += x*(x-1)*(x-2);
		ans += y*(y-1)*(y-2);
		ans += x*(x-1)*y;
		ans += y*(y-1)*x;
		cout << ans << '\n';
	}

 return 0;	
}