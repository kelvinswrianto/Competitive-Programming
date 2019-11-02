#include<stdio.h>

int main(){
	
	int n, length;
	int arr[60];
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &length);
		int counter = 0;
		for(int j=0; j<length; j++){
			scanf("%d", &arr[j]);
			for(int k=0; k<j; k++){
				if(arr[j] < arr[k]){
					int temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;
					counter++;
				}
			}
		}
		
		printf("Optimal train swapping takes %d swaps.\n", counter);
//		for(int j=0; j<length; j++){
//			printf("%d ", arr[j]);
//		}
		
	}
	
	return 0;
}
