#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(10);
    s[0] = " "; 
    s[1] = ".,?\""; 
    s[2] =  "abc"; 
    s[3] = "def"; 
    s[4] = "ghi"; 
    s[5] = "jkl"; 
    s[6] = "mno"; 
    s[7] = "pqrs"; 
    s[8] = "tuv"; 
    s[9] ="wxyz";
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int j = 0; j < n; j++) cin >> a[j];
        for (int j = 0; j < n; j++) cin >> b[j];
        for (int j = 0; j < n; j++) cout << s[a[j]][b[j] - 1];
        cout << "\n";
    }
    return 0;
}