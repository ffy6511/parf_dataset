#include <stdio.h>
#include <string.h>
#define N	500
#define M	500
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static int aa[N], bb[M], ll[N], rr[N], ll_[N], rr_[N], ss[N], sss[M + 1][M + 1], lcp[N + 1][M + 1], dp[N + 1][M + 1][2], dq[N + 1][M + 1][2];
		static char bad[N], used[N];
		int n, m, k, k_, h, h_, i, j, j_, jl, jr, s, u, u_, upd;
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%d", &aa[i]);
		for (j = 0; j < m; j++)
			scanf("%d", &bb[j]);
		memset(bad, 0, n * sizeof *bad);
		while (1) {
			upd = 0;
			s = 0;
			for (i = 0; i < n; i++) {
				s += aa[i];
				if (bad[i])
					s = 0;
				else if (s < 0) {
					bad[i] = 1, upd = 1;
					break;
				}
			}
			s = 0;
			for (i = n - 1; i >= 0; i--) {
				s += aa[i];
				if (bad[i])
					s = 0;
				else if (s < 0) {
					bad[i] = 1, upd = 1;
					break;
				}
			}
			if (!upd)
				break;
		}
		k = 0;
		for (i = 0, j = 1; j <= n; j++)
			if (j == n || bad[j - 1] || bad[j]) {
				ll[k] = i, rr[k] = j, ss[k] = 0;
				while (i < j)
					ss[k] += aa[i++];
				k++;
			}
		for (jl = m; jl >= 0; jl--) {
			s = 0;
			for (jr = jl + 1; jr <= m; jr++) {
				sss[jl][jr] = s += bb[jr - 1];
				if (jr - jl > 1)
					sss[jl][jr] = max(sss[jl][jr], max(sss[jl + 1][jr], sss[jl][jr - 1]));
			}
		}
		for (i = n; i >= 0; i--)
			for (j = m; j >= 0; j--)
				lcp[i][j] = i < n && j < m && aa[i] == bb[j] ? lcp[i + 1][j + 1] + 1 : 0;
		for (h_ = 0; h_ < k; h_++) {
			s = ss[h_];
			for (h = 0; h <= k; h++)
				for (j = 0; j <= m; j++)
					for (u = 0; u < 2; u++)
						dp[h][j][u] = dq[h][j][u] = -1;
			dp[0][0][0] = dq[0][0][0] = -2;
			for (h = 0; h < k; h++)
				if (ss[h] < s) {
					for (j = 0; j < m; j++)
						for (u = 0; u < 2; u++)
							if (dp[h][j][u] != -1)
								if (ll[h] + lcp[ll[h]][j] >= rr[h]) {
									j_ = j + rr[h] - ll[h];
									dp[h + 1][j_][u] = j, dq[h + 1][j_][u] = u;
								}
				} else {
					for (u = 0; u < 2; u++) {
						for (j = 0, j_ = 0; j < m; j++)
							if (dp[h][j][u] != -1) {
								j_ = max(j_, j + 1);
								while (j_ <= m && sss[j][j_] <= s) {
									dp[h + 1][j_][u] = j, dq[h + 1][j_][u] = u;
									j_++;
								}
							}
						if (u == 0)
							for (j = 0; j < m; j++)
								if (dp[h][j][u] != -1) {
									for (j_ = j + 1; j_ <= m; j_++)
										dp[h + 1][j_][1] = j, dq[h + 1][j_][1] = u;
									break;
								}
					}
				}
			if (dp[k][m][0] != -1 || dp[k][m][1] != -1) {
				j = m, u = dp[k][m][0] != -1 ? 0 : 1;
				for (h = k - 1; h >= 0; h--) {
					j_ = dp[h + 1][j][u], u_ = dq[h + 1][j][u];
					ll_[h] = j_, rr_[h] = j;
					j = j_, u = u_;
				}
				k_ = 0;
				for (h = 0; h < k; h++)
					if (ss[h] >= s)
						k_++;
				printf("%d\n", k_ * 2);
				memset(used, 0, k * sizeof *used);
				while (1) {
					h_ = -1;
					for (h = 0; h < k; h++)
						if (!used[h] && (h_ == -1 || ss[h_] < ss[h]))
							h_ = h;
					if (h_ == -1 || ss[h_] < s)
						break;
					used[h_] = 1;
					i = 0;
					for (h = 0; h < h_; h++)
						i += !used[h] ? rr[h] - ll[h] : 1;
					j = i + rr[h_] - ll[h_];
					printf("%d %d 1\n", i + 1, j);
					printf("%d\n", s);
				}
				while (1) {
					h_ = -1;
					for (h = 0; h < k; h++)
						if (used[h] == 1 && (h_ == -1 || sss[ll_[h_]][rr_[h_]] > sss[ll_[h]][rr_[h]]))
							h_ = h;
					if (h_ == -1)
						break;
					used[h_] = 2;
					i = 0;
					for (h = 0; h < h_; h++)
						i += used[h] == 1 ? 1 : rr_[h] - ll_[h];
					j = i + 1;
					printf("%d %d %d\n", i + 1, j, rr_[h_] - ll_[h_]);
					for (j = ll_[h_]; j < rr_[h_]; j++)
						printf("%d ", bb[j]);
					printf("\n");
				}
				goto end;
			}
		}
		printf("-1\n");
end:;
	}
	return 0;
}