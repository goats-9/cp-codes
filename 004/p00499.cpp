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

int main() {
    string s;
    while (getline(cin, s)) {
        map<char, int> dist;
        for (char z : s) {
            if (isalpha(z)) {
                if (dist.find(z) == dist.end()) dist[z] = 1;
                else ++dist[z];
            }
        }
        vector<pair<int, char>> vec;
        for (auto it = dist.begin(); it != dist.end(); ++it) {
            vec.push_back({it->second, it->first});
        }
        string out = "";
        sort(vec.rbegin(), vec.rend());
        int n = vec.size(), k = vec[0].first;
        f(i, 0, n, 1) {
            if (vec[i].first == k) out = vec[i].second + out;
            else break;
        }
        cout << out << " " << k << endl;
        if (cin.eof()) break;
    }
    return 0;
}