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
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        vi a(n);
        int b = 0;
        f(i,0,n,1) {
            cin >> a[i];
            if (a[i] < 0) ++b;
        }
        int c = n - 2*b;
        int ctr = 0;
        f(i,0,b+c,1) cout << ++ctr << ' ';
        f(i,0,b,1) cout << --ctr << ' ';
        cout << nl;
        f(i,0,b,1) cout << "1 0 ";
        ctr = 0;
        f(i,0,c,1) cout << ++ctr << ' ';
        cout << nl;
	}
	return 0;
}
