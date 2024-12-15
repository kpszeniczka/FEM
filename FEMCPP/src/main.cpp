#include "header.h"

std::vector<Node> loadNodes(const std::string& filename) {
    std::vector<Node> nodes;
    std::ifstream file("res/tests/" + filename);
    std::string line;
    bool nodeSection = false;
    bool bcSection = false;

    while (getline(file, line)) {
        if (line.find("*Node") != std::string::npos) {
            nodeSection = true;
            continue;
        }
        if (line.find("*BC") != std::string::npos){
            bcSection = true;
            continue;
        }
        if (line.find('*') != std::string::npos && nodeSection) {
            nodeSection = false;
        }
        if (nodeSection && !line.empty()) {
            std::istringstream iss(line);
            std::string temp;
            double x, y;

            getline(iss, temp, ',');
            iss >> x;
            iss.ignore(1, ',');
            iss >> y;
            nodes.push_back({x, y});
        }
        if (bcSection && !line.empty()){
            std::istringstream iss(line);
            std::string temp;


            while (std::getline(iss, temp, ',')) {
                nodes[std::stoi(temp)-1].BC = true;
            }
        }
    }

    return nodes;
}
GlobalData loadData(const std::string& filename) {
    GlobalData data;
    std::ifstream file("res/tests/" + filename);
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string key, extra;
        int value;
        if (!(iss >> key)) continue;
        if ((key == "Nodes" || key == "Elements") && (iss >> extra) && (extra == "number")) {
            if (iss >> value) {
                if (key == "Nodes") {
                    data.NodesNumber = value;
                } else if (key == "Elements") {
                    data.ElementsNumber = value;
                }
            }
        }
        else if (iss >> value) {
            if (key == "SimulationTime") data.SimulationTime = value;
            else if (key == "SimulationStepTime") data.SimulationStepTime = value;
            else if (key == "Conductivity") data.Conductivity = value;
            else if (key == "Alfa") data.Alfa = value;
            else if (key == "Tot") data.Tot = value;
            else if (key == "InitialTemp") data.InitialTemp = value;
            else if (key == "Density") data.Density = value;
            else if (key == "SpecificHeat") data.SpecificHeat = value;
        }
    }
    return data;
}
std::vector<Element> loadElements(const std::string& filename) {
    std::vector<Element> elements;
    std::ifstream file("res/tests/" + filename);
    std::string line;
    bool elementSection = false;

    while (getline(file, line)) {
        if (line.find("Element, type=DC2D4") != std::string::npos) {
            elementSection = true;
            continue;
        }

        if (elementSection && line.find("*BC") != std::string::npos) {
            break;
        }

        if (elementSection && !line.empty()) {
            std::istringstream iss(line);
            std::string temp;
            std::vector<int> nodeIds;

            getline(iss, temp, ',');

            while (getline(iss, temp, ',')) {
                nodeIds.push_back(stoi(temp));
            }

            elements.push_back({nodeIds});
        }
    }

    return elements;
}

std::vector<Node> nodes = loadNodes(filename);
GlobalData data = loadData(filename);
std::vector<Element> elements = loadElements(filename);

ElemUniv::ElemUniv(){
        calculatedNs();
        calculateSurface();
    };

void ElemUniv::calculatedNs(){
        for (int i = 0; i < NPC * NPC; ++i) {
            dndksi.push_back({-0.25 * (1 - eta[i]),
                              0.25 * (1 - eta[i]),
                              0.25 * (1 + eta[i]),
                              -0.25 * (1 + eta[i])});
            dndeta.push_back({-0.25 * (1 - ksi[i]),
                              -0.25 * (1 + ksi[i]),
                              0.25 * (1 + ksi[i]),
                              0.25 * (1 - ksi[i])});
        }

}
void ElemUniv::calculateSurface(){
    for (int i = 0; i < NPCBC * 4; ++i) {
    dnBc.push_back({0.25 * (1 - ksibc[i]) * (1 - etabc[i]),
                    0.25 * (1 + ksibc[i]) * (1 - etabc[i]),
                    0.25 * (1 + ksibc[i]) * (1 + etabc[i]),
                    0.25 * (1 - ksibc[i]) * (1 + etabc[i])});
    }
}

