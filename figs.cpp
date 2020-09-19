#include<iostream>
#include"figs.hpp"
#include<cmath>
#include<cassert>
#include <vector>

//Pentagon
Pentagon::Pentagon() {};
Pentagon::Pentagon(std::istream& in) {
    in >> Vertexs[0].x >> Vertexs[0].y >> Vertexs[1].x >> Vertexs[1].y >> Vertexs[2].x >> Vertexs[2].y >> Vertexs[3].x >> Vertexs[3].y >> Vertexs[4].x >> Vertexs[4].y;
}

Vertex Pentagon::center() const {
    Vertex res = Vertex();
    for (int i = 0; i < 5; i++)
        res += Vertexs[i];
    return res / 5;
}
double Pentagon::square() const  {
    double Area = 0;
    Vertex Cntr = center();
    std::vector<Vertex > Sqr;
    for (int i = 0; i < 5; i++){
        Sqr.push_back(Cntr);
        Sqr[i].x = Vertexs[i].x - Cntr.x;
        Sqr[i].y = Vertexs[i].y - Cntr.y;
    }
    for (int i = 0; i < 5; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1)%5].y) - (Vertexs[(i + 1)%5].x)*(Vertexs[i].y);
    }
    Area *=  0.5 ;
    return abs(Area);
}

void Pentagon::printCords() const {
    std::cout << "Pentagon: ";
    for (int i = 0; i < 5; i++)
        std::cout << Vertexs[i] << ' ';
    std::cout << '\b';
}

//Hexagon
Hexagon::Hexagon() {};
Hexagon::Hexagon(std::istream &in) {
    in >> Vertexs[0].x >> Vertexs[0].y >> Vertexs[1].x >> Vertexs[1].y >> Vertexs[2].x >> Vertexs[2].y >> Vertexs[3].x
       >> Vertexs[3].y >> Vertexs[4].x >> Vertexs[4].y >> Vertexs[5].x >> Vertexs[5].y;}
    Vertex Hexagon::center() const {
        Vertex res = Vertex();
        for (int i = 0; i < 6; i++)
            res += Vertexs[i];
        return res / 6;
    }
    double Hexagon::square() const  {
        double Area = 0;
        for (int i = 0; i < 6; i++) {
            Area += (Vertexs[i].x) * (Vertexs[(i + 1)%6].y) - (Vertexs[(i + 1)%6].x)*(Vertexs[i].y);
        }
        Area *= 0.5;
        return abs(Area);
    }

    void Hexagon::printCords() const {
        std::cout << "Hexagon: ";
        for (int i = 0; i < 6; i++)
            std::cout << Vertexs[i] << ' ';
        std::cout << '\b';
    }

//Hexagon
Octagon::Octagon(){};
Octagon::Octagon(std::istream &in) {
    in >> Vertexs[0].x >> Vertexs[0].y >> Vertexs[1].x >> Vertexs[1].y >> Vertexs[2].x >> Vertexs[2].y >> Vertexs[3].x
       >> Vertexs[3].y >> Vertexs[4].x >> Vertexs[4].y >> Vertexs[5].x >> Vertexs[5].y >> Vertexs[6].x >> Vertexs[6].y
                                                                        >> Vertexs[7].x >> Vertexs[7].y;
}
    Vertex Octagon::center() const {
        Vertex res = Vertex();
        for (int i = 0; i < 8; i++)
            res += Vertexs[i];
        return res / 8;
    }
    double Octagon::square() const  {
        double Area = 0;
        for (int i = 0; i < 8; i++) {
            Area += (Vertexs[i].x) * (Vertexs[(i + 1)%8].y) - (Vertexs[(i + 1)%8].x)*(Vertexs[i].y);
        }
        Area *= 0.5;
        return abs(Area);
    }

    void Octagon::printCords() const {
        std::cout << "Octagon: ";
        for (int i = 0; i < 8; i++)
            std::cout << Vertexs[i] << ' ';
        std::cout << '\b';
    }


