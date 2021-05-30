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
   int i=0;  
   char tmp;
   for(j--;i<j;i++,j--)
   {   tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/*First find the lenth then Reverse & copy to destination simultaneously*/
/*-----------(des_str,str)-----------------*/
void revcopl(char *des,char *s)
{   
   int i=0,j=0;
   while(*(s+j)!=0) j++; *(des+j)='\0';
   for(j--;i<j;i++,j--)
   {   *(des+i)=*(s+j);*(des+j)=*(s+i); }
   if(i==j) *(des+i)=*(s+i);   
}
/*----------First find the lenth then Reverse(str)---------*/
void revl(char *s)
{ 
   int i=0,j=0;
   char tmp;
   while(*(s+j)!=0) j++;
   for(j--;i<j;i++,j--)
   {   tmp=*(s+i);*(s+i)=*(s+j);*(s+j)=tmp; }
}
/*---------Reverse & assign the char's by adding 48 (str,len)----------*/
void rev_assign(char *s,int j)
{   
   int i=0;
   char tmp;
   *(s+j)=0;
   for(j--;i<j;i++,j--)
   {   tmp=*(s+i)+48; *(s+i)=*(s+j)+48; *(s+j)=tmp; }
   if(i==j) (*(s+i))+=48; 
}
/*---------------Number string Compare(str1,str2,len1,len2)-------------*/
int str_cmp(char *a,char *b,int len1,int len2)
{   
   int i=0;
   if(len1>len2) return 1;
   else if(len2>len1) return -1;
   else
   {   for(;i<len1;i++)
         if(*(a+i)>(*(b+i))) return 1;
         else if(*(b+i)>(*(a+i))) return -1;
   } return 0;   
}
/*--------------------------Finding Zero(str)--------------------*/
int zero(char *s)
{   
   int i;
   for(i=0;*(s+i)==48;i++);
   //if(i>0) {strcpy(s,s+i);} 
   return i;
}
/*-----------Assign the char's ASCII num By adding 48(str,len)------------*/
void assign(char *r,int k)
{   
   int i;
   for(i=0;i<k;i++)  *(r+i)+=48; 
}
/*---Find out the number of word in a line(STL_string_array, source_str)---*/
int string_evaluation(string dest[],char *src)
{
   int count=0;
   char *s;

   while(*src)
      {
      if((*src>64&&*src<91)||(*src>96&&*src<123))
         {
         s=src;
         for(src++;(*src>64&&*src<91)||(*src>96&&*src<123);src++);
         dest[count].insert(dest[count].begin(),s,src);
         count++;
         }
      else src++;
      }
   return count;
}
/*---Find out the number of strings in a line(3D_dest_str, source_str)---*/
int string_evaluation(char dest[R][T][T],char *src)
{
   int k,count=0;
   char *i=src;

   while(*i)
   {
      if((*i)!=' '&&(*i)!='\t')
      {
         for(k=0;(*i)!=' '&&(*i)!='\t'&&(*i);i++)
            dest[count][0][k++]=*i;
         count++;
      }
      else i++;
   }
   return count;
}
