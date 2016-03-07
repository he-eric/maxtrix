#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
// #include "parser.h"

int main() {

  screen s;
  color c;

  clear_screen(s);

  //begin testing  
  struct matrix *edges;
  struct matrix *transform;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  edges = new_matrix(4, 4);
  add_edge(edges, 100, 100, 100, 200, 200, 200); //first line
  draw_lines(edges, s, c);

  c.blue = MAX_COLOR;
  transform = make_translate(100, 100, 0); //transform
  matrix_mult(transform, edges);
  draw_lines(edges, s, c);

  c.red = MAX_COLOR;
  scalar_mult(0.3, edges); //scaling
  draw_lines(edges, s, c);

  transform = make_scale(0.5, 1, 1);
  matrix_mult(transform, edges);
  draw_lines(edges, s, c);
  
  transform = make_rotZ(50); //rotate
  matrix_mult(transform, edges);
  draw_lines(edges, s, c);

  display(s);
  save_extension(s, "lines.png");
  //end testing

}
