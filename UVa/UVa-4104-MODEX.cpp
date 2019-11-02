#include<stdio.h>


long modex(long a, long b, long c){
    if(a == 0) return 0;
    if(b == 0) return 1;
    long temp;
    if(b%2 == 0){
        // pangkat genap , (a^b)%c  = (a^(b/2) * a^(b/2))%c ,,, (a*b)%c = a%c * b%c
        temp = modex(a, b/2, c);
        temp = (temp%c) * (temp%c);
    }
    else if(b%2 == 1){
        // pangkat ganjil, (a^b)%c = (a*(a^(b-1)))%c ,,, (a*b)%c = a%c * b%c
        temp = a * modex(a, b-1, c);
    }
    return temp%c;
}


int main(){

    long a, b, c, n;
    scanf("%ld", &n);
    for(int i=0; i<n; i++){
        scanf("%ld %ld %ld", &a, &b, &c);
        printf("%ld\n", modex(a, b, c));
    }
    return 0;
}