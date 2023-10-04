#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  first open file and read binary. Then create struct for points, locate all points, add distance between points,
find perimeter*/

  typedef struct Point {
    int x_value;
    int y_value;
  } Point;

void findperimeter(FILE* binary_file) {
  int num_points = 0;
  fread(&num_points, sizeof(int), 1, binary_file);  //  read the number of points in binary file
  Point pointsarray[num_points];  //  create array to store points from file
  for (int i = 0; i < num_points; ++i) {  //  save points into this file
    fread(&pointsarray[i].x_value, sizeof(int), 1, binary_file);
    fread(&pointsarray[i].y_value, sizeof(int), 1, binary_file);
  }
  // find the perimeter with the given points
  double total = 0;
  double counter = 0;
  double  xtotal = 0;
  double ytotal = 0;
  for (int i = 0; i < num_points - 1; ++i) {
    xtotal = pow(pointsarray[i+1].x_value - pointsarray[i].x_value, 2);
    ytotal = pow(pointsarray[i+1].y_value - pointsarray[i].y_value, 2);
    counter = sqrt(xtotal + ytotal);
    total += counter;
  }
  xtotal = pow(pointsarray[num_points - 1].x_value - pointsarray[0].x_value, 2);
  ytotal = pow(pointsarray[num_points - 1].y_value - pointsarray[0].y_value, 2);
  counter = sqrt(xtotal + ytotal);
  total += counter;

//  print out the perimeter
  printf("The perimeter is %.2f\n", total);
}


int main(int argc, char** argv) {
  FILE* binary_file = fopen(argv[1], "rb");
  findperimeter(binary_file);
  fclose(binary_file);
}
