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

class UnionFind {
private: 
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        setSize.assign(n, 1);
        f(i, 0, n, 1) p.push_back(i);
        numSets = n;
    }

    int findSet(int i) { return ((p[i] == i) ? i : (p[i] = findSet(p[i]))); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }

    int getLargestSet() { return *max_element(setSize.begin(), setSize.end()); }
};

int main() {
    int c, r;
    while (cin >> c >> r) {
        if (!c && !r) break;
        map<string, int> animals;
        string s, t;
        f(i, 0, c, 1) {
            cin >> s;
            animals[s] = i;
        }
        UnionFind UF(c);
        f(i, 0, r, 1) {
            cin >> s >> t;
            UF.unionSet(animals[s], animals[t]);
        }

        cout << UF.getLargestSet() << "\n";
    }
    return 0;
}