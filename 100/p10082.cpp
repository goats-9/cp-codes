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
    map<char, char> dec;
    string a = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.", b = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    int n = a.size();
    f(i, 0, n, 1) dec[b[i]] = a[i];
    string in;
    while (getline(cin, in)) {
        if (cin.eof()) break;
        for (char x : in) {
            if (x != ' ') cout << dec[x];
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}