#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD (int)1e9 + 7

int main() {
    int t, n;
    cin >> t;
    f(i,1,t+1,1) {
        cin >> n;
        cout << "Case #" << i << ": " << n << " is ";
        int m = n;
        set<int> nums;
        nums.insert(n);
        while (1) {
            int k = 0;
            while (m) {
                k += (m%10)*(m%10);
                m /= 10;
            }
            if (k == 1) {cout << "a Happy number.\n"; break;}
            else if (nums.find(k) != nums.end()) {cout << "an Unhappy number.\n"; break;}
            nums.insert(k);
            m = k;
        }
    }
}