ElemUniv elemUniv;

void Element::setup(){
    calculateJakobian();
    calculateDetJ();
    inverseJakobian();
    calculateH();
    calculateDetJBc();
    calculateHbc();
    calculateP();
}

//do liczenia macierzy H
void Element::calculateJakobian(){
    J.resize(NPC * NPC, Matrix(2, Vector(2, 0.0)));
    for (int pc = 0; pc < NPC * NPC; ++pc) {
        for (int j = 0; j < 4; ++j) {
            J[pc][0][0] += elemUniv.dndksi[pc][j] * nodes[nodeIds[j] - 1].x;
            J[pc][0][1] += elemUniv.dndksi[pc][j] * nodes[nodeIds[j] - 1].y;
            J[pc][1][0] += elemUniv.dndeta[pc][j] * nodes[nodeIds[j] - 1].x;
            J[pc][1][1] += elemUniv.dndeta[pc][j] * nodes[nodeIds[j] - 1].y;
        }
    }
}
void Element::calculateDetJ(){
    for (int pc = 0; pc < NPC * NPC; ++pc) {
        detJ.push_back(J[pc][0][0] * J[pc][1][1] - J[pc][0][1] * J[pc][1][0]);
    }
}
void Element::inverseJakobian(){
    J1 = J;
    for (int pc = 0; pc < NPC * NPC; ++pc) {
        J1[pc][0][1] = -J[pc][0][1] / detJ[pc];
        J1[pc][1][0] = -J[pc][1][0] / detJ[pc];
        J1[pc][0][0] = J[pc][1][1] / detJ[pc];
        J1[pc][1][1] = J[pc][0][0] / detJ[pc];
    }
}
void Element::calculateH() {
    Matrix matrix_x(NPC * NPC, Vector(4, 0.0));
    Matrix matrix_y(NPC * NPC, Vector(4, 0.0));
    std::vector<Matrix> matrix_x_pc(NPC * NPC, Matrix(4, Vector(4, 0.0)));
    std::vector<Matrix> matrix_y_pc(NPC * NPC, Matrix(4, Vector(4, 0.0)));
    std::vector<Matrix> matrix_h_pc(NPC * NPC, Matrix(4, Vector(4, 0.0)));
    H.resize(4, Vector(4, 0.0));

    for (int pc = 0; pc < NPC * NPC; ++pc) {
        for (int j = 0; j < 4; ++j) {
            matrix_x[pc][j] = J1[pc][0][0] * elemUniv.dndksi[pc][j] + J1[pc][0][1] * elemUniv.dndeta[pc][j];
            matrix_y[pc][j] = J1[pc][1][0] * elemUniv.dndksi[pc][j] + J1[pc][1][1] * elemUniv.dndeta[pc][j];
        }
    }

    for (int pc = 0; pc < NPC * NPC; ++pc) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix_x_pc[pc][i][j] = matrix_x[pc][i] * matrix_x[pc][j];
                matrix_y_pc[pc][i][j] = matrix_y[pc][i] * matrix_y[pc][j];
            }
        }
    }

    for (int pc = 0; pc < NPC * NPC; ++pc) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix_h_pc[pc][i][j] = data.Conductivity * (matrix_x_pc[pc][i][j] + matrix_y_pc[pc][i][j]) * detJ[pc];
            }
        }
    }

    for (int k = 0; k < NPC; ++k) {
        for (int l = 0; l < NPC; ++l) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                   H[i][j] += matrix_h_pc[k * NPC + l][i][j] * weights[k] * weights[l];
                }
            }
        }
    }
}

