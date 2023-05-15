#include <bits/stdc++.h>
using namespace std;
int main() {
    char c;
    int x = 0;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            if (x % 2 == 0) cout << "``";
            else cout << "\'\'";
            ++x;
        }
        else cout << c;
    }
    return 0;
}