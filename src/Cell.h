#pragma once
#include "Globals.h"

class Cell
{
public:
  int figureId;
  Globals::Color color;
  float fallHeight;

  Cell();
  Cell(int figureId, Globals::Color color);

  void clear();
  Cell & operator = (const Cell & cell);
  inline bool isEmpty() { return color == Globals::Color::clNone; };
};

