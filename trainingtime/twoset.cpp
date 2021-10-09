//nnd
using namespace std;
#include <bits/stdc++.h>
 
long long n;
 
int main() {
 
    cin >> n;
    long long total = n*(n+1)/2;;
    if (total%2 == 1) return cout << "NO", 0;
    vector<int> v1, v2;
    total /= 2;
    while (n) {
    	if (total-n < 0) v1.push_back(n);
    	else v2.push_back(n), total -= n;
    	n--;
    }
    cout << "YES\n";
    cout << v1.size() << "\n";
    for (auto c : v1) cout << c << " ";
    cout << "\n";
	cout << v2.size() << "\n";
	for (auto c : v2) cout << c << " ";
 
 
 return 0;
}