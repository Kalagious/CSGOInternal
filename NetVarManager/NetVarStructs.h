#pragma once
#include <windows.h>


class RecvProp;

class RecvTable
{
public:
	RecvProp* m_pProps;
	uint32_t	m_nProps;
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
	uint32_t	m_Flags;
	uint32_t	m_StringBufferSize;
	bool m_bInsideArray;
	const void* m_pExtraData;
	RecvProp* m_pArrayProp;
	void* m_ArrayLengthProxy;
	void* m_ProxyFn;
	void* m_DataTableProxyFn;
	RecvTable* m_pDataTable;
	uint32_t	m_Offset;
	uint32_t	m_ElementStride;
	uint32_t	m_nElements;
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
	uint32_t	m_ClassID;
	const char* m_pMapClassname;
};