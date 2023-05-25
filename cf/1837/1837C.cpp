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

int main() {
	int t;
	cin >> t;
	while (t--) { 
        string s;
        cin >> s;
        int n = s.size();
        bool hasq = false, has1 = false, has0 = false;
        f(i,0,n,1) {
            if (s[i] == '?') hasq = true;
            if (s[i] == '1') has1 = true;
            if (s[i] == '0') has0 = true;
        }
        if (!hasq) {cout << s << nl; continue;}
        if (!has0) {cout << string(n, '1') << nl; continue;}
        if (!has1) {cout << string(n, '0') << nl; continue;}
        int l = 0;
        int r = n-1;
        while (l < n && s[l] == '?') s[l++] = '0';
        while (r >= 0 && s[r] == '?') s[r--] = '1';
        int i = l;
        while (i < r) {
            if (s[i] != '?') {i++; continue;}
            int k = 0;
            while (i + k < r && s[i] == s[i+k]) k++;
            if (s[i-1] == '0' && s[i+k] == '0') {
                f(j,i,i+k,1) s[j] = '0';
            } else {
                f(j,i,i+k,1) s[j] = '1';
            }
            i += k;
        }
        cout << s << nl;
	}
	return 0;
}
