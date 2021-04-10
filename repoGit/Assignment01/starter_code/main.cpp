#include <iostream>
#include <string>
#include <fstream>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

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

    // Load Environment
    Env env{};
    readEnvStdin(env);
    //check if environment has been read correctly
    if (env[ENV_DIM - 1][ENV_DIM - 1] != '=')
    {
        std::cout << "Please enter a valid filepath." << std::endl;
    }
    else
    {
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
}

//goes through row by row, column by column, each element of env. at the end of each row, prints out a newline, unless it's the final column.
void printEnv(Env env)
{
    for (int i = 0; i < ENV_DIM; i++)
    {
        for (int j = 0; j < ENV_DIM; j++)
        {
            std::cout << env[i][j];
        }
        if (i != ENV_DIM - 1)
        {
            std::cout << '\n';
        }
    }
}

//returns length of char array
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
    //reads contents directly from filename entered in command line, and updates env accordingly, row by row
    for (int i = 0; !std::cin.eof() && i < ENV_DIM; i++)
    {
        std::cin >> env[i];
    }

    //if filename is not entered in from command line, this takes it as input from the user, and reads it into env.
    if (env[ENV_DIM - 1][ENV_DIM - 1] != '=')
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

//goes through all nodes in solution and
void printEnvStdout(Env env, NodeList *solution)
{
    Env out{}; //create a copy of env that will be used to output solution
    for (int i = 0; i < ENV_DIM; i++)
    {
        for (int j = 0; j < ENV_DIM; j++)
        {
            out[i][j] = env[i][j];
        }
    }

    //starts at i = 2 so that start is not modified
    for (int i = 2; i < solution->getLength(); i++)
    {
        Node *prevNode = solution->getNode(i - 1);
        Node *node = solution->getNode(i);
        //up
        if (node->getCol() < prevNode->getCol())
        {
            out[prevNode->getCol()][prevNode->getRow()] = '^';
        }
        //down
        else if (node->getCol() > prevNode->getCol())
        {
            out[prevNode->getCol()][prevNode->getRow()] = 'v';
        }
        //left
        else if (node->getRow() < prevNode->getRow())
        {
            out[prevNode->getCol()][prevNode->getRow()] = '<';
        }
        //right
        else if (node->getRow() > prevNode->getRow())
        {
            out[prevNode->getCol()][prevNode->getRow()] = '>';
        }
    }
    printEnv(out);
}