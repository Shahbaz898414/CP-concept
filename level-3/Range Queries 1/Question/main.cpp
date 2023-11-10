// #include <iostream>

// #include <bits/stdc++.h>




// bool isPrime(int n) {
//     if (n <= 1) {
//         return false;
//     }
//     if (n == 2) {
//         return true;
//     }
//     if (n % 2 == 0) {
//         return false;
//     }
//     for (int i = 3; i <= sqrt(n); i += 2) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// std::string getWinner(int N) {
//     int oddPrimeFactors = 0;
//     int p = 3;
    
//     while (p <= N) {
//         if (N % p == 0 && isPrime(p)) {
//             oddPrimeFactors++;
//         }
//         p += 2;
//     }

//     if (N == 0 || oddPrimeFactors % 2 == 0) {
//         return "Bob";
//     } else {
//         return "Alice";
//     }
// }

// int main() {
//     int T;
//     std::cin >> T;

//     for (int i = 0; i < T; i++) {
//         int N;
//         std::cin >> N;
//         std::cout << getWinner(N) << std::endl;
//     }

//     return 0;
// }



// #include <iostream>
// #include <cmath>

// bool isPrime(int n) {
//     if (n <= 1) {
//         return false;
//     }
//     if (n == 2) {
//         return true;
//     }
//     if (n % 2 == 0) {
//         return false;
//     }
//     for (int i = 3; i <= sqrt(n); i += 2) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// std::string getWinner(int N) {
//     if (N == 0 || N % 2 == 0) {
//         return "Bob";
//     } else {
//         return "Alice";
//     }
// }

// int main() {
//     int T;
//     std::cin >> T;

//     for (int i = 0; i < T; i++) {
//         int N;
//         std::cin >> N;
//         std::cout << getWinner(N) << std::endl;
//     }

//     return 0;
// }



/*


Alice and Bob play a game.  They start with the integer  N and take turns, with Alice going first. On their turn, a player must select an odd prime factor   p of  N, and subtract it from   N (so  N changes to N−p).  The player who cannot make a move loses (that is, if either  N=0 or   N has no odd prime factors). If Alice and Bob play optimally, who wins the game?  Input Format The first line of input will contain a single integer  T, denoting the number of test cases. The only line of each test case contains a single integer  N — the value Alice and Bob start with. Output Format For each test case, output on a new line the winner of the game — either "Alice" or "Bob" (without quotes).  Each letter of the output may be printed in either uppercase or lowercase, i.e, the strings Bob, BOB, bOb, and boB will all be treated as equivalent.

explain in simple way and code in c++ plz optimize code

*/


#include <iostream>
#include <bitset>

std::bitset<1000001> isPrime; // Using a bitset to store prime flags, assuming the maximum N is 1e6

void generatePrimes() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; p * p <= 1000000; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= 1000000; i += p) {
                isPrime[i] = 0;
            }
        }
    }
}

std::string getWinner(long  long N) {
    if (N > 1000000) {
        return "Alice"; // Return "Alice" for large N (out of range of isPrime array)
    }

    int oddPrimeFactors = 0;
    for (int p = 3; p <= N; p += 2) {
        if (isPrime[p] && N % p == 0) {
            oddPrimeFactors++;
        }
    }

    if (oddPrimeFactors % 2 == 0) {
        return "Bob";
    } else {
        return "Alice";
    }
}

int main() {
    generatePrimes(); // Precompute primes
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        long long N;
        std::cin >> N;
        std::cout << getWinner(N) << std::endl;
    }

    return 0;
}




