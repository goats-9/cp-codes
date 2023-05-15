#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rot90(vector<vector<char>> &a) {
    int n = a.size();
    vector<vector<char>> a_rot(n, vector<char> (n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a_rot[j][n - 1 - i] = a[i][j];
    return a_rot;
}

vector<vector<char>> ref(vector<vector<char>> &a) {
    int n = a.size();
    vector<vector<char>> a_ref(n, vector<char> (n));
    for (int i = 0; i < n; i++) a_ref[i] = a[n - i - 1];
    return a_ref;
}

int main() {
    int n, ctr = 1, x;
    string p, q;
    while (cin >> n) {
        x = 1;
        vector<vector<char>> a(n, vector<char> (n)), b(n, vector<char> (n));
        for (int i = 0; i < n; i++) {
            cin >> p >> q;
            for (int j = 0; j < n; j++) a[i][j] = p[j], b[i][j] = q[j];
        }
        cout << "Pattern " << ctr << " was ";
        if (a == b) {
            cout << "preserved.\n";
            x = 0;
        }
        else if (x) {
            a = rot90(a);
            if (x && a == b) {
                cout << "rotated 90 degrees.\n";
                x = 0;
            }
            a = rot90(a);
            if (x && a == b) {
                cout << "rotated 180 degrees.\n";
                x = 0;
            }
            a = rot90(a);
            if (x && a == b) {
                cout << "rotated 270 degrees.\n";
                x = 0;
            }
            a = rot90(a);
        }
        if (x) {
            a = ref(a);
            if (x && a == b) {
                cout << "reflected vertically.\n";
                x = 0;
            }
            a = rot90(a);
            if (x && a == b) {
                cout << "reflected vertically and rotated 90 degrees.\n";
                x = 0;
            }
            a = rot90(a);
            if (x && a == b) {
                cout << "reflected vertically and rotated 180 degrees.\n";
                x = 0;
            }
            a = rot90(a);
            if (x && a == b) {
                cout << "reflected vertically and rotated 270 degrees.\n";
                x = 0;
            }
            a = rot90(a);
        }
        if (x) cout << "improperly transformed.\n";
        ++ctr; 
    }
    return 0;
}