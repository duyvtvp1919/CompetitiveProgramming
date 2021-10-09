#include <bits/stdc++.h>
using namespace std;

long long T,x,y;

int main() {
    cin>>T;
    while(T--) {
        cin >> x >> y;
        long long m = x + y;
        long long i;
        if (m < 3)
        {
            cout << 0 << endl;
        }
        else
        {
            if (x == 0 && y != 0)
            {
                i = y * (y - 1) * (y - 2);
                cout << i << endl;
            }
            if (x != 0 && y == 0)
            {
                i = x * (x - 1) * (x - 2);
                cout << i << endl;
            }
            if (x != 0 && y != 0)
            {
                i = x * y * (x - 1) + y * x * (y - 1);
                cout << i << endl;
            }
        }
    }
}