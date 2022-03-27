// Copyright @bigpel66

#include "MutantStack.hpp"

void test_normal(void) {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

void test_const_iterator(void) {
  MutantStack<char> mstack;
  mstack.push('a');
  mstack.push('b');
  mstack.push('c');
  mstack.push('d');
  mstack.push('e');
  MutantStack<char>::const_iterator cit = mstack.cbegin();
  MutantStack<char>::const_iterator cite = mstack.cend();
  ++cit;
  --cit;
  while (cit != cite) {
    std::cout << *cit << std::endl;
    ++cit;
  }
}

void test_reverse_iterator(void) {
  MutantStack<double> mstack;
  mstack.push(1.0);
  mstack.push(2.0);
  mstack.push(3.0);
  mstack.push(4.0);
  mstack.push(5.0);
  MutantStack<double>::reverse_iterator rit = mstack.rbegin();
  MutantStack<double>::reverse_iterator rite = mstack.rend();
  ++rit;
  --rit;
  while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
  }
}

void test_const_reverse_iterator(void) {
  MutantStack<std::string> mstack;
  mstack.push("hi");
  mstack.push("42");
  mstack.push("Seoul");
  mstack.push("guys");
  mstack.push("Jseo");
  MutantStack<std::string>::const_reverse_iterator crit = mstack.crbegin();
  MutantStack<std::string>::const_reverse_iterator crite = mstack.crend();
  ++crit;
  --crit;
  while (crit != crite) {
    std::cout << *crit << std::endl;
    ++crit;
  }
}

int main(void) {
  test_normal();
  std::cout << std::endl;
  test_const_iterator();
  std::cout << std::endl;
  test_reverse_iterator();
  std::cout << std::endl;
  test_const_reverse_iterator();
  std::cout << std::endl;
  return 0;
}
