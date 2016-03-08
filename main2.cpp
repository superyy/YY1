#include <iostream>

using namespace std;

int ArraySum(int array[], int num)
{
    int sum = 0;
    for(int i = 0; i < num; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int result;
    int length=3;
    int a[3] = {-2574,-4010,8243};
    result = ArraySum(a, length);
    cout << "The result is :" << result <<endl;
    return 0;
}
