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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int n;
		cin >> n;
		vi a(n);
		mii fq;
		f(i, 0, n, 1) cin >> a[i];
		int i;
		for (i = n - 1; i >= 0; i--) { 
			if (fq.find(a[i]) != fq.end()) break;
			else fq[a[i]] = 1;
		}
		cout << i + 1 << "\n";
	}
	return 0;
}
