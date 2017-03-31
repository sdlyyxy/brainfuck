#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cctype>
#define debug
#undef debug
using namespace std;
const int N=100000;
char code[N];
char data[N];
int runPtr=N>>1;
int p=0;
int status(){
	printf("code prt=%d data ptr=%d\n",p,runPtr);
	if(isalnum(data[runPtr])||ispunct(data[runPtr]))printf("code[%d]='%c' data[%d]='%c'\n",p,code[p],runPtr,data[runPtr]);
	else printf("code[%d]='%c' data[%d]='\\%d'\n",p,code[p],runPtr,data[runPtr]);
	printf("%s\n",code);
	for(int i=0;i<p;i++)putchar(' ');
	puts("^");
	puts("");
	return 0;
}
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
	//int p=0;
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
	static int cnt=0;
	if(cnt++<=1000)status();
	//if(p>=61)status();
	//printf("r=%d\n",runPtr);
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
				char c;
				while((c=getchar())==26);
				//windows input eof on keyboard adds '\26'
				data[runPtr]=c;
				}
				break;
			case '[':
				if(!data[runPtr]){
					int cnt=1;
					while(cnt){
						p++;
						if(code[p]=='[')cnt++;
						if(code[p]==']')cnt--;
					}
				}
				break;
//note that '[' will not just find the nearest ']'!i.g. [[]] the first '[' will find the last ']'!!1
//this is why I failed the first time.
			case ']':
				if(data[runPtr]){
					int cnt=1;
					while(cnt){
						p--;
						if(code[p]==']')cnt++;
						if(code[p]=='[')cnt--;
					}
				}
				break;
			default:
				break;
		}
		p++;
	}
	return 0;
}




