#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = a; i < b; i = i + j)

int isUgly(int n, vi &ugly) {
    f(i, 1, n/2 + 1, 1) if ((find(ugly.begin(), ugly.end(), i) != ugly.end()) && n % i) return 0;
    return 1;
}

int main() {
    vi ugly;
    ugly.push_back(1);
    int t2 = 0, t3 = 0, t5 = 0, t7 = 0;
    f(i, 1, 5842, 1) {
        while (ugly[t2]*2 <= ugly[i - 1]) ++t2;
        while (ugly[t3]*3 <= ugly[i - 1]) ++t3;
        while (ugly[t5]*5 <= ugly[i - 1]) ++t5;
        while (ugly[t7]*7 <= ugly[i - 1]) ++t7;
        int t = ugly[t2]*2;
        if (ugly[t3]*3 < t) t = ugly[t3]*3;
        if (ugly[t5]*5 < t) t = ugly[t5]*5;
        if (ugly[t7]*7 < t) t = ugly[t7]*7;
        ugly.push_back(t); 
    }
    int n;
    while (cin >> n) {
        if (!n) break;
        cout << "The " << n;
        if (n % 10 == 1 && n % 100 != 11) cout << "st";
        else if (n % 10 == 2 && n % 100 != 12) cout << "nd";
        else if (n % 10 == 3 && n % 100 != 13) cout << "rd";
        else cout << "th";
        cout << " humble number is " << ugly[n - 1] << ".\n";
    }
    return 0;
}