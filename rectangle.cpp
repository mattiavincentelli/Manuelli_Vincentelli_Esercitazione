/*! \file rectangle.cpp
    \brief implementation of class rectangle
    \author Paolo Gastaldo
*/

#include "rectangle.h"
#include <iostream>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
rectangle::rectangle() : shape()
{
    cout << "rectangle - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
rectangle::rectangle(float px, float py, float w, float h) : shape(px, py, w, h)
{
    cout << "rectangle - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
rectangle::rectangle(const rectangle &r) : shape(r)
{
    cout << "rectangle - copy constructor" << endl;
}

/// @brief destructor
rectangle::~rectangle()
{
    cout << "rectangle - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
rectangle& rectangle::operator=(const rectangle &r)
{
    if (this != &r) 
        shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool rectangle::operator==(const rectangle &r)
{
    return shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void rectangle::Init()
{
    shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void rectangle::Init(const rectangle &r)
{
    shape::Init(r);
}

/// @brief total reset of the object  
void rectangle::Reset()
{
    shape::Reset();
}


/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the height of the rectangle
/// @return height
float rectangle::GetVSide()
{
	return height;
    
}

/// @brief to get the width of the rectangle
/// @return width
float rectangle::GetHSide()
{
    return width;
}

/// @brief computes the area of the rectangle
/// @return area 
float rectangle::GetArea()
{
    return width * height;
}

/// @brief computes the perimeter of the rectangle
/// @return perimeter 
float rectangle::GetPerimeter()
{
    return 2.0 * (width + height);
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void rectangle::Dump()
{
	cout << endl <<  "----------------------" << endl;
    cout << "rectangle Dump:" << endl << endl;
	
	shape::Dump();
	
    
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
	cout << endl;
}