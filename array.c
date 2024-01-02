#include <stdlib.h>
#include <stdio.h>

int * clearing_garbage(int * array, int max_ind, int size){
    for(int i = max_ind; i < size; i++){
        array[i]=0;
    }
    return array;
}

int * size_up(int * array, int * size, int max_ind){
    array = realloc(array, (*size) * sizeof(int));
    array = clearing_garbage(array, max_ind, *size);
    return array;
} 

int * size_down(int * array, int * size){
    array = realloc(array, *size * sizeof(int));
    return array;
}

int * create_array(int * array){
    array = calloc(1, sizeof(int));
    return array;
}

int * add_element(int * array, int * size, int * max_ind, int num, int index){
    int temp = *max_ind + 1;
    if(index > *max_ind){
        *max_ind = index;
    }
    if((*max_ind) + 1 > *size){
        while(*size < (*max_ind + 1)){
            *size *= 2;
        }
        array = size_up(array, size, temp);
    }
    if(array[*size - 1] != 0 && array[index] != 0){
       *size *=2;
        array = size_up(array, size, temp);
    }
    else if(array[index] != 0){
       for(int i = *size; i > index; i--){
          array[i] = array[i - 1];
        }
    }
    array[index] = num;
    return array;
}

void print_array(int * array, int * size){
    for(int i = 0; i < (*size); i++){
        if(array[i] != 0){
            printf("[%d] ", array[i]);
        }
        else{
            printf("[-] ");
        }
    }
    printf("\n");
}

int *remove_element(int * array, int * max_ind, int * size, int index){
    if(array[index] == 0 || index > (*max_ind)){
        printf("Incorrect index\n");
        return array;
    }
    array[index] = 0;
    if((*max_ind) == index){
        for(int i = (*max_ind); i >=0; i--){
            if(array[i] != 0){
                *max_ind = i;
                break;
            }
            *max_ind = 0;
        }
    }
    for(int i = index; i < (*size - 1); i++){
        array[i] = array[i + 1];
    }
    while(((*size) / 2) - 1 > (*max_ind) || (*size == 2 && *max_ind == 0)){
        (*size) /= 2;
    }
    array = size_down(array, size);
    return array;
}

int *create_pr_array(int *array, int *max_ind, int * pr_sz, int * size_ar){
    return NULL;
}
