/*------Linear Search( array, total_element, searching_number)---------*/
int linear_search(int *ar,int n,int s)
{   
   int i=0;
   for(;i<n;i++)
      if(*(ar+i)==s) return i;
   return -1;
}
/*---Binary Search(array, total_element, searching_number)[ascending]-----*/
int binary_search(int data[],int n,int key)
{
   int begin=0,mid;
   while(begin<n)
   {
      mid=(begin+n)/2;
      if(data[mid]==key)
      {
         while(data[mid-1]==key) mid--; //if there has several key value
         return mid;
      }
      else if(key<data[mid]) n=mid; //
      else begin=mid+1;
   }
   return -1;
}   
/*---Binary Search(array, total_element, searching_number)-----*/
int binary_search(int data[],int n,int key)
{                     // here total_element is "total_element-1".
   int begin=0,mid;
   while(begin<=n)
   {
      mid=(begin+n)/2;
      if(data[mid]==key)
      {
         while(data[mid-1]==key) mid--; //if there has several key
         return mid;
      }
      else if(key>data[mid]) n=mid-1;//##  /* '>' if the data are in descending order   */
      else begin=mid+1;               /*## '<=' if want to take the subsequent value */
   }
   //return begin;   //middle position where the key lies between
   return (-1);
}   
