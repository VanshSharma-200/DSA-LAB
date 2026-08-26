#include<stdio.h>
void main(){
    int a[50];
    int b[50];
    int c[100];
    int n1,n2,n3;
    printf("enter the size of a\n");
    scanf("%d",&n1);
    printf("enter array elements of a\n");
    for(int i=0;i<n1;i++)
        scanf("%d",&a[i]);
    printf("enter size of b\n");
    scanf("%d",&n2);
    printf("enter array elements of b\n");
    for(int i=0;i<n2;i++)
        scanf("%d",&b[i]);
    n3=n1+n2;
    for(int i=0;i<n1;i++)
        c[i]=a[i];
    for(int i=0;i<n2;i++)
        c[n1+i]=b[i];
    printf("values of merged array c are:\n");
    for(int i=0;i<n3;i++){
        printf("%d\n",c[i]);
    }
}
