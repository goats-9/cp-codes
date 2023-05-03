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
	int i, t, x;
    string s;
    while (cin >> s >> t && t) { 
        i = 0;
        if (s[1] == 'x') f(k,2,s.size(),1) i = (i<<4) + (isalpha(s[k])?(s[k]-'A'+10):(s[k]-'0'));
        else if (s[0] == '0') f(k,1,s.size(),1) i = (i<<3) + (s[k]-'0');
        else f(k,0,s.size(),1) i = i*10 + (s[k]-'0');
        int ctr = 0;
        f(k,0,t,1) {
            cin >> s >> x;
            if (s[0] == '+') {
                if (i + 1 == x) ++ctr;
                i = x;
            } else if (s[0] == '-') {
                if (i - 1 == x) ++ctr;
                i = x;
            } else {
                if (int(s.size()) == 1) {
                    if (i == x) ++ctr;
                    i = x;
                } else if (s[2] == '+') {
                    if (i == x) ++ctr;
                    i = x + 1;
                } else {
                    if (i == x) ++ctr;
                    i = x - 1;
                }
            }
        }
        cout << ctr << nl;
	}
	return 0;
}
