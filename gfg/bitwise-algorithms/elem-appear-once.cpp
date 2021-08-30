// https://www.geeksforgeeks.org/find-the-element-that-appears-once/

#include <iostream>
// Used to prints bits
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

// For elements repeated even times
int elem_once_even(int arr[], int n)
{
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        ones = ones ^ arr[i];
    }
    return ones;
}

// For elements repeated odd times
int elem_once_odd(int arr[], int n)
{
    int ones = 0, twos = 0;
    int common_bit_mask;

    for (int i = 0; i < n; i++)
    {
        twos = twos | (ones & arr[i]);
        // cout << "Twos :\t" << bitset<4>(twos) << endl;

        ones = ones ^ arr[i];
        // cout << "Ones :\t" << bitset<4>(ones) << endl;

        common_bit_mask = ~(ones & twos);
        // cout << "Comn :\t" << bitset<4>(common_bit_mask) << endl;

        ones &= common_bit_mask;
        // cout << "Ones :\t" << bitset<4>(ones) << endl;

        twos &= common_bit_mask;
        // cout << "Twos :\t" << bitset<4>(twos) << endl;
    }

    return ones;
}

// Using bit position count
int position_count(int arr[], int n)
{
    int tn = INT_MAX;
    int tnp1 = 0;
    int tnp2 = 0;

    for (int i = 0; i < n; i++)
    {
        int cwtn = tn & arr[i];
        int cwtnp1 = tnp1 & arr[i];
        int cwtnp2 = tnp2 & arr[i];

        tn = tn & ~(cwtn);
        tnp1 = tnp1 | cwtn;

        tnp1 = tnp1 & ~(cwtnp1);
        tnp2 = tnp2 | cwtnp1;

        tnp2 = tnp2 & ~(cwtnp2);
        tn = tn | cwtnp2;
    }

    return tnp1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int obj = elem_once_even(arr, n);
    cout << "Even \t" << obj << "\n";

    obj = elem_once_odd(arr, n);
    cout << "Odd \t" << obj << "\n";

    obj = position_count(arr, n);
    cout << "Odd \t" << obj << "\n";
}