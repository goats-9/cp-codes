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
		int n;
		cin >> n;
		cout << "2\n";
		int i = 1;
		while (i <= n) {
			int k = i;
			while (k <= n) {  
				cout << k << " ";
				k *= 2;
			}
			i += 2;
		}
		cout << "\n";
	}
	return 0;
}
