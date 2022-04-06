#pragma once
#include <windows.h>


class RecvProp;

class RecvTable
{
public:
	RecvProp* m_pProps;
	int	m_nProps;
	void* m_pDecoder;
	const char* m_pNetTableName;
	bool m_bInitialized;
	bool m_bInMainList;
};

class RecvProp
{
public:
	const char* m_pVarName;
	void* m_RecvType;
	int	m_Flags;
	int	m_StringBufferSize;
	bool m_bInsideArray;
	const void* m_pExtraData;
	RecvProp* m_pArrayProp;
	void* m_ArrayLengthProxy;
	void* m_ProxyFn;
	void* m_DataTableProxyFn;
	RecvTable* m_pDataTable;
	int	m_Offset;
	int	m_ElementStride;
	int	m_nElements;
	const char* m_pParentArrayPropName;
};



class ClientClass
{
public:
	void* m_pCreateFn;
	void* m_pCreateEventFn;
	char* m_pNetworkName;
	RecvTable* m_pRecvTable;
	ClientClass* m_pNext;
	int	m_ClassID;
	const char* m_pMapClassname;
};