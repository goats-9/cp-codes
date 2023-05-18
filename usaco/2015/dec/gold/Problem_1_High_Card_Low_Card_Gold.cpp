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
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    int n;
    fin >> n;
    vi elsie_top(n>>1), elsie_bottom(n>>1);
    set<int> bessie_top, bessie_bottom;
    vi cards(1+(n<<1), 1);
    int ans = 0;
    f(i,0,n>>1,1) {
        fin >> elsie_top[i];
        --cards[elsie_top[i]];
    }
    f(i,0,n>>1,1) {
        fin >> elsie_bottom[i];
        --cards[elsie_bottom[i]];
    }
    sort(all(elsie_top)), sort(rall(elsie_bottom));
    int ctr = 0;
    f(i,1,1+(n<<1),1) {
        if (cards[i]) {
            if (ctr < (n>>1)) bessie_bottom.insert(i);
            else bessie_top.insert(i);
            ++ctr;
        }
    }
    f(i,0,(n>>1),1) {
        auto it = bessie_bottom.upper_bound(elsie_bottom[i]);
        if (it == bessie_bottom.begin()) break;
        else {
            bessie_bottom.erase(--it);
            ++ans;
        }
    }
    f(i,0,(n>>1),1) {
        auto it = bessie_top.upper_bound(elsie_top[i]);
        if (it == bessie_top.end()) break;
        else {
            bessie_top.erase(it);
            ++ans;
        }
    }
    fout << ans << nl;
    fin.close(), fout.close();
	return 0;
}
