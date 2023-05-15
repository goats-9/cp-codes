#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int isPal(string &in) {
    int n = in.size();
    f(i, 0, ceil(n/2), 1) if (in[i] != in[n - i - 1]) return 0;
    return 1;
}

int isMirr(string &in, map<char, char> &char_rev) {
    int n = in.size();
    f(i, 0, n, 1) if (char_rev.find(in[i]) == char_rev.end()) return 0;
    f(i, 0, ceil(n/2) + 1, 1) if (in[i] != char_rev[in[n - 1 - i]]) return 0;
    return 1;
}

int main() {
    map<char, char> char_rev;
    vector<char> a = {'A', 'E', 'H', 'I', 'J', 'L', 'M', 'O', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5', '8'};
    vector<char> b = {'A', '3', 'H', 'I', 'L', 'J', 'M', 'O', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z', '8'};
    int x = a.size();
    f(i, 0, x, 1) char_rev[a[i]] = b[i];
    string in;
    while (cin >> in) {
        int p = isPal(in), q = isMirr(in, char_rev);
        cout << in << " -- is ";
        if (p && q) cout << "a mirrored palindrome.\n";
        else if (!p && q) cout << "a mirrored string.\n";
        else if (p && !q) cout << "a regular palindrome.\n";
        else cout << "not a palindrome.\n";
        cout << "\n";
    }
    return 0;
}