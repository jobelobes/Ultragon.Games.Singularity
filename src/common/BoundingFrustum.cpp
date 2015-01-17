#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Constructors and Finalizers
	BoundingFrustum::BoundingFrustum() { }

	BoundingFrustum::BoundingFrustum(const Vector3& v0, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, const Vector3& v5, const Vector3& v6, const Vector3& v7)
	{
		this->Corners[0] = Vector3(v0);
		this->Corners[1] = Vector3(v1);
		this->Corners[2] = Vector3(v2);
		this->Corners[3] = Vector3(v3);
		this->Corners[4] = Vector3(v4);
		this->Corners[5] = Vector3(v5);
		this->Corners[6] = Vector3(v6);
		this->Corners[7] = Vector3(v7);
	}

	BoundingFrustum::~BoundingFrustum() { }
	#pragma endregion

	#pragma region Methods
	const ContainmentType BoundingFrustum::Contains(const BoundingBox& value) const
	{
		return ContainmentType::Disjoint;
	}
	
	const ContainmentType BoundingFrustum::Contains(const BoundingSphere& value) const
	{
		return ContainmentType::Disjoint;
	}

	const ContainmentType BoundingFrustum::Contains(const BoundingFrustum& value) const
	{
		return ContainmentType::Disjoint;
	}

	const ContainmentType BoundingFrustum::Contains(const Vector3& value) const
	{
		return ContainmentType::Disjoint;
	}

	void BoundingFrustum::Offset(const Vector3& offset)
	{
		
	}
	#pragma endregion

	#pragma region Operator Methods
	bool BoundingFrustum::operator==(const BoundingFrustum& value)
	{
		return false;
	}

	bool BoundingFrustum::operator!=(const BoundingFrustum& value)
	{
		return true;
	}
	#pragma endregion

	#pragma region Static Methods
	BoundingFrustum BoundingFrustum::CreateMerged(const BoundingFrustum& box1, const BoundingFrustum& box2)
	{
		return BoundingFrustum();
	}
	#pragma endregion
}
