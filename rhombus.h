/*! \file rhombus.h
    \brief Declaration of the class rhombus
    \author Manuelli Vincentelli
*/

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "shape.h"

/// @class rhombus
/// @brief to manage an object with the shape of a rhombus
class rhombus : public shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    rhombus();
    rhombus(float px, float py, float w, float h);
    rhombus(const rhombus &r);

    ~rhombus();
    /// @}

    /// @name OPERATORS
    /// @{
    rhombus& operator=(const rhombus &r);
    bool operator==(const rhombus &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const rhombus &r);
    void Reset();
    /// @}
	
	/// @name GETTERS
    /// @{
	float GetSide();
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