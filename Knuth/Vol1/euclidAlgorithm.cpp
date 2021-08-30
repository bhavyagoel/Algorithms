#include "iostream"
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * todo: finding the greatest common divisor
 * ! find remaider
 * ? if remainder 0, divisor is the ansewr
 * ? else m<-n, n<-r
 * 
**/
int euclid(int m, int n)
{

    int rem = m % n;
    if (rem == 0)
    {
        return n;
    }
    else
    {
        return euclid(n, rem);
    }
}

int main()
{
    auto start = high_resolution_clock::now();

    cout << euclid(100, 121) << "\n";
    cout << euclid(121, 100) << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}