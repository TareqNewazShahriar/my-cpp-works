//#include<stdio.h>
#include<string.h>
#include<time.h>

#define SPC 85
#define R 300
/**************************************************/
void string_brushing(char string[],int retardation,int space);
void marque_string(char string[],int retardation,int space,int screen);
void marging_string(char string[],int retardation,int space);
void spreding_string(char string[],int retardation,int space);
void brought_togather(char string[],int retardation,int space);
void go_back(char string[],int retardation,int back);
void cyclic_string(char string[],int retardation,int space);
void consecutively_appeared(char n[],int retardation,int space);
/*------------------------------------------------*/
void string_brushing(char string[]);
void marque_string(char string[]);
void marging_string(char string[]);
void spreding_string(char string[]);
void brought_togather(char string[]);
void go_back(char string[]);
void cyclic_string(char string[]);
void consecutively_appeared(char n[]);
/**************************************************/
/*----Pauses for a specified number of milliseconds----*/
void sleep( clock_t wait )
{
	clock_t goal;
	goal = wait + clock();
	while( goal > clock() );
}	
/*------------------------------------------------
void main()
{
	char string[]="Tar IQ Newaz Shahriar Shawon"; //"Sabah Alma Maimuna";//"ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //"1234567890";
	//char string[]="1234567891123456789212345678931234567894123456789512345678961234567897123456789"; 
	char marque[]="Programmed By TarIQ Newaz Shahriar                  \
           It was tried to make the program bug free. If any bug is monitored, feel free to mail.";
	
	//string_brushing(string);		//putchar(10);
	//marging_string(string);		//putchar(10);
	//spreding_string(string);	//	putchar(10);
	//marque_string(string);		//putchar(10);
	//go_back(string);			//	putchar(10);
	//brought_togather(string);	//	putchar(10);
	//cyclic_string(string);//	putchar(10);
	
	//=============================================

	//string_brushing(string,20,5);	//	putchar(10);
	//marging_string(string,20,5);	//	putchar(10);
	//spreding_string(string,20,5);	//	putchar(10);
	//marque_string(string,90,5,15);	//putchar(10);
	//brought_togather(string,15,30);	//putchar(10);
	//go_back(string,30,8);			//	putchar(10);
	cyclic_string(string,50,25);		//putchar(10);
	
} //*/
/*-------------Requires sleep function----------------------*/
void cyclic_string(char string[],int retardation,int space)
{
	int i,j,len=strlen(string); const int K=(len+2)/2;
	char ch,*s,*t,str[R],spc[SPC]="                                                                                 ";
	
	for(i=K-1;i>=0;str[i]=' ',i--);
	s=str+K;
	spc[space]=0;  //spc[space-1]='>';	
	for(i=0;string[i];i++) { *(s++)=string[i], *(s++)=' '; } *(--s)=0;
	s--;	
	//printf("%s%s",spc,string);
	for(i=0;i<len;i++,s--)
	{
		sleep(retardation);
		printf("\r%s%s",spc,s);		
	}
	for(i=0,j=len+K-1;i<j;i++,s--)
	{
		ch=s[len]; s[len]=0;
		sleep(retardation);
		printf("\r%s%s",spc,s);
		s[len]=ch;
	}
	t=str+(len*2)+K-2; s++;
	for(i=len-1;i>=0;i--,t--)
	{
		ch=s[i]; s[i]=0;
		sleep(retardation);
		printf("\r%s%s%s",spc,t,s);
 		s[i]=ch;
	}
	j=(len*2)+K-3; t=str+j-len+1;
	retardation+=10;
	for(i=len-1;i;i--,s--,t--,j-=2)
	{
		str[j]=0;
		sleep(retardation);
	 	printf("\r%s%s",spc,t);
	}	
	printf("%s",string+1);
}	
/*-------------Requires sleep function----------------------*/
void go_back(char string[],int retardation,int back)
{
	char *s, str[500]; int i,j=strlen(string);
	strcpy(str,"                                                                                ");
	strcat(str,string);
	s=str+80+j-1;
	for(i=35+8;i<79;i++,s--)
	{
		sleep(retardation);
		printf("\r\t%s",s);
	}
	for(i=0;i<35;i++,s--,retardation++)
	{
		sleep(retardation);
		printf("\r\t%s",s);
	}
	sleep(100);  strcat(str,"                    ");	
	for(i=0,s++;i<back;i++,s++)
	{
		*(s+71)=0;
		sleep(retardation);
		printf("\r\t%s",s);
		*(s+71)=' ';
	}
}	 
/*-------------Requires sleep function----------------------*/
void brought_togather(char string[],int retardation,int space)
{
	int i,j;
	char *s, str[500]="                                                                                 ",
			spc[SPC]="                                                                                ";
	spc[space]=0;
	//k=80-j;
	
	s=str+81;
	for(i=0;string[i];i++) { *(s++)=string[i], *(s++)=' '; } *(--s)=0;
	s--; j=strlen(string);
	space=space+j;
	for(i=0;i<space;i++,s--)
	{
		sleep(retardation);
		printf("\r     %s",s);
	}
	i=j-1;
	j=space-1; retardation=(retardation*2)+5;
	for(;i;i--,s--,j--)
	{
		s[j]=0;			//j=81+(j*2)-3 if str[j]=0
		sleep(retardation);
		printf("\r     %s",s);
	}
	printf("%s",string+1);
}	 
/*-------------requires sleep function----------------------*/
void marque_string(char string[],int retardation,int space,int screen)
{
	char ch,marque[R],spc[SPC]="                                                                                 ";
	spc[screen+1]=0;
	strcpy(marque,spc); strcat(marque,string); strcat(marque,spc);
	spc[screen+1]=' '; spc[space]=0;
	for(int i=0;marque[screen];i++,screen++)
	{
		sleep(retardation);
		ch=marque[screen]; marque[screen]=0;
		printf("\r%s%s",spc,marque+i);
		marque[screen]=ch;
	}
}	
/*-------------requires sleep function----------------------*/
void string_brushing(char string[],int retardation,int space)
{
	int i,j; bool q=0;
	char spc[SPC]="                                                                                 ";
	spc[space]=0;
	j=strlen(string);
	
	//printf("\t0123456789012345678901234567890\n");
	printf("\r%s",spc);
	for(i=1;i<j;putchar(32),i++);
	if(j%2)	q=1;
	for(i=j-1;i>0;i--)
	{	sleep(retardation);
		if(q=!q) printf("%c%c%c",string[i],8,8);
		else printf("%c",8);
	}	
	for(i=0;i<j;i++)
	{	sleep(25);
		putchar(string[i]);
	}
}	
/*-------------Requires sleep function----------------------*/
void marging_string(char string[],int retardation,int space)
{
	int i,j=strlen(string); char temp[R], spc[SPC]="                                                                                 ";
	spc[space]=0;
	for(i=1;i<j;temp[i]=' ',i++); temp[j]=0;
	
	for(i=0,j--;i<=j;i++,j--)
	{	
		temp[i]=string[i]; temp[j]=string[j]; //temp[j+1]=0;
		sleep(retardation);
		printf("\r%s%s",spc,temp);
	}
	//if(i==j) printf("\r\t\t%s",temp[i]);
}	
/*-------------Requires sleep function----------------------*/
void spreding_string(char string[],int retardation,int space)
{
	int i,j=strlen(string); char temp[R], spc[SPC]="                                                                                 ";
	spc[space]=0;
	for(i=0;i<j;temp[i]=' ',i++); temp[j]=0;

	if(j%2) 
	{
		j=(j/2)+1; i=j-2;
		temp[i+1]=string[i+1];
		printf("\r%s%s",spc,temp);
	}
	else { j/=2; i=j-1; }
	
	for(;i>-1;i--,j++)
	{	
		temp[i]=string[i]; temp[j]=string[j]; //temp[j+1]=0;
		sleep(retardation);
		printf("\r%s%s",spc,temp);
	}
	//if(i==j) printf("\r\t\t%s",temp[i]);
}	
/*-------------Requires sleep function----------------------*/
void consecutively_appeared(char n[],int retardation,int space)
{
	char spc[SPC]="                                                                                ";
	spc[space]=0;
	printf("\r%s",spc);
	for(int i=0;n[i];i++)
	{
		sleep(retardation); putchar(n[i]); 
	}
}	

