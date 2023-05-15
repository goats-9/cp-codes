#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    vi a;
    int n;
    int x = 0;
    while (cin >> n) {
        a.push_back(n);
        sort(a.begin(), a.end());
        ++x;
        if (x % 2) cout << a[x/2] << "\n";
        else cout << (a[x/2] + a[x/2 - 1])/2 << "\n";
    }
    return 0;
}