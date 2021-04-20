#pragma once


#include "utils.hpp"
#include "vec3.hpp"
#include "hittable.hpp"

//using std::shared_ptr;
using std::make_shared;

class hittableList : public hittable
{
    public:
        //
        std::vector<std::shared_ptr<hittable> > objects;
        //
        hittableList();
        hittableList(std::shared_ptr<hittable> object);
        //
        void clear();
        void add(std::shared_ptr<hittable> object);
        virtual bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) const override;

    public:
};
