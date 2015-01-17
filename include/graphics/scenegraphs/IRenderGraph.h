#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		class IRenderGraph
		{
			private:
				#pragma region Variables
				bool	m_bSuspendUpdate;
				#pragma endregion

			protected:
				#pragma region Event Methods
				virtual void OnUpdate(bool force) = 0;
				#pragma endregion

			public:
				#pragma region Methods
				virtual void Add(Renderer* object) = 0;
				virtual void Remove(Renderer* object) = 0;

				inline void Update(bool force = false) { if(!this->m_bSuspendUpdate) this->OnUpdate(force); };
				
				inline void BeginUpdate() { this->m_bSuspendUpdate = true; };
				inline void EndUpdate(bool force = false) { if(this->m_bSuspendUpdate) this->OnUpdate(force); };

				virtual IRenderIterator* Contains(const Bounds& box) = 0;
				#pragma endregion
		};
	}
}