#include<stdio.h>
void main(){
    int n,pos;
    printf("enter size of arrr: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("enter the pos to be deleted: ");
    scanf("%d",&pos);
    if(pos<1 || pos>n){
        printf("invalid pos\n");
    } 
    else{
        for(int i=pos-1;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        n--;

    }
    printf("elements of array are:\n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }

}
