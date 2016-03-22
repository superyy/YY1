#include <iostream>
#include <cstring>
//#include <stdio.h>
#include <fstream>
using namespace std;

void func(char result[][100]);
int main()
{   int count = 1;
    char result[100][100] = {0};
    func(result);
    for(int i = 0; strlen(result[i]); i++)
    {
       for(int j = i + 1; strlen(result[j]); j++)
       {
            int count = 1;
            if(!strcmp(strlwr(result[i]), strlwr(result[j])))
            {
                count++;
            }
       }
       cout << result[i] << '\t' << count <<endl;

    }

    return 0;
}



void func(char result[][100])
{
    char buff[100];
    ifstream in("D:\\A_Tale_of_Two_Cities.txt");
    int j = 0;
    char ch;
    if(in)
    {
        in >> noskipws;
        while(in >> ch)
            {
            int i = 0;
            if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
                {
                    buff[i++] = ch;
                }
                    else
                {
                    continue;
                }
            while(in >> ch && ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
            {
                buff[i++] = ch;
            }
            buff[i] = '\0';
            if(strlen(buff) >= 1)//4
            {
                strcpy(result[j++],buff);
            }
        }

       in.close();
    }


}
