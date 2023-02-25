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

bool isPall(string &s) {
    int n = s.size();
    f(i,0,n,1) if (s[i] != s[n-i-1]) return false;
    return true;
}

int main() {
	int t, n;
    string s;
	cin >> t;
    while (t--) { 
        cin >> n >> s;
        if (isPall(s)) cout << "Yes\n";
        else {
            vi d;
            f(i,0,n/2,1) {
                if (s[i] != s[n-i-1]) d.pb(i);
            }
            bool fl = true;
            f(i,0,d.size()-1,1) {
                if (d[i+1]-d[i]>1) {
                    fl = false;
                    break;
                }
            }
            if (fl) cout << "Yes\n";
            else cout << "No\n";
        }
	}
	return 0;
}
