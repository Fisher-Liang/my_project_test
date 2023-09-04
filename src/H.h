#ifndef H_H
#define H_H

#include <iostream>
#include <memory>
#include "G.h"
using namespace std;

class G;

class H{
public:
  H() = default;
  H(shared_ptr<G>& _spg){
    spg = _spg;
  }
public:
  int h = 0;
  shared_ptr<G> spg = nullptr;
};

#endif