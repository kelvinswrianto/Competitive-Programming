#include <iostream>
#include <vector>
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



int main()
{
    int scenario;
    cin >> scenario;
    for(int i=0; i<scenario; i++){
        int coin[105], coinNum;
    	cin >> coinNum;
		int total = 0;
    	for(int i=0; i<coinNum; i++){
    		cin >> coin[i];
			total += coin[i];
	    }
		// cout << process(coin, coinNum, total/2);
		cout << total - (process(coin, coinNum, total/2)*2) << endl;
    }
	return 0;
}
