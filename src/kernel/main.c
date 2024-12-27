// Simple kernel entry point (C code)
#include "common.h"  // Include any necessary common headers

void kernel_main(void) {
    // Initialize screen (output for user)
    terminal_initialize();

    // Print a welcome message
    terminal_writestring("Welcome to SyntharaOS!\n");

    // Start the kernel setup (memory, scheduling, etc.)
    kernel_initialize();

    // Main loop (simple kernel loop to keep the system running)
    while (1) {
        // Do kernel tasks like handling interrupts, scheduling, etc.
    }
}

void kernel_initialize() {
    // Set up memory management, interrupts, and other system resources here
    // E.g., initialize the heap, stack, enable interrupts, etc.
    init_memory_manager();
    init_interrupts();
}
