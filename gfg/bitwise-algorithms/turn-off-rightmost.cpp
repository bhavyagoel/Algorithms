// https://www.geeksforgeeks.org/turn-off-the-rightmost-set-bit/

#include <iostream>
// Used to prints bits
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // bitset<8> a(n);
    // cout << a << "\n";
    int x = 1;
    int k = ~n;
    while (x & k)
    {
        x = x << 1;
        // bitset<8> b(x);
        // cout << b << "\n";
    }

    n = x ^ n;

    // bitset<8> y(n);
    // cout << y << "\n";
    cout << n << "\n";
}