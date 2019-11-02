#include<stdio.h>

// int numofdivisor(int num){
//     int counter = 2;
//     for(int i=2; i<=num/2; i++){
//         if(num%i == 0){
//             counter++;
//         }
//     }
//     return counter;
// }

// int sumofdivisor(int num){
//     int sum = 1 + num;
//     for(int i=2; i<=num/2; i++){
//         if(num%i == 0){
//             sum+=i;
//         }
//     }
//     return sum;
// }

int main(){
    int arrSum[100000];
    int arrNum[100000];
    int n, sumg, sumh;
    int numdiv, sumdiv;
    int a, b, k;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &a, &b, &k);
        sumh = 0;
        sumg = 0;
        
        for(int i=a; i<=b; i++){
            if(arrNum[i] != NULL){
                numdiv = arrNum[i];
                sumdiv = arrSum[i];
            }
            else{
                sumdiv = 0;
                numdiv = 0;
                if(i%k == 0){
                    sumdiv = i + 1;
                    numdiv = 2;
                    for(int j=2; j<=i/2; j++){
                        if(i%j == 0){
                            sumdiv+=j;
                            numdiv++;
                        }
                    }
                    arrSum[i] = sumdiv;
                    arrNum[i] = numdiv;
                }
            }

            
            sumh+= sumdiv;
            sumg+= numdiv;
        }
        printf("%d %d\n", sumg, sumh);
    }


    return 0;
}