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

int main() {
    vi ans(10010);
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 6;
    ans[4] = 4;
    ans[5] = 2;
    ans[6] = 2;
    ans[7] = 4;
    ans[8] = 2;
    ans[9] = 8;
    f(i,10,10010,1) {
        int ten = i/10 % 10;
        if (ten%2) ans[i] = 4*ans[i/5]*ans[i%10] % 10;
        else ans[i] = 6*ans[i/5]*ans[i%10] % 10;
    }
    int n;
    while (cin >> n) printf("%5d -> %d\n", n, ans[n]);
}
