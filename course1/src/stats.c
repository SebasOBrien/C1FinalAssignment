/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Functions for analysing an reporting an array's contents
 *
 * This file contains the implementation of functions that can analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of a data set.
 *
 * @author Sebastian O'Brien
 * @date 04/10/2026 (dd/mm/yyyy)
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
    

  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
  printf("BEFORE SORTING THE ARRAY\n");
  print_array(test, SIZE);
  sort_array(test, SIZE);
  printf("AFTER SORTING THE ARRAY\n");
  print_array(test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char * array, int size) {
  printf("STATISTICS OF THE ARRAY \n");
  printf("====================================\n");
  printf("Median value: %d\n", find_median(array, size));
  printf("Mean value: %d\n", find_mean(array, size));
  printf("Maximum value: %d\n", find_maximum(array, size));
  printf("Minimum value: %d\n", find_minimum(array, size));
  printf("====================================\n");
}

void print_array(unsigned char * array, int size) {
  printf("Contents of the array: ");
  for (int i=0; i<size; i++)
    printf("%d " , array[i]);
  printf("\n");
}

int find_median(unsigned char * array, int size) {
  int pos_median = size/2;
  return array[pos_median];
}

int find_mean(unsigned char * array, int size) {
  int sum = 0;
  for (int i=0; i<size; i++)
    sum += array[i];
  return sum/size;
}

int find_maximum(unsigned char * array, int size) {
  int maximum = 0;
  for (int i=0; i<size; i++) {
    if (array[i] > maximum)
      maximum = array[i];
  }
  return maximum;
}

int find_minimum(unsigned char * array, int size) {
  int minimum = 99999;
  for (int i=0; i<size; i++) {
    if (array[i] < minimum)
      minimum = array[i];
  }
  return minimum;
}

void sort_array(unsigned char * array, int size) {
  int i, j;
  for (i=0; i<size-1; i++) {
    int pos_max = i;
    for (j=i+1; j<size; j++) {
      if (array[j] > array[pos_max])
        pos_max = j;
    }
    if (pos_max != i) {
      int temp = array[i];
      array[i] = array[pos_max];
      array[pos_max] = temp;
    }
  }
}


