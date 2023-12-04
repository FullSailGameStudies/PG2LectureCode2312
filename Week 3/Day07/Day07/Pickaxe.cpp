#include "Pickaxe.h"

Material Pickaxe::GetMaterial() const
{
    return material_;
}

void Pickaxe::SetMaterial(Material material)
{
    material_ = material; //field = parameter
}

bool Pickaxe::Swing(int x, int y, int z)
{
    return false;
}
