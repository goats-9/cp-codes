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
    int n, p, r, tc = 0;
    double d;
    string inp;
    while (cin >> n >> p && (n || p)) {
        cin.ignore();
        string comp = "", name = "";
        int mx = 0;
        double pr = FLT_MAX;
        f(i,0,n,1) getline(cin, inp);
        if (tc) cout << nl;
        f(i,0,p,1) {
            getline(cin, name);
            cin >> d >> r;
            cin.ignore();
            if ((r > mx) || (r == mx && d < pr)) comp = name, mx = r, pr = d;
            f(j,0,r,1) getline(cin, inp);
        }
        cout << "RFP #" << ++tc << nl << comp << nl;
    }
	return 0;
}
