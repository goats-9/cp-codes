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
		int n, m;
		cin >> n >> m;
		vi prof(m + 1);
		f(i, 0, m, 1) cin >> prof[i + 1];
		vi time(n + 1);
		int min = 0, max = 0;
		f(i, 0, m, 1) {
			int y = prof[i + 1];
			if (max - min < 2) { 
				if (time[y] < min) time[y] = min;
				++time[y];
				if (time[y] > max) max = time[y];
			} else { 
				min += 2;
			}
		}
		cout << max << "\n";
	}
	return 0;
}
