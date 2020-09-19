#include<iostream>
#include <vector>
#include"figs.hpp"
#include<locale>
#include <cmath>

int getOption() {
    int Menu;
    std::cout << "1. Ввести фигуру" << std::endl;
    std::cout << "2. Вычислить центр фигуры по индексу" << std::endl;
    std::cout << "3. Вычислить площадь фигуры по индексу" << std::endl;
    std::cout << "4. Распечатать коориднаты фигуры по индексу" << std::endl;
    std::cout << "5. Вычислить общую площадь всех фигур" << std::endl;
    std::cout << "6. Удалить фигуру по индексу" << std::endl;
    std::cout << "7. Задать координаты фигуры по количеству вершин, радиусу, центру фигуры и углу вращения" << std::endl;
    std::cin >> Menu;
    return Menu;
}

int whatFigure() {
    int Menu;
    std::cout << "1. Ввести 5-угольник" << std::endl;
    std::cout << "2. Ввести 6-угольник" << std::endl;
    std::cout << "3. Ввести 8-угольник" << std::endl;
    std::cin >> Menu;
    return Menu;
}

int main() {

    setlocale(LC_ALL, "rus");
    int Menu_1,Menu_2, Index;
    double SummaryArea = 0;
    Figure* f;
    std::vector<Figure*> Figures;

    while (true) {
        switch (Menu_1 = getOption()) {
            case 1:
                switch (Menu_2 = whatFigure()) {
                    case 1:
                        f = new Pentagon{ std::cin };
                        break;
                    case 2:
                        f = new Hexagon{ std::cin };
                        break;
                    case 3:
                        f = new Octagon(std::cin);
                        break;
                }
                Figures.push_back(f);
                break;
            case 2:
                std::cout << "Введите индекс: ";
                std::cin >> Index;
                if (Figures[Index] != nullptr)
                    std::cout << "Центр фигуры по индексу " << Index << ": " << (*Figures[Index]).center() << std::endl;
                break;
            case 3:
                std::cout << "Введите индекс: ";
                std::cin >> Index;
                if (Figures[Index] != nullptr)
                    std::cout << "Площадь фигуры по индексу " << Index << ": " << (*Figures[Index]).square() << std::endl;
                break;
            case 4:
                std::cout << "Введите индекс: ";
                std::cin >> Index;
                std::cout << "Координты фигуры по индексу " << Index << ": ";
                (*Figures[Index]).printCords();
                std::cout << std::endl;
                continue;
            case 5:
                for (int i = 0; i < (int)Figures.size(); i++)
                    if (Figures[i] != nullptr) {
                        (*Figures[i]).printCords();
                        std::cout << std::endl;
                        std::cout << "Area: " << (*Figures[i]).square() << std::endl;
                        std::cout << "Center: " << (*Figures[i]).center() << std::endl;
                    }
                std::cout << "Общая площадь фигур: " << SummaryArea << std::endl;
                break;
            case 6:
                std::cout << "Введите индекс: ";
                std::cin >> Index;
                std::swap(Figures[Figures.size() - 1], Figures[Index]);
                delete Figures[Figures.size() - 1];
                Figures.pop_back();
                break;

            case 7: {
                std::cout << "Введите R, n, x0, y0, phi" << std::endl;
                double x, y, R, phi;
                int n;
                std::cin >> R >> n >> x >> y >> phi;
                std::vector<Vertex> z0;
                for (int i = 0; i < n; i++) {
                    z0.push_back(Vertex(x + R * cos(phi + 2 * M_PI * i / n),
                                        y + R * (float) sin(phi + 2 * M_PI * i / n)));
                }
                for (int i = 0; i < n; i++) {
                    std::cout << z0[i].x <<" " << z0[i].y<<std::endl;
                }
                std::cout << std::endl;
            }
                break;
            default:
                for (int i = 0; i < (int)Figures.size(); i++) {
                    delete Figures[i];
                    Figures[i] = nullptr;
                }

                return 0;
        }
    }
    return 0;
}