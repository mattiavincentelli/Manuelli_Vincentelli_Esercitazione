/*! \file right_triangle.cpp
    \brief implementation of class Right Triangle
    \author Manuelli e Vincentelli
*/

#include "right_triangle.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
right_triangle::right_triangle() : shape(){
    cout << "Right Triangle - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
right_triangle::right_triangle(float px, float py, float w, float h) : shape(px, py, w, h){
    cout << "Right Triangle - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
right_triangle::right_triangle(const right_triangle &r) : shape(r){
    cout << "Right Triangle - copy constructor" << endl;
}

/// @brief destructor
right_triangle::~right_triangle(){
    cout << "Right Triangle - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
right_triangle& right_triangle::operator=(const right_triangle &r){
    if (this != &r) 
        shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool right_triangle::operator==(const right_triangle &r){
    return shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void right_triangle::Init(){
    shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void right_triangle::Init(const right_triangle &r){
    shape::Init(r);
}

/// @brief total reset of the object  
void right_triangle::Reset(){
    shape::Reset();
}

/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the height of the right_triangle
/// @return height
float right_triangle::GetHeight(){
	return height;
}


/// @brief to get the bigger cathetus of the right triangle
/// @return CatMax
float right_triangle::GetCatMax(){
    if (height == width){
        cout << "The triangle is both right and isosceles, default return orizontal cathetus ";
    }
    if (height > width){
        return height;
    }
    else return width;
}

/// @brief to get the smaller cathetus of the right triangle
/// @return CatMin
float right_triangle::GetCatMin(){
    if (height == width){
        cout << "The triangle is both right and isosceles, default return vertical cathetus ";
    }
    if (height > width){
        return width;
    }
    else return height;
}

/// @brief computes the area of the right triangle
/// @return area 
float right_triangle::GetArea(){
    return ((height*width)/2) ;
}

/// @brief to get the hypotenuse of the right triangle
/// @return hypotenuse
float right_triangle::GetHypotenuse(){
    return sqrt((height*height)+(width*width));
}


/// @brief computes the perimeter of the right triangle
/// @return perimeter 
float right_triangle::GetPerimeter(){
    return GetHypotenuse() + height + width;
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void right_triangle::Dump()
{
	cout << endl <<  "----------------------" << endl;
    cout << "Right Triangle Dump:" << endl << endl;
	
	cout << "  Position: (" << x << ", " << y << ")" << std::endl;
    cout << "  Figure major cathethus:  " << GetCatMax() << std::endl;
    cout << "  Figure minor cathetus: " << GetCatMin() << std::endl;
    cout << "  Figure hypotenuse:   " << GetHypotenuse() << endl;
    cout << "  Bounding Box Area:   " << shape::GetBoundingBoxArea() << std::endl;
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
	cout << endl;
}