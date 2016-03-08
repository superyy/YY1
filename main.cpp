#include <iostream>
#include <fstream>

using namespace std;

int ArraySum(int* array, int num)
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
    int length,x;
    cout<<"输入所取数据长度"<<endl;
    cin>>length;
    ifstream in("D:\\Book.txt");
    int* a = new int[length];
    for(int i = 0; i < length; i++)
    {
        in >> x;
        a[i] = x;
    }
    int result = ArraySum(a, length);
    cout << "The result is :" << result <<endl;
    in.close();
    delete a;
    return 0;
}
