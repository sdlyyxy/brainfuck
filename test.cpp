#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
using namespace std;
const int N=100000;
char code[N];
int data[N];
int runPtr=N>>1;
int main(int argc,char** argv){
	ifstream ifile;
	//ifile.open(argv[1]);
	ifile.open("test.bt");
	if(!ifile.is_open())return 1;
	int p=0;
	char c;
	while(ifile>>c)code[p++]=c;
	ifile.close();
	cout<<code<<endl;
	p=0;
	int len=strlen(code);
	while(p<len){
		switch(code[p]){
			case '>':
				runPtr++;
				break;
			case '<':
				runPtr--;
				break;
			case '+':
				data[runPtr]++;
				break;
			case '-':
				data[runPtr]--;
				break;
			case '.':
				putchar(data[runPtr]);
				break;
			case ',':{
				char c=getchar();
				data[runPtr]=c;
				}
				break;
			case '[':
				if(!data[runPtr]){
					while(code[p]!=']')p++;
				}
				break;
			case ']':
				if(data[runPtr]){
					while(code[p]!='[')p--;
				}
				break;
			default:
				break;
		}
		p++;
	}
	return 0;
}




