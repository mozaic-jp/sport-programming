#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

int main(){
    ll N,K,S;
    cin >> N >> K >> S;

    REP(i,N)
    {
        if(i < K)
        {
            cout << S << " ";
        }
        else 
        {
            if(S < 1000000000)
            {
                cout << S+1 << " ";
            }
            else
            {
                cout << 1 << " ";
            }
            
        }


    }

    return 0;    
}
