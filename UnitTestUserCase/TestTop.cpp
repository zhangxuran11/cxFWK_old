
#include "UnitTestSuiteUserCase.h"


int main(){
    CXF::UnitTestSuite* suite = new CXF::UnitTestSuite;
    suite->add(CXF::UnitTestSuiteUserCase::getSuite());
    suite->run();
    suite->print();
    delete suite;
    return 0;
}
