// Final Project Milestone 2 - Error Class
// Version 3.4
// Error.h
// Date	2018-11-09
// Author Anmol Singh 147528178
// Description
// This is the  declarations of the Error class including all variables and functions along with helper functions.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// CS                 2017-10-11           Fall semester upgrade
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           Message -> State
/////////////////////////////////////////////////////////////////
#pragma once
namespace aid 
{
	class Error 
	{
			char* m_message;

			public:

			Error();
			explicit Error(const char*);
			Error(const Error& em) = delete;
			Error& operator=(const Error& em) = delete;
			virtual ~Error();
			void clear();
			bool isClear() const;
			void message(const char* str);
			const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, const Error& em);
}
