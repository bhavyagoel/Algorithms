// 2021-08-26T03:44:04+05:30

/**
* * Calculating the exponential value
* ! Traditional method using O(n) using ercursive for loop.
* ? Converting to binary and caclulating decreases time complexity to O(logn)
*/

#include <iostream>
using namespace std;

int recursive(int a, int b)
{
    int res = 1;
    if (b == 0)
    {
        return res;
    }
    else
    {
        for (int i = 0; i < b; i++)
        {
            res = res * a;
        }
    }
    return res;
}

int exponent(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = exponent(a, b);
    cout << ans << "\n";

    ans = recursive(a, b);
    cout << ans << "\n";
}