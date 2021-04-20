#pragma once


#include <memory>
#include <vector>

#include "hittable.hpp"

using std::shared_ptr;
using std::make_shared;

class hittableList : public hittable
{
    public:
        //
        std::vector<shared_ptr<hittable> > objects;
        //
        hittableList();
        hittableList(shared_ptr<hittable> object);
        //
        void clear();
        void add(shared_ptr<hittable> object);
        virtual bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) const override;

    public:
};
