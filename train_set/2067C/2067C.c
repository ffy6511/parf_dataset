#include <stdio.h>
int test(long long n, int i) {
 int c = 0;
 while (n > 0) {
 long long temp = n;
 while (temp > 0) {
 int r = temp % 10;
 if (r == 7) {
 return c;
 }
 temp /= 10;
 }
 n += i;
 c++;
 }
 return -1;
}
int main() {
 int t;
 scanf("%d", &t);
 if (t < 1 || t > 10000) {
 printf("Out of range!\n");
 return 0;
 }
 long long arr[t];
 for (int i = 0; i < t; i++) {
 scanf("%lld", &arr[i]);
 }
 for (int i = 0; i < t; i++) {
 if (arr[i] < 10 || arr[i] > 1000000000) {
 printf("Out of range!\n");
 continue;
 } else {
 int result[] = {
 test(arr[i], 9),
 test(arr[i], 99),
 test(arr[i], 999),
 test(arr[i], 9999),
 test(arr[i], 99999),
 test(arr[i], 999999),
 test(arr[i], 9999999),
 test(arr[i], 99999999),
 test(arr[i], 999999999)
 };
 int x = result[0];
 for (int j = 1; j < 9; j++) {
 if (result[j] < x) {
 x = result[j];
 }
 }
 printf("%d\n", x);
 }
 }
 return 0;
}