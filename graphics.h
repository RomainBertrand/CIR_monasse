#pragma once
#include <Imagine/Graphics.h>
#include <Imagine/Images.h>
#include <map>
#include "piece.h"
using namespace Imagine;

class Case;

const int SPACE=90;
const int FONT_SIZE = 30;
const int MARGIN = 50;
const AlphaColor LIGHTGREEN=AlphaColor(119, 149, 89, 255);
const AlphaColor IVORY=AlphaColor(238, 238, 211, 255);
const AlphaColor BOARD_COLORS[2] = {LIGHTGREEN, IVORY};

void load_all_pieces();
void coord(Case c, int&x, int&y);

void display_grid_empty();
void display_piece(Case c, Piece* p);
void display_byte(Piece* p, Case c, bool xor_mode=true, double fact=1.);
void clr_case(Case c);
void go_to(Case c1, Case c2, Piece* p);
