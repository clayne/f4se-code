set(SOURCES
	include/F4SE/API.h
	include/F4SE/F4SE.h
	include/F4SE/Impl/PCH.h
	include/F4SE/Impl/WinAPI.h
	include/F4SE/Interfaces.h
	include/F4SE/Logger.h
	include/F4SE/Trampoline.h
	include/F4SE/Version.h
	include/RE/Bethesda/AITimeStamp.h
	include/RE/Bethesda/Actor.h
	include/RE/Bethesda/ActorValueInfo.h
	include/RE/Bethesda/AnimationSystemUtils.h
	include/RE/Bethesda/Atomic.h
	include/RE/Bethesda/BGSAnimationSystemUtils.h
	include/RE/Bethesda/BGSBaseAliases.h
	include/RE/Bethesda/BGSBodyPartDefs.h
	include/RE/Bethesda/BGSCharacterMorph.h
	include/RE/Bethesda/BGSCharacterTint.h
	include/RE/Bethesda/BGSCreatedObjectManager.h
	include/RE/Bethesda/BGSDefaultObjectManager.h
	include/RE/Bethesda/BGSDynamicPersistenceManager.h
	include/RE/Bethesda/BGSEntryPoint.h
	include/RE/Bethesda/BGSHeadPart.h
	include/RE/Bethesda/BGSInventoryInterface.h
	include/RE/Bethesda/BGSInventoryItem.h
	include/RE/Bethesda/BGSMod.h
	include/RE/Bethesda/BGSPrimitive.h
	include/RE/Bethesda/BGSSaveLoad.h
	include/RE/Bethesda/BGSStoryEventManager.h
	include/RE/Bethesda/BGSStoryManagerTreeForm.h
	include/RE/Bethesda/BGSSynchronizedAnimationManager.h
	include/RE/Bethesda/BGSTextureSet.h
	include/RE/Bethesda/BSAnimation/AnimationSpeedInfo.h
	include/RE/Bethesda/BSAnimation/AnimationStanceData.h
	include/RE/Bethesda/BSAnimation/BSAnimationGraphManager.h
	include/RE/Bethesda/BSAnimation/BSLinearInterpolator.h
	include/RE/Bethesda/BSAnimation/FirstPersonRootEvents.h
	include/RE/Bethesda/BSCompoundFrustum.h
	include/RE/Bethesda/BSContainer.h
	include/RE/Bethesda/BSCore/AllocatorStackCounter.h
	include/RE/Bethesda/BSCore/BSAutoLock.h
	include/RE/Bethesda/BSCore/BSCRC32.h
	include/RE/Bethesda/BSCore/BSCore.h
	include/RE/Bethesda/BSCore/BSCoreDefines.h
	include/RE/Bethesda/BSCore/BSCoreHeaders.h
	include/RE/Bethesda/BSCore/BSCoreLibType.h
	include/RE/Bethesda/BSCore/BSCoreMath.h
	include/RE/Bethesda/BSCore/BSCoreMemory.h
	include/RE/Bethesda/BSCore/BSCoreMessage.h
	include/RE/Bethesda/BSCore/BSCoreTypes.h
	include/RE/Bethesda/BSCore/BSCoreUtils.h
	include/RE/Bethesda/BSCore/BSCriticalSection.h
	include/RE/Bethesda/BSCore/BSD3DX.h
	include/RE/Bethesda/BSCore/BSEventFlag.h
	include/RE/Bethesda/BSCore/BSIntrusiveRBTree.h
	include/RE/Bethesda/BSCore/BSMemoryUtility.h
	include/RE/Bethesda/BSCore/BSNonReEntrantSpinLock.h
	include/RE/Bethesda/BSCore/BSPrecisionTimer.h
	include/RE/Bethesda/BSCore/BSRandom.h
	include/RE/Bethesda/BSCore/BSReadWriteLock.h
	include/RE/Bethesda/BSCore/BSSafeSleep.h
	include/RE/Bethesda/BSCore/BSScrapArray.h
	include/RE/Bethesda/BSCore/BSSemaphore.h
	include/RE/Bethesda/BSCore/BSSimpleList.h
	include/RE/Bethesda/BSCore/BSSmallBlockAllocator.h
	include/RE/Bethesda/BSCore/BSSpinLock.h
	include/RE/Bethesda/BSCore/BSString.h
	include/RE/Bethesda/BSCore/BSTArray.h
	include/RE/Bethesda/BSCore/BSTArrayAlg.h
	include/RE/Bethesda/BSCore/BSTBTree.h
	include/RE/Bethesda/BSCore/BSTEvent.h
	include/RE/Bethesda/BSCore/BSTHashMap.h
	include/RE/Bethesda/BSCore/BSTList.h
	include/RE/Bethesda/BSCore/BSTListAlg.h
	include/RE/Bethesda/BSCore/BSTLocklessQueue.h
	include/RE/Bethesda/BSCore/BSTObjectArena.h
	include/RE/Bethesda/BSCore/BSTPoint.h
	include/RE/Bethesda/BSCore/BSTPoint2.h
	include/RE/Bethesda/BSCore/BSTPoint3.h
	include/RE/Bethesda/BSCore/BSTPointBase.h
	include/RE/Bethesda/BSCore/BSTRelocatableScatterTable.h
	include/RE/Bethesda/BSCore/BSTScatterTable.h
	include/RE/Bethesda/BSCore/BSTScrapHashMap.h
	include/RE/Bethesda/BSCore/BSTScrapSet.h
	include/RE/Bethesda/BSCore/BSTSet.h
	include/RE/Bethesda/BSCore/BSTSingleton.h
	include/RE/Bethesda/BSCore/BSTSmallArray.h
	include/RE/Bethesda/BSCore/BSTSmallIndexScatterTable.h
	include/RE/Bethesda/BSCore/BSTStaticHashMap.h
	include/RE/Bethesda/BSCore/BSTStaticPrimitiveArray.h
	include/RE/Bethesda/BSCore/BSTTuple.h
	include/RE/Bethesda/BSCore/BSThread.h
	include/RE/Bethesda/BSCore/BSTimer.h
	include/RE/Bethesda/BSCore/CompactingStore.h
	include/RE/Bethesda/BSCore/CompactingStoreCommon.h
	include/RE/Bethesda/BSCore/HeapBlocks.h
	include/RE/Bethesda/BSCore/IMemoryHeap.h
	include/RE/Bethesda/BSCore/IMemoryStore.h
	include/RE/Bethesda/BSCore/IMemoryTracker.h
	include/RE/Bethesda/BSCore/MemoryContextTracker.h
	include/RE/Bethesda/BSCore/MemoryDefs.h
	include/RE/Bethesda/BSCore/MemoryManager.h
	include/RE/Bethesda/BSCore/MemoryTrackSettings.h
	include/RE/Bethesda/BSCore/NewOverloads.h
	include/RE/Bethesda/BSCore/ScrapHeap.h
	include/RE/Bethesda/BSCore/Unicode.h
	include/RE/Bethesda/BSDevices/BSControllerDevice.h
	include/RE/Bethesda/BSDevices/BSDevice.h
	include/RE/Bethesda/BSDevices/BSGamepad.h
	include/RE/Bethesda/BSDevices/BSInputEvent.h
	include/RE/Bethesda/BSDevices/BSInterfaceDevice.h
	include/RE/Bethesda/BSDevices/XPrefSettings.h
	include/RE/Bethesda/BSExtraData.h
	include/RE/Bethesda/BSGeometry.h
	include/RE/Bethesda/BSGraphics/BSGraphics.h
	include/RE/Bethesda/BSGraphics/BSGraphicsHandles.h
	include/RE/Bethesda/BSGraphics/BSGraphicsLibType.h
	include/RE/Bethesda/BSGraphics/BSGraphicsRenderTargetManager.h
	include/RE/Bethesda/BSGraphics/BSGraphicsRenderer.h
	include/RE/Bethesda/BSGraphics/BSGraphicsResourceCache.h
	include/RE/Bethesda/BSGraphics/BSGraphicsState.h
	include/RE/Bethesda/BSGraphics/BSGraphicsTypes.h
	include/RE/Bethesda/BSGraphics/BSGraphicsUtility.h
	include/RE/Bethesda/BSHavok/BSClothExtraData.h
	include/RE/Bethesda/BSHavok/BSClothUtils.h
	include/RE/Bethesda/BSHavok/BSConnectPoint.h
	include/RE/Bethesda/BSHavok/BSHavok.h
	include/RE/Bethesda/BSHavok/DecalCaster.h
	include/RE/Bethesda/BSHavok/bhkCharProxyController.h
	include/RE/Bethesda/BSHavok/bhkCharProxyManager.h
	include/RE/Bethesda/BSHavok/bhkCharRigidBodyController.h
	include/RE/Bethesda/BSHavok/bhkCharRigidBodyManager.h
	include/RE/Bethesda/BSHavok/bhkCharacterController.h
	include/RE/Bethesda/BSHavok/bhkCharacterProxy.h
	include/RE/Bethesda/BSHavok/bhkCharacterRigidBody.h
	include/RE/Bethesda/BSHavok/bhkCharacterState.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateClimbing.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateFloating.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateFlying.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateInAir.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateJumping.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateOnGround.h
	include/RE/Bethesda/BSHavok/bhkCharacterStateSwimming.h
	include/RE/Bethesda/BSHavok/bhkCollisionFilter.h
	include/RE/Bethesda/BSHavok/bhkCollisionFilterDefs.h
	include/RE/Bethesda/BSHavok/bhkCollisionQuery.h
	include/RE/Bethesda/BSHavok/bhkConvert.h
	include/RE/Bethesda/BSHavok/bhkIWorldstepListener.h
	include/RE/Bethesda/BSHavok/bhkNPCollisionObject.h
	include/RE/Bethesda/BSHavok/bhkPhysicsSystem.h
	include/RE/Bethesda/BSHavok/bhkWorld.h
	include/RE/Bethesda/BSHavokMigration/bhkRefObject.h
	include/RE/Bethesda/BSInputDeviceManager.h
	include/RE/Bethesda/BSInputEventReceiver.h
	include/RE/Bethesda/BSInputEventSingleUser.h
	include/RE/Bethesda/BSInputEventUser.h
	include/RE/Bethesda/BSLock.h
	include/RE/Bethesda/BSMain/BSBoneMap.h
	include/RE/Bethesda/BSMain/BSBound.h
	include/RE/Bethesda/BSMain/BSCloningProcess.h
	include/RE/Bethesda/BSMain/BSCullingProcess.h
	include/RE/Bethesda/BSMain/BSCurrent.h
	include/RE/Bethesda/BSMain/BSGeometryConstructor.h
	include/RE/Bethesda/BSMain/BSModelDB.h
	include/RE/Bethesda/BSMain/BSMultiBound.h
	include/RE/Bethesda/BSMain/BSMultiBoundNode.h
	include/RE/Bethesda/BSMain/BSMultiBoundShape.h
	include/RE/Bethesda/BSMain/BSNiLinesConstructor.h
	include/RE/Bethesda/BSMain/BSNiNode.h
	include/RE/Bethesda/BSMain/BSNiTriShapeConstructor.h
	include/RE/Bethesda/BSMain/BSNodeVisitation.h
	include/RE/Bethesda/BSMain/BSPointerHandle.h
	include/RE/Bethesda/BSMain/BSPointerHandleManager.h
	include/RE/Bethesda/BSMain/BSQueuedResourceCollection.h
	include/RE/Bethesda/BSMain/BSReference.h
	include/RE/Bethesda/BSMain/BSSpline.h
	include/RE/Bethesda/BSMain/BSStream.h
	include/RE/Bethesda/BSMain/BSTestObjects.h
	include/RE/Bethesda/BSMain/BSTextureDB.h
	include/RE/Bethesda/BSMain/BSTextureIndex.h
	include/RE/Bethesda/BSMain/BSTextureStreamerTypes.h
	include/RE/Bethesda/BSMain/BSUtilities.h
	include/RE/Bethesda/BSMain/BSXFlags.h
	include/RE/Bethesda/BSMain/IOManager.h
	include/RE/Bethesda/BSMain/IOManagerDef.h
	include/RE/Bethesda/BSMain/NiBSLODNodeEnums.h
	include/RE/Bethesda/BSMain/QueuedFiles.h
	include/RE/Bethesda/BSMain/Setting.h
	include/RE/Bethesda/BSMain/XIniSetting.h
	include/RE/Bethesda/BSMemStorage.h
	include/RE/Bethesda/BSPathfinding/AStarNode.h
	include/RE/Bethesda/BSPathfinding/BSNavMeshInfo.h
	include/RE/Bethesda/BSPathfinding/BSNavmeshRaycast.h
	include/RE/Bethesda/BSPathfinding/BSNavmeshTriangle.h
	include/RE/Bethesda/BSPathfinding/BSPathSmootherRayCast.h
	include/RE/Bethesda/BSPathfinding/BSPathingNode.h
	include/RE/Bethesda/BSPathfinding/BSPathingSpline.h
	include/RE/Bethesda/BSPathfinding/BSPathingStart.h
	include/RE/Bethesda/BSPathfinding/MovementTypes.h
	include/RE/Bethesda/BSPortalGraph.h
	include/RE/Bethesda/BSPreCulledObjects.h
	include/RE/Bethesda/BSResource/BSResource.h
	include/RE/Bethesda/BSResource/BSResourceArchive2.h
	include/RE/Bethesda/BSResource/BSResourceDirectory.h
	include/RE/Bethesda/BSResource/BSResourceEntry.h
	include/RE/Bethesda/BSResource/BSResourceEntryDB.h
	include/RE/Bethesda/BSResource/BSResourceEntryQueue.h
	include/RE/Bethesda/BSResource/BSResourceEnums.h
	include/RE/Bethesda/BSResource/BSResourceID.h
	include/RE/Bethesda/BSResource/BSResourceLocation.h
	include/RE/Bethesda/BSResource/BSResourceStream.h
	include/RE/Bethesda/BSResource/BSResourceStreamBase.h
	include/RE/Bethesda/BSResource/BSResourceStreamer.h
	include/RE/Bethesda/BSResource/BSResourceUtil.h
	include/RE/Bethesda/BSResource/LooseFileStreamBase.h
	include/RE/Bethesda/BSResourceNiBinaryStream.h
	include/RE/Bethesda/BSScaleformManager.h
	include/RE/Bethesda/BSSceneGraph.h
	include/RE/Bethesda/BSScript.h
	include/RE/Bethesda/BSScript/Array.h
	include/RE/Bethesda/BSScript/ArrayWrapper.h
	include/RE/Bethesda/BSScript/CompiledScriptLoader.h
	include/RE/Bethesda/BSScript/ErrorLogger.h
	include/RE/Bethesda/BSScript/ICachedErrorMessage.h
	include/RE/Bethesda/BSScript/IClientVM.h
	include/RE/Bethesda/BSScript/IComplexType.h
	include/RE/Bethesda/BSScript/IFunction.h
	include/RE/Bethesda/BSScript/IHandleReaderWriter.h
	include/RE/Bethesda/BSScript/ILoader.h
	include/RE/Bethesda/BSScript/IMemoryPagePolicy.h
	include/RE/Bethesda/BSScript/IObjectHandlePolicy.h
	include/RE/Bethesda/BSScript/IObjectProcessor.h
	include/RE/Bethesda/BSScript/IProfilePolicy.h
	include/RE/Bethesda/BSScript/ISavePatcherInterface.h
	include/RE/Bethesda/BSScript/IStackCallbackFunctor.h
	include/RE/Bethesda/BSScript/IStackCallbackSaveInterface.h
	include/RE/Bethesda/BSScript/IVMDebugInterface.h
	include/RE/Bethesda/BSScript/IVMObjectBindInterface.h
	include/RE/Bethesda/BSScript/IVMSaveLoadInterface.h
	include/RE/Bethesda/BSScript/IVirtualMachine.h
	include/RE/Bethesda/BSScript/Internal/AttachedScript.h
	include/RE/Bethesda/BSScript/Internal/CodeTasklet.h
	include/RE/Bethesda/BSScript/Internal/EventRelay.h
	include/RE/Bethesda/BSScript/Internal/FunctionMessage.h
	include/RE/Bethesda/BSScript/Internal/IFuncCallQuery.h
	include/RE/Bethesda/BSScript/Internal/RawFuncCallQuery.h
	include/RE/Bethesda/BSScript/Internal/ReadableStringTable.h
	include/RE/Bethesda/BSScript/Internal/ReadableTypeTable.h
	include/RE/Bethesda/BSScript/Internal/ScriptFunction.h
	include/RE/Bethesda/BSScript/Internal/SuspendedStack.h
	include/RE/Bethesda/BSScript/Internal/VDescTable.h
	include/RE/Bethesda/BSScript/Internal/VirtualMachine.h
	include/RE/Bethesda/BSScript/Internal/WritableStringTable.h
	include/RE/Bethesda/BSScript/Internal/WritableTypeTable.h
	include/RE/Bethesda/BSScript/LinkerProcessor.h
	include/RE/Bethesda/BSScript/LogEvent.h
	include/RE/Bethesda/BSScript/MergedBoundScript.h
	include/RE/Bethesda/BSScript/NF_util/NativeFunctionBase.h
	include/RE/Bethesda/BSScript/Object.h
	include/RE/Bethesda/BSScript/ObjectBindPolicy.h
	include/RE/Bethesda/BSScript/ObjectTypeInfo.h
	include/RE/Bethesda/BSScript/PackedInstructionStream.h
	include/RE/Bethesda/BSScript/PropertyGroupInfo.h
	include/RE/Bethesda/BSScript/PropertyTypeInfo.h
	include/RE/Bethesda/BSScript/SimpleAllocMemoryPagePolicy.h
	include/RE/Bethesda/BSScript/Stack.h
	include/RE/Bethesda/BSScript/StackFrame.h
	include/RE/Bethesda/BSScript/StatsEvent.h
	include/RE/Bethesda/BSScript/Struct.h
	include/RE/Bethesda/BSScript/StructTypeInfo.h
	include/RE/Bethesda/BSScript/TypeInfo.h
	include/RE/Bethesda/BSScript/Variable.h
	include/RE/Bethesda/BSScriptUtil.h
	include/RE/Bethesda/BSSemaphore.h
	include/RE/Bethesda/BSShader/BSBatchRenderer.h
	include/RE/Bethesda/BSShader/BSComputeShader.h
	include/RE/Bethesda/BSShader/BSDistanceObjectInstanceRenderer.h
	include/RE/Bethesda/BSShader/BSFadeNode.h
	include/RE/Bethesda/BSShader/BSImagespace.h
	include/RE/Bethesda/BSShader/BSLeafAnimNode.h
	include/RE/Bethesda/BSShader/BSLight.h
	include/RE/Bethesda/BSShader/BSMTAManager.h
	include/RE/Bethesda/BSShader/BSMTRManagerDefs.h
	include/RE/Bethesda/BSShader/BSMeshLODTriShape.h
	include/RE/Bethesda/BSShader/BSShader.h
	include/RE/Bethesda/BSShader/BSShaderAccumulator.h
	include/RE/Bethesda/BSShader/BSShaderData.h
	include/RE/Bethesda/BSShader/BSShaderLibType.h
	include/RE/Bethesda/BSShader/BSShaderManager.h
	include/RE/Bethesda/BSShader/BSShaderMaterial.h
	include/RE/Bethesda/BSShader/BSShaderProperty.h
	include/RE/Bethesda/BSShader/BSShaderPropertyLightData.h
	include/RE/Bethesda/BSShader/BSShaderRenderTargets.h
	include/RE/Bethesda/BSShader/BSShaderSDM.h
	include/RE/Bethesda/BSShader/BSShaderTechniqueIDMap.h
	include/RE/Bethesda/BSShader/BSShaderTextureSet.h
	include/RE/Bethesda/BSShader/BSShaderUtil.h
	include/RE/Bethesda/BSShader/BSShadowDirectionalLight_Compute.h
	include/RE/Bethesda/BSShader/BSTreeNode.h
	include/RE/Bethesda/BSShader/ImageSpace.h
	include/RE/Bethesda/BSShader/ImageSpaceManager.h
	include/RE/Bethesda/BSShader/ImageSpaceShaderParam.h
	include/RE/Bethesda/BSShader/Shaders/BSBloodSplatterShader.h
	include/RE/Bethesda/BSShader/Shaders/BSBloodSplatterShaderProperty.h
	include/RE/Bethesda/BSShader/Shaders/BSDFCompositeShader.h
	include/RE/Bethesda/BSShader/Shaders/BSDFCompositeShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSDFLightShader.h
	include/RE/Bethesda/BSShader/Shaders/BSDFLightShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSDFPrePassShader.h
	include/RE/Bethesda/BSShader/Shaders/BSDFPrePassShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSDFTiledLighting.h
	include/RE/Bethesda/BSShader/Shaders/BSDistantTreeShader.h
	include/RE/Bethesda/BSShader/Shaders/BSEffectShader.h
	include/RE/Bethesda/BSShader/Shaders/BSEffectShaderData.h
	include/RE/Bethesda/BSShader/Shaders/BSEffectShaderMaterial.h
	include/RE/Bethesda/BSShader/Shaders/BSEffectShaderProperty.h
	include/RE/Bethesda/BSShader/Shaders/BSGrassShaderProperty.h
	include/RE/Bethesda/BSShader/Shaders/BSImagespaceShader.h
	include/RE/Bethesda/BSShader/Shaders/BSImagespaceShaderLensFlare.h
	include/RE/Bethesda/BSShader/Shaders/BSImagespaceShaderVLS.h
	include/RE/Bethesda/BSShader/Shaders/BSLightingShader.h
	include/RE/Bethesda/BSShader/Shaders/BSLightingShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSLightingShaderMaterial.h
	include/RE/Bethesda/BSShader/Shaders/BSLightingShaderProperty.h
	include/RE/Bethesda/BSShader/Shaders/BSParticleShader.h
	include/RE/Bethesda/BSShader/Shaders/BSParticleShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSParticleShaderEmitter.h
	include/RE/Bethesda/BSShader/Shaders/BSSkyShader.h
	include/RE/Bethesda/BSShader/Shaders/BSSkyShaderProperty.h
	include/RE/Bethesda/BSShader/Shaders/BSUtilityShader.h
	include/RE/Bethesda/BSShader/Shaders/BSUtilityShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSWaterShader.h
	include/RE/Bethesda/BSShader/Shaders/BSWaterShaderCommon.h
	include/RE/Bethesda/BSShader/Shaders/BSWaterShaderMaterial.h
	include/RE/Bethesda/BSShader/Shaders/BSWaterShaderProperty.h
	include/RE/Bethesda/BSSkin.h
	include/RE/Bethesda/BSSoundHandle.h
	include/RE/Bethesda/BSSpring.h
	include/RE/Bethesda/BSStorage.h
	include/RE/Bethesda/BSStringPool.h
	include/RE/Bethesda/BSStringT.h
	include/RE/Bethesda/BSSystem/BSFile.h
	include/RE/Bethesda/BSSystem/BSFixedString.h
	include/RE/Bethesda/BSSystem/BSJobs.h
	include/RE/Bethesda/BSSystem/BSSocket.h
	include/RE/Bethesda/BSSystem/BSSocketDefines.h
	include/RE/Bethesda/BSSystem/BSSocketError.h
	include/RE/Bethesda/BSSystem/BSSocketServer.h
	include/RE/Bethesda/BSSystem/BSSystemFile.h
	include/RE/Bethesda/BSSystem/BSSystemFileStreamer.h
	include/RE/Bethesda/BSSystem/BSSystemMonitorEvent.h
	include/RE/Bethesda/BSSystem/BSTBTreeFile.h
	include/RE/Bethesda/BSSystem/BSTCreateFactory.h
	include/RE/Bethesda/BSSystem/BSTFactory.h
	include/RE/Bethesda/BSSystem/BSTPointerAndFlags.h
	include/RE/Bethesda/BSSystem/BSTSmartPointer.h
	include/RE/Bethesda/BSSystem/BSTaskletManager.h
	include/RE/Bethesda/BSSystem/FilePathUtilities.h
	include/RE/Bethesda/BSSystemMonitor/BSSystemMonitor.h
	include/RE/Bethesda/BSSystemMonitor/BSSystemMonitorMessage.h
	include/RE/Bethesda/BSSystemUtilities/BSSystemUtility.h
	include/RE/Bethesda/BSTFreeList.h
	include/RE/Bethesda/BSTInterpolator.h
	include/RE/Bethesda/BSTMessageQueue.h
	include/RE/Bethesda/BSTOptional.h
	include/RE/Bethesda/BSTextureSet.h
	include/RE/Bethesda/BSTextureStreamer.h
	include/RE/Bethesda/CELLJobs.h
	include/RE/Bethesda/CRC.h
	include/RE/Bethesda/Calendar.h
	include/RE/Bethesda/CombatFormulas.h
	include/RE/Bethesda/Console.h
	include/RE/Bethesda/ControlMap.h
	include/RE/Bethesda/CreateNS.h
	include/RE/Bethesda/DrawWorld.h
	include/RE/Bethesda/Events.h
	include/RE/Bethesda/FavoritesManager.h
	include/RE/Bethesda/FormComponents.h
	include/RE/Bethesda/FormFactory.h
	include/RE/Bethesda/FormUtil.h
	include/RE/Bethesda/GamePlayFormulas.h
	include/RE/Bethesda/GameScript.h
	include/RE/Bethesda/HUDModes.h
	include/RE/Bethesda/IMenu.h
	include/RE/Bethesda/IMovementInterface.h
	include/RE/Bethesda/InputDevice.h
	include/RE/Bethesda/InputEvent.h
	include/RE/Bethesda/Interface3D.h
	include/RE/Bethesda/InventoryUserUIUtils.h
	include/RE/Bethesda/ItemCrafted.h
	include/RE/Bethesda/LocalMap.h
	include/RE/Bethesda/MagicItems.h
	include/RE/Bethesda/Main.h
	include/RE/Bethesda/MenuControls.h
	include/RE/Bethesda/MenuCursor.h
	include/RE/Bethesda/MessageMenuManager.h
	include/RE/Bethesda/Movement.h
	include/RE/Bethesda/NavMesh.h
	include/RE/Bethesda/NavMeshInfoMap.h
	include/RE/Bethesda/PipboyInventoryUtils.h
	include/RE/Bethesda/PipboyManager.h
	include/RE/Bethesda/PlayerCharacter.h
	include/RE/Bethesda/PlayerControls.h
	include/RE/Bethesda/PowerArmor.h
	include/RE/Bethesda/PowerUtils.h
	include/RE/Bethesda/ProcessLists.h
	include/RE/Bethesda/Projectiles.h
	include/RE/Bethesda/SCRIPT_OUTPUT.h
	include/RE/Bethesda/SWFToCodeFunctionHandler.h
	include/RE/Bethesda/SceneGraph.h
	include/RE/Bethesda/Script.h
	include/RE/Bethesda/SendHUDMessage.h
	include/RE/Bethesda/Settings.h
	include/RE/Bethesda/ShadowSceneNode.h
	include/RE/Bethesda/SplineUtils.h
	include/RE/Bethesda/TESBoundAnimObjects.h
	include/RE/Bethesda/TESBoundObjects.h
	include/RE/Bethesda/TESCamera.h
	include/RE/Bethesda/TESCombatStyle.h
	include/RE/Bethesda/TESCondition.h
	include/RE/Bethesda/TESDataHandler.h
	include/RE/Bethesda/TESFaction.h
	include/RE/Bethesda/TESFile.h
	include/RE/Bethesda/TESForms.h
	include/RE/Bethesda/TESObjectREFRs.h
	include/RE/Bethesda/TESPackages.h
	include/RE/Bethesda/TESRace.h
	include/RE/Bethesda/TESWaterForm.h
	include/RE/Bethesda/TESWorldSpace.h
	include/RE/Bethesda/UI.h
	include/RE/Bethesda/UIMessage.h
	include/RE/Bethesda/UIMessageQueue.h
	include/RE/Bethesda/UIShaderFXInfo.h
	include/RE/Bethesda/UserEvents.h
	include/RE/Bethesda/VATS.h
	include/RE/Bethesda/Workshop.h
	include/RE/Fallout.h
	include/RE/Havok/Common/Base/Container/Array/hkArray.h
	include/RE/Havok/Common/Base/Container/Array/hkFixedInPlaceArray.h
	include/RE/Havok/Common/Base/Container/BlockStream/hkBlockStream.h
	include/RE/Havok/Common/Base/Math/Matrix/hkMatrix3.h
	include/RE/Havok/Common/Base/Math/Matrix/hkMatrix3f.h
	include/RE/Havok/Common/Base/Math/Matrix/hkMatrix4.h
	include/RE/Havok/Common/Base/Math/Matrix/hkMatrix4f.h
	include/RE/Havok/Common/Base/Math/Matrix/hkMatrix6.h
	include/RE/Havok/Common/Base/Math/Matrix/hkMatrix6f.h
	include/RE/Havok/Common/Base/Math/Matrix/hkRotation.h
	include/RE/Havok/Common/Base/Math/Matrix/hkRotationf.h
	include/RE/Havok/Common/Base/Math/Matrix/hkTransform.h
	include/RE/Havok/Common/Base/Math/Matrix/hkTransformf.h
	include/RE/Havok/Common/Base/Math/Quaternion/hkQuaternion.h
	include/RE/Havok/Common/Base/Math/Quaternion/hkQuaternionf.h
	include/RE/Havok/Common/Base/Math/Vector/hkSimdFloat.h
	include/RE/Havok/Common/Base/Math/Vector/hkVector4.h
	include/RE/Havok/Common/Base/Math/Vector/hkVector4f.h
	include/RE/Havok/Common/Base/Memory/Allocator/Lifo/hkLifoAllocator.h
	include/RE/Havok/Common/Base/Memory/Allocator/hkMemoryAllocator.h
	include/RE/Havok/Common/Base/Memory/Router/hkMemoryRouter.h
	include/RE/Havok/Common/Base/Memory/System/hkMemorySystem.h
	include/RE/Havok/Common/Base/Object/hkBaseObject.h
	include/RE/Havok/Common/Base/Object/hkReferencedObject.h
	include/RE/Havok/Common/Base/Reflection/hkClassEnum.h
	include/RE/Havok/Common/Base/Types/Geometry/Aabb/hkAabb.h
	include/RE/Havok/Common/Base/Types/Physics/ContactPoint/hkContactPoint.h
	include/RE/Havok/Common/Base/Types/Physics/ContactPoint/hkContactPointMaterial.h
	include/RE/Havok/Common/Base/Types/Physics/hkBaseDefs.h
	include/RE/Havok/Common/Base/Types/Physics/hkBaseTypes.h
	include/RE/Havok/Common/Base/Types/Physics/hkHandle.h
	include/RE/Havok/Common/Base/Types/Physics/hkRefPtr.h
	include/RE/Havok/Common/Base/Types/Physics/hkStepInfo.h
	include/RE/Havok/Physics/ConstraintSolver/VehicleFriction/hkpVehicleFriction.h
	include/RE/Havok/Physics/ConstraintSolver/VehicleFriction/hkpVehicleFrictionSolver.h
	include/RE/Havok/Physics/Physics/Dynamics/World/hknpWorld.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/Proxy/hknpCharacterProxy.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/RigidBody/hknpCharacterRigidbody.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/RigidBody/hknpCharacterRigidbodyCInfo.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/StateMachine/hknpCharacterContext.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/StateMachine/hknpCharacterState.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/StateMachine/hknpCharacterStateManager.h
	include/RE/Havok/Physics/Physics/Extensions/CharacterControl/hknpCharacterSurfaceInfo.h
	include/RE/Havok/Physics/Physics/Extensions/PhysicsSystem/hknpPhysicsSystem.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Aerodynamics/Default/hknpVehicleDefaultAerodynamics.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Aerodynamics/hknpVehicleAerodynamics.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Brake/Default/hknpVehicleDefaultBrake.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Brake/hknpVehicleBrake.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/DriverInput/Default/hknpVehicleDefaultAnalogDriverInput.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/DriverInput/hknpVehicleDriverInput.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Engine/Default/hknpVehicleDefaultEngine.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Engine/hknpVehicleEngine.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Steering/Default/hknpVehicleDefaultSteering.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Steering/hknpVehicleSteering.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Suspension/Default/hknpVehicleDefaultSuspension.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Suspension/hknpVehicleSuspension.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Transmission/Default/hknpVehicleDefaultTransmission.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/Transmission/hknpVehicleTransmission.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/TyreMarks/hknpTyreMarksInfo.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/VelocityDamper/Default/hknpVehicleDefaultVelocityDamper.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/VelocityDamper/hknpVehicleVelocityDamper.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/WheelCollide/LinerCast/hknpVehicleLinearCastWheelCollide.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/WheelCollide/RayCast/hknpVehicleRayCastWheelCollide.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/WheelCollide/hknpVehicleWheelCollide.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/hknpVehicleData.h
	include/RE/Havok/Physics/Physics/Extensions/Vehicle/hknpVehicleInstance.h
	include/RE/Havok/hknpAllHitsCollector.h
	include/RE/Havok/hknpBodyId.h
	include/RE/Havok/hknpClosestUniqueBodyIdHitCollector.h
	include/RE/Havok/hknpCollisionQueryCollector.h
	include/RE/Havok/hknpCollisionResult.h
	include/RE/Havok/hknpMaterialId.h
	include/RE/Havok/hknpShape.h
	include/RE/Havok/hknpUniqueBodyIdHitCollector.h
	include/RE/NetImmerse/NiAccumulator.h
	include/RE/NetImmerse/NiAnimation/BSAnimNote.h
	include/RE/NetImmerse/NiAnimation/NiBlendInterpolator.h
	include/RE/NetImmerse/NiAnimation/NiBlendTransformInterpolator.h
	include/RE/NetImmerse/NiAnimation/NiControllerManager.h
	include/RE/NetImmerse/NiAnimation/NiControllerSequence.h
	include/RE/NetImmerse/NiAnimation/NiInterpController.h
	include/RE/NetImmerse/NiAnimation/NiInterpolator.h
	include/RE/NetImmerse/NiAnimation/NiMultiTargetTransformController.h
	include/RE/NetImmerse/NiAnimation/NiQuatTransform.h
	include/RE/NetImmerse/NiAnimation/NiStringPalette.h
	include/RE/NetImmerse/NiAnimation/NiTextKey.h
	include/RE/NetImmerse/NiAnimation/NiTextKeyExtraData.h
	include/RE/NetImmerse/NiMain/BSDynamicTriShape.h
	include/RE/NetImmerse/NiMain/BSFlattenedBoneTree.h
	include/RE/NetImmerse/NiMain/BSGeometry.h
	include/RE/NetImmerse/NiMain/BSGeometrySegmentData.h
	include/RE/NetImmerse/NiMain/BSGeometrySegmentID.h
	include/RE/NetImmerse/NiMain/BSSkinInstance.h
	include/RE/NetImmerse/NiMain/BSTriShape.h
	include/RE/NetImmerse/NiMain/IRendererResourceManager.h
	include/RE/NetImmerse/NiMain/NiAVObject.h
	include/RE/NetImmerse/NiMain/NiAVObjectPalette.h
	include/RE/NetImmerse/NiMain/NiAbstractPoolAllocator.h
	include/RE/NetImmerse/NiMain/NiAlphaProperty.h
	include/RE/NetImmerse/NiMain/NiBool.h
	include/RE/NetImmerse/NiMain/NiBound.h
	include/RE/NetImmerse/NiMain/NiCamera.h
	include/RE/NetImmerse/NiMain/NiClone.h
	include/RE/NetImmerse/NiMain/NiCloningProcess.h
	include/RE/NetImmerse/NiMain/NiCollisionObject.h
	include/RE/NetImmerse/NiMain/NiColor.h
	include/RE/NetImmerse/NiMain/NiCullingProcess.h
	include/RE/NetImmerse/NiMain/NiDefaultAVObjectPalette.h
	include/RE/NetImmerse/NiMain/NiExtraData.h
	include/RE/NetImmerse/NiMain/NiFlags.h
	include/RE/NetImmerse/NiMain/NiFrustum.h
	include/RE/NetImmerse/NiMain/NiFrustumPlanes.h
	include/RE/NetImmerse/NiMain/NiGeometry.h
	include/RE/NetImmerse/NiMain/NiGeometryData.h
	include/RE/NetImmerse/NiMain/NiGeometryDataIterators.h
	include/RE/NetImmerse/NiMain/NiLight.h
	include/RE/NetImmerse/NiMain/NiMath.h
	include/RE/NetImmerse/NiMain/NiMatrix3.h
	include/RE/NetImmerse/NiMain/NiNode.h
	include/RE/NetImmerse/NiMain/NiObject.h
	include/RE/NetImmerse/NiMain/NiPlane.h
	include/RE/NetImmerse/NiMain/NiPoint2.h
	include/RE/NetImmerse/NiMain/NiPoint3.h
	include/RE/NetImmerse/NiMain/NiPoint4.h
	include/RE/NetImmerse/NiMain/NiProperty.h
	include/RE/NetImmerse/NiMain/NiQuatTransform.h
	include/RE/NetImmerse/NiMain/NiQuaternion.h
	include/RE/NetImmerse/NiMain/NiRTTI.h
	include/RE/NetImmerse/NiMain/NiRect.h
	include/RE/NetImmerse/NiMain/NiRefObject.h
	include/RE/NetImmerse/NiMain/NiShadeProperty.h
	include/RE/NetImmerse/NiMain/NiSkinData.h
	include/RE/NetImmerse/NiMain/NiSkinInstance.h
	include/RE/NetImmerse/NiMain/NiSkinPartition.h
	include/RE/NetImmerse/NiMain/NiSmartPointer.h
	include/RE/NetImmerse/NiMain/NiStream.h
	include/RE/NetImmerse/NiMain/NiStringExtraData.h
	include/RE/NetImmerse/NiMain/NiSwitchNode.h
	include/RE/NetImmerse/NiMain/NiTArray.h
	include/RE/NetImmerse/NiMain/NiTCollection.h
	include/RE/NetImmerse/NiMain/NiTConvertingStrideIterator.h
	include/RE/NetImmerse/NiMain/NiTDefaultAllocator.h
	include/RE/NetImmerse/NiMain/NiTLargeArray.h
	include/RE/NetImmerse/NiMain/NiTList.h
	include/RE/NetImmerse/NiMain/NiTListBase.h
	include/RE/NetImmerse/NiMain/NiTMap.h
	include/RE/NetImmerse/NiMain/NiTMapBase.h
	include/RE/NetImmerse/NiMain/NiTPointerAllocator.h
	include/RE/NetImmerse/NiMain/NiTPointerListBase.h
	include/RE/NetImmerse/NiMain/NiTPointerMap.h
	include/RE/NetImmerse/NiMain/NiTPtrSet.h
	include/RE/NetImmerse/NiMain/NiTSet.h
	include/RE/NetImmerse/NiMain/NiTStringMap.h
	include/RE/NetImmerse/NiMain/NiTexture.h
	include/RE/NetImmerse/NiMain/NiTimeController.h
	include/RE/NetImmerse/NiMain/NiTransform.h
	include/RE/NetImmerse/NiMain/NiTriBasedGeom.h
	include/RE/NetImmerse/NiMain/NiTriBasedGeomData.h
	include/RE/NetImmerse/NiMain/NiTriShape.h
	include/RE/NetImmerse/NiMain/NiTriShapeData.h
	include/RE/NetImmerse/NiMain/NiTriStrips.h
	include/RE/NetImmerse/NiMain/NiTriStripsData.h
	include/RE/NetImmerse/NiMain/NiViewerStrings.h
	include/RE/NetImmerse/NiMemStream.h
	include/RE/NetImmerse/NiObjectNET.h
	include/RE/NetImmerse/NiSystem/NiAllocator.h
	include/RE/NetImmerse/NiSystem/NiBinaryStream.h
	include/RE/NetImmerse/NiSystem/NiFile.h
	include/RE/NetImmerse/NiSystem/NiMemObject.h
	include/RE/NetImmerse/NiSystem/NiSystemDesc.h
	include/RE/NetImmerse/NiUpdateData.h
	include/RE/NiRTTI_IDs.h
	include/RE/RTTI.h
	include/RE/RTTI_IDs.h
	include/RE/Scaleform/GFx/GFx_AS3.h
	include/RE/Scaleform/GFx/GFx_ASMovieRootBase.h
	include/RE/Scaleform/GFx/GFx_ASString.h
	include/RE/Scaleform/GFx/GFx_Loader.h
	include/RE/Scaleform/GFx/GFx_Log.h
	include/RE/Scaleform/GFx/GFx_Player.h
	include/RE/Scaleform/GFx/GFx_Resource.h
	include/RE/Scaleform/GFx/GFx_Types.h
	include/RE/Scaleform/Kernel/SF_AllocInfo.h
	include/RE/Scaleform/Kernel/SF_Allocator.h
	include/RE/Scaleform/Kernel/SF_Array.h
	include/RE/Scaleform/Kernel/SF_Atomic.h
	include/RE/Scaleform/Kernel/SF_List.h
	include/RE/Scaleform/Kernel/SF_Log.h
	include/RE/Scaleform/Kernel/SF_Memory.h
	include/RE/Scaleform/Kernel/SF_MemoryHeap.h
	include/RE/Scaleform/Kernel/SF_RefCount.h
	include/RE/Scaleform/Kernel/SF_Stats.h
	include/RE/Scaleform/Kernel/SF_SysAlloc.h
	include/RE/Scaleform/Kernel/SF_System.h
	include/RE/Scaleform/Kernel/SF_Threads.h
	include/RE/Scaleform/Render/Render_Color.h
	include/RE/Scaleform/Render/Render_Constants.h
	include/RE/Scaleform/Render/Render_Containers.h
	include/RE/Scaleform/Render/Render_Context.h
	include/RE/Scaleform/Render/Render_Matrix2x4.h
	include/RE/Scaleform/Render/Render_Matrix3x4.h
	include/RE/Scaleform/Render/Render_Matrix4x4.h
	include/RE/Scaleform/Render/Render_ThreadCommandQueue.h
	include/RE/Scaleform/Render/Render_TreeNode.h
	include/RE/Scaleform/Render/Render_Types2D.h
	include/RE/Scaleform/Render/Render_Viewport.h
	include/RE/Shared/FileIO/TES.h
	include/RE/Shared/Misc/VatsEffectControl.h
	include/RE/Shared/Sky/Moon.h
	include/RE/Shared/Sky/Sky.h
	include/RE/Shared/TESForms/Objects/TESEffectShader.h
	include/RE/VTABLE_IDs.h
	include/RE/msvc/functional.h
	include/RE/msvc/memory.h
	include/RE/msvc/typeinfo.h
	include/REL/Relocation.h
	src/F4SE/API.cpp
	src/F4SE/Impl/PCH.cpp
	src/F4SE/Impl/WinAPI.cpp
	src/F4SE/Interfaces.cpp
	src/F4SE/Logger.cpp
	src/F4SE/Trampoline.cpp
	src/RE/Bethesda/Actor.cpp
	src/RE/Bethesda/BGSInventoryItem.cpp
	src/RE/Bethesda/BSAnimation/FirstPersonRootEvents.cpp
	src/RE/Bethesda/BSExtraData.cpp
	src/RE/Bethesda/BSGraphics/BSGraphics.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsHandles.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsLibType.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsRenderTargetManager.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsRenderer.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsResourceCache.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsState.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsTypes.cpp
	src/RE/Bethesda/BSGraphics/BSGraphicsUtility.cpp
	src/RE/Bethesda/BSResource.cpp
	src/RE/Bethesda/BSResource/BSResourceStream.cpp
	src/RE/Bethesda/BSResource/BSResourceStreamBase.cpp
	src/RE/Bethesda/BSResourceNiBinaryStream.cpp
	src/RE/Bethesda/BSScaleformManager.cpp
	src/RE/Bethesda/BSScript.cpp
	src/RE/Bethesda/BSScript/Array.cpp
	src/RE/Bethesda/BSScript/Internal/VirtualMachine.cpp
	src/RE/Bethesda/BSScript/Object.cpp
	src/RE/Bethesda/BSScript/ObjectTypeInfo.cpp
	src/RE/Bethesda/BSScript/PackedInstructionStream.cpp
	src/RE/Bethesda/BSScript/StackFrame.cpp
	src/RE/Bethesda/BSScript/Struct.cpp
	src/RE/Bethesda/BSScript/StructTypeInfo.cpp
	src/RE/Bethesda/BSScript/TypeInfo.cpp
	src/RE/Bethesda/BSScript/Variable.cpp
	src/RE/Bethesda/BSShader/BSShaderManager.cpp
	src/RE/Bethesda/BSShader/ImageSpace.cpp
	src/RE/Bethesda/BSShader/ImageSpaceManager.cpp
	src/RE/Bethesda/BSShader/Shaders/BSImagespaceShader.cpp
	src/RE/Bethesda/CRC.cpp
	src/RE/Bethesda/Calendar.cpp
	src/RE/Bethesda/DrawWorld.cpp
	src/RE/Bethesda/FormComponents.cpp
	src/RE/Bethesda/MenuCursor.cpp
	src/RE/Bethesda/TESBoundAnimObjects.cpp
	src/RE/Bethesda/TESForms.cpp
	src/RE/Bethesda/TESObjectREFRs.cpp
	src/RE/Fallout.cpp
	src/RE/NetImmerse/NiMain/NiAVObject.cpp
	src/RE/NetImmerse/NiMain/NiColor.cpp
	src/RE/NetImmerse/NiMain/NiPoint3.cpp
	src/RE/NetImmerse/NiMain/NiRect.cpp
	src/RE/NetImmerse/NiObjectNET.cpp
	src/RE/NetImmerse/NiSystem/NiBinaryStream.cpp
	src/RE/Scaleform/GFx/GFx_Player.cpp
	src/REL/Relocation.cpp
)
