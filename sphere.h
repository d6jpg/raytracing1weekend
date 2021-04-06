#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable{
public:
  sphere() {}
  sphere(point3 cen, double r) : center(cen), radius(r){};

  virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
  point3 center;
  double radius;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
  vec3 oc = r.origin() - center;
  auto a = r.direction().length_squared();
  auto half_b = dot(r.direction(), oc);
  auto c = oc.length_squared() - radius * radius;
  auto discriminant = half_b * half_b - a * c;
  if(discriminant < 0)return false;

  // find the nearest root(answer) that lies in the acceptable range.
  auto root = (-half_b - sqrt(discriminant)) / a;
  if(root < t_min || t_max < root){
    root = (-half_b + sqrt(discriminant)) / a;
    if(root < t_min || t_max < root)return false;
  }

  rec.t = root;
  rec.p = r.at(root);
  rec.normal = (rec.p - center) / radius;

  return true;
}
  
#endif
		 
