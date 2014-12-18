#include <MeggyJrSimple.h>
int mapscreen = 2; //this variable deals with the screens
void setup()
{
  MeggyJrSimpleSetup();
  


}
void loop ()
{
DisplaySlate();

delay(10);
CheckButtonsDown();
if (Button_Left)
{
  mapscreen --;
}
if (Button_Right)
{
  mapscreen ++;
}
if (Button_Down)
{
  mapscreen = mapscreen -4;
}
if (Button_Up)
{
  mapscreen = mapscreen +4;
}

maps();
}

void maps()
{
  if (mapscreen == 1)// check for current mapscreen
  {
     for (int x=0; x<8; x++) // simple draw commands
    {
      for(int y=0; y<8;y++) 
      {
        DrawPx(x,y,Green);
      }
    }
   
    for(int x=0; x<2;x++)
    {
      for (int y=5 ;y<8; y++)
      {
        DrawPx(x,y,Blue);
      }
    }
     
    for (int x=7; x> 3; x--)
    {       
        DrawPx(x,4,9); 
        DisplaySlate;     
    }
    
    for (int x=4; x>2; x--)
    {       
        DrawPx(x,3,9);      
    }        
    
    for (int y=3; y>=0; y--)
    {       
        DrawPx(2,y,9);   
    }
  }
if (mapscreen == 2)
  {
     for (int x=0; x<8; x++)
    {
      for(int y=0; y<8;y++) 
      {
        DrawPx(x,y,Green);
      }
    }
    
    
    DrawPx(2,3,Yellow);
    
    for(int x = 0;x<8;x++) 
    {
      DrawPx(x,4,9);
    }
    
    for(int x= 2;x<5; x++)
    {  
      DrawPx(x,4,Green);
    }
    
    for(int y=4; y<7;y++)
      {
        DrawPx(3,y,Blue);
      }
      
    for(int x = 2; x<5;x++)
      {
        DrawPx(x,5,Blue);
      }
      
    DrawPx(7,3,9);
    
    for(int y = 2; y<4; y++)
      {
        DrawPx(1,y,9);
      }
      
    for(int x = 2; x<5;x++)
      {
        for(int y = 1;y<3; y++)
        {
          DrawPx(x,y,9);
        }
      }
      
    DrawPx(3,0,9);
    
    DrawPx(6,0,Blue);
    
    for(int y = 0;y<2;y++)
    {  
      DrawPx(7,y,Blue);
    }
    
    for(int y = 2;y!=4; y++)
    {
      DrawPx(5,y,9);
    }
    
  }
  if (mapscreen == 3)
    {
    
    }
  
  if (mapscreen == 7)
    {
    
    }
  
  if (mapscreen == 5)
    {
    
    }
  
  if (mapscreen == 6)
    {
    
    }
  
}
