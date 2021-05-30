/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
void ss_add(char *r,char *u,char *v,int len,int i)//<Require revcop & rev>
{   
   char m[R],n[R], sum;
   revcop(&m[0],u,len); revcop(&n[0],v,i);
   
   if(len>i) for(;i<len;i++) n[i]=48;
   else if(len<i) for(;len<i;len++) m[len]=48;
   
   for(sum=0,i=0;i<len;i++)
   {   
      sum+=(m[i]+n[i]);
      if (sum>105) {   *(r+i)=sum-58; sum=1; }
      else  { *(r+i)=sum-48; sum=0; }
   }
   if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
   else  *(r+i)=0;    rev(r,i);
}
/*----------Addition of string & Number(des str,str,num,len)------------*/
void si_add(char *r,char *u,long sum,int len)//<Require revcop & rev>
{   
   char m[R],n[R]; int i=0;
   revcop(&m[0],u,len);
   while(sum>9) {n[i++]=sum%10; sum/=10;} n[i++]=sum;
   
   if(len>i) for(;i<len;i++) n[i]=48;
   else if(len<i) for(;len<i;len++) m[len]=48;
   
   for(sum=0,i=0;i<len;i++)
   {   
      sum+=(m[i]+n[i]); if (sum>57) { *(r+i)=sum-10; sum=1; }
      else  { *(r+i)=sum; sum=0; }
   }
   if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
   else  *(r+i)=0;   rev(r,i);    }
/*----------Subtraction of 2 string(des str,str1,str2,len1,len2)--------*/
void ss_sub(char *r,char *m,char *n,int len,int ln)
{   
   int i=len,sub=0; *(r+i)=0;
   for(len--,ln--,i--;ln>-1&&len>-1;len--,ln--,i--)
   {   
      sub=*(m+len)-*(n+ln)-sub;
      if (sub<0) {   *(r+i)=sub+58; sub=1; }
      else  { *(r+i)=sub+48; sub=0; }
   }
   for(;len>-1;len--,i--)
   {   
      if (*(m+len)-sub<48) { *(r+i)=57; sub=1; }
      else
      {   *(r+i)=*(m+len)-sub;
         for(i--;i>-1;i--) *(r+i)=(*(m+i));
         break;
      }
   }// for
}// end
