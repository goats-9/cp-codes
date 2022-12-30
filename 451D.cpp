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
    string s; cin >> s;
    ll ae = 0, ao = 0, be = 0, bo = 0, e = 0, o = 0;
    f(i, 0, s.size(), 1) { 
        if (s[i] == 'a') {
            if (i%2) ++ao, o += ao, e += ae;
            else ++ae, o += ae, e += ao;
        } else { 
            if (i%2) ++bo, o += bo, e += be;
            else ++be, o += be, e += bo;
        }
    }
    cout << e << " " << o << nl; 
	return 0;
}
