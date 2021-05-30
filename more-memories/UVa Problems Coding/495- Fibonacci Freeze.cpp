#include<stdio.h>
//#include<BigInt_Al.h>
#define Size 5001
typedef __int64 Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/****** Tariqul Islam Sarker (Alauddin) ******/
#include<ctype.h>
#include<string>
#include<algorithm>
//#include<math.h>
#define type int

using namespace std;

typedef struct { string digits; bool sign; } BigInt;

void encode(BigInt &n)
{
type i; reverse(n.digits.begin(),n.digits.end());
for(i=0;i<n.digits.length();i++)n.digits[i]-='0';
}

void decode(BigInt &n)
{
type i; reverse(n.digits.begin(),n.digits.end());
for(i=0;i<n.digits.length();i++)n.digits[i]+='0';
}

type compare(BigInt &n1,BigInt &n2)
{
if(n1.digits.length()<n2.digits.length())return -1;
if(n1.digits.length()>n2.digits.length())return  1;
type i,Len=n1.digits.length();
for(i=Len-1;i>=0;i--)
	if(n1.digits[i]==n2.digits[i])continue; else return  n1.digits[i]-n2.digits[i];
return 0;
}

BigInt operator+(BigInt n1,char n2)
{
type i,carry=n2;
for(i = 0; i<n1.digits.length(); i++)
	{ carry+=n1.digits[i]; n1.digits[i]=carry%10; carry/=10; }
if(carry>0)n1.digits+=carry; 
return n1;
}

void operator+=(BigInt &n1,char n2)
{
type i,carry=n2;
for(i = 0; i<n1.digits.length(); i++)
	{ carry+=n1.digits[i]; n1.digits[i]=carry%10; carry/=10; }
if(carry>0)n1.digits+=carry; 
}


BigInt operator+(BigInt &n1,BigInt &n2)
{
type i,Len,carry=0;
if(n1.digits.length()>n2.digits.length())Len=n1.digits.length(); else Len=n2.digits.length();
BigInt n;  n.digits.resize(Len);
for(i=0;i<Len;i++)
	{ 
	if(i<n1.digits.length())carry+=n1.digits[i]; 
	if(i<n2.digits.length())carry+=n2.digits[i]; 
	n.digits[i]=carry%10; carry/=10; 
	}
if(carry>0)n.digits+=carry; 
return n;	
}

void operator+=(BigInt &n1,BigInt &n2)
{
type i,Len,carry=0;
if(n1.digits.length()>n2.digits.length())Len=n1.digits.length(); else Len=n2.digits.length();
n1.digits.resize(Len);
for(i=0;i<Len;i++)
	{ 
	if(i<n1.digits.length())carry+=n1.digits[i]; 
	if(i<n2.digits.length())carry+=n2.digits[i]; 
	n1.digits[i]=carry%10; carry/=10; 
	}
if(carry>0)n1.digits+=carry;
}

BigInt operator+(BigInt &n1,int n2)
{
if(n2==0)return n1; BigInt tmp; tmp.digits = ""; 
while(n2>0){ tmp.digits+= n2%10; n2/=10; }
tmp+=n1;
return tmp;
}

void operator+=(BigInt &n1,int n2)
{
if(n2==0)return ; BigInt tmp; tmp.digits = ""; 
while(n2>0){ tmp.digits+= n2%10; n2/=10; }
n1+=tmp;
}

BigInt operator-(BigInt &n1,BigInt &n2)
{
if(compare(n1,n2)<0)return n2-n1;
type i,Len,carry=0,digit; Len=n1.digits.length();
BigInt n;  n.digits.resize(Len);
for(i=0;i<Len;i++)
	{ 
	if(i<n2.digits.length())digit=n1.digits[i]-n2.digits[i]; else  digit=n1.digits[i];
	digit-=carry; if(digit<0){ digit+=10; carry=1; } else carry=0;
	n.digits[i]=digit;
	}
for(Len--;Len>0;Len--)if(n.digits[Len]!=0)break;
n.digits.resize(Len+1);
return n;	
}

void operator-=(BigInt &n1,BigInt &n2)
{
	if(compare(n1,n2)<0){ n2-=n1; return; }
type i,Len,carry=0,digit; Len=n1.digits.length();
for(i=0;i<Len;i++)
	{ 
	if(i<n2.digits.length())digit=n1.digits[i]-n2.digits[i]; else  digit=n1.digits[i];
	digit-=carry; if(digit<0){ digit+=10; carry=1; } else carry=0;
	n1.digits[i]=digit;
	}
for(Len--;Len>0;Len--)if(n1.digits[Len]!=0)break;
n1.digits.resize(Len+1);
}

BigInt operator-(BigInt &n1,int n2)
{
if(n2==0)return n1; BigInt tmp; tmp.digits = ""; 
while(n2>0){ tmp.digits+= n2%10; n2/=10; }
tmp=n1-tmp;
return tmp;
}

void operator-=(BigInt &n1,int n2)
{
if(n2==0)return ; BigInt tmp; tmp.digits = ""; 
while(n2>0){ tmp.digits+= n2%10; n2/=10; }
n1-=tmp;
}

BigInt operator*(BigInt &n1,type n2)
{
type i,carry=0,Len=n1.digits.length(); 
BigInt n;  n.digits.resize(Len);
for(i=0;i<Len;i++)
	{ 
	carry+=n1.digits[i]*n2; 
	n.digits[i]=carry%10; carry/=10; 
	}
while(carry>0){ n.digits+=carry%10; carry/=10; }
return n;	
}

