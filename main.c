#include <stdlib.h>
#include <stdio.h>
#include "array.h"
int main(){
   int input, *array = NULL, max_index = 0, *max_ind = &max_index, size_arr = 1, *size = &size_arr, *arr_pr = NULL, pr_size, *pr_sz = &pr_size;
        printf("Menu:\n");
        printf("1 Create array\n");
        printf("2 Add new number\n");
        printf("3 Delete number\n");
        printf("4 Create progressive array\n");
        printf("5 Exit\n");
      do{
        scanf("%d", &input);
        switch (input){
            case 1:
                array = create_array(array);
                print_array(array, size);
                break;
            case 2:
                int index, num;
                printf("Input num and index\n");
                scanf("%d %d", &num, &index);
                array = add_element(array, size, max_ind, num, index);
                printf("Elemen was added\n");
                print_array(array, size);
                break;
            case 3:
                printf("Input index\n");
                scanf("%d", &index);
                array = remove_element(array, max_ind, size, index);
                print_array(array, size);
                break;
            case 4:
                int **ptr_array = &array;
                arr_pr = create_pr_array(ptr_array, max_ind, pr_sz, size);
                printf("Old array: ");
                print_array(array, size);
                printf("New array: ");
                print_array(arr_pr, pr_sz);
                break;
            case 5:
                printf("Exiting\n");
                free(array);
                free(arr_pr);
                break;
            default:
                break;
        }
    }
    while(input != 5);
    return 0;
}
