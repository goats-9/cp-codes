#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> qtod;
    string q = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
    string d = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";
    int n = q.size();
    for (int i = 0; i < n; i++) qtod[q[i]] = d[i];
    string s;
    while (getline(cin, s)) {
        for (char x: s) cout << qtod[x];
        cout << "\n";
    }
    return 0;
}