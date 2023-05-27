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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    f(tc,0,t,1) {
        if (tc) cout << nl;
        string inp;
        getline(cin, inp);
        getline(cin, inp);
        stringstream ss(inp);
        vi idx;
        int x;
        V<string> flt;
        string dbl; 
        while (ss >> x) idx.pb(x);
        getline(cin, inp);
        ss = stringstream(inp);
        while (ss >> dbl) flt.pb(dbl);
        M<int, string> ord;
        f(i,0,idx.size(),1) ord[idx[i]] = flt[i];
        for (auto &keyval : ord) cout << keyval.second << nl;
    }
	return 0;
}
