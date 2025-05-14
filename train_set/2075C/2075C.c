#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 200005
// 比较函数，用于 qsort 降序排序
int compa(const void *a, const void *b) {
 return (*(int *)b - *(int *)a);
}
// 二分查找函数，返回第一个大于等于 x 的元素的位置
int ser(int x, int *a, int l, int r) 
{
 if(x <= a[r])
 {
 return r+1;
 }
 if(x > a[r] && x < a[r - 1])
 {
 return r;
 }
 while (l <= r) 
 {
 int mid = l + (r - l) / 2;
 if (a[mid] == x ) 
 {
 if(a[mid] == a[mid + 1])
 {
 l = mid + 1;
 continue;
 }
 return mid + 1;
 } else if (a[mid] > x) 
 {
 l = mid + 1;
 } else 
 {
 r = mid - 1;
 }
 }
 return l;
}
int main() {
 int t = 0, n = 0, m = 0, a[maxn] = {0};
 // 读取测试用例的数量
 scanf("%d", &t);
 for (int j = 0; j < t; j++) {
 long long sum = 0;
 memset(a, 0, sizeof(a));
 scanf("%d %d", &n, &m);
 for (int i = 0; i < m; i++) {
 scanf("%d", &a[i]);
 }
 qsort(a, m, sizeof(int), compa);
 for (int i = 1; i < n; i++) 
 {
 int min = (i < n - i) ? i : (n - i);
 int max = n - min;
 if( max > a[0])
 {
 continue;
 }
 long long mo = ser(min, a, 0, m - 1);
 long long mi = ser(max, a, 0, m - 1);
 sum += mo* mi - mi;
 }
 printf("%lld\n", sum);
 }
 return 0;
}