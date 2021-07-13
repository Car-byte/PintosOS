#include "devices/input.h"
#include "lib/kernel/default-shell.h"
#include <stdio.h>
#include "threads/malloc.h"
#include <string.h>

#define MAX_INPUT 80
#define ENTER_KEY 13
#define DELETE_KEY 127
#define BACKSPACE 8
#define SPACE 32

void start_default_shell(void) {
  printf("Default shell starting...\n");

  for (;;) {
    printf("Pintos> "); // dynamic in the future
    uint8_t buffer[MAX_INPUT + 1];
    buffer[MAX_INPUT] = '\0';
    get_command(&buffer, MAX_INPUT);
    if (strcmp((char*)&buffer, "whoami") == 0) {
      printf("\nRoot\n");
    }
    else if (strcmp((char*)&buffer, "exit") == 0 ||
              strcmp((char*)&buffer, "quit") == 0) {
      printf("\nExiting shell, shutting down\n");
      return;
    }
    else {
      printf("\nUnknown command\n");
    }
    //printf("String is: %s\n", (char*)&buffer);
  }
}


void get_command(uint8_t* buffer, size_t size) {
  uint8_t backspace_string[3] = { BACKSPACE, SPACE, BACKSPACE };
  size_t index = 0;
  uint8_t cur_key = 0;
  while (index < size) {
    cur_key = input_getc();
    if (cur_key == ENTER_KEY) {
      buffer[index] = '\0';
      break;
    }
    else if (cur_key == BACKSPACE || cur_key == DELETE_KEY) {
      if (index > 0) {
        buffer[--index] = ' ';
        putbuf((char*)&backspace_string, 3);
      }
    }
    else {
      buffer[index] = cur_key;
      putchar(cur_key);
      ++index;
    }
  }
}
