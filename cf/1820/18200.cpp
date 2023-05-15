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
	int t;
    string s;
	cin >> t;
    while (t--) { 
        cin >> s;
        if (s == "^") {cout << 1 << nl; continue;}
        int i = 0, n = s.size();
        int ctr = 0;
        while (i < n) {
            while (i < n && s[i] == '^') i++;
            int k = 0;
            while (i + k < n && s[i + k] == '_') k++;
            ctr += (k - 1);
            if (i == 0) ++ctr;
            if (i + k == n) ++ctr; 
            i += k;
        }
        cout << ctr << nl;
	}
	return 0;
}
