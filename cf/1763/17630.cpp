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
	int t, n;
    scanf("%d", &t);
    while (t--) { 
        cin >> n;
        int x = 0, y = 0;
        vi a(n);
        f(i, 0, n, 1) cin >> a[i];
        f(i, 0, 10, 1) { 
            bool f0 = false, f1 = false;
            f(j, 0, n, 1) {
                if (a[j] & (1<<i)) f1 = true;
                else f0 = true;
            }
            if (f1 && f0) x |= (1<<i);
            else if (f1) x |= (1<<i), y |= (1<<i);
        }
        cout << x - y << nl;
	}
	return 0;
}
