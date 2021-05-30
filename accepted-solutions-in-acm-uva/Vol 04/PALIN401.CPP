#include<stdio.h>
#include<string.h>
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int len)
{    int i=0,j=len-1; *(des+len)='\0';
	for(len=len/2+1;i<len;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }}
void main()
{	int k,len; char str[41],s[21],revs[21];
	strcpy(str,"1SE.Z..8........A...3..HIL.JM.O...2TUVWXY5");
	//strcpy(str,"123.5..8........A...E..HIJ.LM.O...STUVWXYZ");
//freopen("input.txt","r",stdin);
	while(scanf("%s",s)!=EOF)
	{	printf("%s -- is ",s);  len=strlen(s);  revcop(revs,s,len); k=0;
		if(strcmp(s,revs)==0) k=1;
		for(len=len/2;len>-1;len--)
			if(s[len]!=str[revs[len]-49]){ k-=2; break; }  k+=2;
		if(k==0) printf("not a palindrome.\n\n");
		else if(k==1) printf("a regular palindrome.\n\n");
		else if(k==2) printf("a mirrored string.\n\n");
		else printf("a mirrored palindrome.\n\n");
	}
}//m