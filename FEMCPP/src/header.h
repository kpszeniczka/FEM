#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

#define PRINT 1
#define TEST 1
#define NPC 2
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
double value[NPC] = { -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0)};
double weights[NPC] = { 1.0, 1.0 };
#endif
#if NPC == 3
double value[NPC] = { -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0)};
double weights[NPC] = {5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0};
#endif
#if NPC == 4
double value[NPC] = {-std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                   -std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                   std::sqrt(3.0 / 7.0 - 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
                   std::sqrt(3.0 / 7.0 + 2.0 / 7.0 * std::sqrt(6.0 / 5.0)),
};
double weights[NPC] = {(18.0 - std::sqrt(30.0)) / 36.0,
                       (18.0 + std::sqrt(30.0)) / 36.0,
                       (18.0 + std::sqrt(30.0)) / 36.0,
                       (18.0 - std::sqrt(30.0)) / 36.0};
#endif

#if NPCBC == 2
double ksibc[NPCBC * 4] = { -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0),
                               1.0, 1.0,
                                1.0 / std::sqrt(3.0), -1.0 / std::sqrt(3.0),
                                -1.0, -1.0 };
double etabc[NPCBC * 4] = { -1.0, -1.0, -1.0 / std::sqrt(3.0), 1.0 / std::sqrt(3.0), 1.0, 1.0, 1.0 / std::sqrt(3.0), -1.0 / std::sqrt(3.0) };
double weightsbc[NPCBC] = {1.0, 1.0};
#endif
#if NPCBC == 3
double ksibc[NPCBC * 4] = { -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0),
                              1.0, 1.0, 1.0,
                              std::sqrt(3.0 / 5.0), 0.0, -std::sqrt(3.0 / 5.0),
                              -1.0, -1.0, -1.0 };
double etabc[NPCBC * 4] = { -1.0, -1.0, -1.0,
                              -std::sqrt(3.0 / 5.0), 0.0, std::sqrt(3.0 / 5.0),
                               1.0, 1.0, 1.0,
                               std::sqrt(3.0 / 5.0), 0.0, -std::sqrt(3.0 / 5.0) };
double weightsbc[NPCBC] = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
#endif
#if NPCBC == 4
double ksibc[NPCBC * 4] = {
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

double etabc[NPCBC * 4] = {
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

double weightsbc[NPCBC] = {
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
    double dndksi[NPC * NPC][4] = { 0 };
    double dndeta[NPC * NPC][4] = { 0 };
    double NBc[NPCBC * 4][4] = { 0 };
    double N[NPC * NPC][4] = { 0 };

    ElemUniv();
    void calculatedNs();

    void calculateNBc();

    void calculateN();
};


struct Element {
    std::vector<int> nodeIds;
    double H[4][4] = { 0 };
    double Hbc[4][4] = { 0 };
    double P[4] = { 0 };
    double C[4][4] = { 0 };
    double J[NPC * NPC][2][2] = { 0 };
    double J1[NPC * NPC][2][2] = { 0 };
    double detJ[NPC * NPC] = { 0 };
    double detJBc[4] = { 0 };

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
void printMatrix();
void printVector();