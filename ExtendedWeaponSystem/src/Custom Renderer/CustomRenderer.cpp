#include "Custom Renderer/CustomRenderer.h"

#pragma region ScopeCamera

//This gets called twice. Needs fix
ScopeCamera::ScopeCamera() :
	TESCamera() {
	logInfo("ScopeCamera ctor Starting...");

	DefaultState* camDefaultState;
	ThermalState* camThermalState;
	NightVisionState* camNightVisionState;
	TESCameraState* oldCamState;

	//defaultState init
	camDefaultState = (DefaultState*)RE::malloc(sizeof(DefaultState));
	if (camDefaultState) {
		new (camDefaultState) DefaultState(*this, ScopeCameraStates::kDefault);
		cameraStates[ScopeCameraStates::kDefault].reset(camDefaultState);
		logInfo("ScopeCamera - Created ScopeCamera::DefaultState");
	} else {
		camDefaultState = nullptr;
		logError("ScopeCamera - ScopeCamera::DefaultState Creation FAILED");
	}
	//thermalState init
	camThermalState = (ThermalState*)RE::malloc(sizeof(ThermalState));
	if (camThermalState) {
		new (camThermalState) ThermalState(*this, ScopeCameraStates::kThermal);
		cameraStates[ScopeCameraStates::kThermal].reset(camThermalState);
		logInfo("ScopeCamera - Created ScopeCamera::ThermalState");
	} else {
		camThermalState = nullptr;
		logError("ScopeCamera - ScopeCamera::ThermalState Creation FAILED");
	}
	//nightVisionState init
	camNightVisionState = (NightVisionState*)RE::malloc(sizeof(NightVisionState));
	if (camNightVisionState) {
		new (camNightVisionState) NightVisionState(*this, ScopeCameraStates::kNightVision);
		cameraStates[ScopeCameraStates::kNightVision].reset(camNightVisionState);
		logInfo("ScopeCamera - Created ScopeCamera::NightVisionState");
	} else {
		camNightVisionState = nullptr;
		logError("ScopeCamera - ScopeCamera::NightVisionState Creation FAILED");
	}

	//oldState
	oldCamState = currentState.get();
	if (camDefaultState != oldCamState) {
		if (camDefaultState) {
			InterlockedIncrement(&camDefaultState->refCount);
		}
		currentState.reset(camDefaultState);
		if (oldCamState && !InterlockedDecrement(&oldCamState->refCount)) {
			oldCamState->~TESCameraState();
		}
	}

	//set state to default
	this->SetState(cameraStates[ScopeCameraStates::kDefault].get());
	logInfo("ScopeCamera ctor Completed.");
}

ScopeCamera::ScopeCamera(bool createDefault) :
	ScopeCamera() {
	if (createDefault) {
		CreateDefault3D();
	}
	camera = nullptr;
	renderPlane = nullptr;
	geometryDefault = false;
	geometryFound = false;
}

ScopeCamera::~ScopeCamera() {  //TODO
}

void ScopeCamera::SetCameraRoot(NiNode* node) {  //TODO
}

void ScopeCamera::SetEnabled(bool bEnabled) {  //TODO
	enabled = bEnabled;
}

bool ScopeCamera::QCameraHasRenderPlane() {
	if (!renderPlane) {
		return false;
	}
	if (geometryDefault || geometryFound) {
		return true;
	}
	return false;
}

bool ScopeCamera::QCameraEquals(std::uint32_t cameraIndex) {
	TESCameraState* pCurrentState = currentState.get();
	return pCurrentState && pCurrentState == cameraStates[cameraIndex].get();
}

TESCameraState* ScopeCamera::QCameraState(std::uint32_t index) {
	if (!index) {
		return nullptr;
	}
	if (index > ScopeCameraStates::kTotal) {
		return nullptr;
	}
	return cameraStates[index].get();
}

NiCamera* ScopeCamera::QRenderCamera() {
	return camera;
}

