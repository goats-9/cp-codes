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

int main() {
	int t;
    scanf("%d", &t);
    while (t--) { 
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a && b && c && d) cout << "2\n";
		else if (!a && !b && !c && !d) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}