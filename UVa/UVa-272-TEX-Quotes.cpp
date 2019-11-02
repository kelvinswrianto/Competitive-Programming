#include<stdio.h>
#include<string.h>

int main(){
	char sent[1000];
	int j, counter = 0;
	bool status;
//	strcat(res, "hello");
//	printf("%s", res); getchar();
	
	while(scanf("%[^\n]s", sent) != EOF){
		fflush(stdin);
		counter = 0;
		char res[1000]= "";
		for(int i=0; i<strlen(sent); i++){
			if(sent[i] == 34 && status == false){
				res[i+counter] = '\`';
				counter += 1;
				res[i+counter] = '\`';
				status = true;
			}
			else if(sent[i] == 34 && status == true){
				res[i+counter] = '\'';
				counter += 1;
				res[i+counter] = '\'';
				status = false;
			}
			else{
				j = i + counter;
				res[j] = sent[i];
			}
		}
		
		printf("%s\n", res);
	}
	return 0;
}
