
/*----Multiplication between string and int(des_str,str,int,len)----*/
/*------------The 2nd number b < 21474836. Require rev()------------*/
int si_multiplication(char *r, char *a, long b, int len)
{   
   int i,j;
   unsigned long m=0;
   for(i=len-1,j=0;i>-1;i--)
   {   
      m+= *(a+i)* b;
      *(r+ j++)=(m%10)+48;
      m/=10;
   }
   while(m)
   {   *(r+ j++)=(m%10)+48; m/=10; }
   
   if(*(r+j-1)==0) {  *r=48; j=1; }
   else rev(r,j);  *(r+j)=0;
   
   return j;
}
/*----Multiplication between string without subtracting 48----*/
/*-----int(des_str,str,int,len)--The 2nd number b<21474836----*/
int si_multiplication_48(char *r, char *a, long b, int len)
{   
   int i,j; 
   unsigned long m=0;
   for(i=len-1,j=0;i>-1;i--)
   {   
      m+= *(a+i)* b;
      *(r+ j++)=m%10;
      m/=10;
   }
   while(m)
   {   *(r+ j++)=m%10; m/=10; }
   
   if(*(r+j-1)==0) {  *r=0; j=1; }
   else rev(r,j);  *(r+j)=0; // Require rev();
   
   return j;
}
/*--------Multiplication between 2 strings without subtracting 48---------*/
/*(des_str,str1,str2,len1,len2)Cautious about any str operation of des_str*/
int ss_multi_48(char *r,char *n1,char *n2,int l1,int i)// Require rev()
{   
   char x[R], sum; 
   int j,k, m,z=0;
   
   for(j=l1+i;j>-1;j--)  *(r+j)=0;
   
   for(i--;i>-1;i--)
   {   
      for(j=l1-1,m=0,k=0; j>-1; j--)
      {    
         m+=*(n1+j)*(*(n2+i));
         x[k++]=(m%10);
         m=m/10; 
      }
      if(m!=0) x[k++]=m;
      
      for(j=z,k=k+z,m=0; j<k; j++,m++) 
      {
         sum=*(r+j)+x[m];
         if(sum>9) 
         {   
            *(r+j)=sum-10;
            (*(r+j+1))++; 
         }
         else *(r+j)=sum;
      }
      z++;
   } 
   if(sum>9) k++; *(r+k)=0;
   if(*(r+k-1)==0)
   {   *r=48; *(r+1)=0;}
   else rev(r,k); 
   return k;
}
/*----------Multiplication between 2 int(des_str,int,int)----------*/
int ii_multi(char *r,long sum,long m)//<Rquire rev_assign() >
{   
   char x[11],n1[10],n2[10];
   int l1=0,l2=0,i,j,k, z=0;
   
   while(m>9)
   {   n2[l2++]=m%10;  m/=10;  }
   n2[l2++]=m;
   
   while(sum>9)
   {   n1[l1++]=sum%10;  sum/=10;  }
   n1[l1++]=sum;
   
   for(j=l1+l2;j>-1;j--) *(r+j)=0;

   for(i=0;i<l2;i++)
   {   
      for(j=0,m=0,k=0; j<l1; j++)
      {    
         m+=n1[j]*n2[i]; 
         x[k++]=(m%10); 
         m=m/10;
      }
      if(m!=0) x[k++]=m;
      
      for(j=z,k=k+z,m=0; j<k; j++,m++)
      {   
         sum=*(r+j)+x[m];
         if(sum>9)
         {   *(r+j)=sum-10; (*(r+j+1))++; }
         else*(r+j)=sum;
      }
      z++;
   }
   if(sum>9) k++;
   *(r+k)=0;
   if(*(r+k-1)==0)
   {   *r=48; *(r+1)=0; }
   else rev_assign(r,k);
   return k;
}
/*---Division of String and integer(des str,str,num,len) return the length---*/
int sn_dev(char *r,char *m,long n,int len)
{   
   int i=0,j=0;
   long dev=0;
   while(dev<n&&j<len)
   {   dev=dev*10; dev+=(*(m+j))-48; j++; }

   do
   {   while(dev<n&&j<len)
      {   
         dev=dev*10; dev+=(*(m+j))-48; j++;
         if(dev<n&&j<len) *(r+i++)=48;
      } 
   *(r+i++)=dev/n+48;
   dev%=n;
   }while(j<len);
   
   *(r+i)=0;
   return i;
}
/*----Find out is "str" divisible by "devider" or not(str,len,devider)-----*/
bool str_modulo_int(char *m,int len, long d)
{   
   int i=0,j=0; 
   long dev=0;
   while(dev<d&&j<len) 
   {   dev=dev*10; dev+=(*(m+j))-48; j++; }
   
   do
   {   while(dev<d&&j<len)
      {   
         dev=dev*10; 
         dev+=(*(m+j))-48; j++;
         //if(dev<d&&j<len) 
         //   *(r+i++)=48;
      } 
      //*(r+i++)=dev/d+48; 
      dev%=d;
   }while(j<len); 
   //*(r+i)=0;  
   if(dev)   return 0;
   return 1;
}