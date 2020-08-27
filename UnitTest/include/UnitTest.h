#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "UnitTestCase.h"
#include "UnitTestSuite.h"



#define CXF_UT_ASSERT(tc,msg,cond)  do{ \
    if((cond) == false) { tc->assertFailured(__FILE__,__LINE__,msg);return false;} \
}while(false);

#endif//UNIT_TEST_H
