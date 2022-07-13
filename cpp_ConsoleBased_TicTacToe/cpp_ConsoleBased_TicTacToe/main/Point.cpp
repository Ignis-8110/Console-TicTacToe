#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator ==(const Point& otherPt) {
	return this->x == otherPt.x && this->y == otherPt.y;
}

bool Point::operator!=(const Point& otherPt) {
	return !(*this == otherPt);
}

bool Point::operator==(const Point& otherPt) const {
	return this->x == otherPt.x && this->y == otherPt.y;
}

bool Point::operator!=(const Point& otherPt) const {
	return !(*this == otherPt);
}
