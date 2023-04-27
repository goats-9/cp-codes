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
	int t, n, k;
	cin >> t;
    while (t--) { 
        cin >> n >> k;
        vi a(n);
        f(i,0,n,1) {
            cin >> a[i];
            --a[i];
        }
        int ctr = 0;
        if (k == 1) {
            cout << "0\n";
            continue;
        }
        f(i,0,n,1) if (i%k != a[i]%k) ++ctr;
        if (ctr == 0) cout << "0\n";
        else if (ctr == 2) cout << "1\n";
        else cout << "-1\n";
	}
	return 0;
}
