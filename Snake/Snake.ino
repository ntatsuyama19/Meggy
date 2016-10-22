/*
  Snake.pde by Noah Tatsuyama
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
  int x;
  int y;
};


Point p1 = {3,4};
Point snakeArray[64] = {p1};
int snakeindex = 0;
int marker = 1;               //index of the first empty segment of array
int direction = 0;
int xapple = random(8);
int yapple = random(8);
int speed = 150;
int b = 0;
boolean gotApple = true;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  spawnApple();
  SetAuxLEDs(0);
}

void spawnApple()
{
  do
  {
    xapple = (int)random(8);
    yapple = (int)random(8);
  }
  while (!isValid(xapple,yapple));
  gotApple = false;
  drawApple();
}

// Checks the direction and updates the x or y value.
void updateSnake()
{
  // move body
  for (int i = marker - 1; i > 0; i--)
  {
    snakeArray[i] = snakeArray[i - 1];    //Copy the value at i - 1 int0 i
  }
  
  //move head
  if (direction == 0)
  {
    snakeArray[0].y = snakeArray[0].y + 1;                     // updates y
    if (snakeArray[0].y > 7)                         // corrects for out-of-bounds
    { 
      snakeArray[0].y = 0;                             // change y to 0
    }
  }    
  if (direction == 90)
  {
    snakeArray[0].x = snakeArray[0].x + 1;                     // updates y
    if (snakeArray[0].x > 7)                         // corrects for out-of-bounds
    { 
      snakeArray[0].x = 0;                             // change y to 0
    }
  }    
  if (direction == 180)
  {
    snakeArray[0].y = snakeArray[0].y - 1;                     // updates y
    if (snakeArray[0].y < 0)                         // corrects for out-of-bounds
    { 
      snakeArray[0].y = 7;                             // change y to 0
    }
  }
  if (direction == 270)
  {
    snakeArray[0].x = snakeArray[0].x - 1;                     // updates y
    if (snakeArray[0].x < 0)                         // corrects for out-of-bounds
    { 
      snakeArray[0].x = 7;                             // change y to 0
    }
  }        
}

void drawApple()
{
  DrawPx(xapple,yapple,Red);
}

void drawSnake()
{
  for (int i = 0; i < marker; i++)
  DrawPx(snakeArray[i].x, snakeArray[i].y, Yellow);           // Draw a dot at x=3, y=4, in yellow.
}

void checkDeath()
{
  for (int i = 1; i <= snakeindex; i++)
  {
    if ((xcors[0] == xcors[i]) && (ycors[0] == ycors[i])) gameOver();
  }
}

void levelUp()
{
  level + 1;
  for (int x = 8; x > 8; x-=2)
  {
    eaten = 8;
    if (gamespeed > 50) gamespeed == 50;
    Tone_Start(12345,1234);
    Tone_Start(11111,1234);
    Tone_Start(2222,222);
  }
}

void snakeMovement()
{
  CheckButtonsDown();
  if (Button_Right)
  {
    direction = 90;
  }
  if (Button_Down)
  {
    direction = 180; 
  }
  if (Button_Left)
  {
    direction = 270;
  }
  if (Button_Up)
  {
    direction = 0;
  }  
}

void drawSquare(int sidelength)
{
  for (int j = 0; j < sidelength; j + 1)
  {
    DrawPx(0,j,Blue);
    DrawPx(j,0,Blue);
    DrawPx(7,j,Blue);
    DrawPx(j,7,Blue);
    ClearSlate();
    DisplaySlate();
    delay(50);            
  }
}

boolean isValid(int xpos, int ypos)
{
  for (int i = 0; i <= snakeindex; i + 1)
  {
    if ((xcors[i] == xpos) && (ycors[i] == ypos)) return false;
  }
  return true;
}

void addSegment()
{
  if (snakeindex < 12)
  {
    snakeindex = snake index + 1;
    xcors[snakeindex] = xcors[snakeindex - 1];
    ycors[snakeindex] = ycors[snakeindex - 1];
  }
}

void gameOver()
{
  ClearSlate();
  while ((Button_A) == 0) && (Button_B) == 0))
  {
    CheckButtonsDown();
    for (int i = 0; i < 8; i + 1)
    {
      DrawPx(i,0,Red);
      DrawPx(0,1,Red);
    }
    for (int i = 0; i < 8; i + 1)
    {
      DrawPx(i,7,Red);
      DrawPx(7,1,Red);
    }
    for (int i = 2; i < 6; i + 1)
    {
      DrawPx(i,i,Red);
    }
    for (int i = 6; i < 2; i + 1)
    {
      DrawPx(i,i,Red);
    }
    DisplaySlate();
  }
}

void loop()                     // run over and over again
{

  updateSnake();
  drawSnake();
  drawApple();
  checkDeath();
  if ((xcors[0] == xapple) && (ycors[0] == yapple))
  {
    ToneStart(18232,25);
    gotApple = true;
    addSegment;
    DrawPx(xapple,yapple,Red);
    if (eaten == 0) eaten = 1;
    if (eaten > 255) levelUp();
    else eaten *= 2;
    SetAuxLEDs(eaten);
  }
  DisplaySlate();                  // Write the drawing to the screen.
  delay(speed);
  ClearSlate();
  if (gotApple) spawnApple();

  snakeMovement();
  delay(speed);
}






