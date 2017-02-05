#pragma once

#include <stdint.h>

typedef struct frame frame;

struct frame
{
  uint8_t id : 6;
  uint8_t led0 : 1;
  uint8_t led1 : 1;
  uint8_t led2 : 1;
  uint8_t led3 : 1;
  uint8_t led4 : 1;
  uint8_t led5 : 1;
  uint8_t led6 : 1;
  uint8_t led7 : 1;
  uint8_t led8 : 1;
  uint8_t led9 : 1;
  uint16_t wait;
  frame *next;
};

uint8_t numberOfFrames(frame *item);
void freeFrames(frame *head);

