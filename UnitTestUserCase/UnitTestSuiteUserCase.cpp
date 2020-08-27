#include "UnitTestSuiteUserCase.h"
#include "UnitTest.h"
namespace CXF {
    static bool testCaseFunc(UnitTestCase* tc){
        CXF_UT_ASSERT(tc,"this is a example",1==2);
        return true;
    }
    UnitTestSuite* UnitTestSuiteUserCase::getSuite(){
        UnitTestSuite* suite = new UnitTestSuite;
        UnitTestCase* testCase = new UnitTestCase("UnitTestSuiteUserCase",testCaseFunc);
        suite->add(testCase);
        return suite;
    }


}