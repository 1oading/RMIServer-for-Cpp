class MYIDENTIFYCLASS{};

struct RemoteFunctionStub
{
	std::string mFunctionID;
	int mParaCount;
	void* mReturnValue;
	int mReturnValueLength;
	int mStructLength;
	void* pPara;
};

template<
typename ReturnValue,
typename P1 = MYIDENTIFYCLASS,
typename P2 = MYIDENTIFYCLASS>
class FunctionObject
{
public:
	FunctionObject()
	{
		mParaCount = 2;
	}

	ReturnValue operator() (const char* tRomateFunction, RMIClientBase* pClient, P1 p1, P2 p2)
	{
		ReturnValue r;
		mStub.mFunctionID = tRomateFunction;

		mStub.mReturnValue = (void*)&r;
		mStub.mReturnValueLength = sizeof(ReturnValue);

		mUnionList[0].p1 = p1;
		mUnionList[0].p2 = p2;

		mStub.mPara = (void*)mUnionList;
		mStub.mParaCount = mParaCount;
		mStub.mStructLength = sizeof(UNIONTYPE) * mParaCount - 1;

		pClient->CallRemoteFunction(&mStub);
		return r;
	}

private:

	int mParaCount;
	union UNIONTYPE {
		ReturnValue mReturnValue;
		P1 p1;
		P2 p2;
	};

	UNIONTYPE mUnionList[3];
	RemoteFunctionStub mStub;
};

class RMIServerBase
{
public:
	RMIServerBase();
	~RMIServerBase();

	bool listen(int tPort);

	bool SendResponse(void* pV, int L, SOCKET socket);

	virtual void CallLocalFunction(const char* pFuncID, void* paraList,int paraListLength, SOCKET socket);

	bool stop();

private:
	
};
