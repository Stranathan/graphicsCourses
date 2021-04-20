#include "hittableList.hpp"

hittableList::hittableList(){}

hittableList::hittableList(std::shared_ptr<hittable> object)
{ 
    add(object); 
}
void hittableList::clear()
{
    objects.clear();
}
void hittableList::add(std::shared_ptr<hittable> object) 
{
    objects.push_back(object);
}
bool hittableList::hit(const ray& r, float tMin, float tMax, hitRecord& rec) const
{
    bool hit_anything = false;
    float closestSoFar = tMax;
    
    // each hittable geometry (just spheres for right now) will constrain parameter
    // to be between tMin and tMAx, so the closest object will always come out on top
    // if you feed the hit function the updated closestSoFar as tMAx
    for (auto& object : objects)
    {
        if (object->hit(r, tMin, closestSoFar, rec))
        {
            // our new tMax to maintain painter's algorithm:
            closestSoFar = rec.t;
            hit_anything = true;
        }
    }
    return hit_anything;
}