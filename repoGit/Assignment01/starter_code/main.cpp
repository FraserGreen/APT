#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

/*
Describe (briefly) the approach you have taken in your implementation:
    My implementation:
    -reads environment from file that is passed through the command line or from standard input inside the program.
    -generates a bruteforced list of nodes that eventually go from the start to the goal.
    -refines this list into a solution by going backwards from goal to start and picking only the nodes that make correct progress
    -creates a new environment (to preserve the input), and prints the solution on to that environment, including the direction that the robot would be taking.
    -that new environment is then given as standard output


Describe (briefly) any issues you encountered
    -lots of segmentation faults
    -lots of memory leaks (fixed with help from valgrind)
    -lots of issues with row and column mismatching
    -not knowing how to process standard input through the command line without use of **argv
    -lots of unexpected nullptrs being passed around and handled badly
    -trouble figuring out a good way to identify adjacent nodes without lots of code duplication
    -unsure whether to convert some chunks of code into separate methods or not
*/

// Read an environment from standard input.
void readEnvStdin(Env env);

// Print out an Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList *solution);

//get length of char array
void size(char *str);

//goes through row by row, column by column, each element of env. at the end of each row, prints out a newline, unless it's the final column.
void printEnv(Env env);

int main(int argc, char **argv)
{

    // Load Environment
    Env env{};
    readEnvStdin(env);
    //check if environment has been read correctly
    if (env[ENV_DIM - 1][ENV_DIM - 1] != '=')
    {
        std::cout << "Please enter a valid filepath / environment.";
    }
    else
    {
        PathSolver *pathSolver = new PathSolver();

        //check if env has a starting and ending position
        Node *start = pathSolver->get(env, 'S');
        Node *goal = pathSolver->get(env, 'G');
        if (start == nullptr || goal == nullptr)
        {
            std::cout << "This environment has no starting / ending position!";
        }
        else
        {
            // Solve using forwardSearch
            // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
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
        
        delete start;
        delete goal;
    }
}

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

void printEnvStdout(Env env, NodeList *solution)
{
    Env out{}; //create a deep copy of env that will be used to output solution, so that env is untouched
    for (int i = 0; i < ENV_DIM; i++)
    {
        for (int j = 0; j < ENV_DIM; j++)
        {
            out[i][j] = env[i][j];
        }
    }
    //imprints the solution onto env
    //starts at i = 2 so that start is not modified
    for (int i = 2; i < solution->getLength(); i++)
    {
        Node *prevNode = solution->getNode(i - 1);
        Node *node = solution->getNode(i);
        char direction = '0';
        //up
        if (node->getCol() < prevNode->getCol())
        {
            direction = '^';
        }
        //down
        else if (node->getCol() > prevNode->getCol())
        {
            direction = 'v';
        }
        //left
        else if (node->getRow() < prevNode->getRow())
        {
            direction = '<';
        }
        //right
        else if (node->getRow() > prevNode->getRow())
        {
            direction = '>';
        }
        out[prevNode->getCol()][prevNode->getRow()] = direction;
    }

    printEnv(out);
}