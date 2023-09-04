#ifndef G_H
#define G_H

#include <iostream>
#include <memory>
#include "H.h"
using namespace std;

class H;

class G{
public:
  // G() = default;
  // G(shared_ptr<H>& _sph){
  //   sph = _sph;
  // }
  G(const G& another){
    g = another.g;
    sph = another.sph;
  }
public:
  int g = 0;
  shared_ptr<H> sph = nullptr;
};

#endif