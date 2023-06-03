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
	while (t--) { 
        int n;
        cin >> n;
        vi ctr1(2*n+1), ctr2(2*n+1), a(n), b(n);
        f(i,0,n,1) cin >> a[i];
        f(i,0,n,1) cin >> b[i];
        int i = 0;
        while (i < n) {
            int k = 0;
            while (i + k < n && a[i] == a[i+k]) k++;
            ctr1[a[i]] = max(ctr1[a[i]], k);
            i += k;
        }
        i = 0;
        while (i < n) {
            int k = 0;
            while (i + k < n && b[i] == b[i+k]) k++;
            ctr2[b[i]] = max(ctr2[b[i]], k);
            i += k;
        }
        f(i,0,2*n+1,1) ctr1[i] += ctr2[i];
        cout << *max_element(1+all(ctr1)) << nl;
	}
	return 0;
}
