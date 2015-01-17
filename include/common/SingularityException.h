#include "common\Singularity.Common.h"

namespace Singularity
{
	typedef boost::error_info<struct tag_errno, int> errno_info;
	typedef boost::error_info<struct tag_message, String> message_info;
	typedef boost::error_info<struct tag_filepath, String> filepath_info;

	struct SingularityException : virtual std::exception, virtual boost::exception
	{
		#pragma region Variables
		String Message;
		int ErrorCode;
		#pragma endregion

		#pragma region Constructors and Finalizers
		SingularityException(String message, int errorcode = 0);
		virtual ~SingularityException() throw() { }
		#pragma endregion

		#pragma region Overriden Methods
		const char* what();
		#pragma endregion
	};
}