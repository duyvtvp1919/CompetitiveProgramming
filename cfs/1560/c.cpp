using namespace std;
#include<bits/stdc++.h>

void solve() {
    long long k;
    cin >> k;
    long long temp = (long long) sqrt(k);
    if (temp*temp == k) {
        cout << temp << " " << 1 << "\n";
        return;
    }
    temp += 1;
    if (k == temp*temp-temp+1) {
        cout << temp << " " << temp << "\n";
        return;
    }
    long long diff = temp*temp-k;
    if (diff <= temp-1) {
        cout << temp << " " << diff+1 << "\n";
        return;
    }
    else {
        cout << temp-(diff-temp)-1 << " " << temp << "\n";
    }
}

int main() {

    int T;
    cin >> T;
    while (T--){
        solve();
    }

 return 0; 
}