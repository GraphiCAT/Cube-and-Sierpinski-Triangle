
#ifndef Point_H
#define Point_H

#include <iostream>

class Point {
public:
	// Constructor
	Point(float _x, float _y) { x = _x; y = _y;};
	Point() { Point(0,0); };

	// Getter
	float getX() const { return x; };
	float getY() const { return y; };

	// Setter
	void setX(float _x) {x = _x; };
	void setY(float _y) {y = _y; };

	void printPoint() {
        std::cout << "x : " << x << ", y : " << y << std::endl;
	}

	Point convertToOpenGLCoordinates(Point p, int max_x, int max_y){
        float x_temp = (float)(max_x)/(float)2;
        float y_temp = (float)(max_y)/(float)2;
        Point result;

        result.setX((float)(p.x-x_temp)/(float)x_temp);
        result.setY((float)(y_temp-p.y)/(float)y_temp);

        return result;

    }

private:
	float x;
	float y;
};


#endif
