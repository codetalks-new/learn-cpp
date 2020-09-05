#include <stdint.h>
#include <string.h>
unsigned normal_strlen(const char *str) {
  const char *s = str;
  for (; *s; s++) {
  }
  return s - str;
}

unsigned gcc_strlen(const char *str) {
  uint64_t *p = (uint64_t *)str;
  uint64_t himagic = 0x8080808080808080;
  uint64_t lomagic = 0x0101010101010101;
  for (;;) {
    uint64_t value = *p++;
    if (((value - lomagic) & ~value & himagic) != 0) {
      const char *cp = (const char *)(p - 1);
      if (cp[0] == 0) return cp - str;
      if (cp[1] == 0) return cp - str + 1;
      if (cp[2] == 0) return cp - str + 2;
      if (cp[3] == 0) return cp - str + 3;
      if (cp[4] == 0) return cp - str + 4;
      if (cp[5] == 0) return cp - str + 5;
      if (cp[6] == 0) return cp - str + 6;
      if (cp[7] == 0) return cp - str + 7;
    }
  }
}

int calc_utf8_char_bytes(const uint8_t byte) {
  if ((byte & 0x80) == 0) {
    return 1;
  } else if ((byte & 0xe0) == 0xc0) {
    return 2;
  } else if ((byte & 0xf0) == 0xe0) {
    return 3;
  } else if ((byte & 0xf8) == 0xf0) {
    return 4;
  } else {
    return -1;
  }
}

int utf8_strlen(const char *str) {
  if (str == NULL) {
    return 0;
  }
  int byte_len = strlen(str);
  int i = 0;
  int char_size = 0;
  uint8_t *bytes = (uint8_t *)str;
  while (i < byte_len) {
    uint8_t byte1 = bytes[i];
    int char_total_bytes = calc_utf8_char_bytes(byte1);
    if (char_total_bytes == -1) {
      return -1;
    }
    for (int j = i + 1; j < i + char_total_bytes; j++) {
      if (j < byte_len) {
        if ((bytes[j] & 0xc0) == 0x80) {
          // OK
        } else {
          return -1;
        }
      } else {
        return -1;
      }
    }
    i += char_total_bytes;
    char_size += 1;
  }
  return char_size;
}
