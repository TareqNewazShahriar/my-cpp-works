#include<stdio.h>
#include<string.h>
void swap(char *a,char *b)
{//s
	char temp;
	if(*a>*b)
	{
		temp=*a; *a=*b; *b=temp;
	}
}//s
void main()
{//m
	long b[3],c[3],g[3];
	int i, j, k, m;
	unsigned long w, r, a[3];
	char x[3], z[3], n[3];
//freopen("input.txt","r",stdin);
	while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&b[0],&b[1],&b[2],&g[0],&g[1],&g[2],&c[0],&c[1],&c[2])!=EOF)
	{//w
		r=4294967295;
		x[3]='\0';  z[3]='\0';
		for(i=0;i<3;i++)
		{//1f
			z[0]=i+1;
			a[i]=g[i]+c[i];
			for(j=0;j<3;j++)
			{//2f
				if(j!=i)
				{//3i
					z[1]=j+1;
					a[j]=b[j]+c[j];
					w=a[i]+a[j];
					for(k=0;k<3;k++)
					{//3f
						if(k!=i && k!=j)
						{//4i
							z[2]=k+1;
							a[k]=b[k]+g[k];
							w+=a[k];
							if(w<r)
							{//1i
								strcpy(x,z);
								strcpy(n,z);
								r=w; m=0;
							}//1i
							else if(r==w)
							{//1ei
								strcpy(n,z);
								m++;
							}//1ei
						}//4i
					}//3f
				}//3i
			}//2f
		}//1f
		if(m>1)
			printf("BCG %ld\n",r);
		else
		{//
			for(i=0;i<3;i++)
			{//5f
				if(x[i]==1)
					x[i]='B';
				else if(x[i]==2)
					x[i]='G';
				else
					x[i]='C';

				if(n[i]==1)
					n[i]='B';
				else if(n[i]==2)
					n[i]='G';
				else
					n[i]='C';
			}//5f
			if(n[0]!=x[0] || n[1]!=x[1])
			{//5i
				if(n[0]==x[0])
					swap(&x[1],&x[2]);
				else if(n[1]==x[1])
					swap(&x[0],&x[2]);
				else if(n[2]==x[2])
					swap(&x[0],&x[1]);
			}//5i
			printf("%s %ld\n",x,r);
		}//e
	}//w
}//m