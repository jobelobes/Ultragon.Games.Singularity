#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		class IPAddress
		{
			private:
				#pragma region Variables
				unsigned char	m_iValues[4];
				#pragma endregion

			public:
				#pragma region Static Variables
				static IPAddress Broadcast;
				static IPAddress Loopback;
				#pragma endregion

				#pragma region Constructors and Finalizers
				IPAddress() { };
				IPAddress(String address);
				IPAddress(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
				~IPAddress() { };
				#pragma endregion

				#pragma region Methods
				unsigned char* GetAddressBytes() { return &this->m_iValues[0]; };
				unsigned char GetAddressByte(unsigned index) { return this->m_iValues[index]; };
				String ToString() const;
				#pragma endregion
		};
	}
}