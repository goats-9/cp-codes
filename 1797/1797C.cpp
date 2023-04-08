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
	int t, n, m, resp, sx, sy;
	cin >> t;
    while (t--) { 
        cin >> n >> m;
        cout << "? 1 1" << endl;
        cin >> resp;
        if (n >= m) sx = resp, sy = 0;
        else sx = 0, sy = resp;
        cout << "? " << sx+1 << " " << sy+1 << endl;
        cin >> resp;
        if (sx == 0) {
            if (resp < sy) sx += resp;
            else {
                sx = sy; 
                cout << "? " << sx+1 << " " << sy+1 << endl;
                cin >> resp;
                sy -= resp;
            }
        } else {
            if (resp < sx) sy += resp;
            else {
                sy = sx;
                cout << "? " << sx+1 << " " << sy+1 << endl;
                cin >> resp;
                sx -= resp;
            }
        }
        cout << "! " << sx+1 << ' ' << sy+1 << endl;
	}
	return 0;
}
