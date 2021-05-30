#include<stdio.h>
#include<math.h>

/*====Find out the percentage amount of 2 numbers(total,part_of_total)====*/
float per(float tot,float part)
{   
   float per;
   per=(part*100)/tot;
   return per;  
}
/*--------------Quadratic equation(const_1,const_2,resultant_array)---------------*/
void quad_equ(int a,int b,double *result)
{   
   *result=(-b+sqrt(b*b-4*a*x))/(2*a);
   *(result+1)=(-b-sqrt(b*b-4*a*x))/(2*a);
}
/*-------------Greatest Common Devisor[GCD](Recursive)(num_1,num_2)----------------*/
long gcd_recur(long a,long b)
{   
   while(b>0) gcd(b,a%b);
   return a;
}
/*--------Lowest Common Multiple [LCM] (num1,num2)-//require gcd()---------*/
long lcm(long x,long y)
{   
   long a=x,b=y;
   while(b>0) { a%=b; a^=b; b^=a; a^=b; }
   return (x/a)*y;
}
/*--------Lowest Common Multiple[LCM](num1,num2)-//require gcd()---------*/
long lcm(long a,long b)
{
   return (a*b)/(gcd(a,b)); 
}
/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*---If out of n number then i<n, else if up to n prime then s<n------------*/
long sto_prime(long *p,unsigned long n)
{   
   long s,sq; unsigned int i; int j; char q;
   *p=2; *(p+1)=3;  s=2;
   for(i=5,n++;s<n;i+=2)
   {   q='0';
      sq=sqrt(i)+1;
      for(j=1;*(p+j)<sq;j++)
      {    if(i% *(p+j)==0) { q='1'; break; }
      }
      if(q=='0') *(p+s++)=i;
   }
   return s;
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
//------------- prime 0 , non-prime 1 --------------
void seive_prime(bool *prim, int n)
{   int i,j;
   prim[0]=1;prim[1]=1;
   for(i=4;i<n;prim[i]=1,i+=2);
   for(i=3;i<n;i+=2)
   {   if(prim[i]==0)
         for(j=i+i;j<n;prim[j]=1,j+=i);
   }   
}
/******************Devide by Nine(str)*********************/
int dev_by_9(char *str)
{   int i,sum=0;
   do
   {   //count++;
      for(i=0;sum;i++)
      {   *(str+i)=sum%10+48;
         sum/=10;      
      }
      if(i) *(str+i)=0;
      for(i=1,sum=*str-48; *(str+i); i++) 
      {   sum+= *(str+i)-48; }
   }while(sum>9);
   if(sum==9) return 1;
   return 0;
}
/***************Multiple of 11(str)*********************/
int dev_by_11(char*str)
{
   int i,sum[2]={0,0}; char q=0;
   for(i=0;*(str+i);i++)
   {
      sum[q]+=*(str+i)-48;
      q=!q;
   }
   if( (sum[0]-sum[1])%11 ) return 0;
   return 1;
}
/***************Multiple of 55(str)*********************/
int dev_by_55(char*str)
{
   int i,sum[2]={0,0}; char q=0;
   if(str[len-1]==0||str[len-1]==5)
   {
      for(i=0;*(str+i);i++)
      {
         sum[q]+=*(str+i)-48;
         q=!q;
      }
      if( (sum[0]-sum[1])%11) return 1;
   }   
   return 0;
}
/***************Is devided by 15(str)*********************/
int dev_by_15(char str[])
{
   int i; long sum=0;
   if(str[len-1]==0||str[len-1]==5)
   {
      for(i=0;str[i];i++) sum+=str[i]-48;
      if(sum%3==0) return 1;
   }
   return 0;
}
/*--Converting unsigned int to string and return the lenth without adding_48--*/
/*----------(unsigned  number,char *string)------------*/
int num_alpha_48(long n,char *str)
{   
   int i;
   for(i=0;n>0;i++)
   {
      *(str+i)=n%10; n/=10;
   }
   *(str+i)=0;
   return i;
}
/*-----------------------------Josuphus(int)-----------------------------*/
int josephus(int man)
{   
   int i,j;
   for(i=man,j=1;i>1;i/=2) j*=2;
   man=(man-j)*2+1; 
   return man; 
}
/*______Find the GCD and then Tkatakati with other value of n[]______*/
/*___________________(num_array,num_to_find_GCD)_____________________*/
void gcd_katakati(int *n,int y)
{   
   int a,b,i=0;
   while(y>1)
   {   
      a=n[i];
      if(a==1) { i++; continue; }
      b=y;
      while(b) 
      {   a%=b; 
         a^=b; b^=a; a^=b; 
      }
      if(a!=1) { n[i]/=a; y/=a; } 
      i++;
   }
}
/*____________Load devisor of 'n' into two array by evaluate the sqrt of n___________*/
/*_(int n, int left_devisor, int right_devisor, int tot_left_dev, int tot_right_dev)_*/
void load_devisor(int n,int ld[],int rd[],int &u,int &v)
{
   int i,sq;
   u=0,v=0;
   sq=sqrt(n)+1;
   for(i=1;i<sq;i++)
   {
      if(n%i==0) ld[u++]=i, rd[v++]=n/i;
   }
   if(u&&ld[u-1]==rd[v-1]) v--;
}
/*--Efficient-String checking: a year whether leap year or not(str_year, len)---*/
int str_leap_year(char str[],int len)
{   
   if(str[len-1]==48&&str[len-2]==48) 
      {
      if( ((str[len-3]-48)*10+(str[len-2]-48)) % 4==0 ) 
         return 1;   
      }
   else   
      {
      if( ((str[len-2]-48)*10+(str[len-1]-48)) % 4==0) 
         return 1;
      }
   return 0;   
}
/*--String checking: a year whether leap year or not(str_year, len)---*/
int str_leap_year(char str[],int len)
{   
   int i,sum;  char q=0;
   
   if(str[len-1]==0&&len[len-2]==0) q=1;
   
   for(i=len-2,sum=0;i<len;i++)
      sum=sum*10+str[i]-48;
   if(sum%4==0) q+=2;
   
   if(q==2) return 1;

   for(i=len-3,sum=0;i<len-1;i++)
      sum=sum*10+str[i]-48;
   if(sum%4==0) q+=4;
   
   if(q==5) return 1;

   return 0;
}
