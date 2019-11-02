#include<iostream>
#include<string>
#include<sstream>
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
    int cases, temp, arr[25], total;
    string inp;
    cin >> cases;
    getline(cin, inp);
    for(int i=0; i < cases; i++){
        getline(cin, inp);
        stringstream a(inp);
        int index = 0;
        total = 0;
        while(a >> temp){
            arr[index] = temp;
            total += temp;
            index++;
        }

        int res = process(arr, index, total/2);
        if(res*2 == total){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }        
    }  

    return 0;
}
