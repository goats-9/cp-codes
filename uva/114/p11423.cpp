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
#define LSOne(i) (i & (-i))
#define MAXADDR 1<<24
#define MAXCACHE 30
#define MAXREF 10000000

class FenTree {
private: 
    vi ft;
public:
    FenTree(vi &A) { 
        int n = A.size();
        ft.assign(n + 1, 0);
        build(A); 
    }   

    FenTree(int N) { ft.assign(N + 1, 0); }
    
    void build(vi &A) {
        int m = A.size();
        f(i, 1, m + 1, 1) {
            ft[i] += A[i];
            if (i + LSOne(i) <= m) ft[i + LSOne(i)] += ft[i];
        } 
    }
    
    int rsq(int j) {
        int sum = 0;
        while (j != 0) {
            sum += ft[j];
            j -= LSOne(j);
        }
        return sum;
    }
    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

    void update(int i, int v) {
        while (i < int(ft.size())) {
            ft[i] += v;
            i += LSOne(i);
        }
    }
};

vi miss, cache(MAXCACHE), stamp(MAXADDR);
int N, t = 0;
FenTree F(MAXREF);

void process(int addr) {
    int &st = stamp[addr];
    if (st == 0) f(i, 0, N, 1) ++miss[i];
    else {
        int c = F.rsq(st, t);
        for (int i = 0; i < N && c > cache[i]; i++) ++miss[i];
        F.update(st, -1); 
    }
    st = ++t;
    F.update(st, 1);
}

int main() {
    cin >> N;
    miss.assign(N, 0);
    f(i, 0, N, 1) cin >> cache[i];
    string s;
    while (cin >> s) {
        if (s == "END") break;
        if (s == "ADDR") {
            int x;
            cin >> x;
            process(x);
        } else if (s == "RANGE") {
            int b, y, n;
            cin >> b >> y >> n;
            f(i, 0, n, 1) process(b + y*i);
        } else {
            f(i, 0, N, 1) {
                cout << miss[i];
                if (i == N - 1) cout << "\n";
                else cout << " ";
            }
            miss.assign(N, 0);
        }
    }
    return 0;
}