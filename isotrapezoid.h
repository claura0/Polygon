/*! \file isotrapezoid.h
	\brief Declaration of the class IsoTrapezoid

	Details.
*/


#ifndef ISOTRAPEZOID_H
#define ISOTRAPEZOID_H

#include <iostream>
using namespace std;

/// @class IsoTrapezoid
/// @brief to manage an object with the shape of an isotrapezoid
class IsoTrapezoid {
private:
	float topside;
	float bottomside;
    float height;

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
    IsoTrapezoid(const IsoTrapezoid &i);
    /// @}

    /// @name OPERATORS
    /// @{
    ///Assignment overloading
    IsoTrapezoid& operator=(const IsoTrapezoid &i);
    ///Comparison overloading
    bool operator==(const IsoTrapezoid &i) const;
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const IsoTrapezoid &i);
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