/*****************************************************************************************************/

/*-------------Requires sleep function----------------------*/
void cyclic_string(char string[])
{
	int i,j,len=strlen(string), retardation=50;
	const int K=(len+2)/2;
	char ch,*s,*t,str[R],spc[SPC]="                                                                                 ";
	
	for(i=K-1;i>=0;str[i]=' ',i--);
	s=str+K;
	spc[80-len-15]=0;  //spc[80-len-15-1]='>';	
	for(i=0;string[i];i++) { *(s++)=string[i], *(s++)=' '; } *(--s)=0;
	s--;	
	//printf("%s%s",spc,string);
	for(i=0;i<len;i++,s--)
	{
		sleep(retardation);
		printf("\r%s%s",spc,s);		
	}
	for(i=0,j=len+K-1;i<j;i++,s--)
	{
		ch=s[len]; s[len]=0;
		sleep(retardation);
		printf("\r%s%s",spc,s);
		s[len]=ch;
	}
	t=str+(len*2)+K-2; s++;
	for(i=len-1;i>=0;i--,t--)
	{
		ch=s[i]; s[i]=0;
		sleep(retardation);
		printf("\r%s%s%s",spc,t,s);
 		s[i]=ch;
	}
	j=(len*2)+K-3; t=str+j-len+1;
	retardation+=10;
	for(i=len-1;i;i--,s--,t--,j-=2)
	{
		str[j]=0;
		sleep(retardation);
	 	printf("\r%s%s",spc,t);
	}		
	printf("%s",string+1);
	//putchar(10);
}	
/*-------------Requires sleep function----------------------*/
void go_back(char string[])
{
	char *s, str[500]; int i,j=strlen(string),retardation=13;
	strcpy(str,"                                                                                ");
	strcat(str,string);
	s=str+80+j-1;
	for(i=35+8;i<79;i++,s--)
	{
		sleep(retardation);
		printf("\r\t%s",s);
	}
	for(i=0;i<35;i++,s--,retardation++)
	{
		sleep(retardation);
		printf("\r\t%s",s);
	}
	sleep(100);  strcat(str,"                    ");	
	for(i=0,s++;i<8;i++,s++)
	{
		*(s+71)=0;
		sleep(retardation);
		printf("\r\t%s",s);
		*(s+71)=' ';
	}
	//putchar(10);
}
/*-------------Requires sleep function----------------------*/
void brought_togather(char string[])
{
	char str[R], *s; 
	int i,j, retardation=15;
	//k=80-j;
	strcpy(str,"                                                                                 ");
	s=str+81;
	for(i=0;string[i];i++) { *(s++)=string[i], *(s++)=' '; } *(--s)=0;
	s--; j=s-str;
	for(i=9;i<66;i++,s--)
	{
		sleep(retardation);
		printf("\r\t%s",s);		
	}
	i=strlen(string)-1;
	j--; retardation=(retardation*2)+5;
	for(;i;i--,s--,j-=2)
	{
		str[j]=0;
		sleep(retardation);
		printf("\r\t%s",s);
		//printf("\r Oil-come");
	}
	printf("%s",string+1);
	//putchar(10);
}	
/*-------------requires sleep function----------------------*/
void marque_string(char string[])
{
	int j=30; const int retardation=90;
	char ch,marque[R],spc[SPC]="                                                                                 ";
	spc[j+1]=0;
	strcpy(marque,spc); strcat(marque,string); strcat(marque,spc);
	for(int i=0;marque[j];i++,j++)
	{
		sleep(retardation);
		ch=marque[j]; marque[j]=0;
		printf("\r\t%s",marque+i);
		marque[j]=ch;
	}
	//putchar(10);
}	
/*-------------requires sleep function----------------------*/
void string_brushing(char string[])
{
	const int retardation=30;
	int i,j; bool q=0;
	j=strlen(string);
	
	
	//printf("\t0123456789012345678901234567890\n");
	printf("\r\t\t");
	for(i=1;i<j;putchar(32),i++);
	if(j%2)	q=1;
	for(i=j-1;i>0;i--)
	{	sleep(retardation);
		if(q=!q) printf("%c%c%c",string[i],8,8);
		else printf("%c",8);
	}	
	for(i=0;i<j;i++)
	{	sleep(25);
		putchar(string[i]);
	}
	//putchar(10);
}	
/*-------------Requires sleep function----------------------*/
void marging_string(char string[])
{
	const int retardation=60;
	int i,j=strlen(string); char temp[R];
	
	for(i=1;i<j;temp[i]=' ',i++); temp[j]=0;
	
	for(i=0,j--;i<=j;i++,j--)
	{	
		temp[i]=string[i]; temp[j]=string[j]; //temp[j+1]=0;
		sleep(retardation);
		printf("\r\t\t%s",temp);
	}
	//putchar(10);
}	
/*-------------Requires sleep function----------------------*/
void spreding_string(char string[])
{
	const int retardation=60;
	int i,j=strlen(string); char temp[R];
	
	for(i=0;i<j;temp[i]=' ',i++); temp[j]=0;

	if(j%2) 
	{
		j=(j/2)+1; i=j-2;
		temp[i+1]=string[i+1];
		printf("\r\t\t%s",temp);
	}
	else { j/=2; i=j-1; }
	
	for(;i>-1;i--,j++)
	{	
		temp[i]=string[i]; temp[j]=string[j]; //temp[j+1]=0;
		sleep(retardation);
		printf("\r\t\t%s",temp);
	}
	//putchar(10);
}	
/*-------------Requires sleep function----------------------*/
void consecutively_appeared(char n[])
{
	const int retardation=60;
	printf("\t\t");
	for(int i=0;n[i];i++)
	{
		sleep(retardation); putchar(n[i]); 
	}
	//putchar(10);
}	