#include <stdlib.h>

#include "waterfall.h"

frame *generateWaterfallFrames()
{
  frame *head, *tail;
  
  for (uint8_t i=0; i<4; i++) {
    frame *newFrame;
    
    newFrame = (frame *)malloc(sizeof(frame));
    
    newFrame->id = i;
    newFrame->led0 = (i == 0 || i == 3) ? 1 : 0;
    newFrame->led1 = newFrame->led2 = (i == 1) ? 1 : 0;
    newFrame->led3 = newFrame->led4 = newFrame->led5 = (i == 2) ? 1 : 0;
    newFrame->led6 = newFrame->led7 = newFrame->led8 = newFrame->led9 = (i == 3) ? 1 : 0;
    newFrame->wait = 300;
    
    if (i == 0) {
      head = newFrame;
    } else if (i == 3) {
      newFrame->next = head->next;
    }
    if (i != 0) {
      tail->next = newFrame;
    }
    tail = newFrame;
  }
  
  return head;
}

