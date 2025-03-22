#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define N	200000
#define MD	1000000007
unsigned int Z;
int rand_() {
	return (Z *= 3) >> 1;
}
void srand_() {
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}
int aa[N + 1];
void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
		while (j < k) {
			int c = aa[ii[j]] != aa[i_] ? aa[ii[j]] - aa[i_] : ii[j] - i_;
			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		}
		sort(ii, l, i);
		l = k;
	}
}
int main() {
	int t;
	srand_();
	scanf("%d", &t);
	while (t--) {
		static int dp[N + 1], ii[N + 1], jj[N + 1];
		int n, h, i, j, ans;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &aa[i]), aa[i] ^= aa[i - 1];
		for (i = 0; i <= n; i++)
			ii[i] = i;
		sort(ii, 0, n + 1);
		for (h = 0; h <= n; h++)
			jj[ii[h]] = h == n || aa[ii[h + 1]] != aa[ii[h]] ? -1 : ii[h + 1];
		memset(dp, 0, (n + 1) * sizeof *dp), dp[0] = 3;
		ans = 0;
		for (i = 0; i < n; i++) {
			j = jj[i];
			if (j == -1)
				ans = (ans + dp[i]) % MD;
			else {
				if (j < n)
					dp[j] = (dp[j] + (long long) dp[i] * 3) % MD;
				else
					ans = (ans + dp[i]) % MD;
				dp[j - 1] = (dp[j - 1] + (long long) dp[i] * 2) % MD;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}