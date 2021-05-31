/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int j)
{
   int i=0;
   *(des+j)='\0';
   for(j--;i<j;i++,j--)
   {   *(des+i)=*(s+j); *(des+j)=*(s+i); }
   if(i==j) *(des+i)=*(s+i);   
}
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{   
   int i=0;  char tmp;
   for(j--;i<j;i++,j--)
   {   tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/*---------Reverse & assign the char's by adding 48 (str,len)----------*/
void rev_assign(char *s,int j)
{   
   int i=0;  char tmp;
   for(j--;i<j;i++,j--)
   {   tmp=*(s+i)+48; *(s+i)=*(s+j)+48; *(s+j)=tmp; }
   if(i==j) (*(s+i))+=48;
}
/*---Addition of 2 strings without revcop and subtracting 48 (Incomplete----*/
/*-(des str,str1,str2,len1,len2) Careful about any str operation of des_str-*/
void ss_add_fast(char *r,char *m,char *n,int len,int i)//<Require revcop & rev>
{   
   int sum; if(i>len) { sum=len-1; len=i-1; i=sum; sum=0; }
   for( ;i>-1&&len>-1;i--,len--)
   {   
      sum+=*(m+len)+(*(n+i));
      if(sum>9) { (*(r+i))=sum-10; sum=1; }
      else { *(r+i)=sum; sum=0; }
   }
   if(i!=-1) len=i;
   for(;len>-1;)
   {
   }
   if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
   else  *(r+i)=0;    rev(r,i);     }
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
/*----------This func, assume that at last, there will has a carry----------*/
int ss_add_1(char *r,char *m,char *n,int len,int ln)
{   
   char sum=0; int w,i=len,k=0;
   
   if(len<ln) { i=ln; } w=i+1; *(r+w)=0; 
   for(len--,ln--;len>-1&&ln>-1;len--,ln--,i--)
   {   sum+=(*(m+len))+(*(n+ln));
      if (sum>105) {   *(r+i)=sum-58; sum=1; }
      else { *(r+i)=sum-48; sum=0; }
   }
   if(len>-1)
      for(;len>-1;len--,i--) 
      {   sum+=(*(m+len));
         if (sum>57) { *(r+i)=48; sum=1; }
         else
         {   *(r+i)=sum;sum=0; k=i-1;
            for(i-=2;i>-1;i--) *(r+i)=(*(m+i));
            break;
         }
      }
    else if(ln>-1) 
      for(;ln>-1;ln--,i--)
      {   sum+=(*(n+ln));
         if (sum>57) { *(r+i)=48; sum=1; }
         else
         {   *(r+i)=sum; sum=0; k=i-1;
            for(i-=2;i>-1;i--) *(r+i)=(*(n+i));
            break;
         }
      }
   if(sum==1) { *r=49; w; } 
   else {  strcpy(r+k,r+k+1); w--;  }
   return w;
}
/*----Addintion of 2 string in natural way(des_str,str1,str2,len1,len2)----*/
/*------This func, assume that at last there will has no a carry------------*/
int ss_add_0(char r[],char m[],char n[],int len,int ln)
{    char sum=0; int w=len,i=len;
   if(len<ln) { w=ln; i=ln; } *(r+i)=0;
   for(len--,ln--,i--;  len>-1&&ln>-1 ;  len--,ln--,i--)
   {   sum+=(*(m+len))+(*(n+ln));
      if (sum>105) {   *(r+i)=sum-58; sum=1; }
      else  { *(r+i)=sum-48; sum=0; }
   }
   if(len>-1)
      for(    ;len>-1;  len--,i--)
      {   sum+=(*(m+len)); 
         if(sum>57) {   *(r+i)=48; sum=1;   }
         else   
         {   *(r+i)=sum;sum=0;
            for(i--;i>-1;i--) *(r+i)=(*(m+i));
            break;
         }
      }
    else if(ln>-1) 
      for(    ;ln>-1;  ln--,i--)
      {   sum+=(*(n+ln));
         if (sum>57) { *(r+i)=48; sum=1; }
         else
         {   *(r+i)=sum; sum=0; 
            for(i--;i>-1;i--) *(r+i)=(*(n+i));
            break;
         }
      }
   if(sum==1)
   {   for(i=w++;i>-1;i--)  *(r+i+1)=*(r+i); *r=49;   }
   return w;
}
/*---Addintion of 2 string in practical way(des_str,str1,str2,len1,len2)---*/
/*----Without 48;Assume that no carry; Carefull about any str operation----*/
int ss_add_048(char *r,char *m,char *n,int len,int ln)
{    char sum=0; int w,i=len,k;
   if(len<ln) { i=ln; } k=i;
   for(len--,ln--,i--;ln>-1&&len>-1;len--,ln--,i--)
   {   sum+=(*(m+len))+(*(n+ln));
      if (sum>9) { *(r+i)=sum-10; sum=1; }
      else  { *(r+i)=sum; sum=0; }
   } if(len>-1) for(;len>-1;len--,i--)
      { sum+=(*(m+len)); if (sum>9) { *(r+i)=0; sum=1; }
       else{ *(r+i)=sum; sum=0;for(i--;i>-1;i--) *(r+i)=(*(m+i));break;}}
     else if(ln>-1) for(;ln>-1;ln--,i--)
      { sum+=(*(n+ln)); if (sum>9) { *(r+i)=0; sum=1; }
       else{ *(r+i)=sum; sum=0; for(i--;i>-1;i--) *(r+i)=(*(n+i));break;}
      }if(sum==1){ for(i=k++;i>-1;i--) *(r+i+1)=*(r+i); *r=1; } return k;}
/*----Addintion of 2 string in common way(des_str,str1,str2,len1,len2)----*/
/*------This func, assume that at last there will has no carry------------*/
void sn_add_0(char *r,char *m,long sum,int len)//Require rev.
{    int i=len,k, ln=0; char n[11];
   while(sum>9) { n[ln++]=sum%10; sum/=10;} n[ln++]=sum; sum=0; k=ln; rev(n,ln);
   if(len<ln) { i=ln; k=len; } *(r+i)=0;
   for(len--,i--,ln--;k>-1;len--,ln--,i--,k--)
   {   sum+=*(m+len)+n[ln];
      if (sum>57) {   *(r+i)=sum-10; sum=1; }
      else  { *(r+i)=sum; sum=0; }
   } if(len>-1) for(;len>-1;len--,i--)
      { sum+=(*(m+len)); if (sum>57) { *(r+i)=48; sum=1; }
        else{ *(r+i)=sum; sum=0; for(i--;i>-1;i--) *(r+i)=(*(m+i)); break;}}
     else if(ln>-1) for(;ln>-1;ln--,i--)
      { sum+=n[ln]+48; if (sum>57) { *(r+i)=48; sum=1; }
        else{ *(r+i)=sum; sum=0; for(i--;i>-1;i--) *(r+i)=n[i]; break;}
      } 
      if(sum==1) { for(;k>-1;k--) *(r+k+1)=*(r+k); *r=49; }  
}
/*----Multiplication between string and int(des_str,str,int,len)----*/
void si_multi(char *r,char *n1,long m,int l1)//<Require rev_assign() >
{   char x[R],n2[20], sum; int l2=0,i,j,k, z=0;
   while(m>9){ n2[l2++]=m%10; m/=10; } n2[l2++]=m;
   for(j=l1+l2;j>-1;j--) *(r+j)=0;
   for(i=0;i<l2;i++)
   {   for(j=l1-1,m=0,k=0; j>-1; j--)
      {    m+=(*(n1+j)-48)*(n2[i]); x[k++]=(m%10); m=m/10;}
      if(m!=0) x[k++]=m;
      for(j=z,k=k+z,m=0; j<k; j++,m++) {   sum=*(r+j)+x[m];
         if(sum>9) {*(r+j)=sum-10; (*(r+j+1))++;} else *(r+j)=sum;
      }  z++;
   } if(sum>9) k++; *(r+k)=0;
   if(*(r+k-1)==0) {*r=48; *(r+1)=0;} else rev_assign(r,k); }
/*-------Multiplication between string and num without subtracting 48------*/
/*---(des_str,str,num,len)-cautious about any str operation of des_str--*/
int si_multi_48(char *r,char *n1,long m,int l1)//< Require rev() >
{   char x[R],n2[4], sum; int l2=0,i,j,k, z=0;
   while(m>9) { n2[l2++]=m%10; m/=10; } n2[l2++]=m;
   for(j=l1+l2;j>-1;j--) *(r+j)=0;
   for(i=0;i<l2;i++) {   for(j=l1-1,m=0,k=0; j>-1; j--)
   {   m+=*(n1+j)*n2[i]; x[k++]=(m%10); m=m/10;}
      if(m!=0) x[k++]=m;
      for(j=z,k=k+z,m=0; j<k; j++,m++)
      {   sum=*(r+j)+x[m]; if(sum>9) {*(r+j)=sum-10; (*(r+j+1))++;}
         else *(r+j)=sum; }   z++;
   } if(sum>9) k++; *(r+k)=0; rev(r,k); return k; 
}
/*----Multiplication between string and int(des_str,str,int,len)----*/
/******The 2nd number b<21474836******/
int si_multiplication(char *r, char *a, long b, int len)
{   int i,j; unsigned long m=0;
   for(i=len-1,j=0;i>-1;i--)
   {   m+= (*(a+i)-48) * b;
      *(r+ j++)=(m%10)+48;
      m/=10;
   }
   while(m){ *(r+ j++)=(m%10)+48; m/=10; }
   if(*(r+j-1)==0) {*r=48; j=1;}
   else rev(r,j);  *(r+j)=0;
   return j;
}
/*----Multiplication between string without subtracting 48----*/
/*-----int(des_str,str,int,len)--The 2nd number b<21474836----*/
int si_multiplication_48(char *r, char *a, long b, int len)
{   int i,j; unsigned long m=0;
   for(i=len-1,j=0;i>-1;i--)
   {   m+= *(a+i)* b;
      *(r+ j++)=m%10;
      m/=10;
   }
   while(m){ *(r+ j++)=m%10; m/=10; }
   if(*(r+j-1)==0) {  *r=0; j=1; }
   else rev(r,j);  *(r+j)=0;
   return 1;
}
/*----Multiplication between string and int(des_str,str,int,len)----*/
void si_multi(char *r,char *n1,long m,int l1)//<Require rev_assign() >
{   char x[R],n2[20], sum; int l2=0,i,j,k, z=0;
   while(m>9){ n2[l2++]=m%10; m/=10; } n2[l2++]=m;
   for(j=l1+l2;j>-1;j--) *(r+j)=0;
   for(i=0;i<l2;i++)
   {   for(j=l1-1,m=0,k=0; j>-1; j--)
      {    m+=(*(n1+j)-48)*(n2[i]); x[k++]=(m%10); m=m/10;}
      if(m!=0) x[k++]=m;
      for(j=z,k=k+z,m=0; j<k; j++,m++) {   sum=*(r+j)+x[m];
         if(sum>9) {*(r+j)=sum-10; (*(r+j+1))++;} else *(r+j)=sum;
      }  z++;
   } if(sum>9) k++; *(r+k)=0;
   if(*(r+k-1)==0) {*r=48; *(r+1)=0;} else rev_assign(r,k); }
/*-------Multiplication between string and num without subtracting 48------*/
/*---(des_str,str,num,len)-cautious about any str operation of des_str--*/
int si_multi_48(char *r,char *n1,long m,int l1)//< Require rev() >
{   char x[R],n2[4], sum; int l2=0,i,j,k, z=0;
   while(m>9) { n2[l2++]=m%10; m/=10; } n2[l2++]=m;
   for(j=l1+l2;j>-1;j--) *(r+j)=0;
   for(i=0;i<l2;i++) {   for(j=l1-1,m=0,k=0; j>-1; j--)
   {   m+=*(n1+j)*n2[i]; x[k++]=(m%10); m=m/10;}
      if(m!=0) x[k++]=m;
      for(j=z,k=k+z,m=0; j<k; j++,m++)
      {   sum=*(r+j)+x[m]; if(sum>9) {*(r+j)=sum-10; (*(r+j+1))++;}
         else *(r+j)=sum; }   z++;
   } if(sum>9) k++; *(r+k)=0; rev(r,k); return k; }
/*----------Multiplication between 2 int(des_str,int,int)----------*/
void ii_multi(char *r,long sum,long m)//<Rquire rev_assign() >
{   char x[11],n1[10],n2[10]; int l1=0,l2=0,i,j,k, z=0;
   while(m>9){n2[l2++]=m%10;m/=10;} n2[l2++]=m;
   while(sum>9){n1[l1++]=sum%10;sum/=10;} n1[l1++]=sum;
   for(j=l1+l2;j>-1;j--) *(r+j)=0;
   for(i=0;i<l2;i++)
   {   for(j=0,m=0,k=0; j<l1; j++)
      {    m+=n1[j]*n2[i]; x[k++]=(m%10); m=m/10;}
         if(m!=0) x[k++]=m;
         for(j=z,k=k+z,m=0; j<k; j++,m++) { sum=*(r+j)+x[m];
         if(sum>9){*(r+j)=sum-10;(*(r+j+1))++;} else*(r+j)=sum;
      }  z++;
   } if(sum>9) k++; *(r+k)=0;
   if(*(r+k-1)==0) {*r=48; *(r+1)=0;} else rev_assign(r,k); }
/*------------Division of String and integer(des str,str,num,len)----------*/
void sn_dev(char *r,char *m,long n,int len)
{   
   int i=0,j=0; long dev=0;
   while(dev<n&&j<len) {dev=dev*10; dev+=(*(m+j))-48; j++; }
   do{ while(dev<n&&j<len)
      {   dev=dev*10; dev+=(*(m+j))-48; j++;
         if(dev<n&&j<len) *(r+i++)=48;
      } *(r+i++)=dev/n+48; dev%=n;
   }while(j<len); *(r+i)=0;
}
/************************Searching*****************************/
/*------Binary Search(array, total_element, searching_number)[worse]--------*/
int binary_search(int ar[],int n,int s)
{   int i=n/2,ini=0;
   if(*ar==s) return 1; else if(ar[n-1]==s) i=n-1;
   while(n-ini>1)
   {   if(ar[i]==s)
      {   while(ar[i-1]==s) i--; return i+1; }
      else
      {   if(ar[i]<s) { ini=i; i=(i+n)/2; }
         else { n=i; i=(ini+i)/2; }
      }
   }
   return 0;
}
/*--------Selection sort efficient(incomplete)--(int_array,element)-------*/
void sel_sort_(int data[],int n)
{
   int i,j, m=n-1, low,indx,tmp; char q;
   for(i=0;i<m;i++)
   {
      low=data[i]; indx=i;
      for(j=i+1;j<n;j++)
      {
         if(data[j]<=low)
         {    
            while(data[i]==data[j])  i++;
            if(i>j) j=i-1;
            low=(data[j]); indx=j; q=1;
      }   }
      if(q==0) break;
      if(indx>i)
      {   data[i]^=data[index]; data[indx]^=data[i]; data[i]^=data[index]; }
      else if(i!=indx) i--;
}   }
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int j)
{   int i=0;   *(des+j)='\0';
   for(j--;i<j;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }
   if(i==j) *(des+i)=*(s+i);   }
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{   int i=0;  char tmp;
   for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }}
