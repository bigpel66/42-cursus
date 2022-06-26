#ifndef TESTSELECTER_HPP
#define TESTSELECTER_HPP

#include "./UnitTester.hpp"

#define TABLE_SIZE 0xF00

namespace Suppresser {
extern t_unit_tests func_test_table[TABLE_SIZE];
}

#ifndef _VECTOR
namespace VectorTest = Suppresser;
#else
#include "VectorTest.hpp"
#endif

#ifndef _MAP
namespace MapTest = Suppresser;
#else
#include "MapTest.hpp"
#endif

#ifndef _STACK
namespace StackTest = Suppresser;
#else
#include "StackTest.hpp"
#endif

#ifndef _SET
namespace SetTest = Suppresser;
#else
#include "SetTest.hpp"
#endif

#endif /* TESTSELECTER_HPP */
