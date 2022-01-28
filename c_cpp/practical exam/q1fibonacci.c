//Kaustav Sharma 2005731
#include <stdio.h>
int fibo (int n)
{
    int arr[n],i=0,k=1,a=0,b=1,max=0;
  while(i<n)
  {
    for(int j =0 ; j<k;j++)
    {
      if(i<n)
      {
        arr[i]=b;
        if(b>max)
          max=b;
        b=a+b;
        a=b-a;
        i++;
      }
      else
        break;
    }
    k++;
    a=0;
    b=1;
  }
  printf("Array : \n");
  for(int j =0 ; j<n;j++)
  {
    printf("%d ",arr[j]);

  }
  printf("\nMax Element : %d\n",max);
  return 0;
}
int main()
{
  int n;
  printf("Enter number of terms : ");
  scanf("%d",&n);
  fibo(n);
  return 0;
}