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
	int t, n, x1, x2, y1, y2;
	cin >> t;
    while (t--) { 
        cin >> n >> x1 >> y1 >> x2 >> y2;
        double c = (n/2) + 0.5;
        int l1 = max(abs(x1 - c), abs(y1 - c)) + 0.5;
        int l2 = max(abs(x2 - c), abs(y2 - c)) + 0.5;
        cout <<  abs(l1 - l2) << nl;        
	}
	return 0;
}
