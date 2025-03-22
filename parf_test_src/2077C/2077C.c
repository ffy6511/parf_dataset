#include <stdio.h>
#define N	200000
#define MD	998244353
#define V4	748683265
int pp2[N + 1];
void init() {
	int i;
	pp2[0] = 1;
	for (i = 1; i <= N; i++)
		pp2[i] = pp2[i - 1] * 2 % MD;
}
int main() {
	int t;
	init();
	scanf("%d", &t);
	while (t--) {
		static char cc[N + 1];
		int n, q, i, k0, k1, ans;
		scanf("%d%d%s", &n, &q, cc);
		k0 = 0, k1 = 0;
		for (i = 0; i < n; i++)
			if (cc[i] == '0')
				k0++;
			else
				k1++;
		while (q--) {
			scanf("%d", &i), i--;
			if (cc[i] == '0')
				k0--, cc[i] = '1', k1++;
			else
				k1--, cc[i] = '0', k0++;
			ans = 0;
			if (n >= 2) {
				ans = (ans + ((long long) k0 * (k0 - 1) + (long long) k1 * (k1 - 1)) % MD * pp2[n - 2]) % MD;
				ans = (ans + (long long) (k0 + k1) * pp2[n - 1]) % MD;
				ans = (ans - (long long) k0 * k1 * 2 % MD * pp2[n - 2]) % MD;
				ans = (ans - pp2[n - 1]) % MD;
				ans = (long long) ans * V4 % MD;
				if (ans < 0)
					ans += MD;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}