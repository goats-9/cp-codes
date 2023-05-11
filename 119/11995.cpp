#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7
#define EPS 1e-7

int main() {
    int n;
    while (cin >> n) {
        V<pii> a(n);
        f(i,0,n,1) cin >> a[i].first >> a[i].second;
        stack<int> stk; queue<int> q; priority_queue<int> pq;
        int mask = 7;
        f(i,0,n,1) {
            if (a[i].first == 1) {
                stk.push(a[i].second);
                q.push(a[i].second);
                pq.push(a[i].second);
            } else {
                int chk;
                if (stk.empty()) mask &= ~1;
                else {
                    chk = stk.top(); stk.pop();
                    if (chk != a[i].second) mask &= ~1;
                }
                if (q.empty()) mask &= ~2;
                else {
                    chk = q.front(); q.pop();
                    if (chk != a[i].second) mask &= ~2;
                }
                if (pq.empty()) mask &= ~4;
                else {
                    chk = pq.top(); pq.pop();
                    if (chk != a[i].second) mask &= ~4;
                }
            }
        }
        if (mask == 1) cout << "stack\n";
        else if (mask == 2) cout << "queue\n";
        else if (mask == 4) cout << "priority queue\n";
        else if (mask == 0) cout << "impossible\n";
        else cout << "not sure\n";
    }
    return 0;
}
