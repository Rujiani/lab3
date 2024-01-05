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
    else{
        *max_ind -= 1;
        for(int i = index; i < (*size - 1); i++){
            array[i] = array[i + 1];
        }
        array[*size - 1] = 0;             // clear stuff
    }
    while(((*size) / 2) - 1 >= (*max_ind)){
        (*size) /= 2;
    }  
    array = size_down(array, size);
    return array;
}

int *create_pr_array(int **array, int *max_ind, int * pr_sz, int * size_ar){
    int * t_array = calloc(*size_ar, sizeof(int)), diff = 0, max_pr_index = 0, *max_pr_index_ptr = &max_pr_index;         //diff - progression difference
    for(int i = 0; i < *size_ar; i++){
        t_array[i] = (*array)[i];
    }
    int * pr_array = calloc(1, sizeof(int));
    for(int i = 0; i < *max_ind; i++){
        if(t_array[i]){
            for(int j = i + 1; j <= *max_ind; j++){
                if(t_array[j] && (!diff)){
                    diff = (t_array[j] - t_array[i]);
                    pr_array[0] = t_array[i];
                    *pr_sz = 1;
                }
                if(t_array[j] && (t_array[j] - t_array[i] == diff)){
                    pr_array = add_element(pr_array, pr_sz, max_pr_index_ptr, t_array[j], *max_pr_index_ptr + 1);
                }
            }
        }
    } 
    int temp_size = *size_ar, temp_max_index = *max_ind;
    for(int i = 0; i <= max_pr_index; i++){
        if(pr_array[i]){
            for(int j = 0; j <= *max_ind; j++){
               if(pr_array[i] == t_array[j]){
                    t_array = remove_element(t_array, max_ind, size_ar, j);
                    j--;
               }
            }
        }
    }
    if(*pr_sz < 4){
        free(t_array);
        *max_ind = temp_max_index;
        *size_ar = temp_size;
        printf("ERROR\n");
        return NULL;
    }
    free(*array);
    *array = t_array;
    return pr_array;
}
