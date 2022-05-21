#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define rep(i, a, b, j) for(int i = a; i < b; i = i + j)
#define LSOne(i) (i & (-i))

class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};

int main() {
    int t;
    cin >> t;
    rep(j, 0, t, 1) {
        int m, n, q;
        cin >> n >> m;
        vll A(m + n + 1), pos(n + 1);
        rep(i, m + 1, m + n + 1, 1) { A[i] = 1; pos[i - m] = i; }
        FenwickTree F(A);
        rep(i, 0, m, 1) {
            cin >> q;
            cout << F.rsq(pos[q]) - 1;
            F.update(pos[q], -1);
            pos[q] = m - i;
            F.update(pos[q], 1);
            if (i != m - 1) cout << " ";
            else cout << "\n";
        } 
    }
    return 0;
}