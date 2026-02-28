#include <stdio.h>
#include <math.h>

int main(){
    int size;
    printf("Enter the size of the set you want to enter: \n");
    scanf(" %d", &size);

    int arr[size];
    for(int i = 0; i<size; i++){
        printf("Enter the element number %d: ", i+1);
        scanf(" %d", &arr[i]);
    }

    int num_of_comb = (int)pow(2, size);
    int comb_ty = 0;
    
    while(comb_ty < num_of_comb){

        printf(" { ");

        for(int curr = 0; curr<size; curr++){
            if((comb_ty & (1 << curr))!= 0){
                printf(" %d", arr[curr]);
            } 
        }

        printf(" }\n");
        comb_ty++;

    }
}