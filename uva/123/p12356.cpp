#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, s, l, r;
    while (cin >> s >> b) {
        if (s == 0 && b == 0) break;
        set<int> army;
        for (int i = 0; i < s; i++) army.insert(army.end(), i + 1);
        for (int i = 0; i < b; i++) {
            cin >> l >> r;
            auto left = army.find(l);
            auto right = army.find(r);
            if (left != army.begin()) {
                --left;
                cout << *(left) << " ";
                ++left;
            } else cout << "* ";
            if (++right != army.end()) {
                cout << *(right) << "\n";
            } else cout << "*\n";
            army.erase(left, right);
        }
        cout << "-\n";
    }
    return 0;
}