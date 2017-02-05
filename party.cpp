#include <stdlib.h>
#include <math.h>

#include "party.h"
#include "constant.h"

frame *generatePartyFrames()
{
  uint8_t i;
  frame *head, *newFrame, *tail;
  
  for (i=0; i<16; i++) {
    newFrame = (frame *)malloc(sizeof(frame));
    
    newFrame->id = i;
    newFrame->led0 = (i%3 == 0 && i != 0) ? 1 : 0;
    newFrame->led1 = newFrame->led2 = (i%3 == 2) ? 1 : 0;
    newFrame->led3 = newFrame->led4 = newFrame->led5 = (i%3 == 1) ? 1 : 0;
    newFrame->led6 = newFrame->led7 = newFrame->led8 = newFrame->led9 = (i%3 == 0 && i != 15) ? 1 : 0;
    newFrame->wait = 500/pow(2, i/4);
    
    if (i == 0) {
      head = newFrame;
    } else {
      tail->next = newFrame;
    }
    tail = newFrame;
  }
  
  for (i=0; i<2; i++) {
    newFrame = generateFullFrame();
    newFrame->id = 16 + i;
    tail->next = newFrame;
    tail = newFrame;
  }
  
  newFrame = generateBlankFrame();
  newFrame->id = 18;
  newFrame->next = head;
  tail->next = newFrame;
  
  return head;
}

