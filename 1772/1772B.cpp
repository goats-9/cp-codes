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
	int t, a, b, c, d;
    scanf("%d", &t);
    while (t--) { 
        cin >> a >> b >> c >> d;
        int mn = min(a, min(b, min(c, d)));
        int mx = max(a, max(b, max(c, d)));
        if ((mn == a && mx == d) || (mn == b && mx == c) || (mn == d && mx == a) || (mx == b && mn == c)) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
