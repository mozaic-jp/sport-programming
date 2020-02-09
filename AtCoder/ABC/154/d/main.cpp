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

using Graph = vector<vector<int>>;

typedef long long ll;
static const ll INF = 1000000000000000000LL;
static const ll MOD = 1000000007;


int main()
{
    //累積わ
    //スライディング最大値
    int p = 0;

    int N, K;
    cin >> N >> K;
    ll sum_m = 0;
    ll isum = 0;
    vector <int> a(N);
    
    REP(i,N)
    {
        cin >> a[i];
    }

    for(int i = 0; i < K; ++i)
    {
        isum += a[i];
    }
    sum_m = isum;

    for(int i = K; i < N; ++i)
    {
        isum += a[i];
        isum -= a[i-K];

        if(sum_m < isum)
        {
            sum_m = isum;
            p = i+1 - K;
        }
    }

    double res = 0;

    for(int i = p; i < p + K; ++i)
    {
        res += (double)(1.0 + a[i])/ double(2.0);
        //cout << a[i] <<endl;
    }


    printf("%.12f\n", res);


    return 0;
}