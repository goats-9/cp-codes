#include <bits/stdc++.h>
using namespace std;

int find_id(vector<pair<char, int>> &vec, int &id) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        if (vec[i].second == id) return i;
    }
    return -1;
}

int main() {
    int t, id, val;
    char ch;
    cin >> t;
    for (int i = 0; i < t; i++) {
        map<int, map<int, char>> req;
        map<int, int> blk;
        int x, y;
        while (cin >> ch) {
            if (ch == '#') break;
            x = 0, y = 0;
            cin >> id >> val;
            if (blk.find(id) == blk.end()) blk[id] = 1;
            if (blk[id] == 0) cout << "IGNORED\n";
            else {
                if (req.find(val) != req.end()) {
                    for (auto it : req[val]) {
                        if (it.first != id) { 
                            if (it.second == 'X' || ch == 'X') {
                                cout << "DENIED\n";
                                blk[id] = 0;
                                x = 1;
                            }
                            if (x == 1) break;
                        } else y = 1;
                    }
                    if (x == 0) {
                        cout << "GRANTED\n";
                        if (y == 0) req[val][id] = ch;
                        else if (ch == 'X') req[val][id] = 'X';
                    }
                } else {
                    cout << "GRANTED\n";
                    req[val][id] = ch;
                }
            }
        }
        if (i != t - 1) cout << "\n";
    }
    return 0;
}