#include<stdio.h>

int fun(int inp, int sum=0){
	if(inp == 1){
		sum++;
		return sum;
	}
	else if(inp%2 != 0){
		inp = 3*inp + 1;
	}
	else{
		inp = inp/2;
	}
	sum++;
	return fun(inp, sum);
}

int main(){
	int a, b;
	int max, res;
	while(scanf("%d %d", &a, &b) != EOF){
		max = 0;
		int x, y;
		if(a > b){
			x = b;
			y = a;
		}
		else{
			x = a;
			y = b;
		}
		for(int i=x; i<=y; i++){
			res = fun(i, 0);
			if(res > max){
				max = res;
			}
		}
		printf("%d %d %d\n", a, b, max);	
	}
	
	return 0;
}
