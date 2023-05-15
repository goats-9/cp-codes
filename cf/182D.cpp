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
    string s1, s2; cin >> s1 >> s2;
    int t1 = s1.size(), t2 = s2.size();
    int l = 1, len = 1;
    while (l < t1) { 
        int p = 0;  // Num of common characters
        while (l + p < t1 && p < len && s1[l + p] == s1[p]) ++p;
        l += max(p, 1);
        if (p < len) len = l;
    }
    int x = len;
    l = 1, len = 1;
    while (l < t2) { 
        int p = 0;  // Num of common characters
        while (l + p < t2 && p < len && s2[l + p] == s2[p]) ++p;
        l += max(p, 1);
        if (p < len) len = l;
    }
    int y = len;
    if (x != y || s1.substr(0, x) != s2.substr(0, y)) {cout << 0 << nl; return 0;}
    int ctr = 0;
    for (int i = x; i <= t1 && i <= t2; i += x) if (!(t1%i) && !(t2%i)) ++ctr;
    cout << ctr << nl;
	return 0;
}
