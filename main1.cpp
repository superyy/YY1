#include <iostream>

using namespace std;

int main()
{
    int array[]={-2574,-4010};
    int sum ;
    for(int i = 0; i < 2; i++)
    {
        sum += array[i];
    }

    cout << "result" << sum <<endl;
    return 0;
}
