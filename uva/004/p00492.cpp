#include <bits/stdc++.h>
using namespace std;

vector<char> vow = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

string toPig(string &w) {
    if (find(vow.begin(), vow.end(), w[0]) == vow.end()) return w.substr(1, w.size()) + w[0] + "ay";
    else return w + "ay";
}

int main() {
    string x;
    string w = "";
    while(getline(cin, x)) {
        for (char z: x) {
            if ((z >= 'a' && z <= 'z') || (z >= 'A' && z <= 'Z')) {
                w += z;
            } else {
                if (w != "") {
                    cout << toPig(w);
                    w = "";
                } 
                cout << z;
            }
        }
        if (w != "") {
            cout << toPig(w);
            w = "";
        }
        cout << "\n";
    }
    return 0;
}