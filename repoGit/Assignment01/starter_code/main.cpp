#include <iostream>
#include <string>
#include <fstream>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

//TODO DELETE USINGS
using std::cin;
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

    // Load Environment
    Env env{};
    readEnvStdin(env);
    if (env[ENV_DIM-1][ENV_DIM-1] == '=')
    {

        // printEnv(env);

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
    else
    {
        cout << "Please enter a valid filepath." << endl;
    }
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

void readEnvStdin(Env env)
{

    //reads directly from filename entered in command line
    for (int i = 0; !cin.eof() && i < ENV_DIM; i++)
    {
        cin >> env[i];
    }

    //if filename is not entered in from command line, this takes it as input from the user, and reads it into env.
    if (env[ENV_DIM-1][ENV_DIM-1] != '=')
    {
        std::ifstream file;
        file.open(env[0]);
        if (file.is_open())
        {
            for (int i = 0; i < ENV_DIM; i++)
            {
                file >> env[i];
            }
        }
    }
}

void printEnvStdout(Env env, NodeList *solution)
{
    //TODO
}