/*First find the lenth then Reverse & copy to destination simultaneously*/
/*-----------(des_str,str)-----------------*/
void revcopl(char *des,char *s)
{   int i=0,j=0; while(*(s+j)!=0) j++; *(des+j)='\0';
   for(j--;i<j;i++,j--){*(des+i)=*(s+j);*(des+j)=*(s+i);}
   if(i==j) *(des+i)=*(s+i);   }
/*----------First find the lenth then Reverse(str)---------*/
void revl(char *s)
{ int i=0,j=0;  char tmp; while(*(s+j)!=0) j++;
  for(j--;i<j;i++,j--){tmp=*(s+i);*(s+i)=*(s+j);*(s+j)=tmp; }}
/*---------Reverse & assign the char's by adding 48 (str,len)----------*/
void rev_assign(char *s,int j)
{   int i=0;  char tmp;
   for(j--;i<j;i++,j--){tmp=*(s+i)+48; *(s+i)=*(s+j)+48; *(s+j)=tmp;}
   if(i==j) (*(s+i))+=48; }
/*---------------Number string Compare(str1,str2,len1,len2)-------------*/
int str_cmp(char *a,char *b,int len1,int len2)
{   int i=0;
   if(len1>len2) return 1;
   else if(len2>len1) return -1;
   else
   {   for(;i<len1;i++)
         if(*(a+i)>(*(b+i))) return 1;
         else if(*(b+i)>(*(a+i))) return -1;
   } return 0;   }
/*--------------------------Finding Zero(str)--------------------*/
int zero(char *s)
{   int i;
   for(i=0;*(s+i)==48;i++);
   //if(i>0) {strcpy(s,s+i);} }
   return i;
/*-----------Assign the char's ASCII num By adding 48(str,len)------------*/
void assign(char *r,int k)
{   int i;
for(i=0;i<k;i++)  *(r+i)+=48; }
