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

int main() {
	int t, n, m;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        vi a(n), c(m);
        f(i, 0, n, 1) cin >> a[i];
        f(i, 0, m, 1) cin >> c[i];
        sort(rall(c));
        vi b(n + 1);
        f(i, 0, n, 1) ++b[a[i]];
        priority_queue<int> pq;
        f(i, 1, n + 1, 1) if (b[i]) pq.push(b[i]);
        int ctr = 0;
        f(i, 0, m, 1) { 
            int u = pq.top(); pq.pop();
            int r = max(0, u - c[i]);
            ctr += u - r;
            if (r) pq.push(r);
            if (pq.empty()) break;
        }
        cout << ctr << nl;
	}
	return 0;
}
