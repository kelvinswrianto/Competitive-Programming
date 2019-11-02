#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;

map<char, int> dataset;


int isPrime(char inp[], map<char, int> dataset){
    int lenInp = strlen(inp);
    int res = 0;
    for(int i=0; i<lenInp; i++){
        res += dataset[inp[i]];
    }
    if(res == 0) return 0;
    if(res == 1) return 1;
    for(int i=2; i*i<=res; i++){
        if(res%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    char inp[100];
    int index=1;
    for(char i='a'; i<='z'; i++){
        dataset[i] = index;
        index++;
    }
    for(char i='A'; i<='Z'; i++){
        dataset[i] = index;
        index++;
    }
    // for(char i='a'; i<='z'; i++){
    //     printf("%d ", dataset[i]);
    // }
    // for(char i='A'; i<='Z'; i++){
    //     printf("%d ", dataset[i]);
    // }
    
    while(scanf("%s", inp) != EOF){
        if(isPrime(inp, dataset) == 1){
            printf("It is a prime word.\n");
        }
        else{
            printf("It is not a prime word.\n");
        }
    }



    return 0;
}