#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;

int buildTime[MAX_N], dp[MAX_N];

vector<int> buildOrder[MAX_N];

void reset()
{
    for (auto &i : dp)
    {
        i = -1;
    }

    for (auto &i : buildOrder)
    {
        i.clear();
    }
}

int solve(int here)
{
    auto &ret = dp[here];

    if (ret != -1)
    {
        return ret;
    }

    ret = buildTime[here];

    for (auto i : buildOrder[here])
    {
        ret = max(ret, buildTime[here] + solve(i));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        reset();

        int n, K;
        cin >> n >> K;

        for (int i = 1; i <= n; ++i)
        {
            cin >> buildTime[i];
        }

        while (K--)
        {
            int X, Y;
            cin >> X >> Y;
            buildOrder[Y].emplace_back(X);
        }

        int W;
        cin >> W;

        cout << solve(W) << '\n';
    }

    return 0;
}