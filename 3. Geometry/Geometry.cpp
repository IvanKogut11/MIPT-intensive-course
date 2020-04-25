#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

struct Vector
{
	double x, y;

	Vector operator+(const Vector& other) const
	{
		return { x + other.x, y + other.y };
	}

	Vector operator-(const Vector& other) const
	{
		return { x - other.x, y - other.y };
	}

	Vector operator-() const
	{
		return { -x, -y };
	}

	Vector operator*(double c) const
	{
		return { c * x, c * y };
	}

	Vector operator/(double c) const
	{
		return { x / c, y / c };
	}

	Vector operator*=(double c)
	{
		x *= c;
		y *= c;
		return *this;
	}
};

double crossProduct(Vector v1, Vector v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

double dotProduct(Vector v1, Vector v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

double getAngleBetweenVectors(Vector v1, Vector v2)
{
	return atan2(crossProduct(v1, v2), dotProduct(v1, v2));
}

//Предполагаем, что прямые точно пересекаются. То есть, [p2 - p1, p4 - p3] != 0
Vector getIntersectionPoint(Vector p1, Vector p2, Vector p3, Vector p4)
{
	double t = -crossProduct(p1 - p3, p4 - p3) / crossProduct(p2 - p1, p4 - p3);
	return p1 + (p2 - p1) * t;
}

int main()
{
	// Operators overloading
	Vector a = { 2, 3 };
	Vector b = { 3, 4 };
	Vector add = a + b;
	printf("%lf %lf\n", add.x, add.y);
	add = b + a;
	printf("%lf %lf\n", add.x, add.y);
	Vector sub = a - b;
	printf("%lf %lf\n", sub.x, sub.y);
	sub = -a;
	printf("%lf %lf\n", sub.x, sub.y);
	Vector mult = a * 3;
	printf("%lf %lf\n", mult.x, mult.y);
	mult *= 3;
	printf("%lf %lf\n", mult.x, mult.y);

	//Calculating angles

	Vector v1 = { 5, 7 };
	Vector v2 = { -5, 7 };
	Vector v3 = { -5, -7 };
	Vector v4 = { 5, -7 };
 	printf("%.5lf\n", atan2(v1.y, v1.x) * 180 / M_PI);
	printf("%.5lf\n", atan2(v2.y, v2.x) * 180 / M_PI);
	printf("%.5lf\n", atan2(v3.y, v3.x) * 180 / M_PI);
	printf("%.5lf\n", atan2(v4.y, v4.x) * 180 / M_PI);

	//Angle between vectors
	Vector e1 = { 5, 0 };
	Vector e2 = { -5, 5 };
	Vector e3 = { 5, -5 };
	printf("%.5lf\n", getAngleBetweenVectors(e1, e2) * 180 / M_PI);
	printf("%.5lf\n", getAngleBetweenVectors(e1, e3) * 180 / M_PI);

	//Get intersection of 2 lines
	Vector p1 = { -5, 0 }, p2 = { 5, 0 }, p3 = { 0, 5 }, p4 = { 0, -5 };
	if (crossProduct(p2 - p1, p4 - p3) != 0)
	{
		Vector intersection_point = getIntersectionPoint(p1, p2, p3, p4);
		printf("%lf %lf\n", intersection_point.x, intersection_point.y);
	}
	system("pause");
	return 0;
}