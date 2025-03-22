#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
long long int h[400005], l;
long long int comp_h(long long int a, long long int b)
{
	if (h[a] < h[b])
		return 1;
	else
		return -1;
}
void swap_h(long long int a, long long int b)
{
	long long int f = h[a];
	h[a] = h[b];
	h[b] = f;
	return;
}
void push(long long int ne)
{
	h[l] = ne;
	long long int p = l++;
	for (; p > 0; p = (p - 1) / 2)
		if (comp_h((p - 1) / 2, p) > 0)
			swap_h((p - 1) / 2, p);
	return;
}
long long int pop()
{
	l--;
	swap_h(0, l);
	long long int p = 0;
	for (;;)
	{
		if (2 * p + 2 < l)
		{
			if (comp_h(2 * p + 1, 2 * p + 2) > 0)
			{
				if (comp_h(p, 2 * p + 2) > 0)
					swap_h(p, 2 * p + 2);
				p = 2 * p + 2;
			}
			else
			{
				if (comp_h(p, 2 * p + 1) > 0)
					swap_h(p, 2 * p + 1);
				p = 2 * p + 1;
			}
		}
		else if (2 * p + 1 < l)
		{
			if (comp_h(p, 2 * p + 1) > 0)
				swap_h(p, 2 * p + 1);
			p = 2 * p + 1;
		}
		else
			break;
	}
	return h[l];
}
long long int b[400005];
long long int ans[400005];
void solve()
{
	long long int n;
	scanf("%lld", &n);
	long long int i;
	for (i = 0; i < 2 * n; i++)
		scanf("%lld", &b[i]);
	l = 0;
	for (i = 0; i < 2 * n; i++)
		push(b[i]);
	for (i = 0; i < n; i++)
		ans[2 * i + 1] = pop();
	for (i = 0; i < n; i++)
		ans[2 * i + 2] = pop();
	ans[0] = 0;
	for (i = 1; i < 2 * n + 1; i++)
	{
		if (i % 2 > 0)
			ans[0] += ans[i];
		else
			ans[0] -= ans[i];
	}
	if (ans[0] < ans[1])
	{
		long long int d = ans[1] - ans[0];
		ans[0] = ans[1];
		ans[1] = ans[0] + d;
	}
	else if (ans[1] == ans[0])
	{
		ans[2] ^= ans[3];
		ans[3] ^= ans[2];
		ans[2] ^= ans[3];
		ans[0] = ans[1];
		for (i = 2; i < 2 * n + 1; i++)
		{
			if (i % 2 > 0)
				ans[1] -= ans[i];
			else
				ans[1] += ans[i];
		}
	}
	for (i = 0; i < 2 * n; i++)
		printf("%lld ", ans[i]);
	printf("%lld\n", ans[i]);
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