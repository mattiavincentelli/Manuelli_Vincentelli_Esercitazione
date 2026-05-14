/*! \file right_triangle.h
    \brief declaration of the class Right Triangle
    \author Manuelli e Vincentelli
*/

#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "shape.h"

/// @class Right Triangle
/// @brief to manage an object with the shape of a right triangle 
class right_triangle : public shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    right_triangle();                                           //default
    right_triangle(float px, float py, float w, float h);       //with starting data
    right_triangle(const right_triangle &r);                    //copy

    ~right_triangle();
    /// @}

   
    /// @name OPERATORS
    /// @{
    right_triangle& operator=(const right_triangle &r);
    bool operator==(const right_triangle &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const right_triangle &r);
    void Reset();
    /// @}

    /// @name GETTERS
    /// @{
	float GetCatMax();
	float GetCatMin();
    float GetArea();
    float GetPerimeter();
    float GetHypotenuse();
    float GetHeight();
    /// @}

    
    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump();
    /// @}

};

#endif