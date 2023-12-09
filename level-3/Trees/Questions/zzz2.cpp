#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// using namespace std;

#define ll long long
typedef pair<ll, ll> II;
typedef vector<II> VII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second

bool can_attack(int x, int y, int target_x, int target_y, const vector<pair<int, int>> &knight_moves)
{
    for (auto &move : knight_moves)
    {
        if (x + move.first == target_x && y + move.second == target_y)
            return true;
    }
    return false;
}

int knight_attack_positions(int a, int b, int xK, int yK, int xQ, int yQ)
{
    vector<pair<int, int>> knight_moves = {
        {a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};

    int possiblePositions = 0, g = 0;

    int moves[8][2] = {{a, b}, {-a, -b}, {a, -b}, {-a, b}, {b, a}, {-b, -a}, {b, -a}, {-b, a}};

    set<pair<int, int>> attack_positions;

    for (int i = 0; i < 8; ++i)
    {
        int newX = xK + moves[i][0];
        int newY = yK + moves[i][1];

        // Check if the new position is valid and can attack the queen
        if (abs(newX - xQ) % a == 0 && abs(newY - yQ) % b == 0 && abs(newX - xQ) / a % 2 == abs(newY - yQ) / b % 2)
        {
            possiblePositions++;
        }
    }

    for (auto &move : knight_moves)
    {

        int knight_x = xK + move.first;
        int knight_y = yK + move.second;
        if (can_attack(knight_x, knight_y, xQ, yQ, knight_moves))
        {
            attack_positions.insert({knight_x, knight_y});
        }

        if (abs(knight_x - xQ) % a == 0 && abs(knight_y - yQ) % b == 0 && abs(knight_x - xQ) / a % 2 == abs(knight_y - yQ) / b % 2)
        {
            possiblePositions++;
        }

        knight_x = xQ + move.first;
        knight_y = yQ + move.second;
        if (can_attack(knight_x, knight_y, xK, yK, knight_moves))
        {
            attack_positions.insert({knight_x, knight_y});
        }

        if (possiblePositions > 0)
            possiblePositions *= g;
    }

    possiblePositions += attack_positions.size();

    return possiblePositions;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> arr(n);

        vector<pair<ll, ll>> par;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];

              arr[i]=par.at(i).first;
        par[i].second = i;
            /* code */
        }

        vector<pair<ll, ll>> a(n);

        sort(a.begin(), a.end());
        VI dfr(n, 0);
        VI isFine(n, 0);
        for (ll i = 0; i < n; i++)
        {
            if (i)
                dfr[i] = dfr[i - 1];
            if (dfr[i] >= a[i].first)
            {
                isFine[i] = 1;
            }
            dfr[i] += a[i].first;
        }
        VI next0Pos(n, 0);
        ll nex0 = n;
        for (ll i = n - 1; i >= 0; i--)
        {
            next0Pos[i] = nex0;
            if (isFine[i] == 0)
                nex0 = i;
        }
        VI ans(n, 0);
        for (ll i = 0; i < n; i++)
        {
            ans[a[i].second] = next0Pos[i] - 1;
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
