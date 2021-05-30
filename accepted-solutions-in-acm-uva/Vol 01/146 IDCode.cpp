#include<stdio.h>
#include<string.h>
void main()
{	int len, i, ar[26];
	char str[50], tmp, q;

	while(scanf("%s",str)!=EOF)
	{// w
		if(strcmp(str,"#")==0)  break;
		for(i=0;i<26;i++)   ar[i]=0;
		len=(strlen(str))-1;  q='0';
		for(;len>0;len--)
		{//1f
			if (str[len] > str[len-1])
			{//2i
				if(q=='0')
				{//0i
					tmp=str[len-1];  str[len-1]=str[len];
					str[len]=tmp;   q='1';   break;
				}//0i

				tmp=str[len-1]-97;  ar[tmp]++;
				tmp=( str[len] )-97;   ar[tmp]++;
				for(i=1;i<26;i++)
					if (ar[i]!=0)
						if ( (str[len-1]) < (i+97) )
						{//6i
							str[len-1]=(i+97);
							if(str[len]!=str[len-1])
							{//7i
								tmp=(str[len-1])-97;
								ar[tmp]--;
							}//7i
							else
							{//2e
								tmp=( str[len] )-97;
								ar[tmp]--;
							}//2e
						break;
						}//6i

				for(i=0;i<=25;i++)
				{//2f
					if(ar[i]!=0)
					{//3i
						for(;ar[i]>0;ar[i]--)
						{//3f
							str[(len)++]=(i+97);
						}//3f
					}//3i
				}//2f
				break;
			}//2i
			else
			{//2e
				tmp=(str[len])-97;
				ar[tmp]++;
				q='1';
			}//2e
		}//1f
		if(len==0)
			printf("No Successor\n");
		else
			printf("%s\n",str);
	}// w
}