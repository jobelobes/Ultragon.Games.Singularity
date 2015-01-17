#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Constructors and Finalizers
	BoundingSphere::BoundingSphere()
		: Centerpoint(0.0f,0.0f,0.0f), Radius(0.0f) { }

	BoundingSphere::BoundingSphere(const Vector3& centerpoint, const float radius)
		: Centerpoint(centerpoint), Radius(radius) { }

	BoundingSphere::~BoundingSphere() { }
	#pragma endregion

	#pragma region Methods
	const ContainmentType BoundingSphere::Contains(const BoundingBox& value) const
	{
		Vector3 vector;
		if (!value.Contains(*this) == ContainmentType::Disjoint)
			return ContainmentType::Disjoint;

		float radiusSquared = this->Radius * this->Radius;
		vector.x = this->Centerpoint.x - value.Min.x;
		vector.y = this->Centerpoint.y - value.Max.y;
		vector.z = this->Centerpoint.z - value.Max.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Max.x;
		vector.y = this->Centerpoint.y - value.Max.y;
		vector.z = this->Centerpoint.z - value.Max.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Max.x;
		vector.y = this->Centerpoint.y - value.Min.y;
		vector.z = this->Centerpoint.z - value.Max.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Min.x;
		vector.y = this->Centerpoint.y - value.Min.y;
		vector.z = this->Centerpoint.z - value.Max.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Min.x;
		vector.y = this->Centerpoint.y - value.Max.y;
		vector.z = this->Centerpoint.z - value.Min.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Max.x;
		vector.y = this->Centerpoint.y - value.Max.y;
		vector.z = this->Centerpoint.z - value.Min.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Max.x;
		vector.y = this->Centerpoint.y - value.Min.y;
		vector.z = this->Centerpoint.z - value.Min.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		vector.x = this->Centerpoint.x - value.Min.x;
		vector.y = this->Centerpoint.y - value.Min.y;
		vector.z = this->Centerpoint.z - value.Min.z;
		if (D3DXVec3LengthSq(&vector) > radiusSquared)
			return ContainmentType::Intersects;

		return ContainmentType::Contains;
	}
	
	const ContainmentType BoundingSphere::Contains(const BoundingSphere& value) const
	{
		Vector3 vector = this->Centerpoint - value.Centerpoint;
		float distance = D3DXVec3Length(&vector);

		if ((this->Radius + value.Radius) < distance)
			return ContainmentType::Disjoint;
		if ((this->Radius - value.Radius) < distance)
			return ContainmentType::Intersects;
		return ContainmentType::Contains;
	}

	const ContainmentType BoundingSphere::Contains(const BoundingFrustum& value) const
	{
		Vector3 vector;
		unsigned index;

		if (value.Contains(*this) == ContainmentType::Disjoint)
			return ContainmentType::Disjoint;

		float radiusSquared = this->Radius * this->Radius;
		for(index = 0; index < 8; index++)
		{
			vector = value.Corners[index] - this->Centerpoint;
			if (D3DXVec3LengthSq(&vector) > radiusSquared)
				return ContainmentType::Intersects;
		}
		return ContainmentType::Contains;
	}

	const ContainmentType BoundingSphere::Contains(const Vector3& value) const
	{
		Vector3 vector = value - this->Centerpoint;
		if( D3DXVec3LengthSq(&vector) >= (this->Radius * this->Radius))
			return ContainmentType::Disjoint;
		return ContainmentType::Contains;
	}

	void BoundingSphere::Offset(const Vector3& offset)
	{
		this->Centerpoint += offset;
	}
	#pragma endregion

	#pragma region Operator Methods
	bool BoundingSphere::operator==(const BoundingSphere& value)
	{
		return (this->Centerpoint == value.Centerpoint)	&& (this->Radius == value.Radius);
	}

	bool BoundingSphere::operator!=(const BoundingSphere& value)
	{
		return (this->Centerpoint.x != value.Centerpoint.x)
			|| (this->Centerpoint.y != value.Centerpoint.y)
			|| (this->Centerpoint.z != value.Centerpoint.z)
			|| (this->Radius != value.Radius);
	}
	#pragma endregion

	#pragma region Static Methods
	BoundingSphere BoundingSphere::CreateMerged(const BoundingSphere& box1, const BoundingSphere& box2)
	{
		Vector3 vector;
		float length, tmpVal1, tmpVal2;

		vector = box2.Centerpoint - box1.Centerpoint;
		length = D3DXVec3Length(&vector);

		if ((box1.Radius + box2.Radius) >= length)
		{
			if ((box1.Radius - box2.Radius) >= length)
				return box1;

			if ((box2.Radius - box1.Radius) >= length)
				return box2;
		}

		vector = vector * (1.0f / length);
		tmpVal1 = min(-box1.Radius, length - box1.Radius);
		tmpVal2 = (max(box1.Radius, length + box1.Radius) - tmpVal1) * 0.5f;
		return BoundingSphere(box1.Centerpoint + vector * (tmpVal2 + tmpVal1), tmpVal2);
	}
	#pragma endregion
}
