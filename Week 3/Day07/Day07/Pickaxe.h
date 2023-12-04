#pragma once
enum Material
{
	Wood, Gold, Stone, Iron, Diamond, Netherite
};
class Pickaxe //class interface
{
	//DECLARE the parts of a class
	// 
	//what can the class DO (methods or member functions)
	// 
	//what describes the class (variables)
	//	called fields or data members

	//material, durability, strength

public:
	//getter methods (accessors to fields)
	Material GetMaterial() const;
	float Durability() const { return durability_; }

	//setter methods (mutators of the fields) change your fields
	void SetMaterial(Material material);
	void Durability(float durability) { 
		if(durability >= 0 && durability <= 100) //constraints
			durability_ = durability; 
	}
protected:
private:
	Material material_; //field (data member)
	float durability_;

	void someMethod()
	{
		Material material = material_;
	}
public:
protected:
private:
};

