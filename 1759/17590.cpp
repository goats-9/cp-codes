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
	int t;
    string s;
    scanf("%d", &t);
    while (t--) { 
        cin >> s;
        int n = s.size();
        bool fl = true;
        if (s[0] != 'Y' && s[0] != 'e' && s[0] != 's') {cout << "NO\n"; continue; }
        f(i, 1, n, 1) { 
            if ((s[i - 1] == 's' && s[i]!= 'Y') || (s[i - 1] == 'e' && s[i] != 's') || (s[i - 1] == 'Y' && s[i] != 'e')) { fl = false; break; }
            if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') {fl = false; break;}
        }
        if (fl) cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
