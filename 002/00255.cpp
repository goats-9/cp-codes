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

void solve(int k, int q, int p) {
    int kx = k/8, ky = k%8, px = p/8, py = p%8, qx = q/8, qy = q%8;
    bool fl = false;
    if (k == q) {cout << "Illegal state\n"; return;}
    if (!(px == qx || py == qy)) {cout << "Illegal move\n"; return;}
    if (p == q || (px == qx && qx == kx && (ky-py)*(ky-qy) <= 0) || (py == qy && ky == py && (kx-px)*(kx-qx) <= 0)) {cout << "Illegal move\n"; return;}
    if ((px == kx && abs(py - ky) == 1) || (py == ky && abs(px - kx) == 1)) {cout << "Move not allowed\n"; return;}
    if (kx > 0 && !(kx-1 == px || ky == py)) fl = true;
    if (kx < 7 && !(kx+1 == px || ky == py)) fl = true;
    if (ky > 0 && !(ky-1 == py || kx == px)) fl = true;
    if (ky < 7 && !(ky+1 == py || kx == px)) fl = true;
    if (fl) cout << "Continue\n";
    else cout << "Stop\n";
}

int main() {
	int k, q, p;
    while (cin >> k >> q >> p) {
        solve(k,q,p);
	}
	return 0;
}