void ScopeCamera::CreateDefault3D() {
	NiCamera* cam;
	NiCamera* oldCam;
	NiCamera* newCam;
	NiCamera* currentCam;

	//cam = (NiCamera*)RE::malloc(0x1A0);
	cam = NiCamera::Create();
	if (cam) {
		newCam = cam;
		logInfo("ScopeCamera - Created NiCamera");
	} else {
		newCam = nullptr;
		logInfo("ScopeCamera - NiCamera Creation FAILED");
	}
	currentCam = camera;
	if (camera != newCam) {
		oldCam = camera;
		if (newCam) {
			InterlockedIncrement(&newCam->refCount);
		}
		currentCam = newCam;
		camera = newCam;
		if (oldCam) {
			if (!InterlockedDecrement(&oldCam->refCount)) {
				oldCam->DeleteThis();
			}
			currentCam = camera;
		}
	}

	BSGraphics::State* pGraphicsState = &BSGraphics::State::GetSingleton();
	float widthRatio = pGraphicsState->uiBackBufferWidth / pGraphicsState->uiBackBufferHeight;

	NiFrustum updatedFrustum{ NiFrustum(0) };
	updatedFrustum.nearPlane = 1.0F;
	updatedFrustum.farPlane = 10000.0F;
	updatedFrustum.leftPlane = widthRatio * -0.5F;
	updatedFrustum.rightPlane = widthRatio * 0.5F;
	updatedFrustum.bottomPlane = -0.5F;
	updatedFrustum.topPlane = 0.5F;
	updatedFrustum.ortho = false;
	camera->SetViewFrustrum(updatedFrustum);

	//more camera setup needed?

	NiNode* currentNode;
	NiNode* newNode;
	NiNode* node;

	node = (NiNode*)RE::malloc(0x140);
	//node = NiNode::Create();
	if (node) {
		new (node) NiNode(1);
		newNode = node;
		logInfo("ScopeCamera - Created NiNode");
	} else {
		newNode = nullptr;
		logError("ScopeCamera - NiNode Creation FAILED");
	}
	currentNode = cameraRoot.get();
	if (currentNode != newNode) {
		if (newNode) {
			InterlockedIncrement(&newNode->refCount);
		}
		cameraRoot = newNode;
		if (currentNode && !InterlockedDecrement(&currentNode->refCount)) {
			currentNode->DeleteThis();
		}
	}
	cameraRoot->AttachChild(camera, true);

	BSGeometry* geo;
	BSGeometry* newGeo;
	BSGeometry* currentGeo;

	geo = CreateScreenQuadShape(0, 1, 0, 1);
	//geo = (BSGeometry*)RE::malloc(0x160);
	if (geo) {
		//new (geo) BSGeometry();
		newGeo = geo;
		logInfo("ScopeCamera - Created BSTriShape");
	} else {
		newGeo = nullptr;
		logError("ScopeCamera - BSTriShape Creation FAILED");
	}
	currentGeo = renderPlane;
	if (currentGeo != newGeo) {
		if (newGeo) {
			InterlockedIncrement(&newGeo->refCount);
		}
		renderPlane = newGeo;
		if (currentGeo && !InterlockedDecrement(&currentGeo->refCount)) {
			currentGeo->DeleteThis();
		}
	}
	geometryDefault = true;

	//Needs aditional setup for the default render plane
	//lightingshaderproperty or effectshaderproperty needs to be made
	//position of render plane needs to be done
}

bool ScopeCamera::IsInDefaultMode() {
	TESCameraState* defaultState;

	defaultState = cameraStates[ScopeCameraState::kDefault].get();
	if (this->currentState.get() == defaultState) {
		return this->currentState.get() == defaultState;
	}
	return false;
}

bool ScopeCamera::IsInThermalMode() {
	TESCameraState* thermalState;

	thermalState = cameraStates[ScopeCameraState::kThermal].get();
	if (this->currentState.get() == thermalState) {
		return this->currentState.get() == thermalState;
	}
	return false;
}

bool ScopeCamera::IsInNightVisionMode() {
	TESCameraState* nightVisionState;

	nightVisionState = cameraStates[ScopeCameraState::kNightVision].get();
	if (this->currentState.get() == nightVisionState) {
		return this->currentState.get() == nightVisionState;
	}
	return false;
}

void ScopeCamera::Reset() {
	currentState->Begin();
}

void ScopeCamera::SetState(TESCameraState* newCameraState) {
	TESCameraState* lastState;
	TESCameraState* oldState;
	TESCameraState* newState;

	lastState = currentState.get();
	if (lastState) {
		lastState->End();
	}
	oldState = currentState.get();
	if (newCameraState != oldState) {
		if (newCameraState) {
			InterlockedIncrement(&newCameraState->refCount);
		}
		currentState.reset(newCameraState);
		if (oldState && !InterlockedDecrement(&oldState->refCount)) {
			oldState->~TESCameraState();
		}
	}
	newState = currentState.get();
	if (newState) {
		newState->Begin();
	}
}

void ScopeCamera::StartDefaultState() {
	TESCameraState* newState = cameraStates[ScopeCameraState::kDefault].get();
	this->SetState(newState);
}

void ScopeCamera::StartThermalState() {
	TESCameraState* newState = cameraStates[ScopeCameraState::kThermal].get();
	this->SetState(newState);
}

void ScopeCamera::StartNightVisionState() {
	TESCameraState* newState = cameraStates[ScopeCameraState::kNightVision].get();
	this->SetState(newState);
}