//do liczenia macierzy Hbc i wektora P
void Element::calculateDetJBc(){
    Vector L;
    Vector x;
    Vector y;
    double dx, dy;
    for (int i = 0; i < 4; ++i) {
        x.push_back(nodes[nodeIds[i]-1].x);
        y.push_back(nodes[nodeIds[i]-1].y);
    }
    for (int i = 0; i < 4; ++i) {
        dx = nodes[nodeIds[i]-1].x - nodes[nodeIds[(i+1)%4] - 1].x;
        dy = nodes[nodeIds[i]-1].y - nodes[nodeIds[(i+1)%4] - 1].y;
        detJBc.push_back(sqrt(dx*dx + dy*dy)/2);
    }
}

void Element::calculateHbc() {
    Matrix matrixHbcSum(4, Vector(16, 0.0));

    for (int edge = 0; edge < 4; ++edge) {
        for (int point = 0; point < NPCBC; ++point) {
            int index = edge * NPCBC + point;

            for (int row = 0; row < 4; ++row) {
                for (int col = 0; col < 4; ++col) {
                    matrixHbcSum[edge][row * 4 + col] += elemUniv.dnBc[index][row] * elemUniv.dnBc[index][col] * weightsbc[point];
                }
            }
        }

        for (int k = 0; k < 16; ++k) {
            matrixHbcSum[edge][k] *= data.Alfa * detJBc[edge];
        }
    }

    Hbc.clear();
    Hbc.resize(4, Vector(4, 0.0));

    for (int edge = 0; edge < 4; ++edge) {
        if (nodes[nodeIds[edge] - 1].BC && nodes[nodeIds[(edge + 1) % 4] - 1].BC) {
            for (int row = 0; row < 4; ++row) {
                for (int col = 0; col < 4; ++col) {
                    Hbc[row][col] += matrixHbcSum[edge][row * 4 + col];
                }
            }
        }
    }
}

void Element::calculateP() {
    Matrix help(NPCBC * 4, Vector(4, 0.0));

    for (int i = 0; i < NPCBC * 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            help[i][j] = elemUniv.dnBc[i][j] * data.Tot;
        }
    }

    Matrix SumP(4, Vector(4, 0.0));

    for (int edge = 0; edge < 4; ++edge) {
        for (int point = 0; point < NPCBC; ++point) {
            int index = edge * NPCBC + point;
            for (int i = 0; i < 4; ++i) {
                SumP[edge][i] += help[index][i] * weightsbc[point];
            }
        }
    }

    P.clear();
    P.resize(4, 0.0);

    for (int edge = 0; edge < 4; ++edge) {
        if (nodes[nodeIds[edge] - 1].BC && nodes[nodeIds[(edge + 1) % 4] - 1].BC) {
            for (int i = 0; i < 4; ++i) {
                P[i] += SumP[edge][i] * data.Alfa * detJBc[edge];
            }
        }
    }
}

void Solution::setup(){
    agregate();
}

void Solution::agregate() {
    Hglobal.resize(data.NodesNumber,Vector(data.NodesNumber,0.0));
    Pglobal.resize(data.NodesNumber,0.0);

    int globalJ, globalK;

    for (int i = 0; i < data.ElementsNumber; ++i) {
        Element element = elements[i];
        element.setup();
        for (int j = 0; j < 4; ++j) {
            globalJ = element.nodeIds[j] - 1;
            for (int k = 0; k < 4; ++k) {
                globalK = element.nodeIds[k] - 1;
                Hglobal[globalJ][globalK] += element.H[j][k] + element.Hbc[j][k];
            }
            Pglobal[globalJ] += element.P[j];
        }
    }
}

void Solution::printH() {
    for (int i = 0; i < data.NodesNumber; ++i) {
        for (int j = 0; j < data.NodesNumber; ++j) {
            std::cout << std::setw(8) << std::setprecision(5) << Hglobal[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout<< std::endl;
}

void Solution::printP() {
    for (int i = 0; i < data.NodesNumber; ++i) {
        std::cout << std::setw(8) << std::setprecision(6) << Pglobal[i] << ", ";
    }
    std::cout << std::endl;
}

int main() {

    Solution sol;
    sol.setup();
#if PRINT != 0
    sol.printH();
    sol.printP();
#endif
    return 0;
}
