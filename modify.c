#include <shlobj.h>
#include <stdio.h>
#include <string.h>
int main(){	
	//get the locaiton
	char location[MAX_PATH];
	SHGetSpecialFolderPath(0,location,CSIDL_APPDATA,0);
	*strstr(location,"Roaming")=0;
	strcat(location,"LocalLow\\Innersloth\\Among Us\\regionInfo.dat");
	//modify the regioninfo
	FILE *fw=fopen(location,"w+");
	int skeld[]={
		0x00,0x00,0x00,0x00,0x09,0x73,0x6b,0x65,
		0x6c,0x64,0x2e,0x6e,0x65,0x74,0x0f,0x31,
		0x39,0x32,0x2e,0x32,0x34,0x31,0x2e,0x31,
		0x35,0x34,0x2e,0x31,0x31,0x35,0x01,0x00,
		0x00,0x00,0x12,0x73,0x6b,0x65,0x6c,0x64,
		0x2e,0x6e,0x65,0x74,0x2d,0x4d,0x61,0x73,
		0x74,0x65,0x72,0x2d,0x31,0xc0,0xf1,0x9a,
		0x73,0x07,0x56,0x00,0x00,0x00,0x00
		};// Thanks for Skeld.Net's support.
	if(fw!=0){
		int i=0,len=sizeof(skeld)/sizeof(int);
		for(i=0;i<len;i++){
			fputc(skeld[i],fw);
		}
		printf("The file has been rewritten correctly!\nHave a nice time!\n");
	}else{
		printf("Maybe there is something wrong happening!\nplease contact to the developer!\n");
	}
	system("pause");
	return 0;
}
