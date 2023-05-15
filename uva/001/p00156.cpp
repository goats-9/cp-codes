#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

map<char, int> letters(string s) {
    map<char, int> ret;
    for (char ch = 'a'; ch <= 'z'; ++ch) ret[ch] = 0;
    int n = s.size();
    f(i, 0, n, 1) ++ret[tolower(s[i])]; 
    return ret;
}

int main() {
    string s;
    map<map<char, int>, pair<string, int>> words;
    while (cin >> s) {
        if (s == "#") break;
        map<char, int> distr = letters(s);
        if (words.find(distr) == words.end()) words[distr] = {s, 1};
        else ++words[distr].second;
    }
    vector<string> ans;
    for (auto it = words.begin(); it != words.end(); ++it) if ((it->second).second == 1) ans.push_back((it->second).first);
    sort(ans.begin(), ans.end());
    int n = ans.size();
    f(i, 0, n, 1) cout << ans[i] << endl;
    return 0;
}