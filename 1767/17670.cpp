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
	int t, x1, x2, x3, y1, y2, y3;
    scanf("%d", &t);
    while (t--) { 
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if ((x1 == x2 || x2 == x3 || x1 == x3) && (y1 == y2 || y2 == y3 || y3 == y1)) cout << "NO\n";
        else cout << "YES\n";
	}
	return 0;
}
