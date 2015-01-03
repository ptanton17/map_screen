
#include <MeggyJrSimple.h>

int mapscreen = 2; //this variable deals with the screens
int x_dot_cord = 2;
int y_dot_cord = 2;
int Map_1Enemy_x = 0;
int Map_1Enemy_y = 0;
int Map_2Enemy_x = 0;
int Map_2Enemy_y = 0;
int Map_3Enemy_x = 0;
int Map_3Enemy_y = 0;


void setup()
{
  MeggyJrSimpleSetup();
  Spawn();


}
void loop ()
{

DisplaySlate();

delay(10);




maps();
void Draw_Creatures();
Cursor_Position(); // finds cursor position adn draws it
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


void Cursor_Position() //sets cursor and changes maps
{
  CheckButtonsPress();
  if (Button_Left)
  {
    if(x_dot_cord == 0)//detects borders
    {
      mapscreen --;// changes map
      x_dot_cord = 7; //changes cursor on map
      if (ReadPx(4,6) == 0)// detects illegal maps
      {
        x_dot_cord = 0;//resets cursor on old map
        mapscreen ++;//resets map
      }
    }
    else 
    {
      x_dot_cord -- ;// actual movement of cursor in normal use
      if (ReadPx(x_dot_cord,y_dot_cord)==Blue) // detects water
      {
        x_dot_cord ++; //resets cursor
      }
    }
  }
  
  if (Button_Right)
  {
    if(x_dot_cord == 7)//detects borders
    {
      mapscreen ++;// changes map
      x_dot_cord = 0; //changes cursor on map
      if (ReadPx(4,6) == 0)// detects illegal maps
      {
        x_dot_cord = 7;//resets cursor on old map
        mapscreen --;//resets map
      }
    }
    else 
    {
      x_dot_cord ++ ;// actual movement of cursor in normal use
      if (ReadPx(x_dot_cord,y_dot_cord)==Blue) // detects water
      {
        x_dot_cord --; //resets cursor
      }
    }
  }
  
  if (Button_Up)
  {
    if(y_dot_cord == 7)//detects borders
    {
      mapscreen = mapscreen -4;// changes map
      y_dot_cord = 0; //changes cursor on map
      if (ReadPx(4,6) == 0)// detects illegal maps
      {
        y_dot_cord = 7;//resets cursor on old map
        mapscreen = mapscreen +4;//resets map
      }
    }
    else 
    {
      y_dot_cord ++ ;// actual movement of cursor in normal use
      if (ReadPx(x_dot_cord,y_dot_cord)==Blue) // detects water
      {
        y_dot_cord --; //resets cursor
      }
    }
  }
  
  
  if (Button_Down)
  {
    if(y_dot_cord == 0)//detects borders
    {
      mapscreen = mapscreen +4; // changes map
      y_dot_cord = 7; //changes cursor on map
       if (ReadPx(4,6) == 0) // detects illegal maps
       {
         y_dot_cord = 0;//resets cursor on old map
         mapscreen = mapscreen -4;//resets map
       }
    }
    else 
    {
      y_dot_cord -- ; // actual movement of cursor in normal use
      if (ReadPx(x_dot_cord,y_dot_cord)==Blue) // detects water
      {
        y_dot_cord ++; //resets cursor
      }
    }
  }
  DrawPx(x_dot_cord,y_dot_cord,6);
}
  
  
void Spawn()
{
  Map_1Enemy_x = random(8);
  Map_1Enemy_y = random(8);
  Map_2Enemy_x = random(8);
  Map_2Enemy_y = random(8);
  Map_3Enemy_x = random(8);
  Map_3Enemy_y = random(8);
}

void Draw_Creatures() //updates enemies
{
  if (abs(Map_1Enemy_x - x_dot_cord) < abs(Map_1Enemy_y - y_dot_cord)) //if the x distance is greater than the y distance 
  {
    if (Map_1Enemy_x - x_dot_cord >= 0)//if enemy is to the right of player
    {
      Map_1Enemy_x --; // move enemy to the left
    }
    else // if enemy is to the left of player
    {
      Map_1Enemy_x ++; // move enemy to the right
    }
  }
  if (abs(Map_1Enemy_x - x_dot_cord) > abs(Map_1Enemy_y - y_dot_cord)) //if the x distance is less than the y distance 
  {
    if (Map_1Enemy_y - y_dot_cord >= 0)//if enemy is above player
    {
      Map_1Enemy_y --; // move enemy to the down
    }
    else // if enemy is below player
    {
      Map_1Enemy_y ++; // move enemy up
    }
  }
  if (abs(Map_2Enemy_x - x_dot_cord) < abs(Map_2Enemy_y - y_dot_cord)) //if the x distance is greater than the y distance 
  {
    if (Map_2Enemy_x - x_dot_cord >= 0)//if enemy is to the right of player
    {
      Map_2Enemy_x --; // move enemy to the left
    }
    else // if enemy is to the left of player
    {
      Map_2Enemy_x ++; // move enemy to the right
    }
  }
  if (abs(Map_2Enemy_x - x_dot_cord) > abs(Map_2Enemy_y - y_dot_cord)) //if the x distance is greater than the y distance 
  {
    if (Map_2Enemy_y - y_dot_cord >= 0)//if enemy is above player
    {
      Map_2Enemy_y --; // move enemy down
    }
    else // if enemy is below player
    {
      Map_1Enemy_y ++; // move enemy up
    }
  }
  if (abs(Map_3Enemy_x - x_dot_cord) < abs(Map_3Enemy_y - y_dot_cord)) //if the x distance is greater than the y distance 
  {
    if (Map_3Enemy_x - x_dot_cord >= 0)//if enemy is to the right of player
    {
      Map_3Enemy_x --; // move enemy to the left
    }
    else // if enemy is to the left of player
    {
      Map_3Enemy_x ++; // move enemy to the right
    }
  }
  if (abs(Map_3Enemy_x - x_dot_cord) > abs(Map_3Enemy_y - y_dot_cord)) //if the x distance is greater than the y distance 
  {
    if (Map_3Enemy_y - x_dot_cord >= 0)//if enemy is above player
    {
      Map_3Enemy_y --; // move enemy down
    }
    else // if enemy is below player
    {
      Map_3Enemy_y ++; // move enemy up
    }
  }
  DrawPx(Map_1Enemy_x,Map_1Enemy_y,Red);//draws enemies
  DrawPx(Map_2Enemy_x,Map_2Enemy_y,Red);//draws enemies
  DrawPx(Map_3Enemy_x,Map_3Enemy_y,Red);//draws enemies
}

