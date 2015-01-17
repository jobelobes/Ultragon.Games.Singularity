#include "common\Singularity.Common.h"

namespace Singularity
{
	#pragma region Constructors and Finalizers
	SingularityException::SingularityException(String message, int errorcode)
		: Message(message), ErrorCode(errorcode)
	{
		switch(this->ErrorCode)
		{
			case D3D10_ERROR_FILE_NOT_FOUND:
				this->Message.append("The file was not found.");
				break;
			case D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS:
				this->Message.append("There are too many unique instances of a particular type of state object.");
				break;
			case D3DERR_INVALIDCALL:
				this->Message.append("The method call is invalid. For example, a method's parameter may not be a valid pointer.");
				break;
			case D3DERR_WASSTILLDRAWING:
				this->Message.append("The previous blit operation that is transferring information to or from this surface is incomplete.");
				break;
			case E_FAIL:
				this->Message.append("Attempted to create a device with the debug layer enabled and the layer is not installed.");
				break;
			case E_INVALIDARG:
				this->Message.append("An invalid parameter was passed to the returning function.");
				break;
			case E_OUTOFMEMORY:
				this->Message.append("Direct3D could not allocate sufficient memory to complete the call.");
				break;
		}

		(*this) << message_info(this->Message) 
			<< errno_info(this->ErrorCode) 
			<< ::boost::throw_function(BOOST_CURRENT_FUNCTION) 
			<< ::boost::throw_file(__FILE__) 
			<< ::boost::throw_line((int)__LINE__);
	}
	#pragma endregion

	#pragma region Overriden Methods
	const char* SingularityException::what()
	{
		return this->Message.c_str();
	}
	#pragma endregion
}