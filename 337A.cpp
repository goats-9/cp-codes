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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
    int n, m; cin >> n >> m;
    vi a(m); f(i, 0, m, 1) cin >> a[i];
    sort(all(a));
    int mn = 6969; //LOL
    f(i, 0, m - n + 1, 1) if (a[i + n - 1] - a[i] < mn) mn = a[i + n - 1] - a[i];
    cout << mn << nl;
	return 0;
}
