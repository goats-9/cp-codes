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
    string s; cin >> s;
    int n = s.size();
    vi wub(n);
    f(i, 0, n - 2, 1) if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') wub[i] = 1;
    int i = 0;
    while (i < n) { 
        int k = 0;
        string word = "";
        while (i + k < n && wub[i + k] == 0) word.pb(s[i + k]), ++k;
        i += (k + 3);
        if (word != "") cout << word << " ";
    }
    cout << nl;
	return 0;
}