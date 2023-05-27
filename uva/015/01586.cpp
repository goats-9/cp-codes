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
#define MOL_C 12.01
#define MOL_H 1.008
#define MOL_O 16.00
#define MOL_N 14.01

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sz = s.size();
        int i = 0;
        double ans = 0;
        while (i < sz) {
            int k = 1, mul = 0;
            while (i + k < sz && isdigit(s[i+k])) mul = 10*mul + (s[i+k] - '0'), k++;
            double mwt;
            if (s[i] == 'C') mwt = MOL_C;
            else if (s[i] == 'H') mwt = MOL_H;
            else if (s[i] == 'O') mwt = MOL_O;
            else mwt = MOL_N;
            ans += mwt*max(mul, 1);
            i += k;
        }
        printf("%.3lf\n", ans);
    }
	return 0;
}
