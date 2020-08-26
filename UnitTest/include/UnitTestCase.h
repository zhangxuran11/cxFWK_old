#ifndef UNIT_TEST_CASE_H
#define UNIT_TEST_CASE_H
#include "UnitTestRunnable.h"
#include <string>
namespace CXF {
    class UnitTestCase : private UnitTestRunnable{
        public:
            typedef void (*UnitTestCaseFunc)(UnitTestCase*);
        private:
            std::string mLogStr;
            UnitTestCaseFunc mCaseFunc;
        public:
            UnitTestCase(UnitTestCaseFunc func);
            void run();
            void print();
    };
}
#endif//UNIT_TEST_CASE_H
