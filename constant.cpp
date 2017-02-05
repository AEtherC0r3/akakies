#include <stdlib.h>

#include "constant.h"

frame *generateFullFrame()
{
  frame *head = (frame *)malloc(sizeof(frame));
  
  head->id = 0;
  head->led0 = head->led1 = head->led2 = head->led3 = head->led4 = head->led5 = head->led6 = head->led7 = head->led8 = head->led9 = 1;
  head->wait = 1000;
  head->next = head;
  
  return head;
}

frame *generateBlankFrame()
{
  frame *head = (frame *)malloc(sizeof(frame));
  
  head->id = 0;
  head->led0 = head->led1 = head->led2 = head->led3 = head->led4 = head->led5 = head->led6 = head->led7 = head->led8 = head->led9 = 0;
  head->wait = 1000;
  head->next = head;
  
  return head;
}

