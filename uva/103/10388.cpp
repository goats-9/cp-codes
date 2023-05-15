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
	int t;
	cin >> t;
    f(i,0,t,1) { 
        if (i) cout << nl;
        string jane, john;
        stack<char> jane_up, jane_down, john_up, john_down;
        cin >> jane >> john;
        reverse(all(jane)), reverse(all(john));
        for (char &c: jane) jane_down.push(c);
        for (char &c: john) john_down.push(c);
        int ctr = 0;
        stringstream ss;
        while (ctr++ < 1000) {
            char jane_card = jane_down.top(), john_card = john_down.top();
            jane_down.pop(), john_down.pop();
            jane_up.push(jane_card), john_up.push(john_card);
            if (jane_card == john_card) {
                string tmp = "";
                ss << "Snap! for ";
                if (random()/141%2) {
                    ss << "John: ";
                    while (!jane_up.empty()) {
                        char x = jane_up.top(); jane_up.pop();
                        tmp = tmp + x;
                    }
                    while (!john_up.empty()) {
                        char x = john_up.top();
                        john_up.pop();
                        tmp = tmp + x;
                    }
                    ss << tmp << nl;
                    reverse(all(tmp));
                    for (char &x : tmp) john_up.push(x);
                } else {
                    ss << "Jane: ";
                    while (!john_up.empty()) {
                        char x = john_up.top(); john_up.pop();
                        tmp = tmp + x;
                    }
                    while (!jane_up.empty()) {
                        char x = jane_up.top();
                        jane_up.pop();
                        tmp = tmp + x;
                    }
                    ss << tmp << nl;
                    reverse(all(tmp));
                    for (char &x : tmp) jane_up.push(x);
                }
            }
            if (john_down.empty()) {
                if (john_up.empty()) {
                    ss << "Jane wins.\n";
                    break;
                } else {
                    while (!john_up.empty()) {
                        char x = john_up.top();
                        john_up.pop();
                        john_down.push(x);
                    }
                }
            }
            if (jane_down.empty()) {
                if (jane_up.empty()) {
                    ss << "John wins.\n";
                    break;
                } else {
                    while (!jane_up.empty()) {
                        char x = jane_up.top();
                        jane_up.pop();
                        jane_down.push(x);
                    }
                }
            }
        }
        if (ctr >= 1000) cout << "Keeps going and going...\n";
        else cout << ss.str();
	}
	return 0;
}
