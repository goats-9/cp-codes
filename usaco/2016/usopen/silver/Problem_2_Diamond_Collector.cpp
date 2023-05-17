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
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
	int n, k;
    fin >> n >> k;
    vi a(n);
    f(i,0,n,1) fin >> a[i];
    sort(all(a));
    int ans = 0;
    vi left(n), mx_right(n+1);
    f(l,0,n,1) {
        int r = l;
        while (r < n && a[r] - a[l] <= k) r++;
        left[l] = r - l;
    }
    mx_right.back() = 0;
    for (int i = n-1; i >= 0; i--) mx_right[i] = max(mx_right[i+1], left[i]);
    f(i,0,n,1) {
        ans = max(ans, left[i] + mx_right[i+left[i]]);
    }
    fout << ans << nl;
    fin.close(), fout.close();
	return 0;
}
