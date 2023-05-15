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
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
	int t, n;
    scanf("%d", &t);
    while (t--) { 
        cin >> n;
        vi a(n);
        f(i, 0, n, 1) cin >> a[i];
        vi b(n), c(n);
        f(i, 0, n, 1) b[i] = i + 1, c[i] = n - i;
        int fo = 0, fs = 0, so = 0;
        f(i, 0, n, 1) { 
            if (a[i] != b[i] && a[i] != c[i]) ++fs;
            else if (a[i] != b[i]) ++fo;
            else if (a[i] != c[i]) ++so;
        }
        int k = min(fo, so);
        fo -= k, so -= k;
        if (so == 0 && fo == 0) { 
            if (fs) cout << "Tie\n";
            else cout << "First\n";
        } else if (so == 0) { 
            if (fs < fo) cout << "Second\n";
            else cout << "Tie\n";
        } else { 
            if (fs <= so) cout << "First\n";
            else cout << "Tie\n";
        }
	}
	return 0;
}
