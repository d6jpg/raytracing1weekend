#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>
using namespace std;

void write_color(ostream &out, color pixel_color, int samples_per_pixel){  
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  auto scale = 1.0 / samples_per_pixel;
  r *= scale;
  g *= scale;
  b *= scale;
  r = sqrt(r);
  g = sqrt(g);
  b = sqrt(b);

  /*
  out << static_cast<int>(255.999 * pixel_color.x()) << ' '
      << static_cast<int>(255.999 * pixel_color.y()) << ' '
      << static_cast<int>(255.999 * pixel_color.z()) << '\n';
  */
  out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

#endif
