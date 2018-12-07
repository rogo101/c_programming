//raghavv2 ishanj2 pujithb2

#include "shape.hpp"
#include <string>


//Base class
//Please implement Shape's member functions
//constructor, getName()

Shape::Shape(string name){
    //TODO
    name_ = name;
}
string Shape::getName(){
    //TODO
    return name_;
}


//Rectangle
//Please implement the member functions of Rectangle:
//getArea(), getVolume(), operator+, operator-
//copy(), clear()

void Rectangle::copy(const Rectangle& other){
    //TODO
    spec = new double[2];
    setWidth(other.getWidth());
    setLength(other.getLength());
}
void Rectangle::clear(){
    //TODO
    delete [] spec;
    spec = NULL;
}
Rectangle::Rectangle(double width, double length):Shape("Rectangle"){
  spec = new double[2];
  setWidth(width);
  setLength(length);
}
Rectangle::Rectangle(const Rectangle& other):Shape("Rectangle"){
    copy(other);
}
Rectangle::~Rectangle(){
    clear();
}
const Rectangle& Rectangle::operator = (const Rectangle& other){
    clear();
    copy(other);
    return *this;
}
double Rectangle::getArea()const{
    //TODO
    return getWidth() * getLength();
}
double Rectangle::getVolume()const{
    //TODO
    return 0;
}
Rectangle Rectangle::operator + (const Rectangle& rhs){
    //TODO
    Rectangle sum(0,0);
    sum.setWidth(getWidth() + rhs.getWidth());
    sum.setLength(getLength() + rhs.getLength());
    return sum;

}

Rectangle Rectangle::operator - (const Rectangle& rhs){
    //TODO
    Rectangle minus(0,0);
    if (getWidth() - rhs.getWidth() > 0) {
      minus.setWidth(getWidth() - rhs.getWidth());
    }
    if (getLength() - rhs.getLength() > 0) {
      minus.setLength(getLength() - rhs.getLength());
    }
    return minus;
}

// double * spec;
//spec[0] should be width
//spec[1] should be length
double Rectangle::getWidth()const{return spec? spec[0]:0;}
double Rectangle::getLength()const{return spec? spec[1]:0;}
void Rectangle::setWidth(double width){
    if (spec == NULL)
        return;

    spec[0] = width;
}
void Rectangle::setLength(double length){
    if (spec == NULL)
        return;

    spec[1] = length;
}


//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
void RectPrism::copy(const RectPrism& other){
    //TODO
    spec = new double[3];
    setWidth(other.getWidth());
    setLength(other.getLength());
    setHeight(other.getHeight());
}
void RectPrism::clear(){
    //TODO
    delete [] spec;
    spec = NULL;
}
RectPrism::RectPrism(double width, double length, double height):Shape("RectPrism"){
  spec = new double[3];
  setWidth(width);
  setLength(length);
  setHeight(height);
}
RectPrism::RectPrism(const RectPrism& other):Shape("RectPrism"){
    copy(other);
}
RectPrism::~RectPrism(){
    clear();
}
const RectPrism& RectPrism::operator = (const RectPrism& other){
    clear();
    copy(other);
    return *this;
}
double RectPrism::getVolume()const{
    //TODO
    return getWidth() * getLength() * getHeight();
}
double RectPrism::getArea()const{
    //TODO
    return 2 * (getLength() * getWidth() + getHeight() * getWidth() + getLength() * getHeight());
}
RectPrism RectPrism::operator + (const RectPrism& rhs){
    //TODO
    RectPrism sum(0,0,0);
    sum.setWidth(getWidth() + rhs.getWidth());
    sum.setLength(getLength() + rhs.getLength());
    sum.setHeight(getHeight() + rhs.getHeight());
    return sum;
}

RectPrism RectPrism::operator - (const RectPrism& rhs){
    //TODO
    RectPrism minus(0,0,0);
    if (getWidth() - rhs.getWidth() > 0) {
      minus.setWidth(getWidth() - rhs.getWidth());
    }
    if (getLength() - rhs.getLength() > 0) {
      minus.setLength(getLength() - rhs.getLength());
    }
    if (getHeight() - rhs.getHeight() > 0) {
      minus.setHeight(getHeight() - rhs.getHeight());
    }
    return minus;
}

// double * spec;
//spec[0] should be length
//spec[1] should be width
//spec[2] should be height
double RectPrism::getWidth()const{return spec? spec[1]:0;}
double RectPrism::getHeight()const{return spec? spec[2]:0;}
double RectPrism::getLength()const{return spec? spec[0]:0;}
void RectPrism::setWidth(double width){
    if (spec == NULL)
        return;

    spec[1] = width;
}
void RectPrism::setHeight(double height){
    if (spec == NULL)
        return;

    spec[2] = height;
}
void RectPrism::setLength(double length){
    if (spec == NULL)
        return;

    spec[0] = length;
}



// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
vector<Shape*> CreateShapes(char* file_name){
    //@@Insert your code here
    ifstream ifs (file_name, std::ifstream::in);
    double num_shapes = 0;
    ifs >> num_shapes;
    vector<Shape*> shape_ptrs(num_shapes, NULL);
    //TODO
    int i;
    for(i = 0; i < num_shapes; i++){
      Shape* shape;
      string name;
      double width, length, height = 0;
      ifs >> name;
      if(name == "Rectangle"){
        ifs >> width >> length;
        shape = new Rectangle(width, length);
      }
      if(name == "RectPrism"){
        ifs >> width >> length >> height;
        shape = new RectPrism(width, length, height);
      }
      shape_ptrs[i]=shape;
    }
    ifs.close();
    return shape_ptrs;
}

// call getArea() of each object
// return the max area
double MaxArea(vector<Shape*> shapes){
    double max_area = 0;
    //@@Insert your code here
    int i;
    for (i = 0; i < shapes.size(); i++) {
      if (shapes[i] -> getArea() > max_area) {
        max_area = shapes[i] -> getArea();
      }
    }
    return max_area;
}


// call getVolume() of each object
// return the max volume
double MaxVolume(vector<Shape*> shapes){
    double max_volume = 0;
    //@@Insert your code here
    int i;
    for (i = 0; i < shapes.size(); i++) {
      if (shapes[i] -> getVolume() > max_volume) {
        max_volume = shapes[i] -> getVolume();
      }
    }
    return max_volume;
}
