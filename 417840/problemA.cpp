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
#define N (int)5e5

int main() {
	int n, k, x;
    cin >> n >> k;
    vi a(N + 1);
    f(i, 0, n, 1) {cin >> x; ++a[x];}
    f(i, 1, N, 1) { 
        a[i + 1] += a[i]/(i + 1);
        a[i] %= (i + 1);
    }
    f(i, 0, k, 1) if (a[i] > 0) {cout << "No\n"; return 0;}
    f(i, k, N + 1, 1) if (a[i] > 0) {cout << "Yes\n"; return 0;}
	return 0;
}
