#include <bits/stdc++.h>
using namespace std;

int timediff(string t1, string t2) {
    return 3600*(10*(t2[0] - t1[0]) + t2[1] - t1[1]) + 60*(10*(t2[3] - t1[3]) + t2[4] - t1[4]);
}

int main() {
    string ws, we, ms, me;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> ws >> we >> ms >> me;
        cout << "Case " << i + 1 << ": ";
        if (timediff(we, ms) > 0 || timediff(me, ws) > 0) cout << "Hits Meeting\n";
        else cout << "Mrs Meeting\n"; 
    }
    return 0;
}