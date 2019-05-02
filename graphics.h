#pragma once
#include <Imagine/Graphics.h>
#include <Imagine/Images.h>
#include "piece.h"
using namespace Imagine;

class Case;

const int SPACE=90;
const int FONT_SIZE = 30;
const int MARGIN = 50;
const Color LIGHTGREEN=Color(119, 149, 89);
const Color IVORY=Color(238, 238, 211);
const Color BOARD_COLORS[2] = {LIGHTGREEN, IVORY};


void coord(Case c, int&x, int&y);

void display_grid_empty();
void display_piece(Case c, Piece* p);
void clr_case(Case c);
void go_to(Case c1, Case c2, Piece* p);
