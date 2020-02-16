#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;

int main()
{
    string S,res;
    ll K;
    ll iMin = 999999;
    ll majiImin = 999999;
    ll tmp;


    cin >> S >> K;

    res = "1";

    ll end = K;
    if(S.size() < K)end = S.size();
    REP(i,end)
    {
        if(S[i] != '1')
        {
            res = S[i];
            break;
        }
    }

    cout << res << endl;

}

