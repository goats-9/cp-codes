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

int main() {
	int t;
	cin >> t;
    vi num = {1,10,100,1000,10000};
	while (t--) { 
        string s;
        cin >> s;
        int n = s.size();
        vi mxr(n); mxr.back() = s.back() - 'A';
        vi cnt(n);
        vvi cfp(5, vi(n)), cfn(5, vi(n));
        for (int i = n - 2; i >= 0; i--) mxr[i] = max(mxr[i+1], s[i] - 'A');
        cnt.back() = (int)pow(10, s.back() - 'A');
        int cur = cnt.back();
        f(i,0,n-1,1) {
            int x = num[s[i]-'A'];
            if (s[i] - 'A' < mxr[i+1]) cnt[i] = -x;
            else cnt[i] = x;
            cur += cnt[i];
        }
        if (cnt[0] > 0) cfp[s[0]-'A'][0] = 1;
        else cfn[s[0]-'A'][0] = 1;
        f(i,1,n,1) {
            if (cnt[i] > 0) cfp[s[i]-'A'][i] = 1;
            else cfn[s[i]-'A'][i] = 1;
            f(j,0,5,1) cfp[j][i] += cfp[j][i-1], cfn[j][i] += cfn[j][i-1];
        }
        vi mxloc(5, -1);
        int mx = 10000 - cnt[0];
        mxloc[mxr[0]] = 0;
        f(i,1,n,1) {
            int tmp = mxr[i];
            f(j,0,5,1) {
                mxr[i] = max(mxr[i], j);
                int lt = -1;
                f(k,mxr[i]+1,5,1) lt = max(lt, mxloc[k]);
                int tmx = 0;
                if (lt == -1) {
                    f(k,0,5,1) {
                        if (k < mxr[i]) tmx -= 2*num[k]*cfp[k][i-1];
                        else tmx += 2*num[k]*cfn[k][i-1];
                    }
                } else {
                    f(k,0,5,1) {
                        if (k < mxr[i]) tmx -= 2*num[k]*(cfp[k][i-1] - cfp[k][lt-1]);
                        else tmx += 2*num[k]*(cfn[k][i-1] - cfn[k][lt-1]);
                    }
                }
                if (i < n - 1 && j < mxr[i+1]) tmx -= num[j];
                else tmx += num[j];
                tmx -= cnt[i];
                mx = max(mx, tmx);
            }
            mxr[i] = tmp;
            mxloc[mxr[i]] = i;
        }
        cout << cur + mx << nl;
	}
	return 0;
}