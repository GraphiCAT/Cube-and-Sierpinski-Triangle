#ifndef Point3D_H
#define Point3D_H

#include <iostream>

class Point3D {
public:
	// Constructor
	Point3D(float _x, float _y, float _z) { x = _x; y = _y; z = _z;};
	Point3D() { Point3D(0,0,0); };

	// Getter
	float getX() const { return x; };
	float getY() const { return y; };
	float getZ() const { return z; };

	// Setter
	void setX(float _x) {x = _x; };
	void setY(float _y) {y = _y; };
	void setZ(float _z) {z = _z; };

	void printPoint() {
        std::cout << "x : " << x << ", y : " << y << ", z : " << z <<std::endl;
	}

	Point3D convertToOpenGLCoordinates(int x, int y, int z, int max_x, int max_y){
        float x_temp = (float)(max_x)/(float)2;
        float y_temp = (float)(max_y)/(float)2;
        Point3D result;

        result.setX((float)(x-x_temp)/(float)x_temp);
        result.setY((float)(y_temp-y)/(float)y_temp);
        result.setZ((float) z);

        return result;

    }

    Point3D convertToOpenGLCoordinates(Point3D p, int max_x, int max_y){
        float x_temp = (float)(max_x)/(float)2;
        float y_temp = (float)(max_y)/(float)2;
        Point3D result;

        result.setX((float)(p.x-x_temp)/(float)x_temp);
        result.setY((float)(y_temp-p.y)/(float)y_temp);
        result.setZ((float) p.z);

        return result;

    }

private:
	float x;
	float y;
	float z;
};


#endif

