// Read integers A and B from input file and write their sum in output file.


// Input

// Input file contains A and B (0<A,B<10001).


// Output

// Write answer in output file.


// Sample Input

// 5 3
// Sample Output

// 8

#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << (a > 0 && b < 10001 ? a+b : -1) << endl;
    return 0;
}