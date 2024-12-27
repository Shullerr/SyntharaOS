// Simple text output to the screen
#include "common.h"

#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Screen buffer
static uint16_t *video = (uint16_t *)VIDEO_MEMORY;
static int cursor_x = 0;
static int cursor_y = 0;

void terminal_initialize() {
    // Clear the screen
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        video[i] = (0x0F << 8) | ' ';  // White text on black background
    }
}

void terminal_writestring(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        terminal_putchar(str[i]);
    }
}

void terminal_putchar(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        video[cursor_y * SCREEN_WIDTH + cursor_x] = (0x0F << 8) | c;
        cursor_x++;
    }

    if (cursor_x >= SCREEN_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y >= SCREEN_HEIGHT) {
        cursor_y = 0;
    }
}
