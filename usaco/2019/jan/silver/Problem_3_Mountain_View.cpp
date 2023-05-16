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

struct Peak {
    int x, y;
};

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
	int n;
    fin >> n;
    V<Peak> a(n);
    f(i,0,n,1) fin >> a[i].x >> a[i].y;
    mii df;
    f(i,0,n,1) {
        int d = a[i].x - a[i].y, s = a[i].x + a[i].y;
        if (df.find(d) == df.end()) df[d] = s;
        else df[d] = max(df[d], s);
    }
    vi sm;
    sm.pb(0);
    for (auto &[key, val] : df) if (val > sm.back()) sm.pb(val);
    fout << sm.size() - 1 << nl;
    fin.close(), fout.close();
	return 0;
}
