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
	int t;
    string a, b;
	cin >> t;
    while (t--) { 
        cin >> a >> b;
        int as = a.size(), bs = b.size();
        if (a[0] == b[0]) {
            cout << "YES\n" << a[0] << "*\n";
        } else if (a.back() == b.back()) {
            cout << "YES\n*" << a.back() << nl;
        } else {
            int k = -1;
            f(i,0,as-1,1) {
                f(j,0,bs-1,1) {
                    if (a[i] == b[j] && a[i+1] == b[j+1]) k = i;
                }
            }
            if (k == -1) cout << "NO\n";
            else cout << "YES\n*" << a[k] << a[k+1] << "*\n";
        }
	}
	return 0;
}
