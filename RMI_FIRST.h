#include "MRI.h"

#define MAKESTRING(str) #str
#define JOINSTRING4(str1, str2, str3, str4) MAKESTRING(str1##str2##str3##str4)

template<typename classname>
class ClientCalculate : public RMIServerBase
{
public:

	ClientCalculate()
	{
	}

private:

	std::string mServerClassName;
	//TServer* pMServer;

	void CallLocalFunction(const char* pFuncID, void* paraList, int paraListLength, SOCKET socket)
	{
		std::string funTempID;
		if (strcmp(JOINSTRING4(int, sum, int, int), pFuncID) == 0)
		{
			int mintsum = pMServer->FunName();
			SendResponse(&mintsum, sizeof(mintsum), socket);
			return ;
		}
	}
};
