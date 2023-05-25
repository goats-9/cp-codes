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

struct Coord {
    int x, y, z;
};

int main() {
    int t;
    cin >> t;
    f(tc,1,t+1,1) {
        string cur, birth;
        cin >> cur >> birth;
        int dc = (cur[0]-'0')*10 + cur[1]-'0';
        int mc = (cur[3]-'0')*10 + cur[4]-'0';
        int yc = (cur[6]-'0')*1000 + (cur[7]-'0')*100 + (cur[8]-'0')*10 + cur[9]-'0';
        int db = (birth[0]-'0')*10 + birth[1]-'0';
        int mb = (birth[3]-'0')*10 + birth[4]-'0';
        int yb = (birth[6]-'0')*1000 + (birth[7]-'0')*100 + (birth[8]-'0')*10 + birth[9]-'0';
        int ans = yc - yb;
        cout << "Case #" << tc << ": ";
        if (mb > mc || (mb == mc && db > dc)) --ans;
        if (ans < 0) cout << "Invalid birth date\n";
        else if (ans > 130) cout << "Check birth date\n";
        else cout << ans << nl;
    }
	return 0;
}
