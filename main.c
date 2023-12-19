#include <stdlib.h>
#include <stdio.h>
#include "array.h"
int main(){
    int input, size_of_array = 1, max_index = 0, input_index, size_pr_arr; 
    int *array, *size = &size_of_array, *max_ind = &max_index; 
    do{
        printf("1 Create array\n");
        printf("2 Add new number\n");
        printf("3 Delete number\n");
        printf("4 Create progressive array\n");
        printf("5 Output array\n");
        printf("6 Output progressive array\n");
        printf("7 Exit\n");
        scanf("%d", &input);
        switch (input){
            case 1:
                create_array(array);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Exiting\n");
                free(array);
                break;
            default:
                break;
        }
    }
    while(input != 7);
    return 0;
}
