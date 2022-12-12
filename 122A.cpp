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

bool isLucky(int n) { 
    while (n) { 
        int d = n%10;
        if (!(d == 4 || d == 7)) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i*i <= n; i++) if (n%i == 0) if (isLucky(i) || isLucky(n/i)) { cout << "YES\n"; return 0;}
    cout << "NO\n";
	return 0;
}
