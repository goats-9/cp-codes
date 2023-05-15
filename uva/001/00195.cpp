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

bool cmp(char a, char b) {
    int x, y;
    if (isupper(a)) x = a - 'A';
    else x = a - 'a';
    if (isupper(b)) y = b - 'A';
    else y = b - 'a';
    if (x == y) return a < b;
    else return x < y;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        sort(all(s), cmp);
        do cout << s << nl;
        while (next_permutation(all(s), cmp));
    }
    return 0;
}
