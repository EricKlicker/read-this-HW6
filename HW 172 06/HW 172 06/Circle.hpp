//
//  Circle.hpp
//  HW 172 06
//
//  Created by Eric Klicker on 11/8/16.
//  Copyright © 2016 Eric Klicker. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>

class Circle
{
private:
    double radius;
    static int numberOfObjects;
    
public:
    Circle();
    Circle(double);
    double getArea() const;
    double getRadius() const;
    void setRadius(double);
    static int getNumberOfObjects();
    bool operator<(Circle&);
    bool operator<=(Circle&);
    bool operator==(Circle&);
    bool operator!=(Circle&);
    bool operator>(Circle&);
    bool operator>=(Circle&);
};


#endif /* Circle_hpp */
