#include <stdio.h>
#include <stdlib.h>
#define N	300000
int *ej[N], eo[N];
void append(int i, int j) {
	int o = eo[i]++;
	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}
int dd[N], jj[N], kk[N]; long long ans;
void dfs(int p, int i) {
	int o, j_;
	j_ = -1;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];
		if (j != p) {
			dfs(i, j);
			if (j_ == -1 || dd[j_] < dd[j])
				j_ = j;
		}
	}
	jj[i] = j_;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];
		if (j != p && j != jj[i]) {
			j_ = jj[i];
			ans -= (long long) kk[j_] * kk[j];
			while (j != -1) {
				ans += (long long) kk[j_] * kk[j] * 2, kk[j_] += kk[j];
				j_ = jj[j_], j = jj[j];
			}
		}
	}
	if (jj[i] == -1)
		dd[i] = 0, kk[i] = 1;
	else
		dd[i] = dd[jj[i]] + 1, kk[i] = kk[jj[i]] + 1;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, h, i, j;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		for (h = 0; h < n - 1; h++) {
			scanf("%d%d", &i, &j), i--, j--;
			append(i, j), append(j, i);
		}
		ans = 0, dfs(-1, 0);
		printf("%lld\n", ans);
	}
	return 0;
}