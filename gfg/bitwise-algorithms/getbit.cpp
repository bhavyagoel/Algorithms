// Find bit at particular position

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i;
    cin >> i;

    cout << ((n & (1 << i)) != 0) << "\n";
}