#pragma once

namespace RE
{
	namespace BSGraphics
	{
		enum AlphaBlendAlphaToCoverage : std::int32_t
		{
			ALPHA_BLEND_ALPHA_TO_COVERAGE_DISABLED = 0x0,
			ALPHA_BLEND_ALPHA_TO_COVERAGE_ENABLED = 0x1,
			ALPHA_BLEND_ALPHA_TO_COVERAGE_COUNT = 0x2,
			ALPHA_BLEND_ALPHA_TO_COVERAGE_DEFAULT = 0x0,
		};

		enum AlphaBlendMode : std::int32_t
		{
			ALPHA_BLEND_MODE_DISABLED = 0x0,
			ALPHA_BLEND_MODE_SRCALPHA_INVSRCALPHA = 0x1,
			ALPHA_BLEND_MODE_SRCALPHA_ONE = 0x2,
			ALPHA_BLEND_MODE_DEST_ZERO = 0x3,
			ALPHA_BLEND_MODE_ONE_INVSRCALPHA = 0x4,
			ALPHA_BLEND_MODE_ONE_ONE = 0x5,
			ALPHA_BLEND_MODE_WEAPON_BLOOD = 0x6,
			ALPHA_BLEND_MODE_COUNT = 0x7,
			ALPHA_BLEND_MODE_DEFAULT = 0x0,
		};

		enum AlphaBlendWriteMode : std::int32_t
		{
			ALPHA_BLEND_WRITE_MODE_DISABLED = 0x0,
			ALPHA_BLEND_WRITE_MODE_DEFAULT = 0x1,
			ALPHA_BLEND_WRITE_MODE_RGB = 0x1,
			ALPHA_BLEND_WRITE_MODE_RGBA = 0x2,
			ALPHA_BLEND_WRITE_MODE_RG = 0x3,
			ALPHA_BLEND_WRITE_MODE_BA = 0x4,
			ALPHA_BLEND_WRITE_MODE_R = 0x5,
			ALPHA_BLEND_WRITE_MODE_G = 0x6,
			ALPHA_BLEND_WRITE_MODE_B = 0x7,
			ALPHA_BLEND_WRITE_MODE_A = 0x8,
			ALPHA_BLEND_WRITE_MODE_A_TARGET0 = 0x9,
			ALPHA_BLEND_WRITE_MODE_A_TARGET1 = 0xA,
			ALPHA_BLEND_WRITE_MODE_A_TARGET2 = 0xB,
			ALPHA_BLEND_WRITE_MODE_A_TARGET3 = 0xC,

			ALPHA_BLEND_WRITE_MODE_COUNT
		};

