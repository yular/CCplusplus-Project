#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1.0);

class Circle{
private:
    pair<double, double> center;
    double radius;
public:
    Circle(){
        center.first = center.second = 0;
        radius = 0;
    }
    
    Circle(pair<double, double> ncenter, double nradius){
        center = ncenter;
        radius = nradius;
    }
    
    ~Circle(){
        
    }
    
    pair<double, double> getCenter(){
        return center;
    }
    
    double getRadius(){
        return radius;
    }
};

class IntersectionArea{
    
public:
    static double TwoCirclesIntersectionArea(Circle &o1, Circle &o2){
        double area = 0;
        double d = sqrt((o1.getCenter().first - o2.getCenter().first)*(o1.getCenter().first - o2.getCenter().first) + (o1.getCenter().second - o2.getCenter().second)*(o1.getCenter().second - o2.getCenter().second));
        if (o1.getRadius() + o2.getRadius() < d + eps)
            return area;
        if (d < fabs(o1.getRadius() - o2.getRadius())+eps){
            double radius = min(o1.getRadius(), o2.getRadius());
            return pi*radius*radius;
        }
        double x = ( d*d + o1.getRadius()*o1.getRadius() - o2.getRadius()*o2.getRadius())/(2*d);
        double t1 = acos(x/o1.getRadius());
        double t2 = acos((d-x)/o2.getRadius());
        area = o1.getRadius()*o1.getRadius()*t1 + o2.getRadius()*o2.getRadius()*t2 - d*o1.getRadius()*sin(t1);
        
        return area;
    }
};
