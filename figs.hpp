#pragma once
#include<iostream>
#include"figure.hpp"

class Pentagon : public Figure {
private:
    Vertex Vertexs[5];
public:
    Pentagon();
    Pentagon(std::istream& in);

    Vertex center() const override;

    double square() const override;

    void printCords() const override;
};


class Hexagon : public Figure {
private:
    Vertex Vertexs[6];
public:
    Hexagon();
    Hexagon(std::istream &in);

    Vertex center() const override;

    double square() const override;

    void printCords() const override;
};

class Octagon : public Figure {
private:
    Vertex Vertexs[8];
public:
    Octagon();
    Octagon(std::istream &in);

    Vertex center() const override;

    double square() const override;

    void printCords() const override;
};


