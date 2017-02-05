#include <stdlib.h>

#include "frame.h"

uint8_t numberOfFrames(frame *item)
{
  uint8_t current_id;
  
  do {
    current_id = item->id;
    item = item->next;
  } while (item->id > current_id);
  
  return current_id + 1;
}

void freeFrames(frame *head) {
  if (head->id == 0) {
    uint8_t i, N;
    frame *tmp;
    N = numberOfFrames(head);
    for (i=0; i<N; i++) {
      tmp = head;
      head = head->next;
      free((void *)tmp);
    }
  }
}

