#include <stdlib.h>
void create_array(int * array){
    array = calloc(1, sizeof(int));
}

void add_element(int * array, int * size, int * max_ind, int num, int index){
    if(index > *max_ind){
        *max_ind = index;
    }
    if((*max_ind) + 1 > *size){
        while(*size < (*max_ind + 1)){
            *size *= 2;
        }
        array = realloc(array, (*size) * sizeof(int));
    }
    if(array[*size - 1] != 0 && array[index] != 0){
       *size *=2;
      array = realloc(array, (*size) * sizeof(int));
    }
    else if(array[index] != 0){
       for(int i = *size; i > index; i--){
          array[i] = array[i - 1];
        }
    array[index] = num;
    }
}
