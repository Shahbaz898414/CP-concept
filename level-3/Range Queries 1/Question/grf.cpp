#include <iostream>
#include <vector>

using namespace std;

#define ll long long



int main() {

  



  int t;cin>>t;

  while(t--){
     ll array_size, subarray_size;
        cin >> array_size >> subarray_size;

        vector<ll> array_elements(array_size);

        for (auto &element : array_elements)
            cin >> element;

        ll left_index = 0;
        ll count_subarrays = 0;
        ll count_evens = 0, count_odds = 0;

        while (left_index < subarray_size) {
            if (array_elements[left_index] % 2 == 0)
                count_evens++;
            else
                count_odds++;

            left_index++;
        }

        if (count_odds > 0) {
            count_subarrays++;
        }

        for (ll right_index = 0; left_index < array_size; right_index++) {
            if (array_elements[right_index] % 2 == 0)
                count_evens--;
            else
                count_odds--;

            if (array_elements[left_index] % 2 == 0)
                count_evens++;
            else
                count_odds++;

            left_index++;

            if (count_odds > 0) {
                count_subarrays++;
            }
        }

        cout << count_subarrays << endl;

    

   
  }

   

    return 0;
}


/*


*/
