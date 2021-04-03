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

// Read an environment from standard input.
void readEnvStdin(Env env);

// Print out an Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList *solution);

int main(int argc, char **argv)
{

    // tests();
    // Load Environment
    Env env;
    readEnvStdin(env);

    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    PathSolver *pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);

    NodeList *exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList *solution = pathSolver->getPath(env);

    printEnvStdout(env, solution);

    delete pathSolver;
    delete exploredPositions;
    delete solution;
}

void tests(){
}

void readEnvStdin(Env env)
{
    //TODO
}

void printEnvStdout(Env env, NodeList *solution)
{
    //TODO
}