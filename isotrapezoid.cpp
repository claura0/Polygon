/// \file isotrapezoid.cpp
///	\brief class IsoTrapezoid: implementation of the functions
///
///	Details.
///

#include <iostream>
#include "isotrapezoid.h"
#include <cmath>

/// @brief default constructor 
IsoTrapezoid::IsoTrapezoid() {

    Init();
	cout << "IsoTrapezoid - constructor - default" << endl;

}

/// @brief constructor 
/// @param tS top side in pixels
/// @param bS bottom side in pixels
/// @param h height in pixels
IsoTrapezoid::IsoTrapezoid(float tS, float bS, float h) {

    Init();
	cout << "IsoTrapezoid - constructor" << endl;

	if (tS <= 0 || tS == bS)
		cout << "WARNING: IsoTrapezoid - constructor: top side should be > 0 and different from bottom side" << endl;
	else
		topside = tS;

	if (bS <= 0 || bS == tS)
		cout << "WARNING: IsoTrapezoid - constructor: bottom side should be > 0 and different from top side" << endl;
	else
		bottomside = bS;

    if (h <= 0)
        cout << "WARNING: IsoTrapezoid - constructor: height should be > 0" << endl;
    else
        height = h;

}

/// @brief destructor 
IsoTrapezoid::~IsoTrapezoid() {

    Reset();
	cout << "IsoTrapezoid - destructor" << endl;

}

/// @brief copy constructor
/// @param reference to the object that should be copied
IsoTrapezoid::IsoTrapezoid(const IsoTrapezoid &t){

    Init(t);
    cout << "IsoTrapezoid - copy constructor" << endl;

}

/// @brief default initializer
void IsoTrapezoid::Init() {
    Reset();
    topside = 0.;
    bottomside = 0.;
    height = 0.;
}

/// @brief copy initializer
/// @param t reference of the object that is copied
void IsoTrapezoid::Init(const IsoTrapezoid &t) {
    Reset();
    topside = t.topside;
    bottomside = t.bottomside;
    height = t.height;
}

/// @brief object eraser
void IsoTrapezoid::Reset() {
    topside = 0.;
    bottomside = 0.;
    height = 0.;
}

/// @brief overload of operator =
/// @param reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
IsoTrapezoid& IsoTrapezoid::operator=(const IsoTrapezoid &t) {

    Init(t);
    cout << "IsoTrapezoid - operator =" << endl;
    return *this;
}

/// @brief overload of operator ==
/// @param reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
bool IsoTrapezoid::operator==(const IsoTrapezoid &t) const{

    cout << "IsoTrapezoid - operator ==" << endl;

    if (topside == t.topside && bottomside == t.bottomside && height == t.height)
        return true;

    return false;
}

/// @brief print operator
ostream & operator << (ostream &o, IsoTrapezoid &t)
{
    o << "Top side:" << t.topside << endl;
    o << "Bottom side:" << t.bottomside << endl;
    o << "Height:" << t.height << endl;
    return o;
}

/// @brief input operator
istream & operator >> (istream &i, IsoTrapezoid &t)
{
    cout << "Enter top side:" << endl;
    i >> t.topside;
    cout << "Enter bottom side:" << endl;
    i >> t.bottomside;
    cout << "Enter height:" << endl;
    i >> t.height;
    return i;
}

/// @brief calculate isosceles trapezoid side
float IsoTrapezoid::Side() {
    return hypotf(height ,(bottomside - topside)/2);
}

/// @brief calculate isosceles trapezoid area
float IsoTrapezoid::Area() {
    return ((topside + bottomside) * height)/2;
}

/// @brief calculate isosceles trapezoid perimeter
float IsoTrapezoid::Perimeter() {
    float side = Side();
    return topside + bottomside + side * 2;
}

/// @brief set top side of the object
/// @param tS top side in pixels
void IsoTrapezoid::SetTopSide(float tS) {

	if (tS < 0) {
		cout << "WARNING: IsoTrapezoid - SetTopSide: top side should be > 0" << endl;
		return;
	}

	topside = tS;

}

/// @brief set bottom side of the object
/// @param bS bottom side in pixels
void IsoTrapezoid::SetBottomSide(float bS) {

    if (bS < 0) {
        cout << "WARNING: IsoTrapezoid - SetBottomSide: bottom side should be > 0" << endl;
        return;
    }

    bottomside = bS;

}

/// @brief set height of the object
/// @param h height in pixels
void IsoTrapezoid::SetHeight(float h) {

	if (h < 0) {
		cout << "WARNING: IsoTrapezoid - SetHeight: height should be > 0" << endl;
		return;
	}

	height = h;

}

/// @brief set top side, bottom side and height of the object
/// @param tS top side in pixels
/// @param bS bottom side in pixels
/// @param h height in pixels
void IsoTrapezoid::SetDim(float tS, float bS, float h) {

	SetTopSide(tS);
    SetBottomSide(bS);
	SetHeight(h);
}


/// @brief get top side of the object
float IsoTrapezoid::GetTopSide() {
    return topside;
}

/// @brief get bottom side of the object
float IsoTrapezoid::GetBottomSide() {
    return bottomside;
}

/// @brief get height of the object
float IsoTrapezoid::GetHeight() {
    return height;
}

/// @brief get side of the object
float IsoTrapezoid::GetSide() {
    return Side();
}

/// @brief set top side, bottom side and height of the object
/// @param tS top side in pixels
/// @param bS bottom side in pixels
/// @param h height in pixels
void IsoTrapezoid::GetDim(float &tS, float &bS, float &h) {
    tS = topside;
    bS = bottomside;
    h = height;
}

/// @brief draw the object
void IsoTrapezoid::Draw() {
    cout << "I'm drawing the isosceles trapezoid..." << endl;
    cout << "Top Side = " << GetTopSide() << endl;
    cout << "Bottom Side = " << GetBottomSide() << endl;
    cout << "Height = " << GetHeight() << endl;
    cout << "Side = " << GetSide() << endl;
    cout << "Area = " << GetPerimeter() << endl;
    cout << "Perimeter = " << GetArea() << endl;
    cout << endl;
}

/// @brief get area of the object
float IsoTrapezoid::GetArea() {
    return Area();
}

/// @brief get perimeter of the object
float IsoTrapezoid::GetPerimeter() {;
    return Perimeter();
}

/// @brief debug
void IsoTrapezoid::Dump() {

    cout << "ISOSCELES TRAPEZOID" << endl;
    cout << "Top Side = " << GetTopSide() << endl;
    cout << "Bottom Side = " << GetBottomSide() << endl;
    cout << "Height = " << GetHeight() << endl;
    cout << "Side = " << GetSide() << endl;
    cout << "Area = " << GetPerimeter() << endl;
    cout << "Perimeter = " << GetArea() << endl;
    cout << endl;

}

/// @brief write an error message
/// @param string message to be printed
void IsoTrapezoid::ErrorMessage(const char *string) {

    cout << endl << "ERROR -- IsoTrapezoid --";
    cout << string << endl;

}

/// @brief write a warning message
/// @param string message to be printed
void IsoTrapezoid::WarningMessage(const char *string) {

    cout << endl << "WARNING -- IsoTrapezoid --";
    cout << string << endl;

}




