#include <stdio.h>
#include <stdlib.h>
#define N	100000
#define MD	998244353
#define V2	499122177
int inv(int a) {
	return a == 1 ? 1 : (long long) inv(a - MD % a) * (MD / a + 1) % MD;
}
int *ej[N], eo[N];
void append(int i, int j) {
	int o = eo[i]++;
	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static int aa[N], vv[N], bb[N], cc[N], pp[N], ss[N];
		int n, h, i, j, o, x, y, z, ans;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			aa[i] = (long long) x * inv(y) % MD, vv[i] = inv(aa[i]);
			bb[i] = (long long) (1 - aa[i]) * vv[i] % MD;
		}
		for (i = 0; i < n; i++)
			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
		for (h = 0; h < n - 1; h++) {
			scanf("%d%d", &i, &j), i--, j--;
			append(i, j), append(j, i);
		}
		x = 0, y = 0, ans = 0;
		for (i = 0; i < n; i++) {
			pp[i] = (1 - aa[i]) % MD, ss[i] = 0;
			for (o = eo[i]; o--; ) {
				j = ej[i][o];
				pp[i] = (long long) pp[i] * aa[j] % MD;
				ss[i] = (ss[i] + bb[j]) % MD;
			}
			cc[i] = (long long) pp[i] * ss[i] % MD;
			x = (x + cc[i]) % MD;
			y = (y + (long long) cc[i] * cc[i]) % MD;
		}
		ans = ((long long) x * x - y) % MD * V2 % MD;
		for (i = 0; i < n; i++)
			for (o = eo[i]; o--; ) {
				j = ej[i][o];
				if (i < j) {
					ans = (ans - (long long) cc[i] * cc[j] % MD) % MD;
					ans = (ans + (long long) pp[i] * pp[j] % MD * vv[i] % MD * vv[j]) % MD;
				}
			}
		for (i = 0; i < n; i++) {
			x = 0, y = 0;
			for (o = eo[i]; o--; ) {
				j = ej[i][o];
				x = (x + cc[j]) % MD;
				y = (y + (long long) cc[j] * cc[j]) % MD;
			}
			ans = (ans - ((long long) x * x - y) % MD * V2) % MD;
			x = 0, y = 0;
			for (o = eo[i]; o--; ) {
				j = ej[i][o];
				x = (x + pp[j]) % MD;
				y = (y + (long long) pp[j] * pp[j]) % MD;
			}
			ans = (ans + ((long long) x * x - y) % MD * V2 % MD * vv[i] % MD * bb[i]) % MD;
			x = 0, y = 0;
			for (o = eo[i]; o--; ) {
				j = ej[i][o], z = (long long) pp[j] * (ss[j] - bb[i]) % MD;
				x = (x + z) % MD;
				y = (y + (long long) z * z) % MD;
			}
			ans = (ans + ((long long) x * x - y) % MD * V2 % MD * vv[i]) % MD;
		}
		if (ans < 0)
			ans += MD;
		printf("%d\n", ans);
		for (i = 0; i < n; i++)
			free(ej[i]);
	}
	return 0;
}