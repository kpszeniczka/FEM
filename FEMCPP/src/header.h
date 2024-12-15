#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#define PRINT 1
#define TEST 2
#define NPC 2
#define NPCBC 2

#if TEST == 1
std::string filename = "Test1_4_4.txt";
#endif
#if TEST == 2
std::string filename = "Test2_4_4_MixGrid.txt";
#endif
#if TEST == 3
std::string filename = "Test3_31_31_kwadrat.txt";
#endif
#if NPC == 2
std::vector<double> ksi = {-1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3), -1 / sqrt(3)};
std::vector<double> eta = {-1 / sqrt(3), -1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3)};
std::vector<double> weights{1,1};
#endif
#if NPC == 3
    std::vector<double> ksi = {-sqrt(3 / 5), 0, sqrt(3 / 5), -sqrt(3 / 5), 0, sqrt(3 / 5), -sqrt(3 / 5), 0, sqrt(3 / 5)};
    std::vector<double> eta = {-sqrt(3 / 5), -sqrt(3 / 5), -sqrt(3 / 5), 0, 0, 0, sqrt(3 / 5), sqrt(3 / 5), sqrt(3 / 5)};
    std::vector<double> weights = {5/9, 8/9, 5/9};
#endif
#if NPC == 4
std::vector<double> ksi = {-sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                    -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                    sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
    };
    std::vector<double> eta = {-sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                               sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5))
    };
    std::vector<double> weights = {(18 - sqrt(30)) / 36, (18 + sqrt(30)) / 36, (18 + sqrt(30)) / 36, (18 - sqrt(30)) / 36};
#endif

#if NPCBC == 2
std::vector<double> ksibc = {-1 / sqrt(3), 1 / sqrt(3), 1, 1, 1 / sqrt(3), -1 / sqrt(3), -1, -1};
std::vector<double> etabc = {-1, -1, -1 / sqrt(3), 1 / sqrt(3), 1, 1, 1 / sqrt(3), -1 / sqrt(3)};
std::vector<double> weightsbc = {1, 1};
#endif
#if NPCBC == 3
    std::vector<double> ksibc = {-sqrt(3 / 5), 0, sqrt(3 / 5),
                 1, 1, 1,
                 sqrt(3 / 5), 0, -sqrt(3 / 5),
                 -1, -1, -1};
    std::vector<double> etabc = {-1, -1, -1,
                 -sqrt(3 / 5), 0, sqrt(3 / 5),
                 1, 1, 1,
                 sqrt(3 / 5), 0, -sqrt(3 / 5)};
    std::vector<double> weightsbc = {5 / 9, 8 / 9, 5 / 9};
#endif
#if NPCBC == 4
std::vector<double> ksibc = {
                 -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)), -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                 1, 1, 1, 1,
                 sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)), sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                 -1, -1, -1, -1};
    std::vector<double> etabc = {
            -1, -1, -1, -1,
                -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)), -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)),
                1, 1, 1, 1,
                sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5)), sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), -sqrt(3 / 7 - 2 / 7 * sqrt(6 / 5)), -sqrt(3 / 7 + 2 / 7 * sqrt(6 / 5))
    };
    std::vector<double> weightsbc = {(18 - sqrt(30)) / 36, (18 + sqrt(30)) / 36, (18 + sqrt(30)) / 36, (18 - sqrt(30)) / 36};
#endif

struct GlobalData{
    int SimulationTime, SimulationStepTime, Conductivity, Alfa, Tot, InitialTemp, Density, SpecificHeat, NodesNumber, ElementsNumber;
};

struct Node {
    double x, y;
    bool BC = false;
};

struct ElemUniv {
    std::vector<std::vector<double>> dndksi;
    std::vector<std::vector<double>> dndeta;
    std::vector<std::vector<double>> dnBc;
    ElemUniv();
    void calculatedNs();

    void calculateSurface();
};


struct Element {
    std::vector<int> nodeIds;
    using Vector = std::vector<double>;
    using Matrix = std::vector<std::vector<double>>;
    Matrix H;
    Matrix Hbc;
    Vector P;
    std::vector<Matrix> J;
    std::vector<Matrix> J1;
    Vector detJ;
    Vector detJBc;
    void calculateJakobian();
    void calculateDetJ();
    void inverseJakobian();
    void calculateH();

    void calculateDetJBc();

    void calculateHbc();

    void calculateP();

    void setup();
};

struct Solution{
    using Matrix = std::vector<std::vector<double>>;
    using Vector = std::vector<double>;
    Matrix Hglobal;
    Vector Pglobal;

    void setup();
    void agregate();
    void printP();
    void printH();
};


std::vector<Node> loadNodes(const std::string& filename);
GlobalData loadData(const std::string& filename);
std::vector<Element> loadElements(const std::string& filename);