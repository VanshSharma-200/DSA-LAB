#include <stdio.h>
void main() {
    int arr[100] ,n;
    printf("enter the size of array: ");
    scanf("%d",&n);
    printf("now enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("elements of array are: ");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
