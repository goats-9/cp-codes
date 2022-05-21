#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    int t;
    string s;
    cin >> t;
    cin.ignore(1, '\n');
    f(i, 0, t, 1) {
        stack<char> stk;
        getline(cin, s);
        for (char x : s) {
            if (stk.empty()) stk.push(x);
            else {
                if ((x == ')' && stk.top() == '(') || (x == ']' && stk.top() == '[')) stk.pop();
                else stk.push(x);
            }
        }
        if (stk.empty()) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}