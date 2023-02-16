#pragma once
#include "RE/Bethesda/BSPortalGraph.h"
#include "RE/NetImmerse/NiCullingProcess.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class NiVisibleArray;
	class NiAccumulator;
	class BSCompoundFrustum;

	class BSCullingProcess : public NiCullingProcess
	{
	public:
		static constexpr auto RTTI{ RTTI::BSCullingProcess };
		static constexpr auto VTABLE{ VTABLE::BSCullingProcess };

		enum BSCPCullingType
		{
			kNormal = 0,
			kAllPass = 1,
			kAllFail = 2,
			kIgnoreMultiBounds = 3,
			kForceMultiBoundsNoUpdate = 4
		};

		BSCullingProcess() = delete;
		BSCullingProcess(NiVisibleArray* a_array) :
			NiCullingProcess(0)
		{
			ctor(a_array);
		};
		//virtual void GetRTTI();
		//virtual void IsNode();
		//virtual void IsNode2();
		//virtual void IsSwitchNode();
		//virtual void IsFadeNode();
		//virtual void IsMultiBoundNode();
		//virtual void IsGeometry();
		//virtual void IsTriStrips();
		//virtual void IsTriShape();
		//virtual void IsDynamicTriShape();
		//virtual void IsSegmentedTriShape();
		//virtual void IsSubIndexTriShape();
		//virtual void IsNiGeometry();
		//virtual void IsNiTriBasedGeom();
		//virtual void IsNiTriShape();
		//virtual void IsParticlesGeom();
		//virtual void IsParticleSystem();
		//virtual void IsLinesGeom();
		//virtual void IsLight();
		//virtual void IsBhkNiCollisionObject();
		//virtual void IsBhkBlendCollisionObject();
		//virtual void IsBhkRigidBody();
		//virtual void IsBhkLimitedHingeConstraint();
		//virtual void IsbhkNPCollisionObject();
		//virtual ~BSCullingProcess();
		//virtual void Process();
		//virtual void Process2();
		//virtual void AppendVirtual();

		//add
		virtual void AppendNonAccum(){};
		virtual void TestBaseVisibility_BSMultiBound(){};
		virtual void TestBaseVisibility_BSOcclusionPlane(){};
		virtual void TestBaseVisibility_NiBound(){};

		void SetAccumulator(NiAccumulator* accumulator) {}

		//members
		std::uint32_t field_128;
		std::uint32_t field_12C;
		std::uint32_t field_130;
		std::uint32_t field_134;
		void* field_138;
		std::uint64_t gap140;
		std::uint64_t field_148;
		BSPortalGraphEntry* QPortalGraphEntry;
		BSCPCullingType CullingType;
		std::uint8_t gap15C[40];
		std::uint32_t field_184;
		BSCompoundFrustum* field_188;
		NiPointer<NiAccumulator> Accumulator;
		bool QRecurseToGeometry;

	private:
		BSCullingProcess* ctor(NiVisibleArray* a_array)
		{
			using func_t = decltype(&BSCullingProcess::ctor);
			REL::Relocation<func_t> func{ REL::ID(423200) };
			return func(this, a_array);
		};
	};
	//static_assert(sizeof(BSCullingProcess) == 0x1A0);
}