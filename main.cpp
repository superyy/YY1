#include <iostream>
#include <fstream>
using namespace std;

int Search(char *str1,char *str2)
{
    char *m=str1;                        //mָ�����
    int i=0,k=0;                        //kͳ�Ƹ���
    while(*m!='\0')
    {
        while(*m!=' ') //���ʽ����˳�ѭ�� �����¸�����
        {
            if(*m!=str2[i])  //������ͬ��ĸ ָ����һ������
                while(*m!=' ') m++;
            else      //��ĸ��ͬ
            {
                if(*(m+1)==' ')
                {
                    k++;
                    m++;
                }
                else
                {
                    i++;
                    m++;
                }
            }
        }
        m++;
        i=0;
    }
    return k+1;
}
int main()
{
    char word[100],sentence[100];
    ifstream in("D:\\A_tale.txt");
    int i=0;
    while (in>>sentence[i])
    i++;
    cout<<"������Ҫ���ҵĵ���"<<endl;
    gets(word);
    cout<<"���ʵĸ�����"<<Search(sentence,word);
    in.close();
    return 0;
}
