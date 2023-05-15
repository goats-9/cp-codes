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
	int t, n, k;
    string s;
	cin >> t;
    while (t--) { 
        cin >> n >> k >> s;
        int l[26], u[26];
        f(i,0,26,1) l[i] = 0, u[i] = 0;
        f(i,0,n,1) {
            if (islower(s[i])) ++l[s[i]-'a'];
            else ++u[s[i]-'A'];
        }
        int tot = 0;
        f(i,0,26,1) {
            int x = abs(l[i]-u[i])/2;
            tot += min(l[i],u[i]) + min(x,k);
            k -= min(x,k);
        }
        cout << tot << nl;
	}
	return 0;
}
