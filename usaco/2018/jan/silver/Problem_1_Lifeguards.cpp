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

struct Guard {
    int tm, id, type;
    bool operator< (const Guard &g) const {
        if (tm == g.tm) return type < g.type;
        else return tm < g.tm;
    }
};

int main() {
	int n, x, y;
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
	fin >> n;
    V<Guard> a;
    Guard g;
    f(i,0,n,1) {
        fin >> x >> y;
        g.tm = x, g.id = i, g.type = 0;
        a.pb(g);
        g.tm = y, g.type = 1;
        a.pb(g);
    }
    sort(all(a));
    set<int> active;
    vi alone(n);
    int tot = 0, prev = 0;
    f(i,0,2*n,1) {
        int curr = a[i].tm;
        if (active.size()) tot += curr - prev;
        if (active.size() == 1) alone[*active.begin()] += curr-prev;
        if (a[i].type) active.erase(a[i].id);
        else active.insert(a[i].id);
        prev = curr;
    }
    int mn = *min_element(all(alone));
    fout << tot - mn << nl;
    fin.close(), fout.close();
	return 0;
}
