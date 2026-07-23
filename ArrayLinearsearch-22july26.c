#include<stdio.h>
void main(){
    int n,key;
    printf("enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter key: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("found\n");
            return;
        }
    }
    printf("not found\n");
}
