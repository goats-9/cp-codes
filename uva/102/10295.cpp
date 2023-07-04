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
#define MOD1 (ll)1000000007
#define MOD2 (ll)998244353

int main() {
	int n, m;
    cin >> n >> m;
    M<string, ll> dict;
    f(i,0,n,1) {
        string s;
        ll x;
        cin >> s >> x;
        dict[s] = x;
    }
    f(i,0,m,1) {
        string s;
        ll sal = 0;
        while (cin >> s && s != ".") if (dict.find(s) != dict.end()) sal += dict[s];
        cout << sal << nl;
    }
	return 0;
}
