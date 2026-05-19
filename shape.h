/*! \file shape.h
    \brief Declaration of the base class shape
	\author Paolo Gastaldo
*/

#ifndef SHAPE_H
#define SHAPE_H

#define TEXTSIZE 1000


/// @class shape
/// @brief to manage a generic object with a shape
class shape
{
protected:

    /// position of the shape in the page/grid
    float x;
    float y;

    /// dimensions of the bounding box
    float height;
    float width;

    /// optional text inside the shape
    char* text;

public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    shape();
    shape(float px, float py, float w, float h);
    shape(const shape &r);

    virtual ~shape();
    /// @}


    /// @name OPERATORS
    /// @{
    shape& operator=(const shape &r);
    bool operator==(const shape &r);
    /// @}


    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const shape &r);
    void Reset();
    /// @}
	
	/// @name FORMATTING
    /// @{
	void Scale(float sf);
	/// @}

    /// @name GETTERS / SETTERS
    /// @{

    void SetPosition(float px, float py);
    void SetHeight(float h);
    void SetWidth(float w);
    void SetDim(float w, float h);

    void SetText(const char* string);

    void GetPosition(float &px, float &py);
    void GetDim(float &w, float &h);

    float GetX();
    float GetY();
    float GetHeight();
    float GetWidth();

    float GetBoundingBoxArea();

    void GetText(char* string);

	
    

	virtual float GetPerimeter()=0;
	virtual float GetArea()=0;

    /// @}


    /// @name DEBUG and SERIALIZATION
    /// @{
    void ErrorMessage(const char *string);
    void WarningMessage(const char *string);
    virtual void Dump();
    /// @}

};

#endif