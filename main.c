#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include <stdbool.h>
void clear_buffer(){
    int temp = getchar();
    while(temp != '\n'){
        temp = getchar();
    }
}

int main(){
   int input, *array = NULL, max_index = 0, *max_ind = &max_index, size_arr = 1, *size = &size_arr, *arr_pr = NULL, pr_size, *pr_sz = &pr_size;
        printf("Menu:\n");
        printf("1 Create array\n");
        printf("2 Add new number\n");
        printf("3 Delete number\n");
        printf("4 Create progressive array\n");
        printf("5 Exit\n");
      do{
        bool scan = scanf("%d", &input);
        if (feof(stdin)){
            printf("EOF\n");
            free(array);
            free(arr_pr);
            return -1;
        }
        
        if(!scan){
            printf("ERROR of input\n");
            clear_buffer();
            continue;
        }
        
        if(!array && input != 1){
            printf("You must create array first\n");
            continue;
        }
        else if(array && input == 1){
            printf("Array already created\n");
            continue;
        }
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
                free(arr_pr);
                arr_pr = create_pr_array(ptr_array, max_ind, pr_sz, size);
                if(arr_pr){
                    printf("Old array: ");
                    print_array(array, size);
                    printf("New array: ");
                    print_array(arr_pr, pr_sz);
                }
                break;
            case 5:
                printf("Exiting\n");
                free(array);
                free(arr_pr);
                break;
            default:
                printf("Please input number (1 - 5)\n");
                break;
        }
    }
    while(input != 5);
    return 0;
}
