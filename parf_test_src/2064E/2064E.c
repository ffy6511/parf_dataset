#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
long long int seg[800005], ss;
void update(long long int x, long long int v)
{
	x += ss - 1;
	seg[x] = v;
	while (x > 0)
	{
		x = (x - 1) / 2;
		seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
	}
	return;
}
long long int get(long long int l, long long int r)
{
	l += ss - 1;
	r += ss - 1;
	long long int res = 0;
	while (l < r)
	{
		if (l % 2 == 0)
			res += seg[l];
		l /= 2;
		if (r % 2 > 0)
			res += seg[r];
		r = r / 2 - 1;
	}
	if (l == r)
		res += seg[l];
	return res;
}
long long int par[200005], cnt[200005];
long long int root(long long int n)
{
	if (par[n] != n)
		par[n] = root(par[n]);
	return par[n];
}
void uni(long long int a, long long int b)
{
	a = root(a);
	b = root(b);
	if (a != b)
	{
		par[b] = a;
		cnt[a] += cnt[b];
	}
	return;
}
long long int p[200005];
long long int c[200005];
long long int q[200005];
void solve()
{
	long long int n;
	scanf("%lld", &n);
	long long int i, j, k;
	for (i = 0; i < n; i++)
		scanf("%lld", &p[i]);
	for (i = 0; i < n; i++)
		scanf("%lld", &c[i]);
	for (i = 0; i < n; i++)
		q[--p[i]] = i;
	const long long int prime = 998244353;
	for (ss = 1; ss < n; ss *= 2);
	for (i = 0; i < 2 * ss - 1; i++)
		seg[i] = 0;
	for (i = 0; i < n; i++)
		update(i, 1);
	for (i = 0; i < n; i++)
	{
		par[i] = i;
		cnt[i] = 1;
	}
	for (i = 0; i < n - 1; i++)
		if (c[i] == c[i + 1])
			uni(i, i + 1);
	long long int min, mid, max;
	long long int ans = 1, ii;
	for (ii = 0; ii < n; ii++)
	{
		i = q[ii];
		min = -1;
		max = i;
		while (max - min > 1)
		{
			mid = (max + min) / 2;
			if (get(mid, i - 1) > 0)
				min = mid;
			else
				max = mid;
		}
		j = min;
		min = i;
		max = n;
		while (max - min > 1)
		{
			mid = (max + min) / 2;
			if (get(i + 1, mid) == 0)
				min = mid;
			else
				max = mid;
		}
		k = max;
		ans = ans * cnt[root(i)] % prime;
		cnt[root(i)]--;
		if (j >= 0 && k < n)
		{
			if (c[j] == c[k])
				uni(j, k);
		}
		update(i, 0);
	}
	printf("%lld\n", ans);
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (; t > 0; t--)
		solve();
	return 0;
}