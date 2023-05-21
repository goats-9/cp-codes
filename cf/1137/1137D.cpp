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
    int n;
    string s;
    cout << "next 0" << endl;
    cin >> n;
    f(i,0,n,1) cin >> s;
    cout << "next 0 1" << endl;
    cin >> n;
    f(i,0,n,1) cin >> s;
    while (n != 2) {
        cout << "next 0" << endl;
        cin >> n;
        f(i,0,n,1) cin >> s;
        cout << "next 0 1" << endl;
        cin >> n;
        f(i,0,n,1) cin >> s;
    }
    cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    cin >> n;
    f(i,0,n,1) cin >> s;
    while (n != 1) {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        cin >> n;
        f(i,0,n,1) cin >> s;
    }
    cout << "done" << endl;
	return 0;
}
