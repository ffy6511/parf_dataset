#include <stdio.h>
#include <stdlib.h>
const long long mod = 998244353;
const int tdep = 17;
struct dval {
 int tvl[3];
 long long w[3];
 long long pw;
};
struct dval combine(struct dval a, struct dval b) {
 struct dval c;
 for (int i = 0; i < 3; i++) {
 c.tvl[i] = a.tvl[b.tvl[i]];
 c.w[i] = (b.w[i] * a.pw + a.w[b.tvl[i]]) % mod;
 }
 c.pw = (a.pw * b.pw) % mod;
 return c;
}
struct dval gen(int t) {
 t--;
 struct dval c;
 for (int i = 0; i < 3; i++) {
 if (i == t) {
 c.tvl[i] = i;
 c.w[i] = 0;
 } else {
 c.tvl[i] = 3 - i - t;
 c.w[i] = 1;
 }
 }
 c.pw = 2;
 return c;
}
struct dval tre[1 << 18];
void upd(int t, int dep, int p, int vl) {
 if (dep == 0) {
 tre[t] = gen(vl);
 return;
 }
 int x = (1 << (dep - 1));
 if (p < x)
 upd(t * 2 + 1, dep - 1, p, vl);
 else
 upd(t * 2 + 2, dep - 1, p - x, vl);
 tre[t] = combine(tre[t * 2 + 1], tre[t * 2 + 2]);
}
struct dval qry(int t, int dep, int l, int r) {
 if (l == 0 && r == (1 << dep))
 return tre[t];
 int x = (1 << (dep - 1));
 if (l < x) {
 if (r <= x)
 return qry(t * 2 + 1, dep - 1, l, r);
 return combine(qry(t * 2 + 1, dep - 1, l, x), qry(t * 2 + 2, dep - 1, 0, r - x));
 }
 return qry(t * 2 + 2, dep - 1, l - x, r - x);
}
int main() {
 int n, q, i, p, x, l, r;
 scanf("%d %d", &n, &q);
 for (i = 0; i < n; i++) {
 scanf("%d", &x);
 upd(0, tdep, i, x);
 }
 char op[10];
 struct dval vl;
 while (q--) {
 scanf("%s", op);
 if (op[0] == 's') {
 scanf("%d %d", &l, &r);
 vl = qry(0, tdep, l - 1, r);
 printf("%lld\n", vl.w[0]);
 } else {
 scanf("%d %d", &p, &x);
 upd(0, tdep, p - 1, x);
 }
 }
 return 0;
}