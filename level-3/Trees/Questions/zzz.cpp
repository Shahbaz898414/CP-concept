#include <iostream>
using namespace std;


long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 


void findABC(int N) {
    // If N is divisible by 3, A and B can be N/3 and C can be set to 1, satisfying the equation.
    if (N % 3 == 0) {

      if(N%2==0){
        cout << N / 3 << " " << N / 3 << " " << 2 << "\n";
      }else
        cout << N / 3 << " " << N / 3 << " " << 1 << "\n";
    } else {
        // If N is not divisible by 3, there is no possible solution as per the trick used.
        cout << "-1\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        findABC(N);
    }
    return 0;
}