void operator*=(BigInt &n1,type n2)
{
type i,carry=0,Len=n1.digits.length(); 
for(i=0;i<Len;i++)
	{ 
	carry+=n1.digits[i]*n2; 
	n1.digits[i]=carry%10; carry/=10;
	}
while(carry>0){ n1.digits+=carry%10; carry/=10; }
}

BigInt operator*(BigInt &n1,BigInt &n2)
{
int i,j,carry=0,Len=n1.digits.length()+n2.digits.length();
BigInt n; n.digits.resize(Len);		fill(n.digits.begin(),n.digits.end(),0);
for(i=0;i<n2.digits.length();i++)if(n2.digits[i])
	for(carry = 0,j = 0;j<n1.digits.length() || carry; j++ )
	{
    carry +=n.digits[i + j] + ( j < n1.digits.length()? n1.digits[j] * n2.digits[i] : 0 ) ;
	n.digits[i + j] = carry % 10;  carry /= 10;            
    }
for(Len--;Len>0;Len--)if(n.digits[Len]!=0)break;
n.digits.resize(Len+1);
return n;
}

void operator*=(BigInt &n1,BigInt &n2) { n1=n1*n2; }

void divide(BigInt &n1,type &n2)
{
if(n2==0){ n2/=n2; return; }
type i,tmp = 0,Len=n1.digits.length();
for( i = Len - 1; i >= 0; i-- )
{  tmp *= 10; tmp += n1.digits[i]; n1.digits[i] = tmp / n2; tmp -= n1.digits[i] * n2;  }
for(Len--;Len>0;Len--)if(n1.digits[Len]!=0)break;
n1.digits.resize(Len+1); n2=tmp;
}

void divide(BigInt &n1,type n2,BigInt &q,type &r) { q=n1; r=n2; divide(q,r); }

BigInt operator/(BigInt n1,type n2) { divide(n1,n2); return n1; }

void operator/=(BigInt &n1,type n2) { divide(n1,n2);  }

type operator%(BigInt n1,type n2) { divide(n1,n2); return n2; }

void divide(BigInt &n1,BigInt &n2)
{
type i=0,Len=n1.digits.length();
if(n2.digits.length()==1)if(n2.digits[0]==0){ i/=i; return ; }
BigInt tmp ; tmp.digits  = char(0);
for( i = Len - 1; i >= 0; i-- )
	{  
	tmp *= 10; tmp += n1.digits[i]; n1.digits[i] = 0; 
	while( compare(tmp,n2)>=0 ) { tmp -= n2; n1.digits[i]++; }
	}
for(Len--;Len>0;Len--)if(n1.digits[Len]!=0)break;
n1.digits.resize(Len+1); n2=tmp;
}


void divide(BigInt &n1,BigInt &n2,BigInt &q,BigInt &r) { q=n1; r=n2; divide(q,r); }

BigInt operator/(BigInt n1,BigInt n2) { divide(n1,n2); return n1; }

void operator/=(BigInt &n1,BigInt n2) { divide(n1,n2);  }

BigInt operator%(BigInt n1,BigInt n2) { divide(n1,n2); return n2; }

void operator%=(BigInt &n1,BigInt n2) { divide(n1,n2); n1=n2; }


BigInt operator^(BigInt &x,type y)
{
BigInt tmp; tmp.digits=char(1);
while(y>0){ tmp*=x; y--; }
return tmp;
}

void operator^=(BigInt &x,type y)
{
BigInt tmp; tmp=x; x.digits=char(1);
while(y>0){ x*=tmp; y--; }
}

BigInt gcd(BigInt a,BigInt b)
{
if(b.digits.length()==1)if(b.digits[0]==0)return a;
return  gcd(b,a%b);
}

BigInt lcm(BigInt a,BigInt b)
{
a/=gcd(a,b); a*=b;
return a;
}

BigInt sqrt(BigInt &n)
{
BigInt remain,odd,answer,group; 
remain.digits = char(0); odd.digits = char(0); answer.digits = char(0);
char one=1,two=2;
type i=n.digits.length()-1,total; 
for(;i>=0;i--)
	{
	group.digits = char(n.digits[i]); total = 0;
	if(i%2==1) { i--; group.digits = char(n.digits[i]) + group.digits; }
	odd = answer * 20 + one ;		
	remain *= 100; remain += group;
	while(compare(remain,odd)>=0) { total ++; remain -= odd; odd += two; }
	answer = answer * 10 + total;
	}	
return answer;
}

/*****************************main Function*****************************/
void main()
	{
	freopen("495.txt","r",stdin);

	int n;
	bool de[Size]={0};
	BigInt fib[Size];

	//for(n=0;n<Size;n++) encode(fib[n]);
	
	fib[0].digits="0";
	fib[1].digits="1";

	encode(fib[0]);
	encode(fib[1]);

	for(n=2;n<Size;n++) fib[n]=fib[n-1]+fib[n-2];
	
	while(scanf("%d",&n)==1)
		{
		if(de[n]==0)
			de[n]=1, decode(fib[n]);

		printf("The Fibonacci number for %d is %s\n",n, fib[n].digits.c_str());
		}
	}
