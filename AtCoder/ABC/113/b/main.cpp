#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;

int main()
{
    ll N,res,T,A;
    cin >> N >> T >> A;

    double iMin;
    iMin = 10000000.0;
    double x,tmp;

    REP(i,N)
    {
        cin >> x;
        tmp = T -  x * 0.006;
        if(iMin > abs(tmp- A))
        {
            iMin = abs(tmp- A);
            res = i+1;
        }
    }

    cout << res << endl;

}

