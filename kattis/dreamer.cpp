using namespace std;
#include<bits/stdc++.h>

string s;

bool checkyy(int yy)  { 
    return (yy%4!=0 || (yy%100==0 && yy%400!=0));
} 

bool ddvalid(int x) {
    return ((x>=1) && x<=31);
}

bool mmvalid(int x) {
    return ((x>=1) && x<=12);
}

bool yyvalid(int x) {
    return (x >= 2000);
}

bool check(int d, int m, int y) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 2000) return false;
    if (d > 29 && m == 2) return false;
    if (d == 31)
        if (m == 4 || m == 6 || m == 9 || m == 11) 
            return false;
    if (d == 29 && m == 2 && (y%4!=0 || (y%100==0 && y%400!=0))) 
        return false;
    return true;
}

pair<int, pair<int, int>> Min(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.second < b.second.second) return a;
    if (a.second.second == b.second.second) {
        if (a.second.first < b.second.first) return a;
        if (a.second.first == b.second.first) {
            if (a.first < b.first) return a;
        }
    }
    return b;

}

int main() {

    int T;
    cin >> T;
    getline(cin, s);
    while (T--) {
        fflush(stdin);
        getline(cin, s);
        string v;
        for (auto c : s) {
            if (c <= '9' && c >= '0') {
                v += c;
            }
        }
        sort(v.begin(), v.end());
        set<pair<int, pair<int, int>>> se;
        pair<int, pair<int, int>> minn = {10000, {10000, 10000}};
        int ans = 0;
        int dd = (v[0]-'0')*10+(v[1]-'0');
        int mm = (v[2]-'0')*10+(v[3]-'0');
        int yy = (v[4]-'0')*1000+(v[5]-'0')*100+(v[6]-'0')*10+(v[7]-'0');  
        //cout << dd << " " << mm << " " << yy << '\n';
        if (check(dd, mm, yy) == true) {
            ans ++;
            minn = Min(minn, {dd, {mm, yy}});
        }
        while (next_permutation(v.begin(), v.end())) {
            dd = (v[0]-'0')*10+(v[1]-'0');
            mm = (v[2]-'0')*10+(v[3]-'0');
            yy = (v[4]-'0')*1000+(v[5]-'0')*100+(v[6]-'0')*10+(v[7]-'0');      
            if (check(dd, mm, yy) == true) {
                //se.insert({dd, {mm, yy}});
                ans ++;
                minn = Min(minn, {dd, {mm, yy}});
            }
        }
        cout << ans;
        if (ans > 0) {
            cout << " ";
            if (minn.first<10) cout << 0 << minn.first << " "; 
            else cout << minn.first << " ";

            if (minn.second.first < 10) cout << 0 << minn.second.first << " "; 
            else cout << minn.second.first << " ";

            cout << minn.second.second;
        }
        cout << "\n";
    }

 return 0; 
}