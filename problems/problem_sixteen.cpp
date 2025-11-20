//  115. Calendar

// time limit per test: 0.25 sec.
// memory limit per test: 4096 KB

// First year of new millenium is gone away. In commemoration of it write a program that finds the name of the day of the week for any date in 2001.

// Input

// Input is a line with two positive integer numbers N and M, where N is a day number in month M. N and M is not more than 100.

// Output

// Write current number of the day of the week for given date (Monday – number 1, … , Sunday – number 7) or phrase “Impossible” if such date does not exist.

// Sample Input

// 21 10

// Sample Output

// 7

#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // Days in each month for 2001
    // 0 is placeholder for easier indexing
    int days_in_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


    if (M < 1 || M > 12 || N < 1 || N > days_in_month[M]) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Count total days from Jan 1
    int total_days = 0;
    for (int i = 1; i < M; i++)
        total_days += days_in_month[i];
    total_days += (N - 1);

    // get day of the week
    int day_of_week = (total_days % 7) + 1;

    cout << day_of_week << endl;

    return 0;
}
