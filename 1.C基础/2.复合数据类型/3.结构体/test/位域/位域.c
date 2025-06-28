#include <stdio.h>
#include <stdint.h>

// CR0 Control Register Bitfield Definition
typedef struct {
    uint64_t PE : 1;      // Protection Enable
    uint64_t MP : 1;      // Monitor Coprocessor
    uint64_t EM : 1;      // Emulation
    uint64_t TS : 1;      // Task Switched
    uint64_t ET : 1;      // Extension Type
    uint64_t NE : 1;      // Numeric Error
    uint64_t reserved1 : 10; // Reserved
    uint64_t WP : 1;      // Write Protect
    uint64_t reserved2 : 1;  // Reserved
    uint64_t AM : 1;      // Alignment Mask
    uint64_t reserved3 : 10; // Reserved
    uint64_t NW : 1;      // Not Write-Through
    uint64_t CD : 1;      // Cache Disable
    uint64_t PG : 1;      // Paging
} CR0_Bits;

// Simulate CR0 Register Value (Return a typical value)
uint64_t simulate_cr0(void) {
    // In modern operating systems, PE (Protection Enable) and PG (Paging) are usually enabled
    // Return a typical CR0 value: PE=1, PG=1, WP=1 (Write Protect)
    return (1ULL << 0) | (1ULL << 16) | (1ULL << 31);
}

// Modify a specific bit in CR0 (simulated operation)
uint64_t modify_cr0_bit(uint64_t current_cr0, int bit_position, int value) {
    if (value) {
        // Set the bit to 1
        return current_cr0 | (1ULL << bit_position);
    } else {
        // Clear the bit to 0
        return current_cr0 & ~(1ULL << bit_position);
    }
}

// Print CR0 Register Status
void print_cr0_status(uint64_t cr0) {
    CR0_Bits* cr0_bits = (CR0_Bits*)&cr0;
    
    printf("CR0 Register Status (Simulated):\n");
    printf("  PE (Protection Enable): %d\n", cr0_bits->PE);
    printf("  MP (Monitor Coprocessor): %d\n", cr0_bits->MP);
    printf("  EM (Emulation): %d\n", cr0_bits->EM);
    printf("  TS (Task Switched): %d\n", cr0_bits->TS);
    printf("  ET (Extension Type): %d\n", cr0_bits->ET);
    printf("  NE (Numeric Error): %d\n", cr0_bits->NE);
    printf("  WP (Write Protect): %d\n", cr0_bits->WP);
    printf("  AM (Alignment Mask): %d\n", cr0_bits->AM);
    printf("  NW (Not Write-Through): %d\n", cr0_bits->NW);
    printf("  CD (Cache Disable): %d\n", cr0_bits->CD);
    printf("  PG (Paging): %d\n", cr0_bits->PG);
}

int main() {
    // 1. Get simulated CR0 value
    uint64_t cr0 = simulate_cr0();
    
    // 2. Print initial state
    printf("=== Initial CR0 State ===\n");
    print_cr0_status(cr0);
    
    // 3. Modify CR0 register bits (simulated operations)
    printf("\n=== Modifying CR0 Register ===\n");
    
    // 3.1 Disable cache (CD=1)
    cr0 = modify_cr0_bit(cr0, 30, 1);
    printf("State after disabling cache (CD=1):\n");
    print_cr0_status(cr0);
    
    // 3.2 Enable write protection (WP=1)
    cr0 = modify_cr0_bit(cr0, 16, 1);
    printf("\nState after enabling write protection (WP=1):\n");
    print_cr0_status(cr0);
    
    // 3.3 Attempt to disable paging (PG=0) - Dangerous in a real system!
    cr0 = modify_cr0_bit(cr0, 31, 0);
    printf("\nState after attempting to disable paging (PG=0):\n");
    print_cr0_status(cr0);
    
    // 4. Demonstrate direct modification through bitfield structure
    printf("\n=== Direct Modification via Bitfield Structure ===\n");
    CR0_Bits* cr0_bits = (CR0_Bits*)&cr0;
    cr0_bits->NE = 1;  // Enable numeric error
    cr0_bits->AM = 0;  // Disable alignment mask
    
    printf("State after modification:\n");
    print_cr0_status(cr0);
    
    return 0;
}
