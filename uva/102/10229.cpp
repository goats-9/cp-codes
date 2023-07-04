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
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

ll md;

void mul(vvll &a, vvll &b) {
    if (a[0].size() != b.size()) return;
    int x = a.size(), y = b[0].size(), z = b.size();
    vvll c(x, vll(y));
    f(i,0,x,1) {
        f(j,0,y,1) {
            f(k,0,z,1) {
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= md;
            }
        }
    }
    a = c;
}

int main() {
	ll n, m;
    while (cin >> n >> m) {
        md = (1<<m);
        vvll a = {
            {1,1},
            {1,0},
        };
        vvll id = {
            {1,0},
            {0,1},
        };
        f(i,0,31,1) {
            if (n&(1<<i)) mul(id, a);
            mul(a,a);
        }
        cout << id[0][1] << nl;
    }
	return 0;
}
