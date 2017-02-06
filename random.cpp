#include <Arduino.h>
#include <stdint.h>

#include "random.h"

frame *generateRandomFrames()
{
  randomSeed(millis());
  
  frame *head, *tail;
  
  for (uint8_t i=0; i<30; i++) {
    frame *newFrame = (frame *)malloc(sizeof(frame));
    uint16_t rand = random(0, 1025);
    
    newFrame->id = i;
    newFrame->led0 = rand & 1;
    newFrame->led1 = rand >> 1 & 1;
    newFrame->led2 = rand >> 2 & 1;
    newFrame->led3 = rand >> 3 & 1;
    newFrame->led4 = rand >> 4 & 1;
    newFrame->led5 = rand >> 5 & 1;
    newFrame->led6 = rand >> 6 & 1;
    newFrame->led7 = rand >> 7 & 1;
    newFrame->led8 = rand >> 8 & 1;
    newFrame->led9 = rand >> 9 & 1;
    newFrame->wait = 1000;
    
    if (i == 0) {
      head = newFrame;
    } else if (i == 29) {
      newFrame->next = head;
    }
    if (i != 0) {
      tail->next = newFrame;
    }
    tail = newFrame;
  }
  
  return head;
}

