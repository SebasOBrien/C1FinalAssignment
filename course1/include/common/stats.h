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
 * @file stats.h
 * @brief Header of stats.c 
 *
 * This file containts declarations and comments about the functions used in stats.c, including their parameters, return values, and descriptions.
 *
 * @author Sebastian O'Brien
 * @date 04/10/2026 (dd/mm/yyyy)
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function that prints the statistics of an array.
 *
 * A function that recieves an array and prints statistics including minimum, maximum, mean, and median by calling the respectives functions. The function has no return value and doesn't modify the original array.
 *
 * @param array The array whose statistics will be shown
 * @param size The size of the array
 *
 * @return The function doesn't return any value
 */
void print_statistics(unsigned char * array, int size);

/**
 * @brief A function that prints the contents of an array.
 *
 * A function that recieves an array and prints its contents separated by a ' '. The function has no return value and doesn't modify the original array.
 *
 * @param array The array whose contents will be shown
 * @param size The size of the array
 *
 * @return The function doesn't return any value
 */
void print_array(unsigned char * array, int size);

/**
 * @brief A function that finds the median value in an array
 *
 * A function that recieves an array and returns its median value. The function doesn't modify the original array.
 *
 * @param array The array whose median value will be found
 * @param size The size of the array
 *
 * @return Median value of the given array
 */
int find_median(unsigned char * array, int size);

/**
 * @brief A function that finds the mean value in an array
 *
 * A function that recieves an array and returns its mean value. The function doesn't modify the original array.
 *
 * @param array The array whose mean value will be found
 * @param size The size of the array
 *
 * @return Mean value of the given array
 */
int find_mean(unsigned char * array, int size);

/**
 * @brief A function that finds the maximum value in an array
 *
 * A function that recieves an array and returns its maximum value. The function doesn't modify the original array.
 *
 * @param array The array whose maximum value will be found
 * @param size The size of the array
 *
 * @return Maximum value of the given array
 */
int find_maximum(unsigned char * array, int size);

/**
 * @brief A function that finds the minimum value in an array
 *
 * A function that recieves an array and returns its minimum value. The function doesn't modify the original array.
 *
 * @param array The array whose minimum value will be found
 * @param size The size of the array
 *
 * @return Minimum value of the given array
 */
int find_minimum(unsigned char * array, int size);

/**
 * @brief A function that descending sorts an array 
 *
 * A function that recieves an array and sorts it from its largest to smallest value by finding the max value and moving it to the front. The function has no return value, but it modifies the given array.
 *
 * @param array The array to be sorted
 * @param size The size of the array
 *
 * @return The function doesn't return any value
 */
void sort_array(unsigned char * array, int size);

#endif /* __STATS_H__ */
