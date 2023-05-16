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
    ifstream fin("split.in");
    ofstream fout("split.out");
    int n; fin >> n;
    V<pll> cows(n);
    f(i,0,n,1) fin >> cows[i].first >> cows[i].second;
    ll ar = 2e18;
    sort(all(cows));
    vll mn_left(n), mx_left(n), mn_right(n), mx_right(n);
    mn_left[0] = cows[0].second, mx_left[0] = cows[0].second;
    mn_right[n-1] = cows[n-1].second, mx_right[n-1] = cows[n-1].second;
    f(i,1,n,1) {
        mn_left[i] = min(mn_left[i-1], cows[i].second);
        mx_left[i] = max(mx_left[i-1], cows[i].second);
        mn_right[n-i-1] = min(mn_right[n-i], cows[n-i-1].second);
        mx_right[n-i-1] = max(mx_right[n-i], cows[n-i-1].second);
    }
    ll init = (cows.back().first - cows.front().first)*(mx_left.back() - mn_left.back());
    f(i,0,n-1,1) {
        if (cows[i].first == cows[i+1].first && mx_left[i] >= mn_right[i+1]) continue;
        ar = min(ar, (cows[i].first-cows.front().first)*(mx_left[i]-mn_left[i]) + (cows.back().first-cows[i+1].first)*(mx_right[i+1]-mn_right[i+1]));
    }
    f(i,0,n,1) swap(cows[i].first, cows[i].second);
    sort(all(cows));
    mn_left.assign(n, 0), mx_left.assign(n, 0), mn_right.assign(n, 0), mx_right.assign(n, 0);
    mn_left[0] = cows[0].second, mx_left[0] = cows[0].second;
    mn_right[n-1] = cows[n-1].second, mx_right[n-1] = cows[n-1].second;
    f(i,1,n,1) {
        mn_left[i] = min(mn_left[i-1], cows[i].second);
        mx_left[i] = max(mx_left[i-1], cows[i].second);
        mn_right[n-i-1] = min(mn_right[n-i], cows[n-i-1].second);
        mx_right[n-i-1] = max(mx_right[n-i], cows[n-i-1].second);
    }
    f(i,0,n-1,1) {
        if (cows[i].first == cows[i+1].first && mx_left[i] >= mn_right[i+1]) continue;
        ar = min(ar, (cows[i].first-cows.front().first)*(mx_left[i]-mn_left[i]) + (cows.back().first-cows[i+1].first)*(mx_right[i+1]-mn_right[i+1]));
    }
    fout << init - ar << nl;
    fin.close(), fout.close();
	return 0;
}
