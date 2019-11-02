#include<iostream>
#include<vector>
using namespace std;

int process(int coin[],int coinNum, int midSum){
	vector<int> valueTaken(midSum+1, 0);
	for(int i=0; i<coinNum; i++){
		for(int j=midSum; j>=0; j--){
			if(coin[i] <= j){
				int temp = coin[i] + valueTaken[j-coin[i]];
				if(valueTaken[j] < temp) valueTaken[j] = temp;
			}
		}
	}

	// for(int i=0; i<=midSum; i++){
	// 	cout << valueTaken[i] << " ";
	// }
	return valueTaken[midSum];
}

int main(){
    int inp;
    int coin[6] = {1, 5, 10, 25, 50};
    vector<int> comb(7495, 0);
    comb[0] = 1;
    for(int i=0; i<5; i++){
        for(int j=1; j<=7490; j++){
            if(j >= coin[i]){
                comb[j] = comb[j] + comb[j-coin[i]];
            }
        }
    }
    while(cin >> inp){
        cout << comb[inp] << endl;
    }    
    return 0;
}