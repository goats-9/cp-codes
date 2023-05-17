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

struct Cow {
    int a, t, id;
};

bool cmp1(const Cow &c1, const Cow &c2) {
    if (c1.a == c2.a) return c1.id < c2.id;
    return c1.a < c2.a;
}

int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");
    int n;
    fin >> n;
    V<Cow> cows(n);
    f(i,0,n,1) {
        fin >> cows[i].a >> cows[i].t;
        cows[i].id = i;
    }
    sort(all(cows), cmp1);
    auto cmp2 = [](Cow c1, Cow c2) {return c1.id > c2.id;};
    priority_queue<Cow, V<Cow>, decltype(cmp2)> cow_queue(cmp2);
    int ans = 0, i = 0, ct = 0;
    while (i < n && cows[i].a == cows[0].a) cow_queue.push(cows[i++]);
    while (!cow_queue.empty()) {
        Cow c = cow_queue.top(); cow_queue.pop();
        ct = max(ct, c.a);
        ans = max(ans, ct - c.a);
        ct += c.t;
        while (i < n && cows[i].a < ct) cow_queue.push(cows[i++]);
        if (i < n && cow_queue.empty()) {
            int k = 0;
            while (i + k < n && cows[i].a == cows[i+k].a) cow_queue.push(cows[i+k++]);
            i += k;
        }
    }
    fout << ans << nl;
    fin.close(), fout.close();
	return 0;
}
