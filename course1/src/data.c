#include <stdint.h>
#include <stddef.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  if (ptr == NULL || base < 2 || base > 16) return 0;

  uint8_t * p = ptr;
  uint8_t negative = 0;
  uint32_t value;

  /* Unsigned so INT32 doesn't overflow'  */
  if (data < 0) {
    negative = 1;
    value = 0u - (uint32_t)data;
  } else {
    value = (uint32_t)data;
  }

  /* Less significative -> Most significative */
  if (value == 0) {
    *p++ = '0';
  }
  while (value != 0) {
    uint32_t rem = value % base;
    *p++ = (rem < 10) ? (uint8_t)('0' + rem) : (uint8_t)('A' + (rem - 10));
    value /= base;
  }

  if (negative) {
    *p++ = '-';
  }
  *p = '\0';

  /* Inverts the string without the '\0' */
  uint8_t * start = ptr;
  uint8_t * end = p - 1;
  while (start < end) {
    uint8_t temp = *start;
    *start++ = *end;
    *end-- = temp;
  }

  /* Length including the sign and '\0' */
  return (uint8_t)((p - ptr) + 1);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  if (ptr == NULL || base < 2 || base > 16) return 0;

  uint32_t result = 0;
  uint8_t negative = 0;

  /* Optional sign at the beginning */
  if (digits > 0 && *ptr == '-') {
    negative = 1;
    ptr++;
    digits--;
  }

  while (digits--) {
    uint8_t c = *ptr++;
    uint32_t digit;

    if (c >= '0' && c <= '9')      digit = c - '0';
    else if (c >= 'A' && c <= 'F') digit = c - 'A' + 10;
    else if (c >= 'a' && c <= 'f') digit = c - 'a' + 10;
    else break;                    /* invalid character */

    if (digit >= base) break;      /* out of base */

    result = result * base + digit;
  }

  return negative ? (int32_t)(0u - result) : (int32_t)result;
}
