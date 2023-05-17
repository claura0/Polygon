/*! \file rectangle.h
	\brief Declaration of the class Rectangle

	Details.
*/

#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "polygon.h"
using namespace std;

/// @class Rectangle
/// @brief to manage an object with the shape of a rectangle
class Rectangle : public Polygon {
protected:
	float length;
	float width;

    float Area();
    float Perimeter();

public:

    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    ///Default Constructor
	Rectangle();
    ///Constructor
	Rectangle(float w, float l);
    ///Destructor
	~Rectangle();
    ///Copy constructor
    Rectangle(const Rectangle &r);
    /// @}

    /// @name OPERATORS
    /// @{
    ///Assignment overloading
    Rectangle& operator=(const Rectangle &r);
    ///Comparison overloading
    bool operator==(const Rectangle &r) const;
    ///Print operator
    friend ostream & operator << ( ostream & o, Rectangle &r);
    ///Input operator
    friend istream & operator >> ( istream & i, Rectangle &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const Rectangle &r);
    void Reset();
    /// @}

    /// ACCESS FUNCTIONS
    /// @{
	void SetDim(float w, float l);
	void SetLength(float l);
	void SetWidth(float w);
    /// @}
	
	void GetDim(float &w, float &l);
	float GetLength();
	float GetWidth();

    /// @name DRAWING
    /// @{
    void Draw();
    /// @}

    /// @name GETTERS
    /// @{
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void ErrorMessage(const char *string);
    void WarningMessage(const char *string);
    void Dump();
    /// @}
};

#endif