/** 
 * ? The purpose of this problem is to verify whether 
 * ? the method you are using to read input data is 
 * ? sufficiently fast to handle problems branded with 
 * ? the enormous Input/Output warning. You are expected 
 * ? to be able to process at least 2.5MB of input data 
 * ? per second at runtime.
**/
#include "iostream"
using namespace std;

bool divTest(int num, int k)
{
    if (num % k == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (divTest(num, k))
        {
            count += 1;
        }
    }
    cout << count;
}