void ScopeCamera::Update3D() {
	BSGeometry* currentGeom;
	BSGeometry* geom;
	BSGeometry* newGeom;
	BSGeometry* oldGeom;

	const BSFixedString geomName = "TextureLoader:0";

	logInfo("Looking for new camera and geometry...");

	geom = (BSGeometry*)GetByNameFromPlayer3D(geomName);
	if (geom) {
		newGeom = geom;
	} else {
		newGeom = nullptr;
	}
	currentGeom = renderPlane;
	if (renderPlane != newGeom) {
		oldGeom = renderPlane;
		if (newGeom) {
			logInfo("Found the geometry of the scope.");
		}
		currentGeom = newGeom;
		renderPlane = newGeom;
		if (oldGeom) {
			currentGeom = renderPlane;
		}
	}

	geometryFound = true;

	NiCamera* currentCam;
	NiCamera* cam;
	NiCamera* newCam;
	NiCamera* oldCam;

	const BSFixedString camName = "ScopePOV";

	cam = (NiCamera*)GetByNameFromPlayer3D(camName);
	if (cam) {
		newCam = cam;
	} else {
		newCam = nullptr;
	}
	currentCam = camera;
	if (camera != newCam) {
		oldCam = camera;
		if (newCam) {
			logInfo("Found the scope camera.");
		}
		currentCam = newCam;
		camera = newCam;
		cameraRoot = camera->parent;
		if (oldCam) {
			currentCam = camera;
		}
	}
	//TODO: add actor value or something similar to set what the FOV should be on the camera of each scope
	BSShaderUtil::SetSceneGraphCameraFOV(Main::GetWorldSceneGraph(), (90.0 / 4.0), 0, camera, 1);  //TEMP. Right now I just have it as 4x zoom

	if (!geom) {
		logWarn("Could not find the geometry of the scope.");
		weaponHasScopeThermal = false;
	}
}

void ScopeCamera::UpdateCamera() {
	if (!this->enabled) {
		return;
	}

	TESCameraState* pCurrentState = this->currentState.get();
	if (pCurrentState == this->cameraStates[ScopeCameraState::kDefault].get()) {
		((ScopeCamera::DefaultState*)pCurrentState)->Update(this->currentState);
	}
	if (pCurrentState == this->cameraStates[ScopeCameraState::kThermal].get()) {
		((ScopeCamera::ThermalState*)pCurrentState)->Update(this->currentState);
	}
	if (pCurrentState == this->cameraStates[ScopeCameraState::kNightVision].get()) {
		((ScopeCamera::NightVisionState*)pCurrentState)->Update(this->currentState);
	}

	this->Update();
}

void ScopeCamera::UpdateCameraState() {
	if (weaponHasScopeThermal) {
		this->StartThermalState();
		return;
	}
	if (weaponHasScopeNV) {
		this->StartNightVisionState();
		return;
	}
	if (weaponHasScopePIP) {
		this->StartDefaultState();
		return;
	}
	//failsafe if no vars equate to true
	this->StartDefaultState();
}

ScopeCamera::DefaultState::DefaultState(TESCamera& cam, std::uint32_t ID) :
	TESCameraState(cam, ID) {
	logInfo("ScopeCamera::DefaultState ctor Starting...");
	refCount = 0;
	camera = &cam;
	id = ID;

	initialRotation.w = 0.0F;
	initialRotation.x = 0.0F;
	initialRotation.y = 0.0F;
	initialRotation.z = 0.0F;
	initialPosition = NiPoint3::ZERO;
	rotation.w = 0.0F;
	rotation.x = 0.0F;
	rotation.y = 0.0F;
	rotation.z = 0.0F;
	translation = NiPoint3::ZERO;
	zoom = 1.0F;
	logInfo("ScopeCamera::DefaultState ctor Completed.");
}

ScopeCamera::DefaultState::~DefaultState() {
	logInfo("ScopeCamera::DefaultState dtor Starting...");
	RE::free(this);
	logInfo("ScopeCamera::DefaultState dtor Completed.");
}

bool ScopeCamera::DefaultState::ShouldHandleEvent(const InputEvent* inputEvent) {  //TODO
	return false;                                                                  //TEMP
}

void ScopeCamera::DefaultState::HandleThumbstickEvent(const ThumbstickEvent* inputEvent) {
}

void ScopeCamera::DefaultState::HandleCursorMoveEvent(const CursorMoveEvent* inputEvent) {
}

void ScopeCamera::DefaultState::HandleMouseMoveEvent(const MouseMoveEvent* inputEvent) {
}

void ScopeCamera::DefaultState::HandleButtonEvent(const ButtonEvent* inputEvent) {  //TODO
}

void ScopeCamera::DefaultState::Begin() {  //TODO: Add new members
	translation = NiPoint3::ZERO;
	zoom = 1.0F;
}

void ScopeCamera::DefaultState::End() {  //TODO
}

