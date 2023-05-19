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
#define N 10001

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++) if (!(n%i)) return false;
    return true;
}

int main() {
    int a, b;
    vi ans(N);
    f(i,0,N,1) ans[i] = isPrime(i*i+i+41);
    f(i,1,N,1) ans[i] += ans[i-1];
    while (cin >> a >> b) {
        int ctr = ans[b];
        if (a) ctr -= ans[a-1];
        int tot = b-a+1;
        printf("%.2lf\n", (100.0*ctr)/tot + 0.00000005); 
    }
	return 0;
}
