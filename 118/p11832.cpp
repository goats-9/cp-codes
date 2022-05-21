#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define MAXF 32768
#define MAXN 64

int n, f, memo[MAXN][MAXF], sign[2][MAXN], trans[MAXN];

bool solve(int id, int val) {
	if (id == n) return (val == f);
	if (memo[id][val + 16000] != -1) return (memo[id][val + 16000] == 1);
	bool sub = false, add = false;
	if (val - trans[id] + 16000 >= 0) sub = solve(id + 1, val - trans[id]);
	if (val + trans[id] + 16000 < MAXF) add = solve(id + 1, val + trans[id]);
	if (sub) sign[1][id] = 1;
	if (add) sign[0][id] = 1;
	return memo[id][val + 16000] = (sub || add) ? 1 : 0;
}

int main() {
	while (scanf("%d %d", &n, &f) == 2 && n) {
		for (int i = 0; i < n; i++)	scanf("%d", &trans[i]);
		memset(sign, 0, sizeof(sign));
		memset (memo, -1, sizeof(memo));
		bool ans = solve(0, 0);
		if (!ans) printf("*\n");
		else {
			for(int i = 0; i < n; i++) {
				if (sign[0][i] && sign[1][i]) printf("?");
				else if (sign[0][i]) printf("+");
				else printf("-");
			}
			printf("\n");
		}
	}
	return 0;
}
