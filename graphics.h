#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;

class Case;

const int space=50;
const int RAYON=fmax(space/4, 1);
const Color col_robot = GREEN;
const Color col_case = RED;
const Color Gray=Color(200, 200, 200);


void Coord(Case c, int&x, int&y);

void DisplayGrid();
void MakeCircle(Case c, Color col, int r = RAYON);
void DisplayRobot(Case c);
void ExitCase(Case c);
void GoTo(Case c1, Case c2);
