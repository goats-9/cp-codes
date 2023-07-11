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
#define N 200010

int main() {
    vi spf(N);
    f(i,0,N,1) spf[i] = i;
    f(i,2,N,2) spf[i] = 2;
    for (int i = 1; i*i <= N; i++) {
        f(j,i*i,N,i) spf[i] = min(spf[i], j);
    }
	int t;
	cin >> t;
	while (t--) { 
        int n;
        cin >> n;
        if (n == 1) {cout << 1 << nl; continue;}
        deque<int> q;
        q.pb(1);
        vi pr, com;
        f(i,3,n+1,1) {
            if (spf[i] == i) pr.pb(i);
            else com.pb(i);
        }
        vi ans;
        for (auto x : pr) ans.pb(x);
        for (auto x : com) ans.pb(x);
        ans.pb(2);
        ans.insert(ans.begin() + (n/2), 1, 1);
        for (auto x : ans) cout << x << ' ';
        cout << nl;
	}
	return 0;
}
