#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Model.h"
#include "Program.h"
#include "Shader.h"

class View
{
private:
  Model & model;
  GLuint vaoId;

  Program figureProg;
  Shader figureVert;
  Shader figureFrag;
  
  std::vector<float> vertexBuffer;
  std::vector<float> uvwBuffer;
  std::vector<float> alphaBuffer;

  GLuint glassFigureVertexBufferId;
  GLuint glassFigureUVWBufferId;
  GLuint glassShadowVertexBufferId;
  GLuint glassShadowUVWBufferId;
  GLuint glassGlowVertexBufferId;
  GLuint glassGlowAlphaBufferId;
  int glassFigureVertCount;
  int glassShadowVertCount;
  int glassGlowVertCount;

  void fillAdjacentCellsArray(Cell * cells, int cellX, int cellY, int cellsWidth, int cellsHeight, Cell * (&adjCells)[3][3]);
  void buildGlassMeshes();
  void buildMeshes(Cell * cells, int cellsWidth, int cellsHeight, GLuint figureVertexBufferId, GLuint figureUVWBufferId, GLuint glowVertexBufferId, GLuint glowAlphaBufferId, int * figureVertCount, int * glowVertCount);
  int addCellVertices(float originX, float originY, int cellX, int cellY, const Cell & cell, Cell * (&adjCells)[3][3], std::vector<float> & vertexBuffer, std::vector<float> & uvwBuffer);
  int addCellShadowMesh(int cellX, int cellY, Cell & cell, Cell * (&adjCells)[3][3], std::vector<float> vertexBuffer, std::vector<float> uvwBuffer);
  int addCellGlowMesh(int cellX, int cellY, Cell & cell, Cell * (&adjCells)[3][3], std::vector<float> vertexBuffer, std::vector<float> alphaBuffer);

  void draw();

public:
  View(Model & model);
  ~View();

  void init();
  void update();
};
