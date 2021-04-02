
// #ifndef BOAT_H
// #define BOAT_H

#include <string>

class Boat {
public:
   Boat(std::string name, double weight, double length);

   std::string getName();
   double getWeight();
   double getLength();

   void setName(std::string name);

private:
   std::string name;
   double weight;
   double length;
};

// #endif // BOATS_H
