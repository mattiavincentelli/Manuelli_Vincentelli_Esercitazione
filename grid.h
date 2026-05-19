/*! \file grid.h
    \brief Declaration of the base class grid
	\author Manuelli Vincentelli
*/

#ifndef GRID_H
#define GRID_H

/// @class grid
/// @brief to manage a generic object with a grid
class grid{
    
    protected: 
        /// width and height of the grid
        float height;
        float width; 
    public: 
        ///@name CONSTRUCTORS/DESTRUCTORS
        ///{
        grid() = default;
        grid(float w, float h);
        grid(const grid &r);

        virtual ~grid() = default;
        ///@}

        float GetHeight();
        float GetWidth();
};

#endif