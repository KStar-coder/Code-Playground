// Kaustav Sharma 2005731
#include <stdio.h>
int main()
{
  int n;
  printf("Enter number of terms: ");
  scanf("%d",&n);
  int a [2*n];
  for(int i=1 ; i<=2*n;i+=2)
  {
    a[i-1]=i;
    a[i]=2*n-i+1;
  }
  for(int i=0 ; i<n;i++)
  {
    for(int j=0 ; j<i;j++)
    {
      printf("  ");
    }
    for(int j=i ; j<2*n-i;j++)
    {
      printf("%d ",a[j]);
    }
    printf("\n");
  }
  return 0;
}
