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
#define INF (int)1e9

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
        cin >> n;
        vi a(n);
        f(i, 0, n, 1) cin >> a[i];
        int l = 0, r = INF;
        bool fl = true;
        f(i, 1, n, 1) { 
            if (a[i] > a[i - 1]) r = min(r, (a[i] + a[i - 1])/2);
            else if (a[i] < a[i - 1]) l = max(l, (int)ceil((a[i] + a[i - 1])/2.0));
            if (r < l) {fl = false; break;}
        }
        if (fl) cout << (l + r)/2 << nl;
        else cout << -1 << nl;
	}
	return 0;
}