void ScopeCamera::DefaultState::Update(BSTSmartPointer<TESCameraState>& a_nextState) {
	NiPoint3 updatedTranslation;
	NiQuaternion updatedQuatRotation;
	NiMatrix3 updatedRotation;

	NiPointer<NiNode> spCameraRoot = nullptr;
	NiNode* pCameraRoot = nullptr;

	NiUpdateData updateData{ NiUpdateData(0.0F, 0) };

	this->GetTranslation(updatedTranslation);
	this->GetRotation(updatedQuatRotation);

	if (this->camera->GetCameraRoot(spCameraRoot)) {
		updatedQuatRotation.ToRotation(updatedRotation);

		pCameraRoot->local.rotate.entry[0].pt[0] = updatedRotation.entry[0].pt[0];
		pCameraRoot->local.rotate.entry[0].pt[1] = updatedRotation.entry[0].pt[1];
		pCameraRoot->local.rotate.entry[0].pt[2] = updatedRotation.entry[0].pt[2];
		pCameraRoot->local.rotate.entry[0].pt[3] = updatedRotation.entry[0].pt[3];
		pCameraRoot->local.rotate.entry[1].pt[0] = updatedRotation.entry[1].pt[0];
		pCameraRoot->local.rotate.entry[1].pt[1] = updatedRotation.entry[1].pt[1];
		pCameraRoot->local.rotate.entry[1].pt[2] = updatedRotation.entry[1].pt[2];
		pCameraRoot->local.rotate.entry[1].pt[3] = updatedRotation.entry[1].pt[3];
		pCameraRoot->local.rotate.entry[2].pt[0] = updatedRotation.entry[2].pt[0];
		pCameraRoot->local.rotate.entry[2].pt[1] = updatedRotation.entry[2].pt[1];
		pCameraRoot->local.rotate.entry[2].pt[2] = updatedRotation.entry[2].pt[2];
		pCameraRoot->local.rotate.entry[2].pt[3] = updatedRotation.entry[2].pt[3];
		pCameraRoot->local.translate = updatedTranslation;
		pCameraRoot->Update(updateData);
	}

	float newZoom = this->camera->zoomInput + zoom;
	if (newZoom <= 1.0F) {
		if (newZoom < 0.0F) {
			newZoom = 0.0F;
		}
	} else {
		newZoom = 1.0F;
	}
	zoom = newZoom;

	//delete the default created node of the nismartpointer???
	NiNode* oldCameraRoot = spCameraRoot.get();
	if (spCameraRoot.get()) {
		if (!InterlockedDecrement(&spCameraRoot->refCount)) {
			oldCameraRoot->DeleteThis();
		}
	}
}

void ScopeCamera::DefaultState::GetRotation(NiQuaternion& a_rotation) const {
	a_rotation = rotation;
}

void ScopeCamera::DefaultState::GetTranslation(NiPoint3& a_translation) const {
	a_translation = translation;
}

NiQuaternion& ScopeCamera::DefaultState::QInitialRotation() {
	return initialRotation;
}

NiPoint3& ScopeCamera::DefaultState::QInitialPosition() {
	return initialPosition;
}

NiQuaternion& ScopeCamera::DefaultState::QRotation() {
	return rotation;
}

NiPoint3& ScopeCamera::DefaultState::QTranslation() {
	return translation;
}

void ScopeCamera::DefaultState::SetInitialPosition(NiPoint3& newPos) {
	initialPosition = newPos;
}

void ScopeCamera::DefaultState::SetTranslation(NiPoint3& newPos) {
	translation = newPos;
}

void ScopeCamera::DefaultState::SetZoom(float newZoom) {
	zoom = newZoom;
}

ScopeCamera::ThermalState::ThermalState(TESCamera& cam, std::uint32_t ID) :
	DefaultState(cam, ID) {
	logInfo("ScopeCamera::ThermalState ctor Starting...");

	logInfo("ScopeCamera::ThermalState ctor Completed.");
}

ScopeCamera::ThermalState::~ThermalState() {
	logInfo("ScopeCamera::ThermalState dtor Starting...");
	RE::free(this);
	logInfo("ScopeCamera::ThermalState dtor Completed.");
}

bool ScopeCamera::ThermalState::ShouldHandleEvent(const InputEvent* inputEvent) {
	return false;
}

void ScopeCamera::ThermalState::HandleThumbstickEvent(const ThumbstickEvent* inputEvent) {
}

void ScopeCamera::ThermalState::HandleCursorMoveEvent(const CursorMoveEvent* inputEvent) {
}

void ScopeCamera::ThermalState::HandleMouseMoveEvent(const MouseMoveEvent* inputEvent) {
}

void ScopeCamera::ThermalState::HandleButtonEvent(const ButtonEvent* inputEvent) {
}

void ScopeCamera::ThermalState::Begin() {
}

void ScopeCamera::ThermalState::End() {
}

void ScopeCamera::ThermalState::Update(BSTSmartPointer<TESCameraState>& a_nextState) {
}


ScopeCamera::NightVisionState::NightVisionState(TESCamera& cam, std::uint32_t ID) :
	DefaultState(cam, ID) {
	logInfo("ScopeCamera::NightVisionState ctor Starting...");

	logInfo("ScopeCamera::NightVisionState ctor Completed.");
}

ScopeCamera::NightVisionState::~NightVisionState() {
	logInfo("ScopeCamera::NightVisionState dtor Starting...");
	RE::free(this);
	logInfo("ScopeCamera::NightVisionState dtor Completed.");
}

