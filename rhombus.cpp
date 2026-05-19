/*! \file rhombus.cpp
    \brief implementation of class rhombus
    \author Manuelli Vincentelli
*/

#include "rhombus.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
rhombus::rhombus() : shape()
{
    cout << "rhombus - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
rhombus::rhombus(float px, float py, float w, float h) : shape(px, py, w, h)
{
    cout << "rhombus - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
rhombus::rhombus(const rhombus &r) : shape(r)
{
    cout << "rhombus - copy constructor" << endl;
}

/// @brief destructor
rhombus::~rhombus()
{
    cout << "rhombus - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
rhombus& rhombus::operator=(const rhombus &r)
{
    if (this != &r) 
        shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool rhombus::operator==(const rhombus &r)
{
    return shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void rhombus::Init()
{
    shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void rhombus::Init(const rhombus &r)
{
    shape::Init(r);
}

/// @brief total reset of the object  
void rhombus::Reset()
{
    shape::Reset();
}


/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the side of the rhombus
/// @return side
float rhombus::GetSide()
{
	return sqrt(((height/2) * (height/2)) + ((width/2) * (width/2)));
    
}

/// @brief to get the height of the rhombus
/// @return height
float rhombus::GetVSide()
{
	return height;
    
}

/// @brief to get the width of the rhombus
/// @return width
float rhombus::GetHSide()
{
    return width;
}

/// @brief computes the area of the rhombus
/// @return area 
float rhombus::GetArea()
{
    return (width * height)/2;
}

/// @brief computes the perimeter of the rhombus
/// @return perimeter 
float rhombus::GetPerimeter()
{
    return 4 * GetSide();
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void rhombus::Dump()
{
	cout << endl <<  "----------------------" << endl;
    cout << "rhombus Dump:" << endl << endl;
	
	shape::Dump();
	
    cout << "  Figure Side:         " << GetSide() << endl;
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
	cout << endl;
}