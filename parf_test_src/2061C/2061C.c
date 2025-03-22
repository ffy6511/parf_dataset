#include <stdio.h>
#define N 998244353ll
#define ll long long
ll dp[200000][2];
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
 {
 int n;
 scanf("%d", &n);
 ll arr[n];
 for(int i = 0; i < n; i++)
 {
 scanf("%lld", &arr[i]);
 }
 if(arr[0] == 0)
 {
 dp[0][0] = 1;
 dp[0][1] = 1;
 }
 else
 {
 dp[0][0] = 1;
 dp[0][1] = 0;
 }
 if(n > 1)
 {
 dp[1][0] = dp[0][1];
 if(arr[1] == 0)
 dp[1][1] = dp[0][1];
 else if(arr[1] == 1)
 dp[1][1] = dp[0][0];
 else
 dp[1][1] = 0;
 }
 if(n > 2)
 {
 for(int i = 2; i < n; i++)
 {
 dp[i][0] = dp[i - 1][1];
 dp[i][1] = 0;
 if(arr[i] == arr[i - 1])
 dp[i][1] += dp[i - 1][1];
 if(arr[i] == arr[i - 2] + 1)
 dp[i][1] += dp[i - 1][0];
 dp[i][1] %= N;
 }
 }
 printf("%lld\n", (dp[n - 1][0] + dp[n - 1][1]) % N);
 }
 return 0;
}