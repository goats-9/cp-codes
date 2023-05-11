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
#define EPS 1e-7

int p, q, r, s, t, u;

double fn(double x) {return p*expl(-x) + q*sinl(x) + r*cosl(x) + s*tanl(x) + t*x*x + u;}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        double l = 0, r = 1;
        if (fn(l)*fn(r) > 0) {cout << "No solution\n"; continue;}
        while (l + EPS < r) {
            double g = (l+r)/2;
            if (fn(l)*fn(g) <= 0) r = g;
            else l = g;
        }
        printf("%.4lf\n", (l+r)/2);
    }
}
