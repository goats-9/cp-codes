#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int x(int n) {
    if (n <= 100) return x(x(n + 11));
    else return n - 10;
}

int main() {
    int n;
    while (cin >> n) {
        if (!n) break;
        cout << "f91(" << n << ") = " << x(n) << "\n";
    }
    return 0;
}