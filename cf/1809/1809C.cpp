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
    vi tr(31);
    f(i,1,31,1) tr[i] = i + tr[i-1];
	int t, n, k;
	cin >> t;
    while (t--) { 
        cin >> n >> k;
        int pos = upper_bound(all(tr), k) - tr.begin() - 1;
        int rem = k - tr[pos];
        f(i,0,pos,1) cout << 2 << ' ';
        if (pos < n) {
            cout << 2*(rem - pos - 1) + 1 << ' ';
            f(i,pos+1,n,1) cout << -1000 << ' ';
        }
        cout << nl;
	}
	return 0;
}
