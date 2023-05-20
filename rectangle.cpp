/// \file rectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include <iostream>
#include "rectangle.h"

/// @brief default constructor 
Rectangle::Rectangle() {

    Init();
	cout << "Rectangle - constructor - default" << endl;

}

/// @brief constructor 
/// @param w width in pixels
/// @param h length in pixels
Rectangle::Rectangle(float w, float l) {

    Init();
	cout << "Rectangle - constructor" << endl;

	if (w <= 0) 
		cout << "WARNING: Rectangle - constructor: width should be > 0" << endl;
	else
		width = w;

	if (l <= 0) 
		cout << "WARNING: Rectangle - constructor: length should be > 0" << endl;
	else
		length = l;

}

/// @brief destructor 
Rectangle::~Rectangle() {

    Reset();
	cout << "Rectangle - destructor" << endl;

}

/// @brief copy constructor
/// @param reference to the object that should be copied
Rectangle::Rectangle(const Rectangle &r){

    Init(r);
    cout << "Rectangle - copy constructor" << endl;

}

/// @brief default initializer
void Rectangle::Init() {
    Reset();
    width = 0.;
    length = 0.;
}

/// @brief copy initializer
/// @param r reference of the object that is copied
void Rectangle::Init(const Rectangle &r) {
    Reset();
    width = r.width;
    length = r.length;
}

/// @brief object eraser
void Rectangle::Reset() {
    width = 0.;
    length = 0.;
}

/// @brief overload of operator =
/// @param reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
Rectangle& Rectangle::operator=(const Rectangle &r) {

    Init(r);
    cout << "Rectangle - operator =" << endl;
    return *this;

}

/// @brief overload of operator ==
/// @param reference to the object on the right side of the operator
/// @return reference to the object on the left side of the operator
bool Rectangle::operator==(const Rectangle &r) const{

    cout << "Rectangle - operator ==" << endl;

    if (width == r.width && length == r.length)
        return true;

    return false;

}

/// @brief print operator
ostream & operator << (ostream &o, Rectangle &r)
{
    o << "Length:" << r.length << endl;
    o << "Width:" << r.width << endl;
    return o;
}

/// @brief input operator
istream & operator >> (istream &i, Rectangle &r)
{
    cout << "Enter length:" << endl;
    i >> r.length;
    cout << "Enter width:" << endl;
    i >> r.width;
    return i;
}

/// @brief calculate rectangle area
float Rectangle::Area() {
    return width * length;
}

/// @brief calculate rectangle perimeter
float Rectangle::Perimeter() {
    return 2 * (width + length);
}


/// @brief set width of the object
/// @param w width in pixels
void Rectangle::SetWidth(float w) {

	if (w < 0) {
		cout << "WARNING: Rectangle - SetWidth: width should be > 0" << endl;
		return;
	}

	width = w;

}

/// @brief set length of the object
/// @param l length in pixels
void Rectangle::SetLength(float l) {

	if (l < 0) {
		cout << "WARNING: Rectangle - SetLength: length should be > 0" << endl;
		return;
	}

	length = l;

}

/// @brief set width and length of the object
/// @param w width in pixels
/// @param l length in pixels
void Rectangle::SetDim(float w, float l) {

	SetWidth(w);
	SetLength(l);
}


/// @brief get width of the object
float Rectangle::GetWidth() {
    return width;
}

/// @brief get length of the object
float Rectangle::GetLength() {
    return length;
}

/// @brief set width and length of the object
/// @param w width in pixels
/// @param l length in pixels
void Rectangle::GetDim(float &w, float &l) {
    w = width;
    l = length;
}

/// @brief draw the object
void Rectangle::Draw() {
    cout << "I'm drawing the rectangle..." << endl;
    cout << "Width = " << GetWidth() << endl;
    cout << "Length = " << GetLength() << endl;
    cout << "Area = " << GetArea() << endl;
    cout << "Perimeter = " << GetPerimeter() << endl;
    cout << endl;

}

/// @brief get area of the object
float Rectangle::GetArea() {
    return Area();
}

/// @brief get perimeter of the object
float Rectangle::GetPerimeter() {
    return Perimeter();
}

/// @brief debug
void Rectangle::Dump() {

    cout << "RECTANGLE" << endl;
    cout << "Width = " << GetWidth() << endl;
    cout << "Length = " << GetLength() << endl;
    cout << "Area = " << GetArea() << endl;
    cout << "Perimeter = " << GetPerimeter() << endl;
    cout << endl;

}

/// @brief write an error message
/// @param string message to be printed
void Rectangle::ErrorMessage(const char *string) {

    cout << endl << "ERROR -- Rectangle --";
    cout << string << endl;

}

/// @brief write a warning message
/// @param string message to be printed
void Rectangle::WarningMessage(const char *string) {

    cout << endl << "WARNING -- Rectangle --";
    cout << string << endl;

}





