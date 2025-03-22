#include <stdio.h>
#include <stdlib.h>
#define N	200000
int max(int a, int b) { return a > b ? a : b; }
int *ej[N], eo[N];
void append(int i, int j) {
	int o = eo[i]++;
	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}
int ll[N], rr[N], dp[N]; long long ans;
void dfs(int p, int i) {
	int o, x;
	x = ll[i];
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];
		if (j != p) {
			dfs(i, j);
			x = max(x, dp[j]);
		}
	}
	if (x > rr[i]) {
		x = rr[i];
		for (o = eo[i]; o--; ) {
			int j = ej[i][o];
			if (j != p)
				ans += max(dp[j] - x, 0);
		}
	}
	dp[i] = x;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, h, i, j;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d%d", &ll[i], &rr[i]);
		for (i = 0; i < n; i++)
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		for (h = 0; h < n - 1; h++) {
			scanf("%d%d", &i, &j), i--, j--;
			append(i, j), append(j, i);
		}
		ans = 0, dfs(-1, 0), ans += dp[0];
		printf("%lld\n", ans);
		for (i = 0; i < n; i++)
			free(ej[i]);
	}
	return 0;
}