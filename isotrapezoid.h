/*! \file isotrapezoid.h
	\brief Declaration of the class IsoTrapezoid
*/

#pragma once
#ifndef ISOTRAPEZOID_H
#define ISOTRAPEZOID_H

#include <iostream>
#include "polygon.h"
using namespace std;

/// @class IsoTrapezoid
/// @brief to manage an object with the shape of an isotrapezoid
class IsoTrapezoid : public Polygon {
protected:
	float topside;
	float bottomside;
    float height;

    float Area();
    float Perimeter();
    float Side();

public:

    /// @name CONSTRUCTORS/DESTRUCTOR
    /// @{
    ///Default Constructor
	IsoTrapezoid();
    ///Constructor
	IsoTrapezoid(float tS, float bS, float h);
    ///Destructor
	~IsoTrapezoid();
    ///Copy constructor
    IsoTrapezoid(const IsoTrapezoid &t);
    /// @}

    /// @name OPERATORS
    /// @{
    ///Assignment overloading
    IsoTrapezoid& operator=(const IsoTrapezoid &t);
    ///Comparison overloading
    bool operator==(const IsoTrapezoid &t) const;
    ///Print operator
    friend ostream & operator << ( ostream & o, IsoTrapezoid &t);
    ///Input operator
    friend istream & operator >> ( istream & i, IsoTrapezoid &t);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const IsoTrapezoid &t);
    void Reset();
    /// @}

    /// @name ACCESS FUNCTIONS
	void SetDim(float tS, float bS, float h);
	void SetTopSide(float tS);
	void SetBottomSide(float bS);
    void SetHeight(float h);

	void GetDim(float &tS, float &bS, float &h);
	float GetTopSide();
	float GetBottomSide();
    float GetHeight();
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