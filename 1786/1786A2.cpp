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
	int t, n;
	cin >> t;
    while (t--) { 
        cin >> n;
        n--;
        int aw = 1, ab = 0, bw = 0, bb = 0;
        int ctr = 2;
        int fl = 1;
        while (n) {
            if (fl) {
                int s = min(n,2*ctr+1);
                n -= s;
                bw += s/2;
                bb += (s - s/2);
            } else { 
                int s = min(n,2*ctr+1);
                n -= s;
                ab += s/2;
                aw += (s - s/2);
            }
            ctr += 2;
            fl = 1 - fl;
        }
        cout << aw <<' ' << ab << ' ' << bw << ' ' << bb << nl;
	}
	return 0;
}
