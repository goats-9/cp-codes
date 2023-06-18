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
	int n;
    int tc = 0;
	while (cin >> n && n) { 
        cout << "Scenario #" << ++tc << nl; 
        M<int, queue<int>> tq;
        f(i,0,n,1) tq[i] = queue<int>();
        mii teams;
        queue<int> q;
        f(i,0,n,1) {
            int x; cin >> x;
            f(j,0,x,1) {
                int y;
                cin >> y;
                teams[y] = i;
            }
        }
        string s;
        while (cin >> s && s != "STOP") {
            if (s.front() == 'E') {
                int k;
                cin >> k;
                int tm = teams[k];
                if (tq[tm].empty()) q.push(tm);
                tq[tm].push(k);
            } else {
                int tmp = q.front();
                int mem = tq[tmp].front();
                cout << mem << nl;
                tq[tmp].pop();
                if (tq[tmp].empty()) q.pop();       
            }
        }
        cout << nl;
	}
	return 0;
}
