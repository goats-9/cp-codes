#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    string s, t;
    int nt, nq, ns, nt_q;
    cin >> x;
    for (int i = 0; i < x; i++) {  
        cout << "Case " << i + 1 << ": ";
        cin >> s >> t;
        nt = 0;
        nq = 0;
        ns = 0;
        nt_q = 0;
        int n = s.size();
        for (int j = 0; j < n; j++) {
            if (s[j] != t[j]) {
                if (s[j] == '?') {
                    ++nq;
                    if (t[j] == '1') ++nt_q;
                }
                else if (s[j] == '1') ++ns;
                else ++nt;
            }
        } 
        if (ns > nt + nt_q) cout << -1 << "\n";
        else cout << nq + max(nt, ns) << "\n";
    }
    return 0;
}