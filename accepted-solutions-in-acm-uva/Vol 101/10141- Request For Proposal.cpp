#include<stdio.h>
#include<string.h>

#define R 200

void main()
	{
	//freopen("10141.in","r",stdin);

	int cs=0,req,prop,offer,i, highest;
	double price,lowp; 
	char met[R],com[R],comp[R],q=0;

	scanf("%d%d",&req,&prop); 
	gets(met); // taking the \n

	while(req||prop)
		{
		if(q) putchar('\n'); q=1;

		for(i=0;i<req;gets(met),i++);
		lowp=99999999999.0; highest=-1;
		
		for(;prop;prop--)
			{
			gets(com);
			scanf("%lf%d",&price,&offer);
			gets(met); // taking the \n

			for(i=0;i<offer;gets(met),i++);
			
			if(offer>highest)
				{ highest=offer; lowp=price; strcpy(comp,com); }
			else if(offer==highest&&lowp>price)
				{ strcpy(comp,com); lowp=price; }
			}
		printf("RFP #%d\n%s\n",++cs,comp);

		scanf("%d%d",&req,&prop);
		gets(met); // taking the \n
		}	
	}