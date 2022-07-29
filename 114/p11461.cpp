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
	int x[100010];
	int a, b, ctr = 1, i = 1;
	while (ctr <= 100000) {
		x[ctr] = x[ctr - 1];
		if (i*i == ctr) {++i; x[ctr]++;}
		ctr++;
	}
	while (cin >> a >> b && a) { 
		cout << x[b] - x[a - 1] << "\n";
	} 
	return 0;
}
