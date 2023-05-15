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
	int t, n, m, x;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        set<int> p;
        int r[n+1];
        f(i,1,n+1,1) r[i] = -1;
        int cpos = n;
        f(i,0,m,1) {
            cin >> x;
            if (p.find(x) == p.end()) {
                p.insert(x);
                r[cpos] = i+1;
                cpos = cpos -1;
            }
        }
        f(i,1,n+1,1) cout << r[i] << " ";
        cout << nl;
	}
	return 0;
}
