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
	int t, n;
	cin >> t;
    string s;
    while (t--) { 
        cin >> n >> s;
        string let = "";
        V<bool> alph(26, false);
        int i = 0;
        while (i < n) {
            int k = 0;
            char ch = tolower(s[i]);
            while (i + k < n && (tolower(s[i+k]) == ch)) ++k;
            i += k;
            let += ch;
        }
        if (let == "meow") cout << "YES\n";
        else cout << "NO\n";
	}
	return 0;
}
