#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void func(char result[][100]);
int main()
{
char result[100][100] = { 0 };
func(result);       //调用func（）这个时候result这个而且数组中都是单词了，且单词都是小写
char temp[100][100] = { 0 };       //这个二维数组是用来存放比较完的没有重复的单词
int count[100] = { 0 };         //用来计数
strcpy(temp[0], result[0]);     //先将第一个单词放入temp
int num = 1;
for (int j = 0; *result[j]; j++) {  //循环遍历所有的单词
for (int i = 0; *temp[i]; i++) {    //循环存放的数组
if (!strcmp(temp[i], result[j])) {  //存放数组中若是有这个单词就count++
count[i]++;
}
else if(i == num - 1){  //难点：没有的话，先判断这个时候i是不是已经在存放数组的最后一个元素了，不是话还要继续上面的循环直至遍历完存放的数组
strcpy(temp[num++], result[j]); //遍历完存放数组也没有该单词，就把这个单词放入存放数组中
}
}
}
for (int i = 0; i < num - 1; i++) {     //输出
cout << temp[i] << ":" << '\t' << count[i] << endl;
}
return 0;
}



void func(char result[][100]) {
char buff[100];
ifstream in("D:\\source.txt");
int j = 0;
char ch;
if (in) {
in >> noskipws; //不跳过空格
while (in >> ch) {  //（￥）
int i = 0;
if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') { //满足是字母的话就可以继续下面的程序（数字在接下来判断）
buff[i++] = ch;
}
else {      //否则不是单词跳转（￥）继续判断剩下的字符
continue;
}
while (in >> ch && ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {    //通过while循环构造一个单词
buff[i++] = ch;
}
buff[i] = '\0'; //单词是结束以\0结束
if (strlen(buff) >= 4) {    //判断单词长度是不是大于等于4
strcpy(result[j++], strlwr(buff));      //是的话就将其保存到二维数组中去，并且在放进去的同时保证字母都是小写，为接下来的比较铺垫
}
}

in.close();
}
}
