#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void func(char result[][100]);
int main()
{
char result[100][100] = { 0 };
func(result);       //����func�������ʱ��result������������ж��ǵ����ˣ��ҵ��ʶ���Сд
char temp[100][100] = { 0 };       //�����ά������������űȽ����û���ظ��ĵ���
int count[100] = { 0 };         //��������
strcpy(temp[0], result[0]);     //�Ƚ���һ�����ʷ���temp
int num = 1;
for (int j = 0; *result[j]; j++) {  //ѭ���������еĵ���
for (int i = 0; *temp[i]; i++) {    //ѭ����ŵ�����
if (!strcmp(temp[i], result[j])) {  //���������������������ʾ�count++
count[i]++;
}
else if(i == num - 1){  //�ѵ㣺û�еĻ������ж����ʱ��i�ǲ����Ѿ��ڴ����������һ��Ԫ���ˣ����ǻ���Ҫ���������ѭ��ֱ���������ŵ�����
strcpy(temp[num++], result[j]); //������������Ҳû�иõ��ʣ��Ͱ�������ʷ�����������
}
}
}
for (int i = 0; i < num - 1; i++) {     //���
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
in >> noskipws; //�������ո�
while (in >> ch) {  //������
int i = 0;
if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') { //��������ĸ�Ļ��Ϳ��Լ�������ĳ��������ڽ������жϣ�
buff[i++] = ch;
}
else {      //�����ǵ�����ת�����������ж�ʣ�µ��ַ�
continue;
}
while (in >> ch && ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {    //ͨ��whileѭ������һ������
buff[i++] = ch;
}
buff[i] = '\0'; //�����ǽ�����\0����
if (strlen(buff) >= 4) {    //�жϵ��ʳ����ǲ��Ǵ��ڵ���4
strcpy(result[j++], strlwr(buff));      //�ǵĻ��ͽ��䱣�浽��ά������ȥ�������ڷŽ�ȥ��ͬʱ��֤��ĸ����Сд��Ϊ�������ıȽ��̵�
}
}

in.close();
}
}
