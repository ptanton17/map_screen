#include <MeggyJrSimple.h>
int mapscreen = 2; //this variable deals with the screens
int x_dot_cord = 2;
int y_dot_cord = 2;

void setup()
{
  MeggyJrSimpleSetup();
  


}
void loop ()
{

DisplaySlate();

delay(10);



Cursor_Position(); // finds cursor position
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
    for (int x=0; x<8; x++) // simple draw commands
    {
      for(int y=0; y<8;y++) 
      {
        DrawPx(x,y,Green);
      }
    }
    for (int y = 7;y>6;y--)
      DrawPx(3,y,9);
    }
    
  
  if (mapscreen == 6)
    {
    
    }

 
  
}


void Cursor_Position()
{
  CheckButtonsPress();
  if (Button_Left)
  {
    if(x_dot_cord == 0)
    {
      mapscreen --;
      x_dot_cord = 7;
    }
    else 
    {
      x_dot_cord -- ;
    }
  }
  
  if (Button_Right)
  {
    if(x_dot_cord == 7)
    {
      mapscreen ++;
      x_dot_cord = 0;
    }
    else 
    {
      x_dot_cord ++ ;
    }
  }
  
  if (Button_Up)
  {
    if(y_dot_cord == 7)
    {
      mapscreen = mapscreen -4;
      y_dot_cord = 0;
    }
    else 
    {
      y_dot_cord ++ ;
    }
  }
  
  
  if (Button_Down)
  {
    if(x_dot_cord == 0)
    {
      mapscreen = mapscreen +4;
      x_dot_cord = 7;
    }
    else 
    {
      x_dot_cord -- ;
    }
  }
}
  
  
