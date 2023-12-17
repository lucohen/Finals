#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

class Shape {
public:
  Shape(double dHeight, double dWidth);
  virtual ~Shape();
  virtual void scale(double dScaleFactor) = 0;
  virtual double area() = 0;
  virtual double perimeter() = 0;
  virtual void displayProperties() {
    std::cout << "Shape Type: " << m_strType << std::endl;
  }

protected:
  double m_dHeight;
  double m_dWidth;
  std::string m_strType;
};

class Rectangle : public Shape {
public:
  Rectangle(double dHeight, double dWidth);
  virtual ~Rectangle();
  void scale(double dScaleFactor) override;
  double area() override;
  double perimeter() override;
};

class Circle : public Shape {
public:
  Circle(double dHeight, double dWidth);
  virtual ~Circle();
  void scale(double dScaleFactor) override;
  double area() override;
  double perimeter() override;
};

Shape::Shape(double dHeight, double dWidth) : m_dHeight(dHeight), m_dWidth(dWidth) {
}

Shape::~Shape() {
}

Rectangle::Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
  m_strType = "Rectangle";
}

Rectangle::~Rectangle() {}

void Rectangle::scale(double dScaleFactor) {
  m_dHeight *= dScaleFactor;
  m_dWidth *= dScaleFactor;
}

double Rectangle::area() {
  return m_dHeight * m_dWidth;
}

double Rectangle::perimeter() {
  return 2 * (m_dHeight + m_dWidth);
}

Circle::Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
  m_strType = "Circle";
}

Circle::~Circle() {}

void Circle::scale(double dScaleFactor) {
  m_dWidth *= dScaleFactor;
}

double Circle::area() {
  return M_PI * std::pow(m_dWidth, 2)/4;
}

double Circle::perimeter() {
  return M_PI * m_dWidth;
}

int main() {
  Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
  Circle* p_shapeCircle = new Circle(2.0, 2.0);

  Shape* p_shapes[2];

  p_shapes[0] = p_shapeCircle;
  p_shapes[1] = p_shapeRectangle;

  for (int i = 0; i < 2; i++) {
    p_shapes[i]->displayProperties();
    std::cout << "Area: " << p_shapes[i]->area() << std::endl;
    std::cout << "Perimeter: " << p_shapes[i]->perimeter() << std::endl;
    p_shapes[i]->scale(2.0);
    std::cout << "Area: " << p_shapes[i]->area() << std::endl;
    std::cout << "Perimeter: " << p_shapes[i]->perimeter() << std::endl;
  }
  delete p_shapeCircle;
  delete p_shapeRectangle;
  return 0;
}