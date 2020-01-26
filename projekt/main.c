#include <stdio.h>
#include <stdlib.h>


int get_num(FILE* f, int* res)
{
fscanf(f,"%d",res);
return 0;
}

int get_char(FILE* f, char* cres)
{
fscanf(f,"%c",cres);
return 0;
}


int main()
{
char *pend, *tekst;
int val;
signed int n;
FILE *fp=NULL;
char buff[32];

fp=fopen("i1.txt","r");

/*for (int i=0; i<=n;i++)
	{
	fscanf(fp,"%s",buff);
	val = strtol(buff,&pend,10);

	if (i==1) tekst = "Pierwszy";
	else if (i==n) tekst = "Ostatni";
	else tekst = "Nastepny";

	if(i==0){
		n=val;
		printf("Spodziewam sie %d elementow\n",n);
	}
	else{
		if (pend == buff) printf("%s element to litera/y: %s\n", tekst, buff);
		else printf("%s element to liczba: %d\n", tekst, val);
	}
	}
*/

int amount, arg1, arg2;
get_num(fp,&amount);
printf("%d\n",amount);
for(int i=0;i<1;i++)
{
char chr;
get_char(&chr);
get_char(&chr);
switch(chr)
{
case 'i':
	get_num(fp,&arg1);
	get_num(fp,&arg2);
	break;
case 'a':
	get_num(fp,&arg1);
	break;
}

printf("i: %d\n", arg1);

}

fclose(fp);
return 0;
}
