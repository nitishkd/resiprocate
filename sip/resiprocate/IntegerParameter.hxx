#ifndef IntegerParameter_hxx
#define IntegerParameter_hxx

#include <sipstack/Parameter.hxx>
#include <iostream>

namespace Vocal2
{

class IntegerParameter : public Parameter
{
   public:
      IntegerParameter(ParameterTypes::Type, const char* startData, unsigned int dataSize);
      IntegerParameter(ParameterTypes::Type type, int value);

      int& value();
      virtual std::ostream& encode(std::ostream& stream) const;

      virtual Parameter* clone() const;
   private:
      int mValue;
};
 
}




#endif
