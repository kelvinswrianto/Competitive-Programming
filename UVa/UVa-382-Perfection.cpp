#include<stdio.h>

int sumDivisor(int num){
	int sum = 0;
	for(int i=1; i<num; i++){
		if(num%i == 0){
			sum+=i;
		}
		if(sum > num){
			return sum;
		}
	}
	return sum;
}

int main(){
	int inp[100];
	int out[100];
	int i=0;
//	printf("%d", sumDivisor(28));
//	getchar();
	while(scanf("%d", &inp[i])){
		if(inp[i] == 0){
			break;
		}
//		printf("%d ", inp[i]);
		out[i] = sumDivisor(inp[i]);
		i++;
	}
	printf("PERFECTION OUTPUT\n");
	for(int j=0; j<i; j++){
		if(out[j] == inp[j]) printf("%5d  PERFECT\n", inp[j]);
		else if(out[j] > inp[j]) printf("%5d  ABUNDANT\n", inp[j]);
		else if(out[j] < inp[j]) printf("%5d  DEFICIENT\n", inp[j]);
	}
	printf("END OF OUTPUT\n");

	return 0;
}
