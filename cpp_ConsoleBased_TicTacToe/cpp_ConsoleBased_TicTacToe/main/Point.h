#pragma once
class Point
{
public:
	int x;
	int y;

	Point() = default;
	Point(int x, int y);

	bool operator ==(const Point& otherPt);
	bool operator != (const Point& otherPt);

	bool operator ==(const Point& otherPt) const;
	bool operator != (const Point& otherPt) const;

};

