using namespace std;
#include<bits/stdc++.h>

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long half = abs(a - b);
    if ((c > (2 * half)) || (a > (2 * half)) || (b > (2 * half)))
        cout << -1 << "\n";
    else if (c > half)
        cout << c - half << "\n";
    else if (c <= half)
        cout << c + half << "\n";
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

 return 0; 
}