//nnd
using namespace std;
#include<bits/stdc++.h>

long long a, b, c;

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		long long res = 1e7;
		res = min(res, abs(a+b+c));
		res = min(res, abs(a+b-c));
		res = min(res, abs(a+b*c));
		res = min(res, abs(a-b+c));
		res = min(res, abs(a-b-c));
		res = min(res, abs(a-b*c));
		res = min(res, abs(a*b+c));
		res = min(res, abs(a*b-c));
		res = min(res, abs(a*b*c));
		cout << res << "\n";
	}

 return 0;    
}