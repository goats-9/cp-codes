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

int main() {
	int t;
	cin >> t;
	cin.ignore(1);
	string inp;
	getline(cin, inp);
	f(k,0,t,1) {
		vi reg(10), ram(1000);
		if (k) cout << nl;
		int addr = 0;
		while (getline(cin, inp) && inp != "") ram[addr++] = atoi(inp.c_str());
		addr = 0;
		int ctr = 0;
		while (1) {
			++ctr;
			int num = ram[addr];
			int c = num % 10;
			num /= 10;
			int b = num % 10;
			num /= 10;
			int a = num % 10;
			bool br = false;
			switch (a) {
				case 0:
					if (!reg[c]) addr = (addr + 1)%1000;
					else addr = reg[b];
					break;
				case 1:
					br = true;
					break;
				case 2:
					reg[b] = c;
					addr = (addr + 1)%1000;
					break;
				case 3:
					reg[b] = (reg[b] + c) % 1000;
					addr = (addr + 1)%1000;
					break;
				case 4:
					reg[b] = (reg[b] * c) % 1000;
					addr = (addr + 1)%1000;
					break;
				case 5:
					reg[b] = reg[c];
					addr = (addr + 1)%1000;
					break;
				case 6:
					reg[b] = (reg[b] + reg[c]) % 1000;
					addr = (addr + 1)%1000;
					break;
				case 7:
					reg[b] = (reg[b] * reg[c]) % 1000;
					addr = (addr + 1)%1000;
					break;
				case 8:
					reg[b] = ram[reg[c]];
					addr = (addr + 1)%1000;
					break;
				case 9:
					ram[reg[c]] = reg[b];
					addr = (addr + 1)%1000;
					break;
				default:
					break;
			}
			if (br) break;
		}
		cout << ctr << nl;
	}
	return 0;
}
