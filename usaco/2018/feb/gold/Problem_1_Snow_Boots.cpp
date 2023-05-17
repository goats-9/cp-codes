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

struct Tile {
    int l, r;
};

int main() {
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    int n, b;
    fin >> n >> b;
    vi tiles(n);
    f(i,0,n,1) fin >> tiles[i];
    V<P<pii, int>> boots(b);
    f(i,0,b,1) {
        fin >> boots[i].first.first >> boots[i].first.second;
        boots[i].second = i;
    }
    sort(rall(boots));
    vi tile_id;
    f(i,1,n-1,1) tile_id.pb(i);
    sort(all(tile_id), [&](int x, int y) {return tiles[x] > tiles[y];});
    set<int> valid_tiles;
    f(i,0,n,1) valid_tiles.insert(i);
    int max_tile = 0, step_size = 1;
    V<bool> ans(b, false);
    for (auto &[boot, id] : boots) {
        while (max_tile < (int)tile_id.size() && tiles[tile_id[max_tile]] > boot.first) {
            auto it = valid_tiles.find(tile_id[max_tile]);
            step_size = max(step_size, *next(it) - *prev(it));
            valid_tiles.erase(it);
            ++max_tile;
        }
        ans[id] = (boot.second >= step_size);
    }
    for (bool bn : ans) fout << bn << nl;
    fin.close(), fout.close();
	return 0;
}
