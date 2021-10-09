//nnd
using namespace std;
#include<bits/stdc++.h>


int n, k;
vector<int> a, b;

int main() {
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
    	int x;
    	cin >> x;
    	a.push_back(x);
    }
    for (int i=1; i<=n; ++i) {
    	int x;
    	cin >> x;
    	b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
 
    set<pair<int, int> > my_set;
 
    pq.push(make_pair(a[0] + b[0], make_pair(0, 0)));
 
    my_set.insert(make_pair(0, 0));
    int flag=1;
    for (int count = 0; count < k && flag; count++) {
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();
        int i = temp.second.first;
        int j = temp.second.second;
        cout << a[i]+b[j] << " ";
        flag=0;
        if (i + 1 < a.size()) {
            int sum = a[i + 1] + b[j];
            pair<int, int> temp1 = make_pair(i + 1, j);
            if (my_set.find(temp1) == my_set.end()) {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
          flag = 1;
        }
        if (j + 1 < b.size()) {
            int sum = a[i] + b[j + 1];
            pair<int, int> temp1 = make_pair(i, j + 1);
            if (my_set.find(temp1) == my_set.end()) {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
          flag = 1;
        }
    }
    return 0;
}	