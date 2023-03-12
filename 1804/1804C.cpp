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
    ll n, x, p;
	cin >> t;
    while (t--) { 
        cin >> n >> x >> p;
        vll mod(2*n);
        f(i,1,2*n,1) mod[i] = (mod[i-1]+i)%n;
        int rem = (n-x)%n;
        bool fl = false;
        f(i,0,2*n,1) {
            if (mod[i] == rem) {
                int k = i?i:2*n;
                if (k <= p) {fl = true; break;}
            }
        }
        if (fl) cout << "Yes\n";
        else cout << "No\n";
	}
	return 0;
}
