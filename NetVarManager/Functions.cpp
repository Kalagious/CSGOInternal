#include "General.h"

uintptr_t getOffset(RecvTable* table, std::string tableName, std::string netVarName)
{
	for (uint32_t i = 0; i < table->m_nProps; i++)
	{
		RecvProp prop = table->m_pProps[i];

		if (!_stricmp(netVarName.c_str(), prop.m_pVarName))
		{
			return prop.m_Offset;
		}

		if (prop.m_pDataTable)
		{
			uintptr_t offset = getOffset(prop.m_pDataTable, tableName, netVarName);

			if (offset)
				return offset + prop.m_Offset;
		}
	}
	return 0;
}