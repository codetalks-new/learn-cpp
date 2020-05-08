#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

uint16_t u16_change_byte_order(uint16_t value) {
  return (value << 8) | (value >> 8);
}

bool is_little_endian() {
  uint16_t value = 2020;
  uint8_t *bytes = (uint8_t *)&value;
  return *bytes == 0x4e;
}
uint64_t hton64(uint64_t value) {
  __asm__("bswap   %0" : "+r"(value));
  return value;
}
int main(int argc, char const *argv[]) {
  assert(hton64(0x123456789abcdef1) == 0xf1debc9a78563412);
  return 0;
}
