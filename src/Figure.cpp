#include "static_headers.h"

#include "Figure.h"

int Figure::nextId = 1;

Figure::Figure() :
  haveSpecificRotation(false),
  specificRotatedFlag(false),
  type(typeNone),
  dim(0),
  angle(0),
  id(0),
  color(Cell::clNone)
{
}


void Figure::buildRandom()
{
  assert(TYPE_COUNT > 0);
  Type type = Type(rand() % TYPE_COUNT);
  build(type);
}


void Figure::build(Type type)
{
  char * cdata = NULL;
  id = Figure::nextId++;
  color = Cell::clNone;
  this->type = type;

  switch (type)
  {
    case typeI:
      haveSpecificRotation = true;
      dim = 4;
      color = Cell::clCyan;
      cdata = "0000111100000000";
      break;

    case typeJ:
      haveSpecificRotation = false;
      dim = 3;
      color = Cell::clBlue;
      cdata = "100111000";
      break;

    case typeL:
      haveSpecificRotation = false;
      dim = 3;
      color = Cell::clOrange;
      cdata = "001111000";
      break;

    case typeO:
      haveSpecificRotation = false;
      dim = 2;
      color = Cell::clYellow;
      cdata = "1111";
      break;

    case typeS:
      haveSpecificRotation = true;
      dim = 3;
      color = Cell::clGreen;
      cdata = "011110000";
      break;

    case typeT:
      haveSpecificRotation = false;
      dim = 3;
      color = Cell::clPurple;
      cdata = "010111000";
      break;

    case typeZ:
      haveSpecificRotation = true;
      dim = 3;
      color = Cell::clRed;
      cdata = "110011000";
      break;

    default:
      assert(0);
  }

  assert((int)strlen(cdata) == dim * dim);

  for (int i = 0, cnt = dim * dim; i < cnt; i++)
    cells[i] = (cdata[i] == '1') ? Cell(id, color) : Cell(0, Cell::clNone);
}


void Figure::internalRotateLeft()
{
  Cell curCells[dimMax * dimMax];
  memcpy(curCells, cells, sizeof(curCells));

  for (int x = 0; x < dim; x++)
    for (int y = 0; y < dim; y++)
    {
      cells[x + y * dim] = curCells[(dim - y - 1) + x * dim];
    }
}


void Figure::internalRotateRight()
{
  Cell curCells[dimMax * dimMax];
  memcpy(curCells, cells, sizeof(curCells));

  for (int x = 0; x < dim; x++)
    for (int y = 0; y < dim; y++)
    {
      cells[x + y * dim] = curCells[y + (dim - x - 1) * dim];
    }
}


void Figure::rotateLeft()
{
  if (haveSpecificRotation && specificRotatedFlag)
  {
    angle -= 270;
    internalRotateRight();
    specificRotatedFlag = false;
  }
  else
  {
    angle -= 90;
    internalRotateLeft();
    specificRotatedFlag = true;
  }
}


void Figure::rotateRight()
{
  if (haveSpecificRotation && !specificRotatedFlag)
  {
    angle += 270;
    internalRotateLeft();
    specificRotatedFlag = true;
  }
  else
  {
    angle += 90;
    internalRotateRight();
    specificRotatedFlag = false;
  }
}


void Figure::swap(Figure & figure1, Figure & figure2)
{
  // TODO : replace by tmp = fig1; fig1 = fig2; fig2 = tmpl; 
  //        or just std::swap(fig1, fig2);
  for (int i = 0; i < dimMax * dimMax; i++)
  {
    Cell tmp = figure1.cells[i];
    figure1.cells[i] = figure2.cells[i];
    figure2.cells[i] = tmp;
  }

  bool tmp_haveSpecificRotation = figure1.haveSpecificRotation;
  figure1.haveSpecificRotation = figure2.haveSpecificRotation;
  figure2.haveSpecificRotation = tmp_haveSpecificRotation;
  
  bool tmp_specificRotatedFlag = figure1.specificRotatedFlag;
  figure1.specificRotatedFlag = figure2.specificRotatedFlag;
  figure2.specificRotatedFlag = tmp_specificRotatedFlag;

  int tmp_id = figure1.id;
  figure1.id = figure2.id;
  figure2.id = tmp_id;

  Type tmp_type = figure1.type;
  figure1.type = figure2.type;
  figure2.type = tmp_type;

  int tmp_dim = figure1.dim;
  figure1.dim = figure2.dim;
  figure2.dim = tmp_dim;

  int tmp_angle = figure1.angle;
  figure1.angle = figure2.angle;
  figure2.angle = tmp_angle;

  Cell::Color tmp_color = figure1.color;
  figure1.color = figure2.color;
  figure2.color = tmp_color;
}


void Figure::clear()
{
  haveSpecificRotation = false;
  specificRotatedFlag = false;
  id = 0;
  type = typeNone;
  dim = 0;
  color = Cell::clNone;
  angle = 0;
}


const Cell * Figure::getCell(int x, int y) const
{
  if (x < 0 || y < 0 || x >= dim || y >= dim)
    return NULL;

  // TODO : non continuous figure storing in the cell buffer could be more optimal
  // so we could use dimMax == 4 instead of dim to multiply
  return &cells[x + y * dim];
}
