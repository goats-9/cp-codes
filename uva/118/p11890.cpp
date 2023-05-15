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
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)
#define pb push_back

int np, nm, sz;

void tog(int &fl) { (fl == 0 ? fl = -1 : fl = 0); }

vi csort(vi &a, int n) {
    vi ret(n);
    int c = n - 1;
    f(i, 0, 6002, 1) {
        f(j, 0, a[i], 1) {
            ret[c] = i - 3000;
            --c;
        }
    }
    return ret;
}

void parse(string &s, int fl, int &idx) {
    if (idx == sz) return;
    if (s[idx] == '(') {
        if (idx > 1 && s[idx - 1] == '-') {
            tog(fl);
            ++idx;
            parse(s, fl, idx);
            tog(fl);
        } else { ++idx; parse(s, fl, idx); }
        ++idx;
        parse(s, fl, idx);
    } else if (s[idx] == ')') return;
    else if (s[idx] == 'x') {
        if (idx > 1 && s[idx - 1] == '-') (fl == 0 ? ++nm : ++np);
        else (fl == -1 ? ++nm : ++np);
        ++idx;
        parse (s, fl, idx);
    } else { ++idx; parse(s, fl, idx); }
} 

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        string s;
        int n, x;
        cin >> s;
        scanf("%d", &n);
        vi a(6002);
        f(i, 0, n, 1) { scanf("%d", &x); ++a[x + 3000]; }
        vi A = csort(a, n);
        sz = s.size(), np = 0, nm = 0;
        int i = 0;
        parse(s, 0, i);
        ll ans = 0;
        f(i, 0, np, 1) ans += A[i];
        f(i, np, n, 1) ans -= A[i];  
        printf("%lld\n", ans);
    }
    return 0;
}