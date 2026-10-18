#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_2  (2)
#define BASE_8  (8)
#define BASE_10 (10)
#define BASE_16 (16)

/**
 * @brief Converts a signed 32-bit integer to an ASCII string.
 *
 * Supports bases 2 to 16. Digits above 9 are written as uppercase letters
 * (A-F). Negative numbers get a leading '-'. The string is null terminated.
 * The buffer must hold at least 34 bytes (32 binary digits + sign + '\0').
 *
 * @param data The integer to convert
 * @param ptr Pointer to the buffer where the string will be stored
 * @param base The base to convert to (2 to 16)
 *
 * @return Length of the converted string, including the sign and the null terminator
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts an ASCII string to a signed 32-bit integer.
 *
 * Supports bases 2 to 16. An optional leading '-' is handled as a negative sign.
 *
 * @param ptr Pointer to the character string to convert
 * @param digits Number of characters in the string, including the sign. A trailing
 *               null terminator may be included in the count; it stops the conversion
 * @param base The base of the string (2 to 16)
 *
 * @return The converted signed 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
