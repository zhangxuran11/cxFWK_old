#ifndef UNIT_TEST_SUITE_H
#define UNIT_TEST_SUITE_H
#include <string>
#include <list>
#include "UnitTestRunnable.h"
namespace CXF {
    class UnitTestSuite : public UnitTestRunnable{
        std::string mLogStr;
        std::list<UnitTestRunnable*> mRunnables;
        public:
            UnitTestSuite();
            virtual ~UnitTestSuite();
            void add(UnitTestRunnable* );
            void run();
            void print();
    };
}



#endif//UNIT_TEST_SUITE_H