#include <stdio.h>
#define ll long long
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
 {
 ll x, y;
 scanf("%lld%lld", &x, &y);
 if(x == y)
 {
 printf("0\n");
 continue;
 }
 ll p = 1;
 for(int i = 0; i < 60; i++)
 p *= 2;
 int nx = -1, ny = -1;
 ll tem = p;
 if(x == 0 || x == 1)
 nx = 1;
 else
 {
 for(int i = 61; ; i--)
 {
 if(x / tem)
 {
 nx = i;
 break;
 }
 tem /= 2;
 }
 }
 tem = p;
 if(y == 0 || y == 1)
 ny = 1;
 else
 {
 for(int i = 61; ; i--)
 {
 if(y / tem)
 {
 ny = i;
 break;
 }
 tem /= 2;
 }
 }
 if(x == 0)
 {
 int sum = 0, max;
 for(int i = 1; ; i++)
 {
 max = i;
 sum += i;
 if(sum >= ny)
 break;
 }
 int cut = -1;
 if(sum > ny)
 {
 for(int i = 1; ; i++)
 {
 if(i == sum - ny)
 {
 cut = i;
 break;
 }
 }
 }
 ll pp = 1, ans = 0;
 for(int i = 1; i <= max; i++)
 {
 pp *= 2;
 if(i != cut)
 {
 ans += pp;
 }
 }
 printf("%lld\n", ans);
 continue;
 }
 if(y == 0)
 {
 int sum = 0, max;
 for(int i = 1; ; i++)
 {
 max = i;
 sum += i;
 if(sum >= nx)
 break;
 }
 int cut = -1;
 if(sum > nx)
 {
 for(int i = 1; ; i++)
 {
 if(i == sum - nx)
 {
 cut = i;
 break;
 }
 }
 }
 ll pp = 1, ans = 0;
 for(int i = 1; i <= max; i++)
 {
 pp *= 2;
 if(i != cut)
 {
 ans += pp;
 }
 }
 printf("%lld\n", ans);
 continue;
 }
 int same = 0;
 for(int i = nx - 1, j = ny - 1; i >= 0 && j >= 0; i--, j--)
 {
 if(((x >> (ll)i) & (ll)1) == ((y >> (ll)j) & (ll)1))
 same++;
 else
 break;
 }
 int num1 = nx - same, num2 = ny - same;
 int op = num1 + num2;
 int sum = 0;
 if(op == 0)
 {
 printf("0\n");
 continue;
 }
 int k;
 for(int i = 1; ; i++)
 {
 k = i;
 sum += i;
 if(sum >= op)
 break;
 }
 int cut = -1;
 if(sum != op)
 {
 for(int i = 1; ; i++)
 {
 if(i == sum - op)
 {
 cut = i;
 break;
 }
 }
 }
 if(cut >= 3 || cut == -1)
 {
 ll ans = 0;
 ll pp = 1;
 for(int i = 0; i < k; i++)
 {
 pp *= 2;
 if(i + 1 != cut)
 ans += pp;
 }
 printf("%lld\n", ans);
 continue;
 }
 if(cut == 1)
 {
 if(num1 == 1 || num2 == 1)
 {
 if(num1 == 0 || num2 == 0)
 {
 printf("2\n");
 continue;;
 }
 if(num1 == 1 && num2 == 1)
 {
 if(nx == 2)
 {
 printf("12\n");
 continue;
 }
 printf("14\n");
 continue;
 }
 k++;
 cut = k - 1;
 ll ans = 0;
 ll pp = 1;
 for(int i = 0; i < k; i++)
 {
 pp *= 2;
 if(!(i == 1 || (i + 1) == cut))
 ans += pp;
 }
 printf("%lld\n", ans);
 continue;
 }
 else
 {
 ll ans = 0;
 ll pp = 1;
 for(int i = 0; i < k; i++)
 {
 pp *= 2;
 if(i + 1 != cut)
 ans += pp;
 }
 printf("%lld\n", ans);
 continue;
 }
 }
 if(cut == 2)
 {
 if(num1 == 2 || num2 == 2)
 {
 ll ans = 0;
 ll pp = 1;
 for(int i = 0; i < k; i++)
 {
 pp *= 2;
 ans += pp;
 }
 printf("%lld\n", ans);
 continue;
 }
 else
 {
 ll ans = 0;
 ll pp = 1;
 for(int i = 0; i < k; i++)
 {
 pp *= 2;
 if(i + 1 != cut)
 ans += pp;
 }
 printf("%lld\n", ans);
 continue;
 }
 }
 }
 return 0;
}