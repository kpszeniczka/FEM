#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#define PRINT 1
#define TEST 1
#define NPC 3
#define NPCBC 3

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
std::vector<double> ksi = { -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0), -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0) };
std::vector<double> eta = { -1.0 / std::sqrt(3.0), -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0) };
std::vector<double> weights{ 1.0, 1.0 };
#endif
#if NPC == 3
std::vector<double> ksi = { -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0),
                           -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0),
                           -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0) };
std::vector<double> eta = { -std::sqrt(3.0 / 5.0), -std::sqrt(3.0 / 5.0), -std::sqrt(3.0 / 5.0),
                           0.0, 0.0, 0.0,
                           std::sqrt(3.0 / 5.0), std::sqrt(3.0 / 5.0), std::sqrt(3.0 / 5.0) };
std::vector<double> weights = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
#endif
#if NPC == 4
std::vector<double> ksi = { -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                           -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
};
std::vector<double> eta = { -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                            std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
};
std::vector<double> weights = { (18.0 - std::sqrt(30.0)) / 36.0,
                               (18.0 + std::sqrt(30.0)) / 36.0,
                               (18.0 + std::sqrt(30.0)) / 36.0,
                               (18.0 - std::sqrt(30.0)) / 36.0 };
#endif

#if NPCBC == 2
std::vector<double> ksibc = { -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0), 1.0, 1.0, 1.0 / std::sqrt(3.0), -1.0 / std::sqrt(3.0), -1.0, -1.0 };
std::vector<double> etabc = { -1.0, -1.0, -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0), 1.0, 1.0, 1.0 / std::sqrt(3.0), -1.0 / std::sqrt(3.0) };
std::vector<double> weightsbc = { 1.0, 1.0 };
#endif
#if NPCBC == 3
std::vector<double> ksibc = { -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0),
                              1.0, 1.0, 1.0,
                              std::sqrt(3.0 / 5.0), 0.0, -std::sqrt(3.0 / 5.0),
                              -1.0, -1.0, -1.0 };
std::vector<double> etabc = { -1.0, -1.0, -1.0,
                              -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0),
                               1.0, 1.0, 1.0,
                               std::sqrt(3.0 / 5.0), 0.0, -std::sqrt(3.0 / 5.0) };
std::vector<double> weightsbc = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
#endif
#if NPCBC == 4
std::vector<double> ksibc = {
    -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     1.0, 1.0, 1.0, 1.0,
     std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -1.0, -1.0, -1.0, -1.0
};

std::vector<double> etabc = {
    -1.0, -1.0, -1.0, -1.0,
    -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     1.0, 1.0, 1.0, 1.0,
     std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
     std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
    -std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0))
};

std::vector<double> weightsbc = {
    (18.0 - std::sqrt(30.0)) / 36.0,
    (18.0 + std::sqrt(30.0)) / 36.0,
    (18.0 + std::sqrt(30.0)) / 36.0,
    (18.0 - std::sqrt(30.0)) / 36.0
};
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
    std::vector<std::vector<double>> N;

    ElemUniv();
    void calculatedNs();

    void calculateSurface();

    void calculateN();
};


struct Element {
    std::vector<int> nodeIds;
    using Vector = std::vector<double>;
    using Matrix = std::vector<std::vector<double>>;
    Matrix H;
    Matrix Hbc;
    Vector P;
    Matrix C;
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

    void calculateC();

    void setup();
};

struct Solution{
    using Matrix = std::vector<std::vector<double>>;
    using Vector = std::vector<double>;
    Matrix Hglobal;
    Vector Pglobal;
    Matrix Cglobal;
    Matrix Global;

    void setup();
    void agregate();
    void printP();
    void printH();
    void printC();
    void solve();
    Vector Gauss(const Matrix& A, Vector& b);
};


std::vector<Node> loadNodes(const std::string& filename);
GlobalData loadData(const std::string& filename);
std::vector<Element> loadElements(const std::string& filename);