using namespace std;
#include<bits/stdc++.h>

int n;

int main() {

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n%3 == 0) {
			cout << n/3 << " " << n/3 << "\n";
			continue;
		}
		if (n%3 == 1) {
			cout << n/3+1 << " " << n/3 << "\n";
			continue;
		}
		if (n%3 == 2) {
			cout << n/3 << " " << n/3+1 << "\n";
			continue;
		}
	}

 return 0;	
}