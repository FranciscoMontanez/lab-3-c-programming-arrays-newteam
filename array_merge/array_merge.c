#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../mergesort/mergesort.c"

bool includes(int length, int* keys, int key) {
    for (int i = 0; i < length; i++) {
        if (key == keys[i]) {
            return true;
        }
    }
    return false;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
    int keys_size = 0;
    for (int i = 0; i < num_arrays; i++) {
        keys_size += sizes[i];
    }
    int keys[keys_size];
    int curr_keys_index = 0;
   
 
   
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            if (!includes(curr_keys_index, keys, values[i][j])) {
                keys[curr_keys_index] = values[i][j];
                curr_keys_index++;
            }
        }
    }
   
    mergesort(curr_keys_index, keys);
   
    int* toReturn = (int*) malloc(sizeof(int) * (curr_keys_index + 2));
    toReturn[0] = curr_keys_index;
    for (int i = 0; i < curr_keys_index + 2; i++) {
        toReturn[i+1] = keys[i];
    }

    return toReturn;
    free(toReturn);
}
