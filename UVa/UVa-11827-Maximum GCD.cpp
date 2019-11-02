#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int calculateGCD(int a, int b){
    int gcd = 0;
    for(int i=1; i<=a && i<=b; i++){
        if(a%i == 0 && b%i == 0){
            gcd = i;
        }
    }
    return gcd;
}

int main(){
    int a=24, b=36;
    int inp;
    int nums[101], counter=0;
    int maxGCD, gcd;
    string temp;
    
    cin >> inp;
    getline(cin, temp);
    for(int i=0; i<inp; i++){
        getline(cin, temp);
        stringstream ss(temp);
        counter = 0;
        while(ss >> nums[counter]){
            counter++;
        }
        maxGCD = 0;
        for(int j=0; j<counter; j++){
            for(int k=j+1; k<counter; k++){
                gcd = calculateGCD(nums[j], nums[k]);
                if(gcd > maxGCD){
                    maxGCD = gcd;
                }
            }
        }

        printf("%d\n", maxGCD);
    }



    return 0;
}