		enum Format
		{
			FORMAT_NONE,
			FORMAT_R32G32B32A32_TYPELESS,
			FORMAT_R32G32B32A32_FLOAT,
			FORMAT_R32G32B32A32_UINT,
			FORMAT_R32G32B32A32_SINT,
			FORMAT_R32G32B32_TYPELESS,
			FORMAT_R32G32B32_FLOAT,
			FORMAT_R32G32B32_UINT,
			FORMAT_R32G32B32_SINT,
			FORMAT_R16G16B16A16_TYPELESS,
			FORMAT_R16G16B16A16_FLOAT,
			FORMAT_R16G16B16A16_UNORM,
			FORMAT_R16G16B16A16_UINT,
			FORMAT_R16G16B16A16_SNORM,
			FORMAT_R16G16B16A16_SINT,
			FORMAT_R32G32_TYPELESS,
			FORMAT_R32G32_FLOAT,
			FORMAT_R32G32_UINT,
			FORMAT_R32G32_SINT,
			FORMAT_R32G8X24_TYPELESS,
			FORMAT_D32_FLOAT_S8X24_UINT,
			FORMAT_R32_FLOAT_X8X24_TYPELESS,
			FORMAT_X32_TYPELESS_G8X24_UINT,
			FORMAT_R10G10B10A2_TYPELESS,
			FORMAT_R10G10B10A2_UNORM,
			FORMAT_R10G10B10A2_UINT,
			FORMAT_R11G11B10_FLOAT,
			FORMAT_R8G8B8A8_TYPELESS,
			FORMAT_R8G8B8A8_UNORM,
			FORMAT_R8G8B8A8_UNORM_SRGB,
			FORMAT_R8G8B8A8_UINT,
			FORMAT_R8G8B8A8_SNORM,
			FORMAT_R8G8B8A8_SINT,
			FORMAT_R16G16_TYPELESS,
			FORMAT_R16G16_FLOAT,
			FORMAT_R16G16_UNORM,
			FORMAT_R16G16_UINT,
			FORMAT_R16G16_SNORM,
			FORMAT_R16G16_SINT,
			FORMAT_R32_TYPELESS,
			FORMAT_D32_FLOAT,
			FORMAT_R32_FLOAT,
			FORMAT_R32_UINT,
			FORMAT_R32_SINT,
			FORMAT_R24G8_TYPELESS,
			FORMAT_D24_UNORM_S8_UINT,
			FORMAT_R24_UNORM_X8_TYPELESS,
			FORMAT_X24_TYPELESS_G8_UINT,
			FORMAT_R8G8_TYPELESS,
			FORMAT_R8G8_UNORM,
			FORMAT_R8G8_UINT,
			FORMAT_R8G8_SNORM,
			FORMAT_R8G8_SINT,
			FORMAT_R16_TYPELESS,
			FORMAT_R16_FLOAT,
			FORMAT_D16_UNORM,
			FORMAT_R16_UNORM,
			FORMAT_R16_UINT,
			FORMAT_R16_SNORM,
			FORMAT_R16_SINT,
			FORMAT_R8_TYPELESS,
			FORMAT_R8_UNORM,
			FORMAT_R8_UINT,
			FORMAT_R8_SNORM,
			FORMAT_R8_SINT,
			FORMAT_A8_UNORM,
			FORMAT_R1_UNORM,
			FORMAT_R9G9B9E5_SHAREDEXP,
			FORMAT_R8G8_B8G8_UNORM,
			FORMAT_G8R8_G8B8_UNORM,
			FORMAT_BC1_TYPELESS,
			FORMAT_BC1_UNORM,
			FORMAT_BC1_UNORM_SRGB,
			FORMAT_BC2_TYPELESS,
			FORMAT_BC2_UNORM,
			FORMAT_BC2_UNORM_SRGB,
			FORMAT_BC3_TYPELESS,
			FORMAT_BC3_UNORM,
			FORMAT_BC3_UNORM_SRGB,
			FORMAT_BC4_TYPELESS,
			FORMAT_BC4_UNORM,
			FORMAT_BC4_SNORM,
			FORMAT_BC5_TYPELESS,
			FORMAT_BC5_UNORM,
			FORMAT_BC5_SNORM,
			FORMAT_B5G6R5_UNORM,
			FORMAT_B5G5R5A1_UNORM,
			FORMAT_B8G8R8A8_UNORM,
			FORMAT_B8G8R8X8_UNORM,
			FORMAT_R10G10B10_XR_BIAS_A2_UNORM,
			FORMAT_B8G8R8A8_TYPELESS,
			FORMAT_B8G8R8A8_UNORM_SRGB,
			FORMAT_B8G8R8X8_TYPELESS,
			FORMAT_B8G8R8X8_UNORM_SRGB,
			FORMAT_BC6H_TYPELESS,
			FORMAT_BC6H_UF16,
			FORMAT_BC6H_SF16,
			FORMAT_BC7_TYPELESS,
			FORMAT_BC7_UNORM,
			FORMAT_BC7_UNORM_SRGB,

			FORMAT_COUNT
		};

		enum class TextureAddressMode
		{
			TEXTURE_ADDRESS_MODE_CLAMP_S_CLAMP_T,
			TEXTURE_ADDRESS_MODE_CLAMP_S_WRAP_T,
			TEXTURE_ADDRESS_MODE_WRAP_S_CLAMP_T,
			TEXTURE_ADDRESS_MODE_WRAP_S_WRAP_T,

			TEXTURE_ADDRESS_MODE_COUNT,
		};

		enum TextureFilterMode : std::uint32_t
		{
			TEXTURE_FILTER_MODE_NEAREST,
			TEXTURE_FILTER_MODE_BILERP,
			TEXTURE_FILTER_MODE_TRILERP,
			TEXTURE_FILTER_MODE_ANISO = 3,
			TEXTURE_FILTER_MODE_DEFAULT = 3,
			TEXTURE_FILTER_MODE_COMP_BILERP,

