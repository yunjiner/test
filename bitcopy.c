#include <stdio.h>
#include <stdint.h>

void bitcpy_by_mask(uint32_t *dest, uint32_t* src, uint32_t mask) {
    *dest = (*dest & ~mask) | (*src & mask);
}

uint32_t bitmemcpy(uint32_t dest, uint32_t src, size_t dest_bit_offset, size_t src_bit_offset, size_t num_bits) {
    uint32_t mask = (1 << num_bits) - 1;

    uint32_t src_bits = (src >> src_bit_offset) & mask;
    uint32_t dest_mask = ~(mask << dest_bit_offset);
    uint32_t dest_bits = (dest & dest_mask) | (src_bits << dest_bit_offset);

    return dest_bits;
}

int main() {
    uint32_t src_data = 0x00000002;
    uint32_t dest_data = 0x11111112;

    size_t src_bit_offset = 12;
    size_t dest_bit_offset = 12;
    size_t num_bits = 8;

    dest_data = bitmemcpy(dest_data, src_data, dest_bit_offset, src_bit_offset, num_bits);

    printf("Source Data: 0x%08X\n", src_data);
    printf("Destination Data: 0x%08X\n", dest_data);


    return 0;
}