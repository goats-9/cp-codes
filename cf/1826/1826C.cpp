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
#define N 1e6+10

int main() {
    vi spf(N);
    f(i,0,N+1,1) spf[i] = i;
    f(i,2,N+1,2) spf[i] = 2;
    for (int i = 3; i*i <= N; i++) {
        if (spf[i] < i) continue;
        for (int j = i*i; j <= N; j += i) spf[j] = min(spf[j], i);
    }
	int t, n, m;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        if (n == 1) cout << "YES\n";
        else if (spf[n] <= m) cout << "NO\n";
        else cout << "YES\n";
	}
	return 0;
}
