#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int main() {
    string s;
    vii freq_ctr(26);
    f(i, 0, 26, 1) freq_ctr[i] = {0, 25 - i};
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    f(i, 0, n, 1) {
        getline(cin, s);
        for (char x : s) {
            if (isupper(x)) ++freq_ctr[x - 65].first;
            else if (islower(x)) ++freq_ctr[x - 97].first;
        }
    }
    sort(freq_ctr.begin(), freq_ctr.end());
    for (int i = 25; i >= 0; i--) {
        if (freq_ctr[i].first != 0) {
            char x = 90 - freq_ctr[i].second;
            cout << x << " " << freq_ctr[i].first << "\n";
        } else break;
    }
    return 0;
}