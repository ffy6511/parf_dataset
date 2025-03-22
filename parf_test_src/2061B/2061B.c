#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b)
{
 return (*(int *)a - *(int *)b);
}
void swap(int *a, int i, int j)
{
 int temp = a[i];
 a[i] = a[j];
 a[j] = temp;
}
int main()
{
 int t;
 scanf("%d", &t);
 while (t--)
 {
 int n;
 scanf("%d", &n);
 if (n < 4)
 {
 printf("-1\n");
 continue;
 }
 int *a = (int *)malloc(n * sizeof(int));
 for (int i = 0; i < n; i++)
 scanf("%d", &a[i]);
 qsort(a, n, sizeof(int), comp);
 int d = 0;
 for (int i = 0; i < n; i++)
 {
 if (a[i] == a[i - 1])
 {
 swap(a, i, n - 1);
 swap(a, i - 1, n - 2);
 d = 1;
 break;
 }
 }
 qsort(a, n-2, sizeof(int), comp);
 if (!d)
 {
 printf("-1\n");
 free(a);
 continue;
 }
 int f = 0;
 for (int i = 1; i < n - 2; i++)
 {
 if (a[i] < (a[i - 1] + 2 * a[n - 1]))
 {
 printf("%d %d %d %d\n", a[n - 1], a[n - 2], a[i-1], a[i]);
 f = 1;
 break;
 }
 }
 if (!f)
 printf("-1\n");
 free(a);
 }
 return 0;
}