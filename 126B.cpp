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

vector<int> prefixFunction(string s) {
    vector<int> p(s.size());
    int j = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        while (j > 0 && s[j] != s[i])
            j = p[j-1];

        if (s[j] == s[i])
            j++;
        p[i] = j;
    }   
    return p;
}

int main() {
    string s;
    cin >> s;
    vi p = prefixFunction(s);
    if (p.back() == 0) { cout << "Just a legend\n"; return 0;}
    f(i, 0, p.size() - 1, 1) if (p[i] == p.back()) {cout << s.substr(0, p[i]) << nl; return 0;}
    if (p[p.back() - 1] == 0) {cout << "Just a legend\n"; return 0;}
    cout << s.substr(0, p[p.back() - 1]) << nl; 
	return 0;
}