			TEXTURE_FILTER_MODE_COUNT,
		};

		enum RenderTargetMode
		{
			RENDER_TARGET_FRAMEBUFFER = 0x0,
			RENDER_TARGET_FRAMEBUFFER_COUNT = 0x1,
			RENDER_TARGET_MAIN = 0x1,
			RENDER_TARGET_MAIN_COPY = 0x2,
			RENDER_TARGET_MAIN_SAVE_RES = 0x3,
			RENDER_TARGET_SSR_PREPASS = 0x4,
			RENDER_TARGET_SSR = 0x5,
			RENDER_TARGET_SSR_BLURRED0 = 0x6,
			RENDER_TARGET_SSR_BLURRED1 = 0x7,
			RENDER_TARGET_SSR_DEPTH = 0x8,
			RENDER_TARGET_SSR_BLEND = 0x9,
			RENDER_TARGET_WATER_DISPLACEMENT = 0xA,
			RENDER_TARGET_WATER_DISPLACEMENT_SWAP = 0xB,
			RENDER_TARGET_WATER_REFLECTIONS = 0xC,
			RENDER_TARGET_WATER_REFRACTION = 0xD,
			RENDER_TARGET_REFRACTION_NORMALS = 0xE,
			RENDER_TARGET_MENUBG = 0xF,
			RENDER_TARGET_VATS_MASK = 0xF,
			RENDER_TARGET_FACE_CUSTOMIZATION_DIFFUSE = 0x10,
			RENDER_TARGET_FACE_CUSTOMIZATION_NORMALS = 0x11,
			RENDER_TARGET_FACE_CUSTOMIZATION_SMOOTHSPEC = 0x12,
			RENDER_TARGET_LOCAL_MAP = 0x13,
			RENDER_TARGET_COMPANION_LOCAL_MAP = 0x14,
			RENDER_TARGET_COMPANION_LOCAL_MAP_NORM = 0x15,
			RENDER_TARGET_FOG_OF_WAR = 0x16,
			RENDER_TARGET_COMPANION_FOG_OF_WAR = 0x17,
			RENDER_TARGET_HUDGLASS = 0x18,
			RENDER_TARGET_HUDGLASS_SWAP = 0x19,
			RENDER_TARGET_GB_ALBEDO_SPEC = 0x1A,
			RENDER_TARGET_GB_NORMAL = 0x1B,
			RENDER_TARGET_GB_NORMAL_COPY = 0x1C,
			RENDER_TARGET_GB_ENVMAP = 0x1D,
			RENDER_TARGET_GB_AMBIENT_MAT = 0x1E,
			RENDER_TARGET_GB_EMIT = 0x1F,
			RENDER_TARGET_GB_MOTION_VECTORS = 0x20,
			RENDER_TARGET_DFLIGHT = 0x21,
			RENDER_TARGET_DFSPECULAR = 0x22,
			RENDER_TARGET_DFLIGHT_TILED = 0x23,
			RENDER_TARGET_DFSPECULAR_TILED = 0x24,
			RENDER_TARGET_AO = 0x25,
			RENDER_TARGET_AO_SWAP_0 = 0x26,
			RENDER_TARGET_AO_2X = 0x27,
			RENDER_TARGET_SAO_CAMERAZ = 0x28,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_0 = 0x29,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_1 = 0x2A,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_2 = 0x2B,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_3 = 0x2C,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_4 = 0x2D,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_5 = 0x2E,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_6 = 0x2F,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_7 = 0x30,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_8 = 0x31,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_9 = 0x32,
			RENDER_TARGET_SAO_CAMERAZ_MIP_LEVEL_10 = 0x33,
			RENDER_TARGET_SAO_RAW_AO = 0x34,
			RENDER_TARGET_SAO_RAW_AO_2 = 0x35,
			RENDER_TARGET_SAO_TEMP_BLUR = 0x36,
			RENDER_TARGET_SAO_RAW_AO_2X = 0x37,
			RENDER_TARGET_SAO_RAW_AO_2_2X = 0x38,
			RENDER_TARGET_SAO_TEMP_BLUR_2X = 0x39,
			RENDER_TARGET_TEMPORAL_AA_ACCUMULATION_1 = 0x3A,
			RENDER_TARGET_TEMPORAL_AA_ACCUMULATION_2 = 0x3B,
			RENDER_TARGET_PIPBOY = 0x3C,
			RENDER_TARGET_PIPBOY_SWAP = 0x3D,
			RENDER_TARGET_MENU_SCREEN_FULLSIZE = 0x3E,
			RENDER_TARGET_MENU_SCREEN_FULLSIZE_SWAP = 0x3F,
			RENDER_TARGET_MENU_TEXT = 0x40,
			RENDER_TARGET_LENSFLAREVIS = 0x41,
			RENDER_TARGET_GETHIT_BUFFER = 0x42,
			RENDER_TARGET_BLURFULL_BUFFER = 0x43,
			RENDER_TARGET_HDR_BLURSWAP = 0x44,
			RENDER_TARGET_HDR_BLOOM = 0x45,
			RENDER_TARGET_HDR_DOWNSAMPLE0 = 0x46,
			RENDER_TARGET_HDR_DOWNSAMPLE1 = 0x47,
			RENDER_TARGET_HDR_DOWNSAMPLE2 = 0x48,
			RENDER_TARGET_HDR_DOWNSAMPLE3 = 0x49,
			RENDER_TARGET_HDR_DOWNSAMPLE4 = 0x4A,
			RENDER_TARGET_HDR_DOWNSAMPLE5 = 0x4B,
			RENDER_TARGET_HDR_DOWNSAMPLE6 = 0x4C,
			RENDER_TARGET_HDR_DOWNSAMPLE7 = 0x4D,
			RENDER_TARGET_HDR_DOWNSAMPLE8 = 0x4E,
			RENDER_TARGET_HDR_DOWNSAMPLE9 = 0x4F,
			RENDER_TARGET_HDR_DOWNSAMPLE10 = 0x50,
			RENDER_TARGET_HDR_DOWNSAMPLE11 = 0x51,
			RENDER_TARGET_HDR_DOWNSAMPLE12 = 0x52,
			RENDER_TARGET_HDR_DOWNSAMPLE13 = 0x53,
			RENDER_TARGET_DOF_1 = 0x54,
			RENDER_TARGET_DOF_2 = 0x55,
			RENDER_TARGET_RAIN_OCCLUSIONMAP = 0x56,
			RENDER_TARGET_EDITOR_TERRAIN_TEXTURE_GENERATION = 0x57,
			RENDER_TARGET_EDITOR_TERRAIN_TEXTURE_GENERATION_FINAL = 0x58,
			RENDER_TARGET_EDITOR_MAP_MAKER = 0x59,
			RENDER_TARGET_EDITOR_MAP_MAKER_SWAP = 0x5A,
			RENDER_TARGET_GODRAYS_PHASE_LUT = 0x5B,
			RENDER_TARGET_GODRAYS_ACCUMULATION = 0x5C,
			RENDER_TARGET_GODRAYS_RESOLVED = 0x5D,
			RENDER_TARGET_GODRAYS_RESOLVED_DEPTH = 0x5E,
			RENDER_TARGET_GODRAYS_FILTERED_0 = 0x5F,
			RENDER_TARGET_GODRAYS_FILTERED_1 = 0x60,
			RENDER_TARGET_GODRAYS_FILTERED_DEPTH_0 = 0x61,
			RENDER_TARGET_GODRAYS_FILTERED_DEPTH_1 = 0x62,
			RENDER_TARGET_MONITOR_SCREENSHOT = 0x63,

