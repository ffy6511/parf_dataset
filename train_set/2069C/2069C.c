#include<stdio.h>
#include<stdlib.h>
#define MOD 998244353
#define MAXN 200010
int pre_2[MAXN];
int prefix_1[MAXN];
int a[MAXN];
int sum_recip[MAXN];
int recip_list[MAXN];
long long pow_mod(long long base, long long exp, long long mod) {
 long long result = 1;
 while (exp > 0) {
 if (exp % 2 == 1) 
 result = (result * base) % mod;
 base = (base * base) % mod;
 exp /= 2;
 }
 return result;
}
int main() {
 int t;
 scanf("%d", &t);
 while (t--) {
 int n;
 scanf("%d", &n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &a[i]);
 }
 prefix_1[0] = 0;
 pre_2[0] = 0;
 for (int i = 1; i <= n; i++) {
 prefix_1[i] = prefix_1[i-1] + (a[i-1] == 1);
 pre_2[i] = pre_2[i-1] + (a[i-1] == 2);
 }
 int m = 0;
 sum_recip[0] = 0;
 for (int i = 0; i < n; i++) {
 if (a[i] == 1) {
 int exponent = MOD - 1 - pre_2[i+1];
 long long recip = pow_mod(2, exponent, MOD);
 recip_list[m] = recip;
 sum_recip[m+1] = (sum_recip[m] + recip) % MOD;
 m++;
 }
 }
 long long ans = 0;
 for (int k = 0; k < n; k++) {
 if (a[k] == 3) {
 int cnt_1 = prefix_1[k];
 if (cnt_1 == 0) continue;
 long long sum_recip_current = sum_recip[cnt_1];
 int cnt_2 = pre_2[k];
 long long pow2 = pow_mod(2, cnt_2, MOD);
 long long term = (pow2 * sum_recip_current) % MOD;
 term = (term - cnt_1 + MOD) % MOD;
 ans = (ans + term) % MOD;
 }
 }
 printf("%lld\n", ans);
 }
 return 0;
}