bool ScopeCamera::NightVisionState::ShouldHandleEvent(const InputEvent* inputEvent) {
	return false;
}

void ScopeCamera::NightVisionState::HandleThumbstickEvent(const ThumbstickEvent* inputEvent) {
}

void ScopeCamera::NightVisionState::HandleCursorMoveEvent(const CursorMoveEvent* inputEvent) {
}

void ScopeCamera::NightVisionState::HandleMouseMoveEvent(const MouseMoveEvent* inputEvent) {
}

void ScopeCamera::NightVisionState::HandleButtonEvent(const ButtonEvent* inputEvent) {
}

void ScopeCamera::NightVisionState::Begin() {
}

void ScopeCamera::NightVisionState::End() {
}

void ScopeCamera::NightVisionState::Update(BSTSmartPointer<TESCameraState>& a_nextState) {
}


#pragma endregion

#pragma region ScopeRenderer

ScopeRenderer::ScopeRenderer() {
	logInfo("ScopeRenderer ctor Starting...");

	BSShaderAccumulator* shaderAccum;
	BSShaderAccumulator* newShaderAccum;
	BSShaderAccumulator* oldShaderAccum;

	logInfo("ScopeRenderer - Creating BSCullingProcess...");
	pScopeCullingProc = (BSCullingProcess*)RE::malloc(0x1A0);
	if (pScopeCullingProc) {
		new (pScopeCullingProc) BSCullingProcess(0);
	} else {
		pScopeCullingProc = nullptr;
		logError("ScopeRenderer - BSCullingProcess Creation FAILED");
	}

	logInfo("ScopeRenderer - Creating ScopeCamera...");
	rendererCamera = (ScopeCamera*)RE::malloc(sizeof(ScopeCamera));
	if (&rendererCamera) {
		new (&rendererCamera) ScopeCamera(false);
	} else {
		logError("ScopeRenderer - ScopeCamera Creation FAILED");
	}

	logInfo("ScopeRenderer - Creating ImageSpaceShaderParam...");
	shaderParams = (ImageSpaceShaderParam*)RE::malloc(0x90);
	if (&shaderParams) {
		new (&shaderParams) ImageSpaceShaderParam();
	} else {
		logError("ScopeRenderer - ImageSpaceShaderParam Creation FAILED");
		shaderParams = &BSImagespaceShader::GetDefaultParam();
	}

	shaderAccum = (BSShaderAccumulator*)RE::malloc(0x590);
	if (shaderAccum) {
		new (shaderAccum) BSShaderAccumulator();
		newShaderAccum = shaderAccum;
		logInfo("ScopeRenderer - Created BSShaderAccumulator");
	} else {
		newShaderAccum = nullptr;
		logError("ScopeRenderer - BSShaderAccumulator Creation FAILED");
	}
	oldShaderAccum = pScopeAccumulator;
	if ((oldShaderAccum != newShaderAccum) || (pScopeAccumulator == nullptr)) {
		if (newShaderAccum) {
			InterlockedIncrement(&newShaderAccum->refCount);
		}
		pScopeAccumulator = newShaderAccum;
		if (oldShaderAccum && !InterlockedDecrement(&oldShaderAccum->refCount)) {
			oldShaderAccum->DeleteThis();
		}
	}
	pScopeAccumulator->ZPrePass = true;
	pScopeAccumulator->activeShadowSceneNode = BSShaderManager::State::GetSingleton().pShadowSceneNode[BSShaderManager::BSSM_SSN_WORLD];
	pScopeAccumulator->QSilhouetteColor = NiColorA::WHITE;
	pScopeCullingProc->SetAccumulator(pScopeAccumulator);
	pScopeCullingProc->kCullMode = BSCullingProcess::BSCP_CULL_IGNOREMULTIBOUNDS;
	pScopeCullingProc->m_bCameraRelatedUpdates = false;
	shaderParams->ResizeConstantGroup(0, 1);
	renderTarget = 19;

	logInfo("ScopeRenderer ctor Completed.");
}

ScopeRenderer::~ScopeRenderer() {
	BSShaderAccumulator* shaderAccum;
	NiCamera* cam;
	TESCameraState* state;

	shaderParams->~ImageSpaceShaderParam();
	shaderAccum = pScopeAccumulator;
	if (shaderAccum && !InterlockedDecrement(&shaderAccum->refCount)) {
		shaderAccum->DeleteThis();
	}
	cam = rendererCamera->camera;
	if (cam && !InterlockedDecrement(&cam->refCount)) {
		cam->DeleteThis();
	}
	state = rendererCamera->currentState.get();
	if (state && !InterlockedDecrement(&state->refCount)) {
		state->~TESCameraState();
	}
	rendererCamera->~ScopeCamera();
	pScopeCullingProc->~BSCullingProcess();
}

