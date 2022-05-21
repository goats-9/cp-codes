#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

typedef struct {
    string elem;
    Link *next;
} Link;

int main() {
    string x, w = "";
    int n;
    Link *head = NULL, prev = NULL;
    while(getline(cin, x)) {
        if (x == "0") break;
        n = x.size();
        int i = 0;
        while (i < n) {
            if (isalpha(x[i])) w += x[i];
            else if (w != "") {
                prev->elem = w;
                prev->next = head;
            }
            if (x[i] >= '1' && x[i] <= '9') {
                int j, y = 0;
                for (j = i; j < n && x[j] >= '0' && x[j] <= '9'; j++) y = 10*y + (x[j] - '0');
                i = j - 1;
                vector<string> rm(y);
                for (j = y - 1; j >= 0; j--) {
                    rm[j] = stk.top();
                    stk.pop();
                } 
                cout << rm[0];
                for (j = 1; j < y; j++) stk.push(rm[j]);
                stk.push(rm[0]);
            } else cout << x[i];
            ++i;
        }
        cout << "\n";
    }
    return 0;
}