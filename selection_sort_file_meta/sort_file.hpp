// Do not change
#include <fstream>
#include <iostream>

#include <deque>
#include <list>
#include <vector>

#include "my_sort.hpp"

template <class X, class Y> void read_file_to_cont(std::ifstream &f, Y &c) {
  X ret;
  while (f >> ret)
    c.push_back(ret);
}

template <class X, class Y>
void read_and_sort(std::ifstream &fi, std::ofstream &fo) {
  Y ret = {};
  read_file_to_cont<X, Y>(fi, ret);
  my_selection_sort(ret.begin(), ret.end());
  for (auto &i : ret) {
    fo << i << std::endl;
  }
}

template <class X>
void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo) {
  char fst;
  fi >> fst;
  fo << fst << std::endl;
  switch (fst) {
  case 'd':
    read_and_sort<X, std::deque<X>>(fi, fo);
    break;
  case 'l':
    read_and_sort<X, std::list<X>>(fi, fo);
    break;
  case 'v':
    read_and_sort<X, std::vector<X>>(fi, fo);
    break;
  default:
    throw std::runtime_error("error type");
  }
}

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo) {
  char lastEl;
  fi >> lastEl;
  fo << lastEl << std::endl;
  switch (lastEl) {
  case 'd':
    read_and_sort_decide_container<double>(fi, fo);
    break;
  case 'f':
    read_and_sort_decide_container<float>(fi, fo);
    break;
  case 'u':
    read_and_sort_decide_container<unsigned>(fi, fo);
    break;
  case 'c':
    read_and_sort_decide_container<char>(fi, fo);
    break;
  case 'i':
    read_and_sort_decide_container<int>(fi, fo);
    break;
  case 's':
    read_and_sort_decide_container<std::string>(fi, fo);
    break;
  default:
    throw std::runtime_error("error type");
  }
}