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
	int t, n, m;
    string s1, s2;
	cin >> t;
    while (t--) { 
        cin >> n >> m >> s1 >> s2;
        int v1 = 0, v2 = 0;
        f(i,0,n-1,1) if (s1[i] == s1[i+1]) {v1 = i+1; break;}
        f(i,0,m-1,1) if (s2[i] == s2[i+1]) {v2 = i+1; break;}
        if (v1 && v2) cout << "NO\n";
        else if (!v1 && !v2) cout << "YES\n";
        else {
            bool fl = true;
            if (v1) {
                string t = s1.substr(v1);
                reverse(all(t));
                s2 += t;
                f(i,0,s2.size()-1,1) if (s2[i] == s2[i+1]) {fl = false; break;}
            } else {
                string t = s2.substr(v2);
                reverse(all(t));
                s1 += t;
                f(i,0,s1.size()-1,1) if (s1[i] == s1[i+1]) {fl = false; break;}
            }
            if (fl) cout << "YES\n";
            else cout << "NO\n";
        }
	}
	return 0;
}
