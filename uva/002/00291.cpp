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

vvi adj = {
    {1,2,4},
    {0,2,4},
    {0,1,3,4},
    {2,4},
    {0,1,2,3}
};

vvi used(5, vi(5));

void dfs(string &s) {
    int n = s.size();
    if (n == 9) {
        for (char ch : s) cout << ++ch;
        cout << nl;
        return;
    }
    int u = s.back() - '0';
    for (auto v : adj[u]) {
        int p = min(u, v), q = u + v - p;
        if (used[p][q]) continue;
        used[p][q] = 1;
        s.pb(v + '0');
        dfs(s);
        s.pop_back();
        used[p][q] = 0;
    }
}

int main() {
    string s = "0";
    dfs(s);
	return 0;
}
