#include<stdio.h>

int main(){
	int inp;
	int rem, get, sum;
	
	
	while(scanf("%d", &inp) != EOF){
		sum = inp;
		while(true){
			get = inp/3;
			sum += get;
			rem = inp%3;
			if(get + rem > 3){
				inp = get + rem;
			}
			else if(get + rem >= 2){
				sum += 1;
				break;
			}
			else{
				break;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
