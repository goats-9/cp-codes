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
    M<int, int> val;
    val[22] = 1;
    val[3] = 3;
    val[23] = 5;
    val[32] = 5;
    val[4] = 10;
    val[5] = 100; 
    while (1) {
        vi a(13), vals(5), c(13,4);
        V<string> cards(5);
        f(i,0,5,1) {
            cin >> cards[i];
            if (cards[i] == "#") return 0;
            char ch = cards[i][0];
            int num;
            if (isdigit(ch)) num = ch - '1';
            else if (ch == 'A') num = 0;
            else if (ch == 'T') num = 9;
            else if (ch == 'J') num = 10;
            else if (ch == 'Q') num = 11;
            else if (ch == 'K') num = 12;
            c[num]--;
            ++a[num];
            vals[i] = num;
        }
        vi b = a;
        int r = 0, s = -1, rn = 0;
        double cur = -1;
        while (1) {
            r = -1;
            f(i,0,13,1) {
                int k = 1;
                while (b[(i + k - 1)%13] && b[(i + k)%13]) k++;
                if (k > r) r = k, s = i;
            }
            if (r > 1) {
                rn = 10*rn + r;
                f(i,s,s+r,1) --b[i%13];
            } else break;
        }
        cur = max(cur, ((val.find(rn) == val.end())?0:val[rn]) - 1.0);
        int idx = -1;
        f(i,0,5,1) {
            int tmp = vals[i];
            --a[tmp];
            int nxt = 0;
            f(j,0,13,1) {
                b = a;
                if (c[j]) ++b[j];
                else continue;
                int r = 0, s = -1, rn = 0;
                while (1) {
                    r = -1;
                    f(m,0,13,1) {
                        int k = 1;
                        while (b[(m + k - 1)%13] && b[(m + k)%13]) k++;
                        if (k > r) r = k, s = m;
                    }
                    if (r > 1) {
                        rn = 10*rn + r;
                        f(m,s,s+r,1) --b[m%13];
                    } else break;
                }
                nxt += c[j]*((val.find(rn) == val.end())?0:val[rn]);
            }
            if (cur < nxt/47.0 - 2.0) cur = nxt/47.0 - 2.0, idx = i;
            ++a[tmp];
        }
        if (idx == -1) cout << "Stay\n";
        else cout << "Exchange " << cards[idx] << "\n";
    }
	return 0;
}
