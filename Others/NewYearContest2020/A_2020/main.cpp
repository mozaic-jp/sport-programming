#include <iostream>

using namespace std;

int solve()
{
    int y,m,d;
    int day;
    cin >> y >> m >> d;
    day = y * 10000 + m * 100 + d;

    string res;
    if(day >= 20190501)
    {
        res = "REIWA";
    }
    else
    {
        res = "HEISEI";
    }
    cout << res << endl;
    return 0;
}

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}
