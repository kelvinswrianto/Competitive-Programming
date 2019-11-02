#include<stdio.h>

int main(){
	
	long rev = 0;
	long inp, counter = 0, n, lastDigit, temp;
	scanf("%ld", &n);
	for(int i=0; i<n; i++){
		scanf("%ld", &inp);
		counter = 0;
		while(true){
			temp = inp;
			rev = 0;
			while(temp!=0){
				lastDigit = temp%10;
				rev = (rev*10) + lastDigit;
				temp = temp/10;
			}
			if(inp == rev){
				break;
			}
			inp = inp + rev;
			counter++;
		}
		printf("%ld %ld\n", counter, rev);
	}
	
	
	return 0;
}
