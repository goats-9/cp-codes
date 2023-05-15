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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int t, m;
    cin >> t;
    V<string> p(2);
    while (t--) { 
        cin >> m >> p[0] >> p[1];
        bool fl = true;
        int j = 0;
        while (j < m) { 
            int k = 0;
            while (j + k < m && p[0][j + k] == 'B' && p[1][j + k] == 'B') ++k;
            if (j != 0 && j + k < m) { 
                if (k%2 && p[0][j - 1] == p[0][j + k]) {fl = false; break;}
                if (k%2 == 0 && p[0][j - 1] == p[1][j + k]) {fl = false; break;}
            }
            j += k + 1;
        }
        if (fl) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
