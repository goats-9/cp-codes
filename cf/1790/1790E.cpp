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
	int t, x;
	cin >> t;
    while (t--) { 
        cin >> x;
        vi X;
        while (x) { 
            X.pb(x%2);
            x >>= 1;
        }
        reverse(all(X));
        int sz = X.size();
        vi A(sz), B(sz);
        bool fl = true;
        int i = 0;
        while (i < sz) {
            if (X[i] == 1) { 
                if (i == sz - 1 || X[i+1] == 1) {fl = false; break;}
                A[i] = 0, B[i] = 1;
                A[i+1] = 1, B[i + 1] = 1;
                i += 2;
            } else {
                A[i] = 0, B[i] = 0;
                i++;
            }
        }
        if (!fl) {cout << -1 << nl; continue;}
        int a = 0, b = 0;
        f(i,0,sz,1) a = (a<<1) + A[i];
        f(i,0,sz,1) b = (b<<1) + B[i];
        cout << a << ' ' << b << nl;
	}
	return 0;
}
