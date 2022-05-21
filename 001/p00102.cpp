#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;

int main() {
    vi a(9);
    while(cin >> a[0]) {
        int m = a[0];
        for(int i = 1; i < 9; i++) {
            cin >> a[i];
            m += a[i];
        }
        vii x(6);
        vector<string> p = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
        x[0] = {m - a[0] - a[5] - a[7], 0};
        x[1] = {m - a[0] - a[4] - a[8], 1};
        x[2] = {m - a[2] - a[3] - a[7], 2};
        x[3] = {m - a[2] - a[4] - a[6], 3};
        x[4] = {m - a[1] - a[3] - a[8], 4};
        x[5] = {m - a[1] - a[5] - a[6], 5};
        sort(x.begin(), x.end());
        cout << p[x[0].second] << " " << x[0].first << "\n";
    } 
    return 0;
}