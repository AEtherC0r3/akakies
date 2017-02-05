#include <stdint.h>

#include "frame.h"
#include "constant.h"

void showFrame(frame *nextFrame);

uint8_t led0 = 0;
uint8_t led1 = 1;
uint8_t led2 = 2;
uint8_t led3 = 3;
uint8_t led4 = 4;
uint8_t led5 = 5;
uint8_t led6 = 6;
uint8_t led7 = 7;
uint8_t led8 = 8;
uint8_t led9 = 9;
uint8_t button = 10;

frame *(*generateFrameSequence[1])();
frame *head, *currentFrame;
uint32_t lastChange = 0;
uint8_t currentIndex = 0;

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  currentFrame = head = generateBlankFrame();
  showFrame(currentFrame);
  
  generateFrameSequence[0] = &generateFullFrame;
}

void loop() {
  if (millis() > lastChange + currentFrame->wait || millis() < lastChange) {
    currentFrame = currentFrame->next;
    showFrame(currentFrame);
    lastChange = millis();
  }
  
  if (digitalRead(button) == LOW) {
    freeFrames(head);
    ++currentIndex %= 1;
    currentFrame = head = generateFrameSequence[currentIndex]();
    showFrame(head);
    lastChange = millis();
  }

}

void showFrame(frame *nextFrame) {
  digitalWrite(led1, nextFrame->led0 ? HIGH : LOW);
  digitalWrite(led2, nextFrame->led1 ? HIGH : LOW);
  digitalWrite(led3, nextFrame->led2 ? HIGH : LOW);
  digitalWrite(led3, nextFrame->led3 ? HIGH : LOW);
  digitalWrite(led4, nextFrame->led4 ? HIGH : LOW);
  digitalWrite(led5, nextFrame->led5 ? HIGH : LOW);
  digitalWrite(led6, nextFrame->led6 ? HIGH : LOW);
  digitalWrite(led7, nextFrame->led7 ? HIGH : LOW);
  digitalWrite(led8, nextFrame->led8 ? HIGH : LOW);
  digitalWrite(led9, nextFrame->led9 ? HIGH : LOW);
}
