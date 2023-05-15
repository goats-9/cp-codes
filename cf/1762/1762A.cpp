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
        vi a(n), b(n);
        int sm = 0;
        f(i, 0, n, 1) { 
            cin >> a[i];
            sm += a[i];
        }
        if (sm%2 == 0) {cout << "0\n"; continue;}
        f(i, 0, n, 1) {
            int x = a[i], y = x%2;
            while (x%2 == y) x /= 2, ++b[i];
        }
        sort(all(b));
        cout << b[0] << nl;
	}
	return 0;
}
