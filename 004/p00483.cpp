#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

void rev(string &w) {
    int n = w.size();
    for (int i = n - 1; i >= 0; i--) cout << w[i];
}

int main() {
    string s;
    while(getline(cin, s)) {
        if (cin.eof()) break;
        string w = "";
        for (char x : s) {
            if (x == ' ') {
                rev(w);
                cout << " ";
                w = "";
            } else w += x;
        }
        rev(w);
        cout << "\n";
    }
    return 0;
}