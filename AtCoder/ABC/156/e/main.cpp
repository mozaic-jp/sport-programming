#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <unistd.h>
#include <bits/stdc++.h>

#define pii pair<int,int>
#define REP(i, n) for (long long i = 0; i < (n); i++) 
using namespace std;


typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    //100円紙幣で支払ったら10円のお釣りをもらうことになる
    //1000円紙幣で支払ったら100円のお釣りをもらうことになる

    vector <vector <ll>> dp(s.size()+1, vector<ll>(2,INF));
    //dp[n][0]:ピッタリはらう
    //dp[n][1]:余分にはらう
    dp[0][0] = 0;

    for(int i = 0; i < N; ++i)
    {
        for(int q = 0; q < 2; ++q)
        {
            int num = s[N-1-i] - '0';
            num += q;
            if(num == 10)
            {
                //余分に払う択しかない?
                dp[i+1][1] = min(dp[i+1][1], dp[i][q]);
                continue;
            }
            dp[]


        }


        
        //ピッタリ払う
        dp[i+1][0] = dp[i][0] + num;
        
        //余分に払う
        dp[i+1][1] = dp[i][0] + num+1 -;

        
        int mae = num;

    }





    return 0;
}