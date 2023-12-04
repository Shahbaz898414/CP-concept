#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring> 
#include <set>
#include <vector>
#include <cmath>
#include <map>
using namespace std;



int c[2020][2020] = {0};
int w[2020] = {0};

int Max;

void fun(int p, int cnt)
{
    for(int i = 0; i < w[p]; i++)
    {
        fun(c[p][i], cnt + 1);
    }
    Max = max(Max, cnt);
}

int main()
{
    int m,n,k;
    while(cin>>n)
    {
        memset(c, 0, sizeof(c));
        memset(w, 0, sizeof(w));
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;
            Max = 0;
            if(x == -1)
            {
                c[0][w[0]++] = i;
            }else
            {
                c[x][w[x]++] = i;
            }
        }
        fun(0, 0);
        printf("%d\n", Max);
    }
    return 0;
}



