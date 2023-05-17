/*! \file rhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/

#pragma once
#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
#include "polygon.h"
using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
class Rhombus : public Polygon {
protected:
    float diagonalH;
    float diagonalV;

    float Area();
    float Perimeter();
    float Side();

public:

    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    ///Default Constructor
    Rhombus();
    ///Constructor
    Rhombus(float dH, float dV);
    ///Destructor
    ~Rhombus();
    ///Copy constructor
    Rhombus(const Rhombus &r);
    /// @}

    /// @name OPERATORS
    /// @{
    ///Assignment overloading
    Rhombus& operator=(const Rhombus &r);
    ///Comparison overloading
    bool operator==(const Rhombus &r) const;
    ///Print operator
    friend ostream & operator << ( ostream & o, Rhombus &r);
    ///Input operator
    friend istream & operator >> ( istream & i, Rhombus &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const Rhombus &r);
    void Reset();
    /// @}

    /// ACCESS FUNCTIONS
    /// @{
    void SetDim(float dH, float dV);
    void SetDiagH(float dH);
    void SetDiagV(float dV);
    /// @}

    void GetDim(float &dH, float &dV);
    float GetDiagH();
    float GetDiagV();
    float GetSide();

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