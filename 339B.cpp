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
    ll n, m;
    cin >> n >> m;
    vll a(m);
    f(i, 0, m, 1) cin >> a[i];
    ll t = a[0] - 1;
    f(i, 1, m, 1) { 
        if (a[i] < a[i - 1]) t += (a[i] - a[i - 1] + n);
        else t += (a[i] - a[i - 1]);
    }
    cout << t << nl;
	return 0;
}
