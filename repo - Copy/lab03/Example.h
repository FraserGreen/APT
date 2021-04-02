#ifndef EXAMPLE_H

#define EXAMPLE_H

class Example {
public:
   Example(double value);
   ~Example();
   void setValue(double value);
   double getValue();

private:
   double* ptrValue;
};

#endif //EXAMPLE_H