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
int marker = 1;               //index of the first empty segment of array
int direction = 0;
boolean gameOver = false;
int xapple = random(8);
int yapple = random(8);
int speed = 80;
int b = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  SetAuxLEDs(0);
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
  if (direction == 0)                         //moving up
  {
    snakeArray[0].y = snakeArray[0].y + 1;                     // updates y
    if (snakeArray[0].y > 7)                         // corrects for out-of-bounds
    { 
      snakeArray[0].y = 0;                             // change y to 0
    }
  }    
  if (direction == 90)                       //moving right
  {
    snakeArray[0].x = snakeArray[0].x + 1;                     // updates y
    if (snakeArray[0].x > 7)                         // corrects for out-of-bounds
    { 
      snakeArray[0].x = 0;                             // change y to 0
    }
  }    
  if (direction == 180)                         //moving down
  {
    snakeArray[0].y = snakeArray[0].y - 1;                     // updates y
    if (snakeArray[0].y < 0)                         // corrects for out-of-bounds
    { 
      snakeArray[0].y = 7;                             // change y to 0
    }
  }
  if (direction == 270)                        //moving left
  {
    snakeArray[0].x = snakeArray[0].x - 1;                     // updates y
    if (snakeArray[0].x < 0)                         // corrects for out-of-bounds
    { 
      snakeArray[0].x = 7;                             // change y to 0
    }
  }        
}

void drawApple()                                 //spawn apple
{
  DrawPx(xapple,yapple,Red);
}

void drawSnake()                                                    //draw snake 
{
  DrawPx(snakeArray[0].x, snakeArray[0].y, Violet);                  //draw head
  for (int i = 1; i < marker; i++)
  {
    DrawPx(snakeArray[i].x, snakeArray[i].y, Yellow);           //draw Body in yellow
  }
}

void checkDeath()                                              //checking of hit itself
{
  for (int i = 1; i < marker; i++)
  if ((snakeArray[0].x == snakeArray[i].x) && (snakeArray[0].y == snakeArray[i].y))
  {
    ClearSlate();
    gameOver = true;
  }  
}


void snakeMovement()                             //moving the snake around and corresponding buttons to direction
{
  CheckButtonsPress();
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

void snakeSpeed()                                      //watching snake speed
{
  CheckButtonsDown();
  if (Button_A)
  {
    speed = speed - 10;
  }
  if (Button_B)
  {
    speed = speed + 10;
  }
}

void checkEaten()                                                      //looking if apples eaten
{
  if (snakeArray[0].x == xapple && snakeArray[0].y == yapple)
  {
    xapple = random(8);
    yapple = random(8);
    b = b * 2 + 1;
    if (b > 255)
    {
      b = 0;
      Tone_Start(11825,25);
      marker = marker + 1;
    }
  }  
}

void death()                                    //check death
{
  ClearSlate();
  delay(500);
  struct Point
  {
    int x;
    int y;
  };

  Point p1 = {3,4};
  Point snakeArray[64] = {p1};
  int marker = 1;               //index of the first empty segment of array
  int direction = 0;
  boolean gameOver = false;
  int xapple = random(8);
  int yapple = random(8);
  int speed = 80;
  int b = 0;
  ClearSlate();
}

void loop()                     // run over and over again
{
  if (gameOver == false)
  {
    updateSnake();
    drawApple();
    checkEaten();
    checkDeath();
    drawSnake();
    SetAuxLEDs(b);
  
    DisplaySlate();                  // Write the drawing to the screen.
    delay(speed);
    ClearSlate();

    snakeMovement();
    delay(speed);
  }
  else death();
}







