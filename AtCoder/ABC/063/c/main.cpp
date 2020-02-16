#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(long long i=(a),i##Len_=(b);i<i##Len_;i++)
typedef long long ll;
static const ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector <int> a(N);

    int sum_a = 0;

    REP(i,N)
    {
        cin >> a[i];
        sum_a += a[i];
    }


    if(sum_a % 10 == 0)
    {
        sort(a.begin(),a.end());
        REP(i,N)
        {
            if((sum_a - a[i]) % 10 != 0)
            {
                sum_a -= a[i];
                break;
            }
        }
    }

    if(sum_a % 10 == 0)sum_a = 0;

    cout << sum_a << endl;
}

