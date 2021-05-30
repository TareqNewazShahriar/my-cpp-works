#include <stdio.h>
void main()
{
	char ch, q='s';
	while (scanf("%c",&ch)!=EOF)
	{
		if ( (ch=='"')&&(q=='s') )
		{
			printf("``");
				q='e';
		}
		else if ( (ch=='"')&&(q=='e') )
		{
			printf("''");
			q='s';
		}
		else
			printf("%c",ch);
	}
}