#include<stdio.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;
vector<long long int> primes;
vector<long long int> prime(1000000, 1);

void primeList(){
    prime[1] = 0;
    prime[0] = 0;
    for(long long int i=2; i<=1000000; i++){
        if(prime[i] == 1){
            for(long long int j=i*i; j<=1000000; j+=i){
                prime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

bool isPrime(long long num){
    if(num <= 1000000){
        if(prime[num] == 1){
            return true;
        }
        return false;
    }

    for(long long p: primes){
        if(p*p > num){
            return true;
        }
        if(num%p == 0){
            return false;
        }
    }
    return true;
}

int main(){
    primeList();
    long long a, b, counter;
    long long idxStart=0, idxEnd=0;
    long long min, max, range;
    long long close1, close2, distant1, distant2;
    bool start;
    string inp;



    while(getline(cin, inp)){
        stringstream s(inp);
        s >> a >> b;
        start = true;
        min = b+1;
        max = 0;
        range = idxStart = idxEnd = 0;
        close1 = close2 = distant1 = distant2 = 0;

        for(long long i=a; i<=b; i++){
            // printf("%d ", isPrime(i));
            // int d = isPrime(i);
            if(isPrime(i)){
                
                if(idxStart == 0 && start == true){
                    idxStart = i;
                    start = false;
                }
                else if(idxEnd == 0 && start == false){
                    idxEnd = i;
                    start = true;
                }
                if(idxStart != 0 && idxEnd != 0){
                    range = idxEnd - idxStart;
                    if(range > max){
                        distant1 = idxStart;
                        distant2 = idxEnd;
                        max = range;
                    }
                    if(range < min){
                        close1 = idxStart;
                        close2 = idxEnd;
                        min = range;
                    }
                    idxStart = idxEnd;
                    idxEnd = 0;
                    start = false;
                }
            }
            
        }

        if(max == 0){
            printf("There are no adjacent primes.\n");
        }
        else{
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", close1, close2, distant1, distant2);
        }
    }
    return 0;
}