#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define N	200000
#define K	33	/* K = floor(log2(10^9)) + 4 */
int max(int a, int b) { return a > b ? a : b; }
unsigned int Z;
int rand_() {
	return (Z *= 3) >> 1;
}
void srand_() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}
int aa[N];
void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
		while (j < k)
			if (aa[ii[j]] == aa[i_])
				j++;
			else if (aa[ii[j]] < aa[i_]) {
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
int solve(int *aa, int n, int s_) {
	static int qu[N], qq[N];
	static long long ss[N];
	int m, cnt, i;
	long long s;
	m = 0;
	cnt = 0;
	for (i = n - 1; i >= 0; i--) {
		while (cnt && aa[qu[cnt - 1]] <= aa[i])
			cnt--;
		qq[i] = cnt == 0 ? -1 : qu[cnt - 1], qu[cnt++] = i;
	}
	for (i = n - 1; i >= 0; i--)
		ss[i] = (i + 1 == n ? 0 : ss[i + 1]) + aa[i];
	if (ss[0] <= s_)
		return -1;
	m = 0, s = 0;
	for (i = 0; i < n; i++) {
		while (qq[i] != -1 && s + ss[qq[i]] > s_)
			i = qq[i];
		aa[m++] = aa[i], s += aa[i];
	}
	return m;
}
int compare(int *aa, int n, int *bb, int m) {
	int i;
	for (i = 0; i < n && i < m; i++)
		if (aa[i] != bb[i])
			return aa[i] < bb[i] ? -1 : 1;
	return n - m;
}
int main() {
	int t;
	srand_();
	scanf("%d", &t);
	while (t--) {
		static int bb[N], bb_[N], ii[N];
		int n, m, m_, i, a, h;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &aa[i]);
		for (i = 0; i < n; i++)
			ii[i] = i;
		sort(ii, 0, n);
		m_ = -1;
		for (h = n - 1; h >= 0 && h >= n - K; h--) {
			a = aa[ii[h]];
			m = 0;
			for (i = 0; i < n; i++)
				if (aa[i] <= a)
					bb[m++] = aa[i];
			m = solve(bb, m, a * 2);
			if (m != -1 && (m_ == -1 || compare(bb_, m_, bb, m) < 0))
				memcpy(bb_, bb, (m_ = m) * sizeof *bb);
		}
		printf("%d\n", m_);
		for (h = 0; h < m_; h++)
			printf("%d ", bb_[h]);
		printf("\n");
	}
	return 0;
}