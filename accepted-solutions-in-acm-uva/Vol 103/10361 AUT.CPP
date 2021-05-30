#include<stdio.h>
#include<string.h>
void main()
{//m
	int cs, i;
	char q, a, b1[100], b2[100], c1[100], c2[100];
//freopen("input.txt","r",stdin);
	while(scanf("%d",&cs)!=EOF)
	{//w
		scanf("%c",&a);
		for(cs*=2;cs>0;cs--)
		{//5f
			do
			{//4d
				scanf("%c",&a);
				if(a!='<' && a!='.' && a!='>')
					printf("%c",a);
				else if(a=='<')
				{//1ei
					i=0;
					do
					{//d
						scanf("%c",&a);
						if(a!='>')
							b1[i++]=a;
					}while(a!='>');
					b1[i]='\0';
					i=0;
					do
					{//2d
						scanf("%c",&a);
						if(a!='<')
							c1[i++]=a;
					}while(a!='<');
					c1[i]='\0';
					i=0;
					do
					{//d
						scanf("%c",&a);
						if(a!='>')
						b2[i++]=a;
					}while(a!='>');
					b2[i]='\0';
					i=0;
					do
					{//2d
						scanf("%c",&a);
						if(a!='\n')
							c2[i++]=a;
					}while(a!='\n');
					c2[i]='\0';
					printf("%s%s%s%s\n",b1,c1,b2,c2);
				}//1ei
				else if(a=='.')
				{//3ei
					i=1;
					do
					{//2d
					scanf("%c",&a);
					if(a=='.')
						i++;
					}while(i<3 && a=='.');
					if(i==3)
						printf("%s%s%s%s",b2,c1,b1,c2);
					else
					{//e
						for(;i>0;i--)
							printf(".");
						printf("%c",a);
					}//e
				}//3ei
			}while(a!='\n');
		}//5f
	}//w
}//m





