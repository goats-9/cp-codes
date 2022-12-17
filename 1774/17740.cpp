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
	int t, n;
    string s;
    scanf("%d", &t);
    while (t--) { 
        cin >> n >> s;
        int fl = 1;
        f(i, 1, n, 1) { 
            if (s[i] == '0') cout << '+';
            else { 
                if (fl) cout << '-';
                else cout << '+';
                fl = 1 - fl;
            }
        }
        cout << nl;
	}
	return 0;
}