ScopeRenderer& ScopeRenderer::operator=(const ScopeRenderer& rhs) {
	memcpy(pScopeCullingProc, rhs.pScopeCullingProc, 0x1A0);
	rendererCamera = rhs.rendererCamera;
	pScopeAccumulator = rhs.pScopeAccumulator;
	shaderParams = rhs.shaderParams;
	renderTarget = rhs.renderTarget;
	return *this;
}

NiTexture* ScopeRenderer::Render(bool saveTexture) {
	ScopeRenderer* pScopeRenderer = (this);
	ScopeCamera* pScopeCam = pScopeRenderer->rendererCamera;

	BSGraphics::State* pGraphicsState = &BSGraphics::State::GetSingleton();
	BSGraphics::RenderTargetManager* pTargetManager = &BSGraphics::RenderTargetManager::GetSingleton();
	BSGraphics::Renderer* pRenderData = &BSGraphics::Renderer::GetSingleton();
	ImageSpaceManager* pImageSpaceManager = ImageSpaceManager::GetSingleton();
	BSShaderManager::State* pShaderState = &BSShaderManager::State::GetSingleton();
	NiCamera* shaderCam = BSShaderManager::GetCamera();

	BSCullingProcess scopeCulling = *(BSCullingProcess*)RE::malloc(0x1A0);
	new (&scopeCulling) BSCullingProcess(0);  //Is this still needed with the above statement?

	ShadowSceneNode* pWorldSSN = pShaderState->pShadowSceneNode[BSShaderManager::BSSM_SSN_WORLD];
	NiAVObject* objectLODRoot = pShaderState->pShadowSceneNode[BSShaderManager::BSSM_SSN_WORLD]->children[3].get();
	if (objectLODRoot) {
		InterlockedIncrement(&objectLODRoot->refCount);
	}
	bool objCullFlag = objectLODRoot->flags.flags & 1;
	objectLODRoot->SetAppCulled(true);

	memcpy(BSShaderManager::GetCamera(), pScopeCam->camera, 0x1A0);

	pGraphicsState->SetCameraData(pScopeCam->camera, false, 0.0F, 1.0F);
	(&scopeCulling)->SetAccumulator(pScopeRenderer->pScopeAccumulator);
	(&scopeCulling)->kCullMode = BSCullingProcess::BSCP_CULL_IGNOREMULTIBOUNDS;
	(&scopeCulling)->m_bCameraRelatedUpdates = false;
	(&scopeCulling)->m_pkCamera = pScopeCam->camera;

	pScopeCam->Update();

	pRenderData->SetClearColor(1.0F, 1.0F, 1.0F, 1.0F);

	pScopeRenderer->pScopeAccumulator->renderMode = BSShaderManager::etRenderMode::BSSM_RENDER_VATS_MASK;
	pScopeRenderer->pScopeAccumulator->QEyePosition = pScopeCam->camera->world.translate;
	pRenderData->ResetZPrePass();
	AccumulateSceneFunctor acummulateFunctor;
	acummulateFunctor.renderer = pScopeRenderer;
	if (TES::GetSingleton()->GetWorldSpace() || (acummulateFunctor.interior = false, TES::GetSingleton()->GetWorldSpace()->flags & 0x40) == 0) {
		acummulateFunctor.interior = true;
	}

	BSPortalGraphEntry* camPortalEntry = (Main::GetSingleton())->GetCameraPortalGraphEntry();
	if (camPortalEntry) {
		BSPortalGraph* camPortalGraph = camPortalEntry->PortalGraph;
		if (camPortalGraph) {
			BSShaderUtil::AccumulateSceneArray(pScopeCam->camera, &camPortalGraph->AlwaysRenderArray, scopeCulling, false);
		}
	}

	NiAVObject* portalSharedNode;
	if (pWorldSSN->children.size() > 9) {
		portalSharedNode = pWorldSSN->children[9].get();
		BSShaderUtil::AccumulateScene(pScopeCam->camera, portalSharedNode, scopeCulling, false);
	} else {
		portalSharedNode = nullptr;
	}

	NiAVObject* multiBoundNode;
	if (pWorldSSN->children.size() > 8) {
		multiBoundNode = pWorldSSN->children[8].get();
		BSShaderUtil::AccumulateScene(pScopeCam->camera, multiBoundNode, scopeCulling, false);
	} else {
		multiBoundNode = nullptr;
	}

	uint32_t depthTargetID = 1;
	uint32_t renderTargetID = 27;
	uint32_t effectID = 152;

	pShaderState->cSceneGraph = BSShaderManager::BSSM_SSN_WORLD;
	pShaderState->pShadowSceneNode[BSShaderManager::BSSM_SSN_WORLD]->ProcessQueuedLights(&scopeCulling);
	pRenderData->ResetState();

	pTargetManager->AcquireDepthStencil(depthTargetID);
	pTargetManager->AcquireRenderTarget(renderTargetID);
	RenderScopeScene(pScopeCam->camera, pScopeRenderer->pScopeAccumulator, renderTargetID, depthTargetID);
	pTargetManager->SetCurrentRenderTarget(0, 2, BSGraphics::SetRenderTargetMode::SRTM_RESTORE);
	pTargetManager->SetCurrentRenderTarget(1, -1, BSGraphics::SetRenderTargetMode::SRTM_CLEAR);
	pTargetManager->SetCurrentDepthStencilTarget(1, BSGraphics::SetRenderTargetMode::SRTM_RESTORE, 0, false);
	//FogOfWar Setup stuff would happen after this in the LocalMapRenderer::Render
	//stuff and things
	//
	pTargetManager->SetCurrentDepthStencilTarget(0, BSGraphics::SetRenderTargetMode::SRTM_RESTORE, 0, false);
	pScopeRenderer->shaderParams->SetPixelConstant(0, 1.0F / pTargetManager->pRenderTargetDataA[pScopeRenderer->renderTarget].uiWidth, 1.0F / pTargetManager->pRenderTargetDataA[pScopeRenderer->renderTarget].uiHeight, 0.0F, 0.0F);
	pTargetManager->SetTextureDepth(1, depthTargetID);
	pTargetManager->SetTextureRenderTarget(2, renderTargetID, false);
	pImageSpaceManager->effectArray[effectID].UseDynamicResolution = false;
	pImageSpaceManager->RenderEffect_1((ImageSpaceManager::ImageSpaceEffectEnum)effectID, pScopeRenderer->renderTarget, pScopeRenderer->shaderParams);
	pTargetManager->ReleaseDepthStencil(depthTargetID);
	pTargetManager->ReleaseRenderTarget(renderTargetID);

	pTargetManager->SetCurrentRenderTarget(0, 1, BSGraphics::SetRenderTargetMode::SRTM_RESTORE);
	NiTexture* renderedTexture = nullptr;
	BSGraphics::Texture* graphicsTex = nullptr;
	if (saveTexture) {
		const BSFixedString strScope("ScopeTexture");
		renderedTexture = renderedTexture->CreateEmpty(strScope, false, false);
		graphicsTex = pTargetManager->SaveRenderTargetToTexture(19, false, false, BSGraphics::Usage::USAGE_DEFAULT);
		renderedTexture->rendererTexture = graphicsTex;
	}
	//BSScaleformRenderer::SetCurrentRenderTarget
	memcpy(BSShaderManager::GetCamera(), shaderCam, 0x1A0);
	pGraphicsState->SetCameraData(shaderCam, false, 0.0F, 1.0F);

	pScopeRenderer->pScopeAccumulator->ClearActivePasses(false);
	pScopeRenderer->pScopeAccumulator->ClearGroupPasses(5, false);
	(&scopeCulling)->~BSCullingProcess();

	objectLODRoot->SetAppCulled(objCullFlag);
	if (!InterlockedDecrement(&objectLODRoot->refCount)) {
		objectLODRoot->DeleteThis();
	}
	return renderedTexture;
}

