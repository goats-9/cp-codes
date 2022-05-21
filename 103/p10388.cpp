#include <bits/stdc++.h>
using namespace std;

int end(string &a, string &a_up, string &b, string &b_up) {
    if ((a == "" && a_up == "") || (b == "" && b_up == "")) return 1;
    else return 0;
}

string rev(string &x) {
    string y = "";
    int n = x.size();
    for (int i = n - 1; i >= 0; i--) y += x[i];
    return y;
}

int main() {
    int t, ctr;
    cin >> t;
    string john, jane, john_up, jane_up;
    for (int i = 0; i < t; i++) {
        ctr = 0;
        cin >> jane >> john;
        john_up = "", jane_up = "";
        while(!end(jane, jane_up, john, john_up) && ctr < 1000) {
            if (jane == "") {
                jane = rev(jane_up);
                jane_up = "";
            }
            if (john == "") {
                john = rev(john_up);
                john_up = "";
            }
            john_up = john[0] + john_up;
            jane_up = jane[0] + jane_up;
            if (john[0] == jane[0]) {
                if (rand()/141%2 == 0) {
                    jane_up = john_up + jane_up;
                    john_up = "";
                    cout << "Snap! for Jane: " << jane_up << "\n";
                } else {
                    john_up = jane_up + john_up;
                    jane_up = "";
                    cout << "Snap! for John: " << john_up << "\n";
                }
            }
            john = john.substr(1, john.size());
            jane = jane.substr(1, jane.size());
            cout << john + ' ' + jane + '\n' + john_up + ' ' + jane_up << "\n";
            ++ctr;
        }
        if (ctr >= 1000) cout << "Keeps going and going ...\n";
        else {
            if (jane == "" && jane_up == "") cout << "John wins.\n";
            else cout << "Jane wins.\n";
        }
        cout << "\n";
    }
    return 0;
}