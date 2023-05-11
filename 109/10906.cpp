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

struct expr {
	string s1, s2;
	char op;
};

int main() {
	int t, n;
	string s1, s2, s3, ans, t1, t2;
	char op1, op2;
	cin >> t;
    f(k,1,t+1,1) { 
		cin >> n;
		map<string, expr> prod;
		f(i,0,n,1) { 
			cin >> s1 >> op1 >> s2 >> op2 >> s3;
			expr exp = {.s1 = s2, .s2 = s3, .op = op2};
			t1 = "", t2 = "";
			expr exprec1, exprec2;
			if (isalpha(exp.s1[0])) {
				exprec1 = prod[exp.s1];
				t1 = exprec1.s1 + exprec1.op + exprec1.s2;
			}
			if (isalpha(exp.s2[0])) {
				exprec2 = prod[exp.s2];
				t2 = exprec2.s1 + exprec2.op + exprec2.s2;
			}
			if (exp.op == '+') {
				if (t2 != "" && exprec2.op == '+') t2 = '(' + t2 + ')';
			} else {
				if (t1 != "" && exprec1.op == '+') t1 = '(' + t1 + ')';
				if (t2 != "") t2 = '(' + t2 + ')';
			}
			if (t1 != "") exp.s1 = t1;
			if (t2 != "") exp.s2 = t2;
			prod[s1] = exp;
			ans = ((t1=="")?exp.s1:t1)+exp.op+((t2=="")?exp.s2:t2);
		}
		cout << "Expression #" << k << ": " << ans << nl;
	}
	return 0;
}
