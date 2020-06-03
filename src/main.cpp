/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Pratham                                                   */
/*    Created:      Wed Jun 03 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

brain Brain;
controller Controller1;

int main() 
{
  int A1 = Controller1.Axis1.position(vex::percent);
  int A2 = Controller1.Axis2.position(vex::percent);
  int A3 = Controller1.Axis3.position(vex::percent);
  int A4 = Controller1.Axis4.position(vex::percent);
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("Axis 1, 2: ");
  Controller1.Screen.print(A1);
  Controller1.Screen.print(", ");
  Controller1.Screen.print(A2);
  Controller1.Screen.setCursor(2,1);
  Controller1.Screen.print("Axis 3: ");
  Controller1.Screen.print(A3);
  Controller1.Screen.setCursor(3,1);
  Controller1.Screen.print("Axis 4: ");
  Controller1.Screen.print(A4);
  
  while(1)
  {
    if(A1 != Controller1.Axis1.position(vex::percent) || A2 != Controller1.Axis1.position(vex::percent))
    {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("Axis 1, 2: ");
      Controller1.Screen.print(Controller1.Axis1.position(vex::percent));
      Controller1.Screen.print(", ");
      Controller1.Screen.print(Controller1.Axis2.position(vex::percent));
      A1 = Controller1.Axis1.position(vex::percent);
    }
    else if(Controller1.Axis1.position(vex::percent) == 0 && Controller1.Axis2.position(vex::percent) == 0)
    {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("Axis 1, 2: 0, 0");
    }
    else if(Controller1.Axis1.position(vex::percent) == 0)
    {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("Axis 1, 2: 0, ");
      Controller1.Screen.print(Controller1.Axis2.position(vex::percent));
    }
    else if(Controller1.Axis2.position(vex::percent) == 0)
    {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print("Axis 1, 2: ");
      Controller1.Screen.print(Controller1.Axis1.position(vex::percent));
      Controller1.Screen.print(", 0");
    }
    if(A3 != Controller1.Axis3.position(vex::percent))
    {
      Controller1.Screen.clearLine(2);
      Controller1.Screen.setCursor(2,1);
      Controller1.Screen.print("Axis 3: ");
      Controller1.Screen.print(Controller1.Axis3.position(vex::percent));
      A3 = Controller1.Axis3.position(vex::percent);
    }
    else if(Controller1.Axis3.position(vex::percent) == 0)
    {
      Controller1.Screen.clearLine(2);
      Controller1.Screen.setCursor(2,1);
      Controller1.Screen.print("Axis 3: 0");
    }
    if(A4 != Controller1.Axis4.position(vex::percent))
    {
      Controller1.Screen.clearLine(3);
      Controller1.Screen.setCursor(3,1);
      Controller1.Screen.print("Axis 4: ");
      Controller1.Screen.print(Controller1.Axis4.position(vex::percent));
      A4 = Controller1.Axis4.position(vex::percent);
    }
    else if(Controller1.Axis4.position(vex::percent) == 0)
    {
      Controller1.Screen.clearLine(3);
      Controller1.Screen.setCursor(3,1);
      Controller1.Screen.print("Axis 4: 0");
    }
    vex::task::sleep(1);
  }
}
