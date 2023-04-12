#pragma once

#include "RE/Havok/Common/Base/Types/hkBaseTypes.h"
#include "RE/Havok/Common/Base/Math/Vector/hkVector4f.h"

namespace RE
{
	struct hknpCharacterSurfaceInfo
	{
	public:
		enum class SupportedState
		{
			kUnsupported,
			kSliding,
			kSupported
		};

		hkBool isSurfaceDynamic;                              // 00
		hkEnum<SupportedState, std::uint8_t> supportedState;  // 01
		float surfaceDistanceExcess;                          // 04
		hkVector4f surfaceNormal;                             // 10
		hkVector4f surfaceVelocity;                           // 20
	};
	static_assert(sizeof(hknpCharacterSurfaceInfo) == 0x30);
}
