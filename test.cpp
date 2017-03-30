#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#define debug
#undef debug
using namespace std;
const int N=100000;
char code[N];
int data[N];
int runPtr=N>>1;
int main(int argc,char** argv){
	ifstream ifile;
	ifile.open(argv[1]);
	//ifile.open("test.bt");
	if(!ifile.is_open()){
		puts("Can not open file!");
		return 1;
	}
#ifdef debug
	puts("File opened!");
#endif
	int p=0;
	char c;
	while(ifile>>c)
		switch(c){
			case '.':
			case ',':
			case '<':
			case '>':
			case '[':
			case ']':
			case '+':
			case '-':
				code[p++]=c;
				break;
			default:
				break;
		}
	ifile.close();
#ifdef debug
	cout<<code<<endl;
#endif
	p=0;
	int len=strlen(code);
	while(p<len){
#ifdef debug
		printf("code prt=%d data ptr=%d\n",p,runPtr);
#endif
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




