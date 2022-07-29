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
#define MOD (int)1e9 + 7

int main() {
	int t, x, y, b, sb, sg;
    scanf("%d", &t);
    while (t--) { 
		priority_queue<int> blue, green;	
		cin >> b >> sg >> sb;
		vi field(b);
		f(i, 0, sg, 1) { 
			cin >> x;
			green.push(x);
		}
		f(i, 0, sb, 1) { 
			cin >> x;
			blue.push(x);
		}
		int i;
		while (!green.empty() && !blue.empty()) {
			i = 0;
			while (i < b) { 
				if (green.empty() || blue.empty()) break;
				x = green.top();
				y = blue.top();
				green.pop();
				blue.pop();
				field[i] = x - y;
				++i;
			}
			f(j, 0, i, 1) { 
				if (field[j] < 0) blue.push(-field[j]);
				else if (field[j] > 0) green.push(field[j]);
			}
		}
		if (green.empty()) { 
			if (blue.empty()) cout << "green and blue died\n";
			else { 
				cout << "blue wins\n";
				while (!blue.empty()) { 
					cout << blue.top() << "\n";
					blue.pop();
				}
			}
		} else { 
			cout << "green wins\n";
			while (!green.empty()) { 
				cout << green.top() << "\n";
				green.pop();
			}
		}
		if (t != 0) cout << "\n";
	}
	return 0;
}
