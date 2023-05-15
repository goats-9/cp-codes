#include <bits/stdc++.h>
using namespace std;

void dispFig(vector<string> &img, int &wl, int &wr, int &pred_state) {
    if (wl == wr) {
        for (int i = 0; i < 7; i++) {
            cout << img[(i - 1 + pred_state + 7) % 7].substr(0, 9) << img[(i + 1 - pred_state + 7) % 7].substr(9, 18) << "\n";
        }
    } else if (wl < wr) {
        for (int i = 0; i < 7; i++) {
            cout << img[(i + pred_state + 7) % 7].substr(0, 9) << img[(i - pred_state + 7) % 7].substr(9, 18) << "\n"; 
        }
    } else {
        for (int i = 0; i < 7; i++) {
            cout << img[(i - 2 + pred_state + 7) % 7].substr(0, 9) << img[(i + 2 - pred_state + 7) % 7].substr(9, 18) << "\n";
        }
    }
}

int weight(char x) {
    int w = 0;
    while (x != 0) {
        if (x % 2) w += 500;
        else w += 250;
        x /= 2;
    }
    return w;
}

int main() {
    vector<string> img(7);
    string s;
    int t, pred_state, wl, wr, chk;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ":\n";
        wl = 0, wr = 0, chk = 0;
        for (int j = 0; j < 7; j++) cin >> img[j];
        cin >> s;
        if (img[0][3] == '/') pred_state = 0;
        else if (img[0][13] == '/') pred_state = 2;
        else pred_state = 1;
        if (pred_state == 0) {
            for (int k = 1; img[3][k] >= 'A' && img[3][k] <= 'Z'; k++) wl += weight(img[3][k]);
            for (int k = 11; img[5][k] >= 'A' && img[5][k] <= 'Z'; k++) wr += weight(img[5][k]);
            if (wl < wr) chk = 1;
        } else if (pred_state == 2) {
            for (int k = 1; img[5][k] >= 'A' && img[5][k] <= 'Z'; k++) wl += weight(img[5][k]);
            for (int k = 11; img[3][k] >= 'A' && img[3][k] <= 'Z'; k++) wr += weight(img[3][k]);
            if (wl > wr) chk = 1;
        } else {
            for (int k = 1; img[4][k] >= 'A' && img[4][k] <= 'Z'; k++) wl += weight(img[4][k]);
            for (int k = 11; img[4][k] >= 'A' && img[4][k] <= 'Z'; k++) wr += weight(img[4][k]);
            if (wl == wr) chk = 1;
        }
        if (chk) cout << "The figure is correct.\n";
        else dispFig(img, wl, wr, pred_state);
    }
    return 0;
}