#include<iostream>
#include<vector>
#include"vertex.hpp"

class Figure {
public:
    virtual Vertex center() const = 0;
    virtual double square() const = 0;
    virtual void printCords() const = 0;
    //virtual ~Figure();
};
