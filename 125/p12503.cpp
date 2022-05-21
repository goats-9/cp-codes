#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, pos;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        pos = 0;
        vector<int> ins(n);
        for (int j = 0; j < n; j++) {
            cin >> s;
            if (s == "LEFT") ins[j] = -1;
            else if (s == "RIGHT") ins[j] = -2;
            else {
                string p;
                int x;
                cin >> p >> x;
                ins[j] = ins[x - 1];
            }
            if (ins[j] == -1) pos--;
            else pos++;
        }
        cout << pos << "\n";
    }
    return 0;
}