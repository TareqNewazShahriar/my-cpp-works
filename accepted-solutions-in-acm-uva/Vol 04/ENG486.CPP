#include<stdio.h>
#include<string.h>
void main()
{	int i,k; char q,w, s[130],str[50][10],out[11],ss[10];
	strcpy(str[0],"zero");strcpy(str[1],"one");
	strcpy(str[2],"two");strcpy(str[3],"three");strcpy(str[4],"four");
	strcpy(str[5],"five");strcpy(str[6],"six");strcpy(str[7],"seven");
	strcpy(str[8],"eight");strcpy(str[9],"nine");strcpy(str[10],"ten");
	strcpy(str[11],"eleven");strcpy(str[12],"twelve");strcpy(str[13],"thirteen");
	strcpy(str[14],"fourteen");strcpy(str[15],"fifteen");
	strcpy(str[16],"sixteen");strcpy(str[17],"seventeen");
	strcpy(str[18],"eighteen");strcpy(str[19],"nineteen");
	strcpy(str[20],"twenty");strcpy(str[21],"thirty");strcpy(str[22],"forty");
	strcpy(str[23],"fifty");strcpy(str[24],"sixty");strcpy(str[25],"seventy");
	strcpy(str[26],"eighty");strcpy(str[27],"ninety");strcpy(str[28],"hundred");
	strcpy(str[29],"thousand");strcpy(str[30],"million");
	strcpy(str[31],"negative");
	int tho,han,mil,len;
//freopen("input.txt","r",stdin);
	while(gets(s))
	{	len=strlen(s); tho=0; han=0; mil=0; q=0;
		for(len--,k=0;len>1;len--)
		{    if(s[len]==32||len<3)
			{    if(len<3) len=0;
				else { s[len]=0; len++; }
				strcpy(ss,&s[len]); w=0;
				if(strcmp(ss,str[31])==0) { out[k++]='-'; w=1; }
				else if(q==0)
				{ for(i=0;i<10;i++)
					if(strcmp(ss,str[i])==0)
					{ out[k++]=i+48;w=1;q=1; tho++;han++;mil++; break; }
					if(q==0)
					for(i=10;i<20;i++)
					{	if(strcmp(ss,str[i])==0)
						{ out[k++]=(i%10)+48; out[k++]=49;
						  q=3; tho+=2; han+=2; mil+=2; w=1;break;
						}
					}
				}
				if(q<2&&w==0)
				{	for(i=20;i<28;i++)
					{	if(strcmp(ss,str[i])==0)
						{w=1;if(q==0)
							{    out[k++]=48; out[k++]=(i+30);
								tho+=2; han+=2; mil+=2; break;
							}
							else{out[k++]=i+30;tho++;han++;mil++;break;}
						}
					} q=3;
				}
				if(q!=2&&w==0)
				{	for(i=28;i<31;i++)
					{	if(strcmp(ss,str[i])==0)
						{if(i==28) for(i=han;i<2;i++)
								{ out[k++]=48; mil++; tho++; }
						 else if(i==29)for(;tho<3;tho++)
									{ out[k++]=48; mil++;}
						 else for(;mil<6;mil++) out[k++]=48;
						 q=0;han=0; break;
						}
					}
				}
			}
		} for(k--;k>-1;k--) printf("%c",out[k]); printf("\n");
	}
}