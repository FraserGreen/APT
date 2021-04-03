#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

//TODO DELETE USINGS
using std::cout;
using std::endl;

void tests();

// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList *solution);

int main(int argc, char **argv)
{

    tests();
    // // Load Environment
    // Env env;
    // readEnvStdin(env);

    // // Solve using forwardSearch
    // // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    // PathSolver *pathSolver = new PathSolver();
    // pathSolver->forwardSearch(env);

    // NodeList *exploredPositions = nullptr;
    // exploredPositions = pathSolver->getNodesExplored();

    // // Get the path
    // // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    // NodeList *solution = pathSolver->getPath(env);

    // printEnvStdout(env, solution);

    // delete pathSolver;
    // delete exploredPositions;
    // delete solution;
}

void tests(){
    PathSolver *pathSolver = new PathSolver();
    cout << "Row of 1st node in deep copied pathSolver: ";
    cout << pathSolver->getNodesExplored()->getNode(0)->getRow() << endl;
    cout << "address of 1st node in deep copied pathSolver: ";
    cout << pathSolver->getNodesExplored()->getNode(0) << endl;
    cout << "address of NodeList in deep copied pathSolver: ";
    cout << pathSolver->getNodesExplored() << endl;
}

void readEnvStdin(Env env)
{
    //TODO
}

void printEnvStdout(Env env, NodeList *solution)
{
    //TODO
}