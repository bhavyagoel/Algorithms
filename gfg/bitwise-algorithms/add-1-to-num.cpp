// https://www.geeksforgeeks.org/add-1-to-a-given-number/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << (n | 1) << "\n";

    // Flipping all 1s till 0

    int m = 1;
    while (n & m)
    {
        n = n ^ m;
        m <<= 1;
    }

    n = n ^ m;
    cout << n << "\n";

    // 2s Complement ~x = ~(x+1)
    cout << (~(~n)) << "\n";
}