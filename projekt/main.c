#include <stdio.h>
#include <stdlib.h>

int main()
{
char *pend, *tekst;
int val;
signed int n;
FILE *fp=NULL;
char buff[32];

fp=fopen("i1.txt","r");

for (int i=0; i<=n;i++)
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

fclose(fp);
return 0;
}
