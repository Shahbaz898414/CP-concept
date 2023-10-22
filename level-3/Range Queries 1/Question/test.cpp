#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);

        bool fl=0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];

            if(arr[i]%5==0) fl=1;
        }


        if(k==5 and fl==1){
            cout<<0<<endl;
                continue;
        }else if(k==5){
            
        }
        int operations = 100000000;
        for (int i = 0; i < n; ++i) {
            if (arr[i] % k != 0) {
               
                int diff = min(k-arr[i]%k,arr[i]%k);
                operations =min(operations,diff) ;
            }
        }

        cout << operations << endl;
    }

    return 0;
}


