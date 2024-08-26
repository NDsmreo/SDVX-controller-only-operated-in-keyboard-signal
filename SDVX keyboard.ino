#include <Keyboard.h>
#define BT_A 13
#define BT_B 12
#define BT_C 11
#define BT_D 10
#define BT_E 9
#define BT_F 8
#define FX_L 7
#define FX_R 6
#define BT_ST 5

#define LBT_A A0
#define LBT_B A1
#define LBT_C A2
#define LBT_D A3
#define LBT_E A4
#define LBT_F A5
#define LFX_L MOSI
#define LFX_R MISO
#define LBT_ST SCK

#include "Encoder.h"
Encoder enc1(0, 1);
Encoder enc2(2, 3);
int16_t knob1 = 0;
int16_t knob2 = 0;
int8_t old_knob1 = 0;
int8_t old_knob2 = 0;

void setup()
{
  pinMode(BT_A, INPUT); 
  pinMode(BT_B, INPUT);
  pinMode(BT_C, INPUT);
  pinMode(BT_D, INPUT);
  pinMode(BT_E, INPUT);
  pinMode(BT_F, INPUT);
  pinMode(FX_L, INPUT);
  pinMode(FX_R, INPUT);
  pinMode(BT_ST, INPUT);

  pinMode(LBT_A, OUTPUT);
  pinMode(LBT_B, OUTPUT);
  pinMode(LBT_C, OUTPUT);
  pinMode(LBT_D, OUTPUT);
  pinMode(LBT_E, OUTPUT);
  pinMode(LBT_F, OUTPUT);
  pinMode(LFX_L, OUTPUT);
  pinMode(LFX_R, OUTPUT);
  pinMode(LBT_ST, OUTPUT);

  digitalWrite(BT_A, HIGH);
  digitalWrite(BT_B, HIGH);
  digitalWrite(BT_C, HIGH);
  digitalWrite(BT_D, HIGH);
  digitalWrite(BT_E, HIGH);
  digitalWrite(BT_F, HIGH);
  digitalWrite(FX_L, HIGH);
  digitalWrite(FX_R, HIGH);
  digitalWrite(BT_ST, HIGH);

  Keyboard.begin();
  Keyboard.releaseAll();
}

void loop()
{
  knob1 = enc1.read();
  knob2 = enc2.read();

  update_knobs();

  if (digitalRead(BT_A) == LOW)
  {
    Keyboard.press('s');
    digitalWrite(LBT_A, HIGH);
  }
  else
  {
    Keyboard.release('s');
    digitalWrite(LBT_A, LOW);
  }

  if (digitalRead(BT_B) == LOW)
  {
    Keyboard.press('d');
    digitalWrite(LBT_B, HIGH);
  }
  else
  {
    Keyboard.release('d');
    digitalWrite(LBT_B, LOW);
  }

  if (digitalRead(BT_C) == LOW)
  {
    Keyboard.press('l');
    digitalWrite(LBT_C, HIGH);
  }
  else
  {
    Keyboard.release('l');
    digitalWrite(LBT_C, LOW);
  }

  if (digitalRead(BT_D) == LOW)
  {
    Keyboard.press(';');
    digitalWrite(LBT_D, HIGH);
  }
  else
  {
    Keyboard.release(';');
    digitalWrite(LBT_D, LOW);
  }

  if (digitalRead(BT_E) == LOW)
  {
    Keyboard.press('a');
    digitalWrite(LBT_E, HIGH);
  }
  else
  {
    Keyboard.release('a');
    digitalWrite(LBT_E, LOW);
  }
  
  if (digitalRead(BT_F) == LOW)
  {
    Keyboard.press('k');
    digitalWrite(LBT_F, HIGH);
  }
  else
  {
    Keyboard.release('k');
    digitalWrite(LBT_F, LOW);
  }

  if (digitalRead(FX_L) == LOW)
  {
    Keyboard.press('c');
    digitalWrite(LFX_L, HIGH);
  }
  else
  {
    Keyboard.release('c');
    digitalWrite(LFX_L, LOW);
  }

  if (digitalRead(FX_R) == LOW)
  {
    Keyboard.press('m');
    digitalWrite(LFX_R, HIGH);
  }
  else
  {
    Keyboard.release('m');
    digitalWrite(LFX_R, LOW);
  }

  if (digitalRead(BT_ST) == LOW)
  {
    Keyboard.press(KEY_RETURN);
    digitalWrite(LBT_ST, HIGH);
  }
  else
  {
    Keyboard.release(KEY_RETURN);
    digitalWrite(LBT_ST, LOW);
  }
}

void update_knobs()
{
  if (knob1 != old_knob1)
  {
    if (knob1 < old_knob1)
    {
      Keyboard.press('w');
      Keyboard.release('q');
    }
    else
    {
      Keyboard.press('q');
      Keyboard.release('w');
    }

    if ((old_knob1 = knob1) != knob1)
    {
      enc1.write(old_knob1);
    }
  }
  else
  {
    Keyboard.release('q');
    Keyboard.release('w');
  }


  if (knob2 != old_knob2)
  {
    if (knob2 > old_knob2)
    {
      Keyboard.press('o');
      Keyboard.release('p');
    }
    else
    {
      Keyboard.press('p');
      Keyboard.release('o');
    }


    if ((old_knob2 = knob2) != knob2)
    {
      enc2.write(old_knob2);
    }
  }
  
  else
  {
    Keyboard.release('o');
    Keyboard.release('p');
  }
}
