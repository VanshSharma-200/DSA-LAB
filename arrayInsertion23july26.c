#include<stdio.h>
void main(){
    int n,element,pos;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d Elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to insert: ");
    scanf("%d",&element);
    printf("Enter pos of element: ");
    scanf("%d",&pos);
    if(pos>n-1 || pos<1){
        printf("Invalid pos");
    }
    else{
        for(int i=n;i>=pos;i--){
        arr[pos-1]= arr[i-1];
        }
        arr[pos-1] = element;
        n++;
    }
    
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
