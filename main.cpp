#include <iostream>
#include <fstream>
using namespace std;

int Search(char *str1,char *str2)
{
    char *m=str1;                        //m指向句子
    int i=0,k=0;                        //k统计个数
    while(*m!='\0')
    {
        while(*m!=' ') //单词结束退出循环 查找下个单词
        {
            if(*m!=str2[i])  //遇到不同字母 指向下一个单词
                while(*m!=' ') m++;
            else      //字母相同
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
    cout<<"请输入要查找的单词"<<endl;
    gets(word);
    cout<<"单词的个数："<<Search(sentence,word);
    in.close();
    return 0;
}
