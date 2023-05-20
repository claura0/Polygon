/// \file rhombus.cpp
///	\brief class Rhombus: implementation of the functions
///
///	Details.
///

#include <iostream>
#include "rhombus.h"
#include <cmath>

/// @brief default constructor
Rhombus::Rhombus() {

    Init();
    cout << "Rhombus - constructor - default" << endl;

}

/// @brief constructor 
/// @param dH width in pixels
/// @param dV length in pixels
Rhombus::Rhombus(float dH, float dV) {

    Init();
    cout << "Rhombus - constructor" << endl;

    if (dH <= 0)
        cout << "WARNING: Rhombus - constructor: width should be > 0" << endl;
    else
        diagonalH = dH;

    if (dV <= 0)
        cout << "WARNING: Rhombus - constructor: length should be > 0" << endl;
    else
        diagonalV = dV;

}

/// @brief destructor 
Rhombus::~Rhombus() {

    cout << "Rhombus - destructor" << endl;

}

/// @brief copy constructor
/// @param reference to the object that should be copied
Rhombus::Rhombus(const Rhombus &r){

    Init(r);
    cout << "Rhombus - copy constructor" << endl;

}

/// @brief default initializer
void Rhombus::Init() {
    Reset();
    diagonalH = 0.;
    diagonalV = 0.;
}

/// @brief copy initializer
void Rhombus::Init(const Rhombus &r) {
    Reset();
    diagonalH = r.diagonalH;
    diagonalV = r.diagonalV;
}

/// @brief object eraser
void Rhombus::Reset() {
    diagonalH = 0.;
    diagonalV = 0.;
}

/// @brief overload of operator =
/// @param reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
Rhombus& Rhombus::operator=(const Rhombus &r) {

    Init(r);
    cout << "Rhombus - operator =" << endl;
    return *this;
}

/// @brief overload of operator ==
/// @param reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
bool Rhombus::operator==(const Rhombus &r) const{

    cout << "Rhombus - operator ==" << endl;

    if (diagonalH == r.diagonalH && diagonalV == r.diagonalV) {
        return true;
    }
    return false;

}

/// @brief print operator
ostream & operator << (ostream &o, Rhombus &r)
{
    o << "Horizontal diagonal:" << r.diagonalH << endl;
    o << "Vertical diagonal:" << r.diagonalV << endl;
    return o;
}

/// @brief input operator
istream & operator >> (istream &i, Rhombus &r)
{
    cout << "Enter horizontal diagonal:" << endl;
    i >> r.diagonalH;
    cout << "Enter vertical diagonal:" << endl;
    i >> r.diagonalV;
    return i;
}

/// @brief calculate Rhombus side
float Rhombus::Side() {
    return hypotf(diagonalH/2 ,diagonalV/2);
}

/// @brief calculate Rhombus area
float Rhombus::Area() {
    return (diagonalH * diagonalV) / 2;
}

/// @brief calculate Rhombus perimeter
float Rhombus::Perimeter() {
    float oneSide = Side();
    return oneSide * 4;
}

/// @brief set horizontal diagonal of the object
/// @param dH horizontal diagonal in pixels
void Rhombus::SetDiagH(float dH) {

    if (dH < 0) {
        cout << "WARNING: Rhombus - SetDiagH: horizontal diagonal should be > 0" << endl;
        return;
    }

    diagonalH = dH;

}

/// @brief set vertical diagonal of the object
/// @param dV vertical diagonal in pixels
void Rhombus::SetDiagV(float dV) {

    if (dV < 0) {
        cout << "WARNING: Rhombus - SetDiagV: vertical diagonal should be > 0" << endl;
        return;
    }

    diagonalV = dV;

}

/// @brief set horizontal and vertical diagonal of the object
/// @param dH horizontal diagonal in pixels
/// @param dV vertical diagonal in pixels
void Rhombus::SetDim(float dH, float dV) {

    SetDiagH(dH);
    SetDiagV(dV);
}


/// @brief get horizontal diagonal of the object
float Rhombus::GetDiagH() {
    return diagonalH;
}

/// @brief get vertical diagonal of the object
float Rhombus::GetDiagV() {
    return diagonalV;
}

/// @brief get side of the object
float Rhombus::GetSide() {
    return Side();
}

/// @brief set width and length of the object
/// @param dH width in pixels
/// @param dV length in pixels
void Rhombus::GetDim(float &dH, float &dV) {
    dH = diagonalH;
    dV = diagonalV;
}

/// @brief draw the object
void Rhombus::Draw() {
    cout << "I'm drawing the rhombus..." << endl;
    cout << "Horizontal diagonal = " << GetDiagH() << endl;
    cout << "Vertical diagonal = " << GetDiagV() << endl;
    cout << "Side = " << GetSide() << endl;
    cout << "Area = " << GetArea() << endl;
    cout << "Perimeter = " << GetPerimeter() << endl;
    cout << endl;

}

/// @brief get area of the object
float Rhombus::GetArea() {
    return Area();
}

/// @brief get perimeter of the object
float Rhombus::GetPerimeter() {
    return Perimeter();
}

/// @brief debug
void Rhombus::Dump() {

    cout << "RHOMBUS" << endl;
    cout << "Horizontal diagonal = " << GetDiagH() << endl;
    cout << "Vertical diagonal = " << GetDiagV() << endl;
    cout << "Side = " << GetSide() << endl;
    cout << "Area = " << GetArea() << endl;
    cout << "Perimeter = " << GetPerimeter() << endl;
    cout << endl;
}

/// @brief write an error message
/// @param string message to be printed
void Rhombus::ErrorMessage(const char *string) {

    cout << endl << "ERROR -- Rhombus --";
    cout << string << endl;

}

/// @brief write a warning message
/// @param string message to be printed
void Rhombus::WarningMessage(const char *string) {

    cout << endl << "WARNING -- Rhombus --";
    cout << string << endl;

}