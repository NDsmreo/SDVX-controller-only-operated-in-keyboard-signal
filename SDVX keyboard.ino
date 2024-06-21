#include <Keyboard.h>
#define BT_A 1
#define BT_B 2
#define BT_C 3
#define BT_D 4
#define BT_E 5
#define BT_F 6
#define FX_L 7
#define FX_R 8
#define BT_ST 9

#define LBT_A 10
#define LBT_B 11
#define LBT_C 12
#define LBT_D 13
#define LBT_E A0
#define LBT_F A1
#define LFX_L A2
#define LFX_R A3
#define LBT_ST A4

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
    Keyboard.press('d');
    digitalWrite(LBT_A, LOW);
  }
  else
  {
    Keyboard.release('d');
    digitalWrite(LBT_A, HIGH);
  }

  if (digitalRead(BT_B) == LOW)
  {
    Keyboard.press('f');
    digitalWrite(LBT_B, LOW);
  }
  else
  {
    Keyboard.release('f');
    digitalWrite(LBT_B, HIGH);
  }

  if (digitalRead(BT_C) == LOW)
  {
    Keyboard.press('j');
    digitalWrite(LBT_C, LOW);
  }
  else
  {
    Keyboard.release('j');
    digitalWrite(LBT_C, HIGH);
  }

  if (digitalRead(BT_D) == LOW)
  {
    Keyboard.press('k');
    digitalWrite(LBT_D, LOW);
  }
  else
  {
    Keyboard.release('k');
    digitalWrite(LBT_D, HIGH);
  }

  if (digitalRead(BT_E) == LOW)
  {
    Keyboard.press('s');
    digitalWrite(LBT_E, LOW);
  }
  else
  {
    Keyboard.release('s');
    digitalWrite(LBT_E, HIGH);
  }
  
  if (digitalRead(BT_F) == LOW)
  {
    Keyboard.press('l');
    digitalWrite(LBT_F, LOW);
  }
  else
  {
    Keyboard.release('l');
    digitalWrite(LBT_F, HIGH);
  }

  if (digitalRead(FX_L) == LOW)
  {
    Keyboard.press('c');
    digitalWrite(LFX_L, LOW);
  }
  else
  {
    Keyboard.release('c');
    digitalWrite(LFX_L, HIGH);
  }

  if (digitalRead(FX_R) == LOW)
  {
    Keyboard.press('m');
    digitalWrite(LFX_R, LOW);
  }
  else
  {
    Keyboard.release('m');
    digitalWrite(LFX_R, HIGH);
  }

  if (digitalRead(BT_ST) == LOW)
  {
    Keyboard.press(KEY_RETURN);
    digitalWrite(LBT_ST, LOW);
  }
  else
  {
    Keyboard.release(KEY_RETURN);
    digitalWrite(LBT_ST, HIGH);
  }
}

void update_knobs()
{
  if (knob1 != old_knob1)
  {
    if (knob1 < old_knob1)
    {
      Keyboard.write('q');
    }
    else
    {
      Keyboard.write('w');
    }

    if ((old_knob1 = knob1) != knob1)
    {
      enc1.write(old_knob1);
    }
  }
  if (knob2 != old_knob2)
  {
    if (knob2 > old_knob2)
    {
      Keyboard.write('o');
    }
    else
    {
      Keyboard.write('p');
    }

    if ((old_knob2 = knob2) != knob2)
    {
      enc2.write(old_knob2);
    }
  }
}
