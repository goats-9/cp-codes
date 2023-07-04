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

vi a(26);

void process(string &s) {
    if (s.empty()) return;
    string l = "", r = "";
    int n = s.size();
    int p = a[s.front() - 'A'];
    f(i,1,n,1) {
        char ch = s[i];
        if (a[ch-'A'] < p) l += ch;
        else r += ch;
    }
    process(l), process(r);
    cout << s.front();
}

int main() {
    string pre, in;
    while (cin >> pre >> in) {
        int n = pre.size();
        f(i,0,n,1) a[in[i]-'A'] = i;
        process(pre);
        cout << nl;
    }
	return 0;
}
