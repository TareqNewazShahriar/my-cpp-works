#include <stdio.h>
void main()
{    char ch;
	while (scanf("%c",&ch)!=EOF )
	{    if (ch!='\n')
		{    ch=ch-7;
			printf("%c",ch);
		}
		else
			printf("%c",ch);
	}
}