#include<stdio.h>

void bubble_sort(int a[],int s){
    int flag=0;
	for(int i=0; i<s-1; i++){
        for(int j=0; j<s-1-i; j++){
            if(a[j]>a[j+1]){
                int temp=a[j+1];    
                a[j+1]=a[j];         
                a[j]=temp;

                flag++;
            }
        }
        if(flag==0){
            printf("\n The array is already Sorted");
            break;
        }
    }
}

int main(){
int array[10],size,i;
   
   printf("Enter the size of the array:: ");
   scanf("%d",&size);

   if(size>10){
        printf("\nSORRY!! The array is Overflows");
    }
   else{
        printf("\n Enter the elements of the array:: ");
        for(i=0; i<size; i++){
            scanf("%d",&array[i]);
        }

        printf("\n The elements of the array:: ");
        for(i=0; i<size; i++){
            printf("%d\t",array[i]);
        }

        bubble_sort(array,size);

        printf("\n After Sorting The Array is:: ");
        for(i=0; i<size; i++){
            printf("%d\t",array[i]);
        }
    }
   return 0;
}
