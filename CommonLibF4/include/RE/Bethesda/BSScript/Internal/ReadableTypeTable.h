#pragma once

#include "RE/Bethesda/BSCore/BSScrapArray.h"
#include "RE/Bethesda/BSCore/BSTScrapHashMap.h"
#include "RE/Bethesda/BSSystem/BSFixedString.h"
#include "RE/Bethesda/BSSystem/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class ReadableTypeTable
			{
			public:
				struct SaveTypeInfo :
					public BSIntrusiveRefCounted  // 00
				{
				public:
					// members
					BSFixedString parentType;                      // 08
					BSScrapArray<std::uint32_t> variableIndicies;  // 10
				};
				static_assert(sizeof(SaveTypeInfo) == 0x30);

				// members
				BSTScrapHashMap<BSFixedString, BSTSmartPointer<SaveTypeInfo>>* saveTypeInfo;  // 00
			};
			static_assert(sizeof(ReadableTypeTable) == 0x08);
		}
	}
}
