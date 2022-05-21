#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

vector<string> A(1001);

string get_str(int d) {
    string ret = "";
    while (d != 0) {
        ret = char(d%10 + '0') + ret;
        d /= 10;
    }
    return ret;
}

string add(string x, string y) {
    int sx = x.size(), sy = y.size(), s, c = 0;
    string ret = "";
    f(i, 1, sy + 1, 1) {
        s = x[sx - i] - '0' + y[sy - i] - '0' + c;
        ret = char(s%10 + '0') + ret;
        c = s/10; 
    }
    f(i, sy + 1, sx + 1, 1) {
        s = int(x[sx - i] - '0') + c;
        ret = char(s%10 + '0') + ret;
        c = s/10;
    }
    if (c != 0) ret = char(c + '0') + ret;
    return ret;
}

string multiply(string x, string y) {
    int sx = x.size(), sy = y.size(), s, c;
    string ret, ans = "0";
    f(i, 1, sy + 1, 1) {
        ret = "";
        c = 0;
        f(j, 1, sx + 1, 1) {
            s = (x[sx - j] - '0')*(y[sy - i] - '0') + c;
            ret = char(s%10 + '0') + ret;
            c = s/10;
        }
        if (c != 0) ret = char(c + '0') + ret;
        f(j, 0, i - 1, 1) ret += '0';
        ans = add(ret, ans);
    }
    return ans;
}

int main() {
    A[0] = "1";
    A[1] = "1";
    f(i, 2, 1001, 1) A[i] = multiply(A[i - 1], get_str(i));
    int t;
    while (scanf("%d", &t) == 1) {
        printf("%d!\n%s\n", t, A[t].c_str());
    }
    return 0;
}