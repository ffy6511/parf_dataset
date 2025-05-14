#include <stdio.h> 
void merge(long long *A,long long l,long long m,long long r){
	long long n1=m-l+1;
	long long n2=r-m;
	long long N1[n1];
	long long N2[n2];
	for(long long i=0;i<n1;i++){
		N1[i]=A[i+l];
	}
	for(long long i=0;i<n2;i++){
		N2[i]=A[i+m+1];
	}
	long long a1=0,a2=0,k=l;
	while(a1<n1&&a2<n2){
		if(N1[a1]>N2[a2]){
			A[k]=N1[a1];
			a1++;
		}
		else {
			A[k]=N2[a2];
			a2++;
		}
		k++;
	}
	while(a1<n1){
		A[k]=N1[a1];
		a1++;
		k++;
	}
	while(a2<n2){
		A[k]=N2[a2];
		a2++;
		k++;
	}
}
void mergeSort(long long *A,long long l,long long r){
	if(l==r)return;
	long long m=(l+r)/2;
	mergeSort(A,l,m);
	mergeSort(A,m+1,r);
	merge(A,l,m,r);
}
int main() { 
 int t; 
 scanf("%d",&t); 
 while(t--){ 
 long long n,m;
 scanf("%lld %lld",&n,&m);
 long long A[n][m];
 //int B[n];
 long long C[n];
 long long D[n];
 for(long long i=0;i<n;i++){
 	C[i]=0;
 	D[i]=0;
 	long long s=0;
 	for(long long y=0;y<m;y++){
 		scanf("%lld",&A[i][y]);
 		C[i]+=A[i][y];
 		D[i]+=A[i][y]+s;
 		s=C[i];
 		//printf("%d!\n",D[i]);
			}
			//printf("%d@\n",D[i]);
		}
		long long res=0;
		long long num=0;
		for(long long i=0;i<n;i++)res+=D[i];
		mergeSort(C,0,n-1);
		for(long long i=0;i<n;i++){
			res+=num*m;
			num+=C[i];
		}
 printf("%lld\n",res);	
 	
 } 
 return 0; 
}