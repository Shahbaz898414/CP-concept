#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int n;
long long S;
const int N = 1e5 + 5;
int a[N];
long long b[N];
long long check(long long x){
    for(int i = 1;i <= n;i++){
        b[i] = a[i] + x * i;
    }
    sort(b + 1,b + 1 + n);
    long long sum = 0;
    for(int i = 1;i <= x;i++){
        sum += b[i];
    }
    if(sum <= S) return sum;
    else return -1;
}
 
int main(int argc, const char * argv[]) {
    while(cin >> n >> S){
        for(int i = 1;i <= n;i++){
            scanf("%d",a + i);
        }
        int l = 0,r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(check(mid) >= 0){
                l = mid;
            }else r = mid - 1;
        }
        cout << l << " " << check(l) << endl;
    }
    return 0;
}