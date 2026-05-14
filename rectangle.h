/*! \file rectangle.h
    \brief Declaration of the class rectangle
    \author Paolo Gastaldo
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

/// @class rectangle
/// @brief to manage an object with the shape of a rectangle
class rectangle : public shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    rectangle();
    rectangle(float px, float py, float w, float h);
    rectangle(const rectangle &r);

    ~rectangle();
    /// @}

    /// @name OPERATORS
    /// @{
    rectangle& operator=(const rectangle &r);
    bool operator==(const rectangle &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const rectangle &r);
    void Reset();
    /// @}
	
	/// @name GETTERS
    /// @{
	float GetVSide();
	float GetHSide();
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump();
    /// @}
};

#endif