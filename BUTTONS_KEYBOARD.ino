#include "Keyboard.h"
#define BTN_1 2
#define BTN_2 3
#define BTN_3 4
#define BTN_4 5

#define BTN_UP 14
#define BTN_DOWN 16
#define BTN_ALL 10
char ctrlKey = KEY_LEFT_CTRL;
int cnt1 = -500;
int cnt2 = -500;
int cnt3 = -500;
int cnt4 = -500;
int cnt5 = -500;
int cnt6 = -500;
int cnt7 = -500;

uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

void setup() {
  Serial.begin(9600);
  pinMode(BTN_1, INPUT);
  pinMode(BTN_2, INPUT);
  pinMode(BTN_3, INPUT);
  pinMode(BTN_4, INPUT);
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  Keyboard.begin();
}


void loop() {
  if(digitalRead(BTN_1) == HIGH){
    cnt1 = cnt1+1;
    if(cnt1 >= 100 && cnt4 >= 70){
      digitalWrite(BTN_4, LOW);
      cnt4 = 0;
    }
  }else if(digitalRead(BTN_1) == LOW){
    cnt1 = 0;
  }
  if(digitalRead(BTN_2) == HIGH){
    cnt2 = cnt2+1;
  }else if(digitalRead(BTN_2) == LOW){
    cnt2 = 0;
  }
  if(digitalRead(BTN_3) == HIGH){
    cnt3 = cnt3+1;
  }else{
    cnt3 = 0;
  }
  if(digitalRead(BTN_4) == HIGH){
    cnt4 = cnt4+1;
    if(cnt4 >= 90){
      digitalWrite(BTN_1, LOW);
      digitalWrite(BTN_3, LOW);
      cnt3 = 0;
      cnt1 = 0;
    }
  }else{
    cnt4 = 0;
  }
  if(digitalRead(BTN_UP) == HIGH){
    cnt5 = cnt5+1;
    if(cnt5 >= 90 || (cnt5 <= -10)){
      digitalWrite(BTN_1, LOW);
      digitalWrite(BTN_2, LOW);
      digitalWrite(BTN_3, LOW);
      digitalWrite(BTN_4, LOW);
      digitalWrite(BTN_DOWN, LOW);
      digitalWrite(BTN_ALL, LOW);
      cnt1 = 0; cnt2 = 0; cnt3 = 0;
      cnt4 = 0; cnt6 = 0; cnt7 = 0;
    }
  }else{
    cnt5 = 0;
  }
  if(digitalRead(BTN_DOWN) == HIGH){
    cnt6 = cnt6+1;
    if(cnt6 >= 90){
      digitalWrite(BTN_1, LOW);
      digitalWrite(BTN_2, LOW);
      digitalWrite(BTN_3, LOW);
      digitalWrite(BTN_4, LOW);
      digitalWrite(BTN_UP, LOW);
      digitalWrite(BTN_ALL, LOW);
      cnt1 = 0; cnt2 = 0; cnt3 = 0;
      cnt4 = 0; cnt5 = 0; cnt7 = 0;
    }
  }else{
    cnt6 = 0;
  }
  if(digitalRead(BTN_ALL) == HIGH){
    cnt7 = cnt7+1;
    if(cnt7 >= 90){
      digitalWrite(BTN_1, LOW);
      digitalWrite(BTN_2, LOW);
      digitalWrite(BTN_3, LOW);
      digitalWrite(BTN_4, LOW);
      digitalWrite(BTN_UP, LOW);
      digitalWrite(BTN_DOWN, LOW);
      cnt1 = 0; cnt2 = 0; cnt3 = 0;
      cnt4 = 0; cnt5 = 0; cnt6 = 0;
    }
  }else{
    cnt7 = 0;
  }

  
  if(cnt1 >= 120){
    cnt1 = -500;
    code_blocks();
    digitalWrite(BTN_1, LOW);
  }else if(cnt2 >= 120){
    cnt2 = -500;
    notepad();
    digitalWrite(BTN_2, LOW);
  }else if(cnt3 >= 120){
    cnt3 = -500;
    chrome();
    digitalWrite(BTN_3, LOW);
  }else if(cnt4 >= 120){
    cnt4 = -500;
    file_explorer();
    digitalWrite(BTN_4, LOW);  
  }else if(cnt5 >= 120){
    Keyboard.press(ctrlKey);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();
    cnt5 = 0-500;
  }else if(cnt6 >= 120){
    Keyboard.press(ctrlKey);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
    cnt6 = -500;
  }else if(cnt7 >= 120){
    Keyboard.press(ctrlKey);
    Keyboard.press('a');
    delay(100);
    Keyboard.releaseAll();
    cnt7 = -500;
  }
  Serial.print(cnt7);
  Serial.print(" ");
  Serial.print(cnt6);
  Serial.print(" ");
  Serial.print(cnt5);
  Serial.print(" ");
  Serial.print(cnt4);
  Serial.print(" ");
  Serial.print(cnt3);
  Serial.print(" ");
  Serial.print(cnt2);
  Serial.print(" ");
  Serial.println(cnt1);
  delay(10);
}

//owoowoowoowoowoowoowoowoowo

void code_blocks(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("codeblocks");
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void notepad(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("notepad");
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void chrome(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("chrome");
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void file_explorer(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("file explorer");
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}
