#include <stdio.h>
#include <stdlib.h>
// solving these problems makes me happy
// this problem seems crazy difficult
int main(){
	int t, res;
	long long int n, a;
	int *check;
	scanf("%d", &t);
	while(t-- > 0){
		scanf("%lld", &n);
		check = malloc(n * sizeof(int));
		res = 1;
		for(int i = 0; i < n; i++){
			check[i] = 0;
		}
		for(int i = 0; i < n; i++){
			scanf("%lld", &a);
			check[a - 1]++;
		}
		int k = 0;
		for (int i = 0; i < n; ++i){
			check[i] += k;
			if(2 < check[i]){
				k = check[i] - 2;
				check[i] = 2; 
			}
			else
				k = 0;
			if(1 == check[i])
				res = 0;
		}
		if(1 == k % 2)
			res = 0;
		// for (int i = 0; i < n; ++i){
		// 	printf("%d ", check[i]);
		// }
		if(res)
			printf("YES");
		else 
			printf("NO");
		printf("\n");
		free(check);
	}
	return 0;
}