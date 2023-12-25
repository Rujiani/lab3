#include <stdlib.h>
#include <stdio.h>
#include "array.h"
int main(){
   int input, *array, max_index = 0, *max_ind = &max_index, size_arr = 1, *size = &size_arr;
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
                int index, num;
                printf("Input num and index\n");
                scanf("%d %d", &num, &index);
                add_element(array, size, max_ind, num, index);
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