			RENDER_TARGET_COUNT,
		};

		enum RenderTargetCubeMapMode : std::uint32_t
		{
			RENDER_TARGET_CUBEMAP_NONE = 0xFFFFFFFF,
			RENDER_TARGET_CUBEMAP_REFLECTIONS = 0x0,
			RENDER_TARGET_CUBEMAP_COUNT = 0x1,
		};

		enum DepthStencilStencilMode : std::int32_t
		{
			DEPTH_STENCIL_STENCIL_MODE_DEFAULT = 0x0,

			DEPTH_STENCIL_STENCIL_MODE_DISABLED = 0x0,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE = 0x1,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM00000001 = 0x2,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM00000010 = 0x3,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM00000100 = 0x4,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM00001000 = 0x5,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM00010000 = 0x6,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM00100000 = 0x7,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM01000000 = 0x8,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_REPLACE_WM10000000 = 0x9,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_ALWAYS_INCREMENT = 0xA,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_GREATER_KEEP = 0xB,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP = 0xC,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM00000001 = 0xD,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM00000010 = 0xE,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM00000100 = 0xF,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM00001000 = 0x10,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM00010000 = 0x11,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM00100000 = 0x12,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM01000000 = 0x13,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_KEEP_RM10000000 = 0x14,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE = 0x15,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM00000010 = 0x16,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM00000100 = 0x17,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM00001000 = 0x18,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM00010000 = 0x19,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM00100000 = 0x1A,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM01000000 = 0x1B,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_RM10000000 = 0x1C,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_NOT_EQUAL_REPLACE_RM00000001 = 0x1D,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT = 0x1E,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM00000010 = 0x1F,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM00000100 = 0x20,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM00001000 = 0x21,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM00010000 = 0x22,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM00100000 = 0x23,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM01000000 = 0x24,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_INCREMENT_RM10000000 = 0x25,
			DEPTH_STENCIL_STENCIL_MODE_ENABLED_EQUAL_REPLACE_WM00000000 = 0x26,

