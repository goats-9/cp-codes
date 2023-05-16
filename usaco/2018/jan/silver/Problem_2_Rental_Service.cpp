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
    ifstream fin("rental.in");
    ofstream fout("rental.out");
	ll n, m, r;
    fin >> n >> m >> r;
    ll ans = 0;
    vll c(n), rent(r);
    V<pll> store(m);
    f(i,0,n,1) fin >> c[i];
    f(i,0,m,1) fin >> store[i].second >> store[i].first;
    f(i,0,r,1) fin >> rent[i];
    sort(rall(c));
    sort(rall(store));
    sort(rall(rent));
    int cow = 0, shop = 0, rnt = 0;
    while (cow < n) {
        ll gal = c[cow], curr_shop = shop;
        ll last = 0, sold = 0, milk_prof = 0;
        while (curr_shop < m) {
            sold = min(gal, store[curr_shop].second);
            milk_prof += sold*store[curr_shop].first;
            gal -= sold;
            if (!gal) {last = sold; break;}
            else curr_shop++;
        }
        if (rnt >= r || milk_prof > rent[rnt]) {
            ans += milk_prof;
            shop = curr_shop;
            if (shop < m) store[shop].second -= last;
            cow++;
        } else {
            ans += rent[rnt++];
            n--;
        }
    }
    fout << ans << nl;
    fin.close(), fout.close();
	return 0;
}