// https://www.geeksforgeeks.org/multiply-an-integer-with-3-5/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;

    //  2x + x + x/2
    cout << (x << 1) + (x) + (x >> 1) << "\n";

    // (8x - x)/2
    cout << ((x << 3) - (x)) / 2 << "\n";

    // 7x / 2
    
}