#ifndef ARRAY_H
#define ARRAY_H
int * clearing_garbage(int * array, int max_ind, int size);
int *create_array(int * array);
int *remove_element(int * array, int * max_ind, int * size, int index);
void print_array(int * array, int * size);
int *add_element(int * array, int * size, int * max_ind, int num, int index); 
int *create_pr_array(int * array, int * max_ind, int * pr_sz, int * size_ar);
int *size_down(int *array, int *size);
#endif
