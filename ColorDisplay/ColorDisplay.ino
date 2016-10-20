#include <MeggyJrSimple.h>    // Required code, line 1 of 2

int color = 1;

void setup() 
{
 MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop() 
{
 for (int i = 0; i < 8; i++)
 {
  for (int j = 0; i < 8; j++)
  {
    if (0 < color < 8)
    {
      color = color + 1;
    }
    else color = 1;
    DrawScreenSaver();
    DisplaySlate();
    delay(600);
    ClearSlate();
  }
 }
}

void DrawScreenSaver()
{
  DrawPx(0,0,color);
  DrawPx(0,1,color);
  DrawPx(0,2,color);
  DrawPx(0,3,color);
  DrawPx(0,4,color);
  DrawPx(0,5,color);
  DrawPx(0,6,color);
  DrawPx(0,7,color);
  DrawPx(1,0,color);
  DrawPx(1,1,color);
  DrawPx(1,2,color);
  DrawPx(1,3,color);
  DrawPx(1,4,color);
  DrawPx(1,5,color);
  DrawPx(1,6,color);
  DrawPx(1,7,color);
  DrawPx(2,0,color);
  DrawPx(2,1,color);
  DrawPx(2,2,color);
  DrawPx(2,3,color);
  DrawPx(2,4,color);
  DrawPx(2,5,color);
  DrawPx(2,6,color);
  DrawPx(2,7,color);
  DrawPx(3,0,color);
  DrawPx(3,1,color);
  DrawPx(3,2,color);
  DrawPx(3,3,color);
  DrawPx(3,4,color);
  DrawPx(3,5,color);
  DrawPx(3,6,color);
  DrawPx(3,7,color);
  DrawPx(4,0,color);
  DrawPx(4,1,color);
  DrawPx(4,2,color);
  DrawPx(4,3,color);
  DrawPx(4,4,color);
  DrawPx(4,5,color);
  DrawPx(4,6,color);
  DrawPx(4,7,color);
  DrawPx(5,0,color);
  DrawPx(5,1,color);
  DrawPx(5,2,color);
  DrawPx(5,3,color);
  DrawPx(5,4,color);
  DrawPx(5,5,color);
  DrawPx(5,6,color);
  DrawPx(5,7,color);
  DrawPx(6,0,color);
  DrawPx(6,1,color);
  DrawPx(6,2,color);
  DrawPx(6,3,color);
  DrawPx(6,4,color);
  DrawPx(6,5,color);
  DrawPx(6,6,color);
  DrawPx(6,7,color);
  DrawPx(7,0,color);
  DrawPx(7,1,color);
  DrawPx(7,2,color);
  DrawPx(7,3,color);
  DrawPx(7,4,color);
  DrawPx(7,5,color);
  DrawPx(7,6,color);
  DrawPx(7,7,color);      
}

