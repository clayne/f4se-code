#pragma once

namespace RE
{
	class NiUpdateData
	{
	public:

		struct AutoFadeNodeDepth
		{
		public:
			//members
			NiUpdateData* rData;
		};

		//members
		float fTime;
		std::uint32_t RenderUseDepth;
		bool bParentsChecked;
		NiCamera* pCamera;
		std::uint32_t Flags;
		std::uint32_t RenderObjects;
		std::uint32_t FadeNodeDepth;
	};
}