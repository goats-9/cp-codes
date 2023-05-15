#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, b, h, w, p, c;
    while (cin >> n >> b >> h >> w) {
        c = b + 1;
        for (int i = 0; i < h; i++) {
            cin >> p;
            vector<int> a(w);
            int x = 0;
            for (int j = 0; j < w; j++) cin >> a[j];
            for (int j = 0; j < w; j++) {
                if (a[j] >= n) {
                    x = p*n;
                    break;
                }
            } 
            if (x > 0 && x <= min(b, c)) c = x;
        }
        if (c == b + 1) cout << "stay home\n";
        else cout << c << "\n";
    }
    return 0;
}