#pragma endregion

void RenderScopeScene(NiCamera* cam, BSShaderAccumulator* shadeAccum, uint32_t target, uint32_t depthTarget) {
	BSGraphics::State* pGraphicsState = &BSGraphics::State::GetSingleton();
	BSGraphics::RenderTargetManager* pTargetManager = &BSGraphics::RenderTargetManager::GetSingleton();
	BSGraphics::Renderer* pRenderData = &BSGraphics::Renderer::GetSingleton();
	BSShaderManager::State* pShaderState = &BSShaderManager::State::GetSingleton();

	pTargetManager->SetCurrentDepthStencilTarget(depthTarget, BSGraphics::SetRenderTargetMode::SRTM_FORCE_COPY_RESTORE, 0, false);
	pTargetManager->SetCurrentRenderTarget(1, target, BSGraphics::SetRenderTargetMode::SRTM_CLEAR);
	pTargetManager->SetCurrentRenderTarget(2, -1, BSGraphics::SetRenderTargetMode::SRTM_CLEAR);
	pTargetManager->SetCurrentRenderTarget(3, -1, BSGraphics::SetRenderTargetMode::SRTM_CLEAR);
	if (pShaderState->bDeferredRGBEmit) {
		pTargetManager->SetCurrentRenderTarget(4, -1, BSGraphics::SetRenderTargetMode::SRTM_CLEAR);
	}
	pTargetManager->SetCurrentRenderTarget(5, -1, BSGraphics::SetRenderTargetMode::SRTM_CLEAR);
	pTargetManager->SetCurrentViewportForceToRenderTargetDimensions();
	pRenderData->SetClearColor(0.0F, 0.0F, 0.0F, 0.0F);
	pRenderData->ClearColor();
	pRenderData->Flush();
	//Threaded stuff happens here in RenderLocalMapScene
	//stuff
	//more stuff
	pGraphicsState->SetCameraData(cam, false, 0.0F, 1.0F);
	pRenderData->DoZPrePass(nullptr, nullptr, 0.0F, 1.0F, 0.0F, 1.0F);
	shadeAccum->RenderOpaqueDecals();
	shadeAccum->RenderBatches(4, false, -1);
	shadeAccum->RenderBlendedDecals();
	//BSGraphics::pDefaultContext stuff happens here in RenderLocalMapScene
	//stuff
	//more stuff
	pRenderData->Flush();
	pRenderData->SetClearColor(1.0F, 1.0F, 1.0F, 1.0F);
	//more context stuff
	//more things
	shadeAccum->ClearEffectPasses();
	shadeAccum->ClearActivePasses(false);
}

