#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;

int main(){
    ll N;
    cin >> N;

    //2で割れれば良い

    ll cnt = 0;
    ll tmp;

    REP(i,N)
    {
        cin >> tmp;
        while(1)
        {
            if(tmp % 2 != 0)break;
            tmp = tmp /2;
            cnt++;
        }
    }

    cout << cnt << endl;

}
