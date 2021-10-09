using namespace std;
#include<bits/stdc++.h>

void solve() {
    long long a, b;
    cin >> b >> a;
    if (a == b) {
        cout << -1 << "\n";
        return;
    }
    long long n = a;
    while (n > b) {
        long long n1 = n;
        vector<long long> v;
        if (n%2 == 0) {
            n--;
            continue;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                v.push_back(i);
                n = n/i;
            }
        }
        if (n > 3) v.push_back(n);
        if (v[0] > b) {
            cout << n1 << "\n";
            return;
        }
        n = n1-1;
    }
    cout << -1 << "\n";

}

int main() {

    int T = 1;

    while (T--) {
        solve();
    }

 return 0;
}
