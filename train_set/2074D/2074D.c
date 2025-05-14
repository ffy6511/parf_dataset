#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
long long max_(long long a, long long b) { return a > b ? a : b; }
int cmp_(int aa[], int bb[]) { return aa[0] - bb[0]; }
void sort(int *aa, int k, int s, int c, int (*_cmp)())
{
 srand(time(NULL));
 int x, y, w, z = rand();
 int _t, u, v;
 for(x = 0; x < 2; x++)
 for(y = 0; y < k; y++) {
 z *= rand(), u = ((z % k) + k) % k;
 u = (((*(aa + u*c) + z) % k) + k) % k;
 for(w = 0; w < c; w++)
 _t = *(aa + u*c + w), *(aa + u*c + w) = *(aa + y*c + w), *(aa + y*c + w) = _t;
 }
 qsort(aa, k, c * s, _cmp);
}
long long F(long long a, long long b, long long c)
{
 long long d = sqrtl(c * c - (b - a) * (b - a));
 return 2 * d + 1; 
}
int main()
{
 int x, y, z, i, j, k, a, b, c, d, e, f, n, m, t;
 long long ans, p;
 
 scanf("%d", &t);
 while(t--)
 {
 ans = 0;
 scanf("%d %d", &n, &m), k = 0;
 int aa[n][2], arr[2 * m + n][3];
 long long ans = 0;
 
 for(y = 0; y < 2; y++)
 for(x = 0; x < n; x++)
 scanf("%d", &aa[x][y]);
 
 for(x = 0; x < n; x++) 
 for(y = aa[x][0] - aa[x][1]; y <= aa[x][0] + aa[x][1]; y++)
 arr[k][0] = y, arr[k][1] = aa[x][0], arr[k++][2] = aa[x][1];
 
 sort(arr, k, sizeof(int), 3, cmp_);
 
 p = 0;
 for(x = 0; x < k; x++)
 if(!x || arr[x][0] != arr[x - 1][0]) 
 ans += p, p = F(arr[x][0], arr[x][1], arr[x][2]);
 else
 p = max_(p, F(arr[x][0], arr[x][1], arr[x][2]));
 
 printf("%lld\n", ans + p); 
 
 
 }
}