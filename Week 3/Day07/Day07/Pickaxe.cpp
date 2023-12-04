#include "Pickaxe.h"

Material Pickaxe::GetMaterial() const
{
    return material_;
}

void Pickaxe::SetMaterial(Material material)
{
    material_ = material; //field = parameter
}
