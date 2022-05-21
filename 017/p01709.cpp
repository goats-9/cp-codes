#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main() {
    int p, a, b, c, d, n;
    while (cin >> p >> a >> b >> c >> d >> n) {
        vector<double> s(n);
        for (int i = 0; i < n; i++) {
            s[i] = p*(sin((double)a*(i + 1) + b) + cos((double)c*(i + 1) + d) + 2);
        }
        double far = 0, here = 0;
        for (int i = 0; i < n - 1; i++) {
            here = min(0.0, here + (s[i + 1] - s[i]));
            far = min(far, here);
        }
        printf("%.6f\n", abs(far));
    }
    return 0;
}