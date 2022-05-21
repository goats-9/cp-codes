#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, n) for(int i = 0; i < n; i++)

int main() {
    string s;
    while (getline(cin, s)) {
        if (cin.eof()) break;
        for (char x: s) {
            char y = x - 7;
            cout << y;
        }
        cout << "\n";
    }
    return 0;
}