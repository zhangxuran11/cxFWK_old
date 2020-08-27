#ifndef UNIT_TEST_RUNNABLE_H
#define UNIT_TEST_RUNNABLE_H
#include <string>
namespace CXF
{
    class UnitTestRunnable{
        public:
        virtual ~UnitTestRunnable(){}
        virtual void run() = 0;
        virtual int count() = 0;
        virtual int failCount() = 0;
        virtual const std::string& summary() = 0;
        virtual std::string failMsgLines() = 0;
    };
} // namespace C

#endif//UNIT_TEST_RUNNABLE_H