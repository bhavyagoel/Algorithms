/**
 * ? Pooja would like to withdraw X $US from an ATM. 
 * ? The cash machine will only accept the transaction if 
 * ? X is a multiple of 5, and Pooja's account balance has 
 * ? enough cash to perform the withdrawal transaction 
 * ? (including bank charges). For each successful withdrawal 
 * ? the bank charges 0.50 $US. Calculate Pooja's account 
 * ? balance after an attempted transaction.
**/

#include "iostream"
#include <bits/stdc++.h>

using namespace std;

float atm(int withdraw, float amt)
{
    if ((withdraw % 5 == 0) && (amt >= (withdraw + 0.50)))
    {
        return amt - withdraw - 0.50;
    }
    else
    {
        return amt;
    }
}

int main()
{
    float amt;
    int withdraw;
    cin >> withdraw >> amt;
    cout << fixed << setprecision(2) << atm(withdraw, amt) << "\n";
    return 0;
}