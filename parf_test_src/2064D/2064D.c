#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int w[200005],pre[200005],pos[200005][31];
int get_bitwidth(int a)
{
 int cnt=0;
 while (a>0)
 {
 cnt++;
 a=a/2;
 }
 return cnt;
}
int main()
{
 int t,n,q,x,bw,h,tail,ans;
 scanf("%d",&t);
 for (int num=1; num<=t; num++)
 {
 scanf("%d%d",&n,&q);
 for (int i=1; i<=n; i++) scanf("%d",&w[i]);
 pre[0]=0;
 for (int i=1; i<=n; i++) pre[i]=pre[i-1]^w[i];
 for (int i=1; i<=30; i++) pos[0][i]=0;
 for (int i=1; i<=n; i++)
 {
 bw=get_bitwidth(w[i]);
 for (int j=1; j<=bw; j++) pos[i][j]=i;
 for (int j=bw+1; j<=30; j++) pos[i][j]=pos[i-1][j]; 
 }
 for (int i=1; i<=q; i++)
 {
 scanf("%d",&x);
 ans=0; tail=n;
 pre[n+1]=pre[n]^x;
 while (tail>0&&x>0)
 {
 bw=get_bitwidth(x);
 h=pos[tail][bw];
 ans=ans+(tail-h);
 //printf("%d ",x);
 x=pre[h]^pre[tail]^x;
 //printf("%d %d %d %d\n",h,tail,pre[h]^pre[tail],x);
 if (x<w[h]||h==0) break; else {x=x^w[h]; tail=h-1; ans++;}
 }
 printf("%d ",ans);
 }
 printf("\n");
 }
}