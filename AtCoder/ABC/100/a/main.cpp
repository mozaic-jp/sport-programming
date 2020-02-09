#include <iostream>



#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;

int main(){
    ll A,B;
    string res;


    cin >> A >> B;

    if( A <= 8 && B <= 8)res = "Yay!";
    else res = ":(";

    cout << res << endl;
}


