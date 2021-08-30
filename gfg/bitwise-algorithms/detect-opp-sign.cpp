// https://www.geeksforgeeks.org/detect-if-two-integers-have-opposite-signs/

#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

int main() {
    int a, b;
    cin >> a>> b;

    if ((a ^ b ) < 0 ) { 
        cout << "Opposite\n";
    }
    else {
        cout << "Same\n";
    }
}
