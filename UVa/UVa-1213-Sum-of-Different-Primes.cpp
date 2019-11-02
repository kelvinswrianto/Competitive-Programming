#include<iostream>
#include<string>    
#include<sstream>
#include<vector>
using namespace std;
vector<vector<int>>res(1140, vector<int>(1140, 0));
vector<long long int> primes;
vector<long long int> prime(1140, 1);


void primeList(){
    prime[1] = 0;
    prime[0] = 0;
    for(long long int i=2; i<=1140; i++){
        if(prime[i] == 1){
            for(long long int j=i*i; j<=1140; j+=i){
                prime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

void process(vector<long long int> coin){
    int coinNum = coin.size();
	for(int i=0; i<coinNum; i++){
		for(int j=1120; j>=coin[i]; j--){
            for(int k=0; k<=14; k++){
                if(k==0) res[j][k] = 0;
                else if(k==1 && j==coin[i]) res[j][k] = 1;
                else{
                    res[j][k] += res[j - coin[i]][k-1];
                }
            }
		}
	}
}

int main(){
    primeList();
    process(primes);
    int n, k;
    while(cin >> n >> k){
        if(n == 0 && k == 0){
            break;
        }
        cout << res[n][k] << endl;
    }

    return 0;
}