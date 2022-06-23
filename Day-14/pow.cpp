#include<iostream>
using namespace std;

double myPow(double x, int n) {
    if(n==0){
        return 1;
    }
    if (n < 0) { 
        n = abs(n);
        x = 1/x;
    }
    if(n&1){
        return x*myPow(x*x,n/2);
    
    }else{
        return myPow(x*x,n/2);
    }
}

int main() {
    double x;
    int n;
    cin >> x >> n;

    cout << myPow(x, n) << endl;
    return 0;
}