#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define M	100000
#define Q	100000
#define N	(M + Q)
#define INF	0x3f3f3f3f3f3f3f3fLL
long long min(long long a, long long b) { return a < b ? a : b; }
unsigned int Z;
int rand_() {
	return (Z *= 3) >> 1;
}
void srand_() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}
int n;
int xx[N], xx_[N], cc[M];
void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
		while (j < k)
			if (xx[ii[j]] == xx[i_])
				j++;
			else if (xx[ii[j]] < xx[i_]) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		sort(ii, l, i);
		l = k;
	}
}
long long dp[N];
long long eval(int i, int c) {
	return (long long) xx_[i] * c - dp[i];
}
int check(int i, int j, int k) {
	return (dp[j] - dp[i] + xx_[j] - xx_[i] - 1) / (xx_[j] - xx_[i]) >= (dp[k] - dp[j] + xx_[k] - xx_[i] - 1) / (xx_[k] - xx_[j]);
}
int aa[N]; long long bb[N];
void update(int a, long long b) {
	int l, r, m;
	long long tmp;
	l = 0, r = n - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (aa[m] == -1) {
			aa[m] = a, bb[m] = b;
			return;
		}
		if ((long long) aa[m] * xx_[m] + bb[m] > (long long) a * xx_[m] + b) {
			tmp = aa[m], aa[m] = a, a = tmp;
			tmp = bb[m], bb[m] = b, b = tmp;
		}
		if (a > aa[m])
			r = m - 1;
		else
			l = m + 1;
	}
}
long long query(int i) {
	int l, r, m;
	long long z;
	l = 0, r = n - 1, z = INF;
	while (l <= r) {
		m = (l + r) / 2;
		if (aa[m] != -1)
			z = min(z, (long long) aa[m] * xx_[i] + bb[m]);
		if (i < m)
			r = m - 1;
		else if (i > m)
			l = m + 1;
		else
			break;
	}
	return z;
}
int main() {
	static int ii[N], qu[N];
	static long long ans[Q];
	int m, cnt, q, g, h, i, i_, j, r, lower, upper;
	long long tmp;
	srand_();
	scanf("%*d%d%d", &m, &q), n = m + q;
	for (h = 0; h < m; h++)
		scanf("%d%d", &xx[h], &cc[h]);
	for (h = 0; h < q; h++)
		scanf("%d", &xx[m + h]);
	for (i = 0; i < n; i++)
		ii[i] = i;
	sort(ii, 0, n);
	for (r = 0; r < 2; r++) {
		for (i = 0; i < n; i++)
			xx_[i] = xx[ii[i]];
		i_ = 0;
		while (i_ < n && ii[i_] != m - 1)
			i_++;
		cnt = 0;
		for (i = i_; i < n; i++) {
			h = ii[i];
			if (h < m) {
				if (i == i_)
					dp[i] = 0;
				else {
					lower = -1, upper = cnt - 1;
					while (upper - lower > 1) {
						g = (lower + upper) / 2;
						if (eval(qu[g], cc[h]) < eval(qu[g + 1], cc[h]))
							lower = g;
						else
							upper = g;
					}
					g = upper;
					dp[i] = (long long) xx_[i] * cc[h] - eval(qu[g], cc[h]);
				}
				if (cnt && xx_[qu[cnt - 1]] == xx_[i] && dp[qu[cnt - 1]] < dp[i])
					continue;
				while (cnt && dp[qu[cnt - 1]] >= dp[i] || cnt >= 2 && check(qu[cnt - 2], qu[cnt - 1], i))
					cnt--;
				qu[cnt++] = i;
			} else
				dp[i] = INF;
		}
		memset(aa, -1, n * sizeof *aa);
		for (i = 0; i < n; i++) {
			h = ii[i];
			if (h < m) {
				if (i < i_)
					update(cc[h] * 2, (long long) -(xx_[i] + xx_[i_]) * cc[h]);
				else
					update(cc[h] * 2, dp[i] - (long long) xx_[i] * cc[h] * 2);
			}
			if (i >= i_)
				dp[i] = query(i);
		}
		for (i = i_; i < n; i++)
			dp[i] = min(dp[i], (long long) (xx_[i] - xx_[i_]) * cc[m - 1]);
		for (i = n - 2; i >= i_; i--)
			dp[i] = min(dp[i], dp[i + 1]);
		for (i = 0; i < n; i++)
			xx[i] = -xx[i];
		for (i = 0, j = n - 1; i < j; i++, j--) {
			tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
			tmp = dp[i], dp[i] = dp[j], dp[j] = tmp;
		}
	}
	for (i = 0; i < n; i++) {
		h = ii[i] - m;
		if (h >= 0)
			ans[h] = dp[i];
	}
	for (h = 0; h < q; h++)
		printf("%lld\n", ans[h]);
	return 0;
}