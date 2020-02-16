#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm> // sort
#include <iomanip>
#include <queue>
#include <map>
#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
typedef pair<int,int> pint;

using namespace std;

const int MOD = 1000000007;

int main(){

    string s;
    cin >> s;
    vector <int> a(26, 0);
    string res = "yes";

    REP(i,s.size())
    {
        int n = s[i]-'0';
        a[n]++;
        if(a[n] > 1)
        {
            res = "no";
            break;
        }
    }
    cout << res << endl;
    
    return 0;     
}

