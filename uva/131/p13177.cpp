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
typedef tuple<double, int, int> dii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)
#define pb push_back

int main() {
    int p, n;
    while (scanf("%d %d", &p, &n) == 2) {
        priority_queue<dii> pq;
        int x;
        f(i, 0, n, 1) {
            scanf("%d", &x);
            pq.push({x/(1.0), x, 1});
        }   
        p -= n;
        while (p--) {
            auto [r, num, d] = pq.top(); pq.pop();
            pq.push({num/(d + 1.0), num, d + 1});
        }
        printf("%d\n", int(ceil(get<0>(pq.top()))));
    }
    return 0;
}