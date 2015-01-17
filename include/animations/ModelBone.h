#include "animations\Singularity.Animations.h"

namespace Singularity
{
	namespace Graphics
	{
		class ModelBone
		{
			private:
				#pragma region Variables
				DynamicList<ModelBone*>		m_pChildren;
				ModelBone*					m_pParent;
				int							m_iIndex;
				String						m_sName;

				Matrix						m_pBindPose;
				Matrix						m_pInvBindPose;
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				ModelBone(int index, String name) { }
				~ModelBone() { }
				#pragma endregion

				#pragma region Methods
				void Initialize() {}
				inline void AddChild(ModelBone* value) { this->m_pChildren.push_back(value); }
				inline void SetBindPoses(Matrix bindPose, Matrix invBindPose)
				{
					this->m_pBindPose = bindPose;
					this->m_pInvBindPose = invBindPose;
				}
				#pragma endregion

				#pragma region Properties
				inline DynamicList<ModelBone*> Get_Children() { return this->m_pChildren; }
				inline int Get_ChildCount() { return this->m_pChildren.size(); }

				inline ModelBone* Get_Parent() { return this->m_pParent; }

				inline int Get_Index() { return this->m_iIndex; }
				
				inline String Get_Name() { return this->m_sName; }
				
				inline Matrix Get_BindPose() { return this->m_pBindPose; }
				
				inline Matrix Get_InvBindPose() { return this->m_pInvBindPose; }
				#pragma endregion
		};
	}
}