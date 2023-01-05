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
	int t, n;
    cin >> t;
    while (t--) { 
        cin >> n;
        V<pii> a(n);
        vi b(n), c(n);
        f(i, 0, n, 1) { cin >> a[i].first; a[i].second = i; }
        sort(all(a));
        V<bool> vis1(n + 1, false), vis2(n + 1, false);
        bool fl = true;
        f(i, 0, n, 1) { 
            int k = a[i].first;
            if (vis1[k] && vis2[k]) {fl = false; break;}
            if (!vis1[k]) { 
                vis1[k] = true;
                b[i] = k;
            } else { 
                vis2[k] = true;
                c[i] = k;
            }
        }
        if (!fl) {cout << "NO\n"; continue;}
        int l1 = 1, l2 = 1;
        f(i, 0, n, 1) { 
            if (b[i] == 0) { 
                while (l1 <= n && vis1[l1]) l1++;
                if (l1 > c[i]) {fl = false; break;}
                vis1[l1] = true;
                b[i] = l1;
            } else { 
                while (l2 <= n && vis2[l2]) l2++;
                if (l2 > b[i]) {fl = false; break;}
                vis2[l2] = true;
                c[i] = l2;
            }
        }
        if (!fl) {cout << "NO\n"; continue;}
        cout << "YES\n";
        vi bf(n), cf(n);
        f(i, 0, n, 1) bf[a[i].second] = b[i], cf[a[i].second] = c[i];
        f(i, 0, n, 1) cout << bf[i] << " ";
        cout << nl;
        f(i, 0, n, 1) cout << cf[i] << " ";
        cout << nl;
	}
	return 0;
}