			DEPTH_STENCIL_STENCIL_MODE_COUNT
		};

		enum DepthStencilDepthMode : std::int32_t
		{
			DEPTH_STENCIL_DEPTH_MODE_DEFAULT = 0x3,

			DEPTH_STENCIL_DEPTH_MODE_DISABLED = 0x0,
			DEPTH_STENCIL_DEPTH_MODE_TEST = 0x1,
			DEPTH_STENCIL_DEPTH_MODE_WRITE = 0x2,
			DEPTH_STENCIL_DEPTH_MODE_TEST_WRITE = 0x3,
			DEPTH_STENCIL_DEPTH_MODE_TESTEQUAL = 0x4,
			DEPTH_STENCIL_DEPTH_MODE_TESTGREATEREQUAL = 0x5,
			DEPTH_STENCIL_DEPTH_MODE_TESTGREATER = 0x6,

			DEPTH_STENCIL_DEPTH_MODE_COUNT,
		};

		enum DepthStencilExtraMode : std::int32_t
		{
			DEPTH_STENCIL_EX_DISABLED = 0x0,
			DEPTH_STENCIL_EX_DFLIGHT_STEP0 = 0x1,
			DEPTH_STENCIL_EX_DFLIGHT_STEP1 = 0x2,
			DEPTH_STENCIL_EX_DFLIGHT_EXCLUSIVE0 = 0x3,
			DEPTH_STENCIL_EX_DFLIGHT_EXCLUSIVE1 = 0x4,
			DEPTH_STENCIL_EX_DFLIGHT_EXCLUSIVECLEAR = 0x5,
			DEPTH_STENCIL_EX_DFDIRLIGHT_SINGLE = 0x6,
			DEPTH_STENCIL_EX_DFDIRLIGHT_STEPS = 0x7,
			DEPTH_STENCIL_EX_DFDIRLIGHT_STEPS_BLEND0 = 0x8,
			DEPTH_STENCIL_EX_DFDIRLIGHT_STEPS_BLEND1 = 0x9,
			DEPTH_STENCIL_EX_DFDIRLIGHT_FINAL = 0xA,
			DEPTH_STENCIL_EX_CHARACTER_LIGHT_TEST = 0xB,
			DEPTH_STENCIL_EX_CHARACTER_LIGHT_MASK = 0xC,
			DEPTH_STENCIL_EX_CHARACTER_LIGHT_MASK_DEPTH_TEST_ONLY = 0xD,
			DEPTH_STENCIL_EX_CLEAR_01111111 = 0xE,

			DEPTH_STENCIL_EX_COUNT
		};

		enum ClearDepthStencilTarget : std::int32_t
		{
			CLEAR_DEPTH_STENCIL_TARGET_DEPTH = 0x1,
			CLEAR_DEPTH_STENCIL_TARGET_STENCIL = 0x2,
			CLEAR_DEPTH_STENCIL_TARGET_ALL = 0x3,
		};

		enum class SetRenderTargetMode : std::uint32_t
		{
			SRTM_CLEAR,
			SRTM_CLEAR_DEPTH,
			SRTM_CLEAR_STENCIL,
			SRTM_NO_CLEAR,
			SRTM_RESTORE,
			SRTM_FORCE_COPY_RESTORE,
			SRTM_INIT,
		};

	};
}
