#ifndef _BOX_H_
#define _BOX_H_

#include <assert.h>
#include "vector3.h"
#include "ray.h"
#include "Util.h"

/*
 * Axis-aligned bounding box class, for use with the optimized ray-box
 * intersection test described in:
 *
 *      Amy Williams, Steve Barrus, R. Keith Morley, and Peter Shirley
 *      "An Efficient and Robust Ray-Box Intersection Algorithm"
 *      Journal of graphics tools, 10(1):49-54, 2005
 *
 */

class Box {
  public:
    Box() { }
    Box(const Vector3 &min, const Vector3 &max) {
 //     assert(min < max);
      parameters[0] = min;
      parameters[1] = max;
    }
    
    // (t0, t1) is the interval for valid hits
    bool intersect(const Ray &, float t0, float t1) const;
    
    

    // corners
    Vector3 parameters[2];
	Vector3 min() { return parameters[0]; }
	Vector3 max() { return parameters[1]; }
    
    //Determine if a 3D point is inside a box
	const bool inside(const Vector3 &p) {
		return ((p.x() >= parameters[0].x() && p.x() <= parameters[1].x()) &&
		     	(p.y() >= parameters[0].y() && p.y() <= parameters[1].y()) &&
			    (p.z() >= parameters[0].z() && p.z() <= parameters[1].z()));
	}
    
    //Determine if a 3D point is inside a box
	const bool inside(Vector3 *points, int size) {
		bool allInside = true;
		for (int i = 0; i < size; i++) {
			if (!inside(points[i])) allInside = false;
			break;
		}
		return allInside;
	}
    
    bool pointInside(ofVec3f v) {
        float maxX = max().x(); // std::max(max().x(), min().x());
        float maxY = max().y(); // std::max(max().y(), min().y());
        float maxZ = max().z(); // std::max(max().z(), min().z());
        float minX = min().x(); // std::min(max().x(), min().x());
        float minY = min().y(); // std::min(max().y(), min().y());
        float minZ = min().z(); // std::min(max().z(), min().z());
        
        return (v.x > minX && v.y > minY && v.z > minZ &&
                v.x < maxX && v.y < maxY && v.z < maxZ);
    }
    
    
    //Get the center of the box
	Vector3 center() {
		return ((max() - min()) / 2 + min());
	}
    
    //Stephanie
    float height() {
        return (max() - min()).y();
    }
    
    //Stephanie
    float length() {
        return (max() - min()).x();
    }
    
    //Stephanie
    float width() {
        return (max() - min()).z();
    }
    
    
};

#endif // _BOX_H_
