#include <bits/stdc++.h>
using namespace std;

vector<int> d = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> d_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(int y, int c) {
    if ((c % 4 == 0 && y % 4 == 0) || (c % 4 != 0 && y % 4 == 0 && y > 0)) return 1;
    else return 0; 
}

void disp(vector<int> &inputs, int x, int y, int z) {
    if (inputs[x] < 10) cout << 0;
    cout << inputs[x] << " ";
    if (inputs[y] < 10) cout << 0;
    cout << inputs[y] << " ";
    if (inputs[z] < 10) cout << 0;
    cout << inputs[z] << "\n";
}

int isValid (int c, int y, int m, int z) {
    if (m == 0 || m > 12) return 0; 
    if (z == 0) return 0;
    if (isLeap(y, c)) {
        if (z <= d_leap[m - 1]) return 1;
        else return 0;
    } else {
        if (z <= d[m - 1]) return 1;
        else return 0;
    }
}

int main() {
    int t, c, p;
    vector<int> inputs(3);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> c >> inputs[0] >> inputs[1] >> inputs[2];
        p = 0;
        sort(inputs.begin(), inputs.end());
        if (isValid(c, inputs[0], inputs[1], inputs[2])) disp(inputs, 0, 1, 2);
        else if (isValid(c, inputs[0], inputs[2], inputs[1])) disp(inputs, 0, 2, 1);
        else if (isValid(c, inputs[1], inputs[0], inputs[2])) disp(inputs, 1, 0, 2);
        else if (isValid(c, inputs[1], inputs[2], inputs[0])) disp(inputs, 1, 2, 0);
        else if (isValid(c, inputs[2], inputs[0], inputs[1])) disp(inputs, 2, 0, 1);
        else if (isValid(c, inputs[2], inputs[1], inputs[0])) disp(inputs, 2, 1, 0);
        else cout << -1  << "\n";
    }
    return 0;
}