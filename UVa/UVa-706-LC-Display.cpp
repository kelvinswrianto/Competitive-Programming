#include<stdio.h>
#include<string.h>
void printTop(int n, char c, bool ld){
	for(int i=0; i<n; i++){
		if(c=='1' || c=='4'){
			printf(" ");
		}
		else if(c=='2' || c=='3' || c=='5' || c=='7' || c=='8' || c=='9' || c=='6' || c=='0'){
			if(i==0 || i==n-1) printf(" ");
			else printf("-");
		}
	}
	if(!ld) printf(" ");
}
void printMidTop(int n, char c, bool ld){
	for(int j=0; j<n; j++){
		if(j==n-1 && (c=='1' || c=='2' || c=='3' || c=='7' )) printf("|");
		else if(j==n-1 && (c=='4' || c=='8' || c=='9' || c=='0') || j==0 && (c=='4' || c=='8' || c=='9' || c=='0')) printf("|");
		else if(j==0 && (c=='5' || c=='6')) printf("|");
		else printf(" ");
		if(j==n-1 && !ld) printf(" ");
	}
}

void printMid(int n, char c, bool ld){
	for(int i=0; i<n; i++){
		if(c=='1' || c=='7' || c=='0'){
			printf(" ");
		}
		else if(c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='8' || c=='9' ){
			if(i==0 || i==n-1) printf(" ");
			else printf("-");
		}
	}
	if(!ld) printf(" ");
}

void printMidLow(int n, char c, bool ld){
	for(int j=0; j<n; j++){
		if(j==n-1 && (c=='1' || c=='4' || c=='3' || c=='5' || c=='9' || c=='7' )) printf("|");
		else if(j==n-1 && (c=='6' || c=='8' || c=='0') || j==0 && (c=='6' || c=='8' || c=='0')) printf("|");
		else if(j==0 && (c=='2')) printf("|");
		else printf(" ");
		if(j==n-1 && !ld) printf(" ");
	}
}

void printLow(int n, char c, bool ld){
	for(int i=0; i<n; i++){
		if(c=='1' || c=='4' || c=='7' ){
			printf(" ");
		}
		else if(c=='2' || c=='3' || c=='5' || c=='6' || c=='8' || c=='9' || c=='0'){
			if(i==0 || i==n-1) printf(" ");
			else printf("-");
		}
	}
	if(!ld) printf(" ");
}

int main(){
	char s[100];
	int n;
	bool lastDigit;
	while(true){
		scanf("%d %s", &n, &s);
		lastDigit = false;
		if(n == 0){
			break;
		}
		for(int i=0; i<strlen(s); i++){
			if(i==strlen(s)-1){
				lastDigit = true;
			}
			printTop(n+2, s[i], lastDigit);		
		}
		printf("\n");
		
		for(int j=0; j<n; j++){
			lastDigit = false;
			for(int i=0; i<strlen(s); i++){
				if(i==strlen(s)-1){
					lastDigit = true;
				}
				printMidTop(n+2, s[i], lastDigit);
			}	
			printf("\n");
		}
		lastDigit = false;
		for(int i=0; i<strlen(s); i++){
			if(i==strlen(s)-1){
				lastDigit = true;
			}
			printMid(n+2, s[i], lastDigit);		
		}
		printf("\n");
		
		for(int j=0; j<n; j++){
			lastDigit = false;
			for(int i=0; i<strlen(s); i++){
				if(i==strlen(s)-1){
					lastDigit = true;
				}
				printMidLow(n+2, s[i], lastDigit);			
			}	
			printf("\n");
		}
		lastDigit = false;
		for(int i=0; i<strlen(s); i++){
			if(i==strlen(s)-1){
				lastDigit = true;
			}
			printLow(n+2, s[i], lastDigit);
		}
		printf("\n\n");
	}
	return 0;
}
