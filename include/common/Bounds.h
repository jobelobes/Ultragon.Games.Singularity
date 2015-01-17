#include "common\Singularity.Common.h"

class Bounds
{
	public:
		#pragma region Static Variables
		static const Bounds Empty;
		#pragma endregion

		#pragma region Variables
		Vector3 Center;
		Vector3 Size;
		#pragma endregion

		#pragma region Properties
		inline const Vector3 Get_Min() const { return Vector3(this->Center - this->Size * 0.5f); };
		inline const Vector3 Get_Max() const { return Vector3(this->Center + this->Size * 0.5f); };
		#pragma endregion

		#pragma region Constructors and Finalizers
		Bounds(const float& cx, const float& cy, const float& cz, const float& sx, const float& sy, const float& sz);
		Bounds(const Vector3& center = Vector3(0,0,0), const Vector3& size = Vector3(0,0,0));
		~Bounds() { }
		#pragma endregion

		#pragma region Methods
		void SetMinMax(const Vector3& min, const Vector3& max);
		void Encapsulate(const Vector3& point);
		void Expand(const float amount);
		void Expand(const Vector3 amount);

		const bool Contains(const Vector3& point) const;
		const float SqrDistance(const Vector3& point) const;
		#pragma endregion

		#pragma region Opertator Overriden Methods
		bool operator==(const Bounds& value);
		bool operator!=(const Bounds& value);
		#pragma endregion
};
