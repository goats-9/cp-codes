#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)
#define F 1000000/(24*3600.00)

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        double req_spd = F*(double(abs(z))/x);
        if (z <= 0 || (int)req_spd == 0) printf("Add %d tons\n", int(req_spd));
        else printf("Remove %d tons\n", int(req_spd));
    }
    return 0;
}