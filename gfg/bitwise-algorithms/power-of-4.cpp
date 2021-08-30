// https://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/

#include <iostream>
// Used to prints bits
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    //  and comdition for 0
    if (n && !(n & (n - 1)))
    {
        int bit = 1; 
        int k = n-1;
        int flag = 0;
        while (bit & k) {
            k = k << 1; 
            flag +=1;
        }
        cout <<flag<<"\n";
        if (flag % 2 == 0) {
            cout<<"Power"<<"\n";
        }
        
    }
}