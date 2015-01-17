#include "common\Singularity.Common.h"

#pragma region Static Variables
const Bounds Bounds::Empty = Bounds(Vector3(0.0f,0.0f,0.0f), Vector3(1.0f,1.0f,1.0f));
#pragma endregion

#pragma region Constructors and Finalizers
Bounds::Bounds(const float& cx, const float& cy, const float& cz, const float& sx, const float& sy, const float& sz)
	: Center(cx,cy,cz), Size(sx,sy,sz) { }
Bounds::Bounds(const Vector3& center, const Vector3& size)
	: Center(center), Size(size) { }
#pragma endregion

#pragma region Methods
void Bounds::SetMinMax(const Vector3& min, const Vector3& max)
{
	this->Size = max - min;
	this->Center = min + this->Size * 0.5f;
}

void Bounds::Encapsulate(const Vector3& point)
{
	Vector3 min = this->Get_Min();
	Vector3 max = this->Get_Min();

	if(point > min && point < max)
		return;
	else if(point < min)
		min = point;
	else
		max = point;
	
	this->SetMinMax(min, max);
}

void Bounds::Expand(const float amount)
{
	this->Size.x += amount;
	this->Size.y += amount;
	this->Size.z += amount;
}

void Bounds::Expand(const Vector3 amount)
{
	this->Size.x += amount.x;
	this->Size.y += amount.y;
	this->Size.z += amount.z;
}

const bool Bounds::Contains(const Vector3& point) const
{
	Vector3 min = this->Get_Min();
	Vector3 max = this->Get_Max();

	return (point.x >= min.x && point.y >= min.y && point.z >= min.z && point.x < max.x && point.y < max.y && point.z < max.z);
}

const float Bounds::SqrDistance(const Vector3& point) const
{
	return 0.0f;
}
#pragma endregion

#pragma region Operator Methods
bool Bounds::operator==(const Bounds& value)
{
	return (this->Center == value.Center) && (this->Size == value.Size);
}

bool Bounds::operator!=(const Bounds& value)
{
	return (this->Center != value.Center) || (this->Size != value.Size);
}
#pragma endregion