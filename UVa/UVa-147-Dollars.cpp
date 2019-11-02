#include<iostream>
#include<vector>
using namespace std;

int main(){
    float inp;
    int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    vector<long long> comb(30005, 0);
    comb[0] = 1;

    for(int i=0; i<11; i++){
        for(int j=1; j<=30000; j++){
            if(j >= coin[i]){
                comb[j] = (comb[j] + comb[j-coin[i]]);
            }
        }
    }
    int temp;
    while(cin >> inp){
        temp = (inp + 0.001)*100;
        if(temp == 0){
            break;
        }
        printf("%6.2f%17lld\n", inp, comb[temp]);
    }


    return 0;
}