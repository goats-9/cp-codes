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
	int t, n, r;
	cin >> t;
    while (t--) { 
        cin >> n;
        cout << "+ " << n + 1 << endl; cin >> r;
        cout << "+ " << n << endl; cin >> r;
        V<pii> dis;
        f(i,2,n+1,1) {
            cout << "? 1 " << i << endl;
            cin >> r;
            dis.pb(pii(r,i));
        }
        sort(all(dis));
        deque<pii> ord;
        ord.push_front(pii(0,1));
        int i = 0, sz = dis.size();
        while (i < sz) {
            pii front = ord.front();
            if (i < sz - 1 && dis[i].first == dis[i+1].first) {
                cout << "? " << front.second << ' ' << dis[i].second << endl; cin >> r;
                if (r == 1) {ord.push_front(dis[i]); ord.push_back(dis[i+1]);}
                else {ord.push_front(dis[i+1]); ord.push_back(dis[i]);}
                i += 2;
            } else {
                cout << "? " << front.second << ' ' << dis[i].second << endl; cin >> r;
                if (r == 1) ord.push_front(dis[i]);
                else ord.push_back(dis[i]);
                i++;
            }
        }
        vi seq;
        while (!ord.empty()) {
            pii front = ord.front(); ord.pop_front();
            seq.pb(front.second);
        }
        vi a(n), p1(n), p2(n);
        int ctr = 1;
        f(i,0,n,2) {
            a[i] = n + 1 - ctr;
            if (i + 1 < n) a[i+1] = ctr;
            ctr++;
        }
        f(i,0,n,1) p1[seq[i]-1] = a[i];
        reverse(all(a));
        f(i,0,n,1) p2[seq[i]-1] = a[i];
        cout << "!";
        f(i,0,n,1) cout << ' ' << p1[i];
        f(i,0,n,1) cout << ' ' << p2[i];
        cout << endl; cin >> r;
	}
	return 0;
}
