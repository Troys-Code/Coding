#include <iostream>
#include <cmath>
using namespace std;

const double k_Value = .00000000109115;

double Test_InsertionSort_AccuracyOfGraph(double arraySize_n)
{
    return(k_Value * (arraySize_n * arraySize_n) );         ///K(n^2)
}

double Test_MergeSort_AccuracyOfGraph(double arraySize_n)
{
    double k = k_Value * 20;
    return(k*arraySize_n*log(arraySize_n));                 ///k(nlogn)
}

int main()
{
    int n = 100000000;

    cout << "\n\nArray Size \t\tInsertionSort \t\t\tMergeSort\n"
         << n << "\t\t" << Test_InsertionSort_AccuracyOfGraph(n) << " \t\t\t" << Test_MergeSort_AccuracyOfGraph(n) << "\n" <<endl;

    for(int i = 10000; i < 210000; i+= 10000)
        cout << i << "\t\t\t" << Test_InsertionSort_AccuracyOfGraph(i) << "    \t\t\t" << Test_MergeSort_AccuracyOfGraph(i) << endl;
}
