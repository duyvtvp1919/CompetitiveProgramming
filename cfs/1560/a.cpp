using namespace std;
#include<bits/stdc++.h>

void solve() {
    int k;
    cin >> k;
    int i = 1;
    int cnt = 1;
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }
    while (cnt < k) {
        i++;
        if (i%3 != 0 && i%10 != 3) cnt++;
    }
    cout << i << "\n";
}

int main() {

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

 return 0; 
}