#include <stdio.h>
#include <math.h>
#define N 500005
int n;
int a[N], idx = 0;
// 快读函数
inline int read() {
 int x = 0, f = 1;
 char ch = getchar();
 while (ch < '0' || ch > '9') {
 if (ch == '-') f = -1;
 ch = getchar();
 }
 while (ch >= '0' && ch <= '9') {
 x = (x << 3) + (x << 1) + (ch ^ 48);
 ch = getchar();
 }
 return x * f;
}
// 快写函数
inline void write(int x) {
 if (x < 0) {
 putchar('-');
 x = -x;
 }
 if (x > 9) write(x / 10);
 putchar(x % 10 + '0');
}
// 判断是否满足条件
int cannot(int i) {
 long long t = sqrt((long long)i * (long long)(i + 1) / 2);
 if (t * t == (long long)i * (long long)(i + 1) / 2) {
 return 1;
 }
 return 0;
}
// 输出数组元素
void print(int x) {
 for (int i = 1; i <= x; i++) {
 write(a[i]);
 putchar(' ');
 }
 putchar('\n');
}
int main() {
 n = read();
 while (n--) {
 int x;
 x = read();
 if (cannot(x))
 puts("-1");
 else if (x <= idx)
 print(x);
 else {
 for (int i = idx + 1; i <= x; i++) {
 if (cannot(i)) continue;
 else if (i == idx + 2) {
 a[idx + 1] = i;
 a[idx + 2] = i - 1;
 idx += 2;
 }
 else {
 a[idx + 1] = i;
 idx++;
 }
 }
 print(x);
 }
 }
 return 0;
}