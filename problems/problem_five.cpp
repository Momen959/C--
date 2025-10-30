// 102. Coprimes

// time limit per test: 0.25 sec.
// memory limit per test: 4096 KB


// For given integer N (1<=N<=104) find amount of positive numbers not greater than N that coprime with N. Let us call two positive integers (say, A and B, for example) coprime if (and only if) their greatest common divisor is 1. (i.e. A and B are coprime iff gcd(A,B) = 1).


// Input

// Input file contains integer N.


// Output

// Write answer in output file.


// Sample Input

// 9
// Sample Output

// 6



#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n, counter = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1)
            counter++;
    }

    cout << counter << endl;
    return 0;
}
