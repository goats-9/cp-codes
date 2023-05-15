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
#define MOD (ll)998244353
#define N 3000010

int main() {
    vll facmod(N), invmod(N), invfacmod(N);
    facmod[0] = 1, invmod[1] = 1, invfacmod[0] = 1;
    f(i,2,N,1) invmod[i] = MOD - (MOD/i)*invmod[MOD%i]%MOD;
    f(i,1,N,1) {facmod[i] = i*facmod[i-1]%MOD; invfacmod[i] = invmod[i]*invfacmod[i-1]%MOD;}
	int n;
    vi x(3);
    cin >> n;
    ll pd = 1;
    f(i,0,n,3) {
        cin >> x[0] >> x[1] >> x[2];
        sort(all(x));
        if (x[0] == x[1]) {
            if (x[1] == x[2]) pd *= 3;
            else pd *= 2;
        }
        pd = pd%MOD;
    }
    cout << ((pd*facmod[n/3]%MOD)*invfacmod[n/6]%MOD)*invfacmod[n/6]%MOD << nl;
	return 0;
}
