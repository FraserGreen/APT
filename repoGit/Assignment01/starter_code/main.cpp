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

//get length of char array
void size(char *str);

//print env to terminal
void printEnv(Env env);

int main(int argc, char **argv)
{
    //TODO cleanse cmd line input

    cout << "" << endl;

    // Load Environment
    Env env{};
    readEnvStdin(env);
    printEnv(env);

    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    PathSolver *pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);

    NodeList *exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();
    cout << exploredPositions->toString() << endl;

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList *solution = pathSolver->getPath(env);

    printEnvStdout(env, solution);


    delete pathSolver;
    delete exploredPositions;
    delete solution;
}

void printEnv(Env env)
{
    for (int i = 0; i < ENV_DIM; i++)
    {
        for (int j = 0; j < ENV_DIM; j++)
        {
            cout << env[i][j];
        }
        cout << endl;
    }
}

void size(char *str)
{
    int length = 0;
    for (int i = 0; i != '\n'; i++)
    {
        length++;
    }
}

void tests()
{
}

void readEnvStdin(Env env)
{
    //TODO
    //reading from file
    //TODO remove hardcoded input source
    std::fstream input;
    input.open("sampleTest/sample08.env");

    // cout << static_cast<char>(input.get()) << endl;

    for (int i = 0; i < ENV_DIM; i++) // && static_cast<char>(input.peek()) != '\0'
    {
        for (int j = 0; j <= ENV_DIM; j++) // && static_cast<char>(input.peek()) != '\n'
        {
            env[i][j] = static_cast<char>(input.get());
        }
    }
    input.close();
}

void printEnvStdout(Env env, NodeList *solution)
{
    //TODO
}