#pragma region nsScope
namespace nsScope {
	ScopeRenderer* scopeRenderer = nullptr;
	BSSpinLock* scopeRendererLock = nullptr;

	void CreateRenderer() {
		logInfo("ScopeRenderer Creation Starting...");

		//create a spinlock
		scopeRendererLock = (BSSpinLock*)RE::malloc(0x8);
		logInfo("ScopeRendererLock Allocated...");
		new (scopeRendererLock) BSSpinLock();

		//there is already an exsisting renderer
		if (scopeRenderer != nullptr) {
			logInfo("nsScope::CreateRenderer() was called but there was already a renderer in place");
			return;
		}

		//if renderer is null
		if (!scopeRenderer) {
			scopeRenderer = InitRenderer();
			//in nsPipboy_LocalMap::CreateRenderer this is where the localMapCameraUpdateEvent stuff would also be created
		}
		scopeRendererLock->unlock();
		readyForRender = true;
		logInfo("ScopeRenderer Creation Complete.");
		logger::info(FMT_STRING("ScopeRenderer created at {:p}"), fmt::ptr(scopeRenderer));
	}

	void DestroyRenderer() {
		logInfo("ScopeRenderer Destroy Starting...");
		scopeRendererLock->lock();

		ScopeRenderer* pRenderer = scopeRenderer;
		if (scopeRenderer) {
			scopeRenderer->~ScopeRenderer();
			RE::free(pRenderer);
		}
		scopeRenderer = nullptr;
		readyForRender = false;
		logInfo("ScopeRenderer Destroy Complete.");
	}

	ScopeRenderer* InitRenderer() {
		logInfo("ScopeRenderer Init Starting...");

		ScopeRenderer* renderer;
		ScopeRenderer* newRenderer;

		//allocate our renderer
		renderer = (ScopeRenderer*)RE::malloc(sizeof(ScopeRenderer));
		logInfo("ScopeRenderer Allocated...");
		//if allocated succesful
		if (renderer) {
			new (renderer) ScopeRenderer();
			newRenderer = renderer;
		} else {
			newRenderer = nullptr;
		}

		logInfo("ScopeRenderer Init Complete.");
		return newRenderer;
	}

	void Render() {
		NiTexture* renderedTexture;

		scopeRendererLock->lock();
		if (scopeRenderer) {
			renderedTexture = scopeRenderer->Render(true);
			if (renderedTexture) {
				/*
			if (texID string init) {
				//stuff about localMapTextureID
				//stuff
			}
			//here there would be stuff for setting the renderedTexture to be the scaleform texture
			*/
				if (scopeRenderer->rendererCamera->renderPlane->shaderProperty.get()->Type() != NiProperty::SHADE) {
					//TODO: Add a creation of a shader property to the geometry for if the shaderProperty of the current geometry is nullptr or invalid
				}
				BSShaderProperty* shaderProperty = scopeRenderer->rendererCamera->renderPlane->QShaderProperty();
				if (shaderProperty->GetMaterialType() == BSShaderMaterial::BSMATERIAL_TYPE_EFFECT) {
					BSEffectShaderProperty* effectShaderProperty;
					BSEffectShaderMaterial* effectShaderMaterial;
					effectShaderProperty = (BSEffectShaderProperty*)shaderProperty;
					if (shaderProperty) {
						effectShaderMaterial = effectShaderProperty->GetEffectShaderMaterial();
						effectShaderMaterial->SetBaseTexture(renderedTexture);
						effectShaderMaterial->fBaseColorScale = 1.0F;
						effectShaderMaterial->kBaseColor = NiColorA::WHITE;
					}
				}
				if (shaderProperty->GetMaterialType() == BSShaderMaterial::BSMATERIAL_TYPE_LIGHTING) {
					BSLightingShaderProperty* lightingShaderProperty;
					BSLightingShaderMaterialBase* lightingShaderMaterial;
					lightingShaderProperty = (BSLightingShaderProperty*)(shaderProperty);
					if (shaderProperty) {
						lightingShaderMaterial = lightingShaderProperty->GetLightingShaderMaterial();
						lightingShaderMaterial->spDiffuseTexture.reset(renderedTexture);
					}
				}
			}
		}
		scopeRendererLock->unlock();
	}
}

#pragma endregion
