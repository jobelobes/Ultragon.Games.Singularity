#include "networking\Singularity.Networking.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Networking
	{
		#pragma region Static Variables
		IPAddress IPAddress::Broadcast = IPAddress("255.255.255.255");
		IPAddress IPAddress::Loopback = IPAddress("127.0.0.1");
		#pragma endregion

		#pragma region Constructors and Finalizers
		IPAddress::IPAddress(String address)
		{
			String substr;
			unsigned offset;

			for(int i = 0; i < 3; i++)
			{
				offset = address.find(".");
				this->m_iValues[i] = (unsigned char)atoi(address.substr(0, offset).c_str());
				address = address.substr(offset + 1);
			}
			this->m_iValues[3] = (unsigned char)atoi(address.c_str());
		}

		IPAddress::IPAddress(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4)
		{
			this->m_iValues[0] = v1;
			this->m_iValues[1] = v2;
			this->m_iValues[2] = v3;
			this->m_iValues[3] = v4;
		}
		#pragma endregion

		#pragma region Methods
		String IPAddress::ToString() const
		{
			String output;
			char value[4];

			_itoa_s((int)m_iValues[0], &value[0], 4, 10);
			output.append(value);
			output.append(".");

			_itoa_s((int)m_iValues[1], &value[0], 4, 10);
			output.append(value);
			output.append(".");

			_itoa_s((int)m_iValues[2], &value[0], 4, 10);
			output.append(value);
			output.append(".");

			_itoa_s((int)m_iValues[3], &value[0], 4, 10);
			output.append(value);

			return output;
		}
		#pragma endregion
	}
}