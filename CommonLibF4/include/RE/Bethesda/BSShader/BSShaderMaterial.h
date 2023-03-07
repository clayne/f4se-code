#pragma once
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/NetImmerse/NiPoint2.h"

namespace RE
{
	class BSShaderProperty;

	class BSShaderMaterial : public BSIntrusiveRefCounted
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderMaterial };
		static constexpr auto VTABLE{ VTABLE::BSShaderMaterial };

		enum ShaderTypes
		{
			kDefault = 0,
			kEnvmap,
			kGlowmap,
			kParallax,
			kFace,
			kSkinTint,
			kHairTint,
			kParallaxOcc,
			kLandscape,
			kLODLandscape,
			kSnow,
			kMultiLayerParallax,
			kTreeAnim,
			kLODObjects,
			kMultiIndexSnow,
			kLODObjectsHD,
			kEye,
			kCloud,
			kLODLandscapeNoise,
			kLODLandscapeBlend,
			kDismemberment
		};

		enum MATERIAL_DIFFERENCES
		{
			MD_TYPE = 0x0,
			MD_END = 0x1,
		};


		virtual ~BSShaderMaterial();

		//add
		virtual BSShaderMaterial* Create();
		virtual void CopyMembers(const BSShaderMaterial* other);
		virtual void ComputeCRC32(std::uint32_t, bool);
		virtual BSShaderMaterial* GetDefault();
		virtual std::uint32_t GetFeature();
		virtual std::uint32_t GetType();
		virtual void ReceiveValuesFromRootMaterial(BSShaderProperty* a_property);
		virtual bool DoIsCopy(const BSShaderMaterial* other);

		//members
		NiPoint2 textCoordOffset[2];  // 0C
		NiPoint2 textCoordScale[2];   // 1C
		std::uint32_t unk2C;          // 2C
		std::uint32_t uiHashKey;      // 30
		std::uint32_t uiUniqueCode;   // 34
	};
	static_assert(sizeof(BSShaderMaterial) == 0x38);

	REL::Relocation<BSShaderMaterial*> BSShaderMaterial__pDefault(95118);
}