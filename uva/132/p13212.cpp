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
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7
#define INF (int)1e9
#define N (int)1e6 + 10

ll merge(vi &A, int p, int q, int r) { 
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1], R[n2 + 1];
	f(i, 1, n1 + 1, 1) L[i] = A[p + i - 1];
	f(j, 1, n2 + 1, 1) R[j] = A[q + j];
	L[n1 + 1] = R[n2 + 1] = INF;
	int i = 1, j = 1, fl = 0;
	ll inv = 0;
	f(k, p, r + 1, 1) { 
		if (!fl && R[j] < L[i]) inv += (n1 - i + 1), fl = 1;
		if (L[i] <= R[j]) A[k] = L[i], ++i;
		else A[k] = R[j], ++j, fl = 0;
	}
	return inv;
}

ll mergesort(vi &A, int p, int r) { 
	ll inv = 0;
	if (p < r) { 
		int q = (p+r)/2;
		inv += mergesort(A, p, q);
		inv += mergesort(A, q + 1, r);
		inv += merge(A, p, q, r);
	}
	return inv;
}

int main() {
	int n;
	while (cin >> n && n) { 
		vi A(n + 1, 0);
		f(i, 1, n + 1, 1) cin >> A[i];
		cout << mergesort(A, 1, n) << "\n";
	} 
	return 0;
}
