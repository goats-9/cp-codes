#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    string s, w;
    while(getline(cin, s)) {
        if (cin.eof()) break;
        int ctr = 0;
        w = "";
        for (char x : s) {
            if (isalpha(x)) w += x;
            else if (w != "") {
                ++ctr;
                w = "";
            }
        }
        if (w != "") ++ctr;
        cout << ctr << "\n";
    }
    return 0;
}