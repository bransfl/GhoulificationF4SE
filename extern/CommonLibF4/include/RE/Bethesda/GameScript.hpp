#pragma once

#include "RE/Bethesda/Atomic.hpp"
#include "RE/Bethesda/BSFixedString.hpp"
#include "RE/Bethesda/BSLock.hpp"
#include "RE/Bethesda/BSScript.hpp"
#include "RE/Bethesda/BSStorage.hpp"
#include "RE/Bethesda/BSTEvent.hpp"
#include "RE/Bethesda/BSTFreeList.hpp"
#include "RE/Bethesda/BSTHashMap.hpp"
#include "RE/Bethesda/BSTMessageQueue.hpp"
#include "RE/Bethesda/BSTSingleton.hpp"
#include "RE/Bethesda/BSTSmartPointer.hpp"
#include "RE/Bethesda/BSTThreadScrapFunction.hpp"
#include "RE/Bethesda/BSTTuple.hpp"
#include "RE/Bethesda/BSTimer.hpp"
#include "RE/Bethesda/Events.hpp"
#include "RE/Bethesda/MemoryManager.hpp"
#include "RE/Bethesda/TESFile.hpp"
#include "RE/NetImmerse/NiSmartPointer.hpp"

namespace RE
{
	namespace BSScript
	{
		class IStore;
		class IVirtualMachine;
		class IVMDebugInterface;
		class IVMSaveLoadInterface;
		class Object;
		struct IHandleReaderWriter;
		struct StatsEvent;
	}

	namespace PlayerDifficultySettingChanged
	{
		struct Event;
	}

	namespace RadioManager
	{
		struct PipboyTransmitterDetectionEvent;
	}

	namespace Workshop
	{
		struct ItemDestroyedEvent;
		struct ItemGrabbedEvent;
		struct ItemMovedEvent;
		struct ItemPlacedEvent;
		struct ItemRepairedEvent;
		struct PowerOffEvent;
		struct PowerOnEvent;
		struct WorkshopModeEvent;
	}

	enum class ENUM_FORMTYPE;

	class BSLog;
	class BSStorage;
	class InputEnableLayerDestroyedEvent;
	class TESForm;
	class TESHitEvent;
	class TESObjectREFR;

	struct BGSLocationLoadedEvent;
	struct BGSOnPlayerCompanionDismiss;
	struct BGSOnPlayerCreateRobotEvent;
	struct BGSOnPlayerEnterVertibirdEvent;
	struct BGSOnPlayerFallLongDistances;
	struct BGSOnPlayerFireWeaponEvent;
	struct BGSOnPlayerHealTeammateEvent;
	struct BGSOnPlayerModArmorWeaponEvent;
	struct BGSOnPlayerModRobotEvent;
	struct BGSOnPlayerSwimmingEvent;
	struct BGSOnPlayerUseWorkBenchEvent;
	struct BGSOnSpeechChallengeAvailable;
	struct BGSRadiationDamageEvent;
	struct PositionPlayerEvent;
	struct TESActivateEvent;
	struct TESActiveEffectApplyRemoveEvent;
	struct TESActorLocationChangeEvent;
	struct TESBookReadEvent;
	struct TESCellAttachDetachEvent;
	struct TESCellFullyLoadedEvent;
	struct TESCombatEvent;
	struct TESCommandModeCompleteCommandEvent;
	struct TESCommandModeEnterEvent;
	struct TESCommandModeExitEvent;
	struct TESCommandModeGiveCommandEvent;
	struct TESConsciousnessEvent;
	struct TESDeathEvent;
	struct TESDeferredKillEvent;
	struct TESDestructionStageChangedEvent;
	struct TESEnterBleedoutEvent;
	struct TESEnterSneakingEvent;
	struct TESEscortWaitStartEvent;
	struct TESEscortWaitStopEvent;
	struct TESExitFurnitureEvent;
	struct TESFormDeleteEvent;
	struct TESFormIDRemapEvent;
	struct TESFurnitureEvent;
	struct TESGrabReleaseEvent;
	struct TESLimbCrippleEvent;
	struct TESLoadGameEvent;
	struct TESLocationClearedEvent;
	struct TESLockChangedEvent;
	struct TESMagicEffectApplyEvent;
	struct TESObjectLoadedEvent;
	struct TESObjectREFRTranslationEvent;
	struct TESOnPCDialogueTargetEvent;
	struct TESOpenCloseEvent;
	struct TESPickpocketFailedEvent;
	struct TESQuestInitEvent;
	struct TESResetEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESSellEvent;
	struct TESSpellCastEvent;
	struct TESSwitchRaceCompleteEvent;
	struct TESTrapHitEvent;
	struct TESTriggerEnterEvent;
	struct TESTriggerLeaveEvent;
	struct TESUniqueIDChangeEvent;
	struct WorkshopNPCTransferEvent;

	namespace GameScript
	{
		class DelayFunctor;

		struct StatsEvent;

		namespace Internal
		{
			class HitRegistrationList;
			class MagicEffectApplyRegistrationList;
			class RadiationDamageRegistrationList;
		}

		inline void LogFormError(
			const TESForm* a_obj,
			const char* a_error,
			BSScript::IVirtualMachine* a_vm,
			VMStackID a_stackID,
			BSScript::ErrorLogger::Severity a_severity = BSScript::ErrorLogger::Severity::kError)
		{
			using func_t = decltype(&LogFormError);
			static REL::Relocation<func_t> func{ REL::RelocationID(1081933, 2251028) };
			return func(a_obj, a_error, a_vm, a_stackID, a_severity);
		}

		class __declspec(novtable) DelayFunctor
			: public BSIntrusiveRefCounted // 08
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__DelayFunctor };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__DelayFunctor };

			enum class FunctorType
			{
				kMoveTo,
				kMoveToOwnEditorLoc,
				kDamageObject,
				kEnable,
				kDisable,
				kDelete,
				kSetPosition,
				kSetAngle,
				kSetMotionType,
				kNonLatentDelete,
				kMoveToPackLoc,
				kSetScale,
				kDropObject,
				kAttachAshPile,
				kAddRemoveConstraint,
				kAddRemoveRagdoll,
				kApplyHavokImpulse,
				kResetRefr,
				kSendPlayerToJail,
				kAddItem,
				kResurrect,
				kCast,
				kScrollCast,
				kRemoveItem,
				kWaitFor3D,
				kPlayBink,
				kMoveToNearestNavmesh,
				kClearDestruction,
				kWaitForResourceRecalc,
				kRemoveComponent,
				kDropRef
			};

			virtual ~DelayFunctor(); // 00

			// add
			[[nodiscard]] virtual BSScript::Variable operator()() = 0;													 // 01
			[[nodiscard]] virtual bool IsLatent() const = 0;															 // 02
			[[nodiscard]] virtual bool WantsRequeue() const { return false; }											 // 03
			[[nodiscard]] virtual FunctorType GetType() const = 0;														 // 04
			virtual bool SaveImpl(BSStorage& a_storage) const = 0;														 // 05
			virtual bool LoadImpl(const BSStorage& a_storage, std::uint32_t a_scriptSaveVersion, bool& a_dataValid) = 0; // 06

			F4_HEAP_REDEFINE_NEW(DelayFunctor);

			// members
			VMStackID stackID; // 0C
		};
		static_assert(sizeof(DelayFunctor) == 0x10);

		class __declspec(novtable) Logger
			: public BSScript::ErrorLogger // 00
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__Logger };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__Logger };

			// override (BSScript::ErrorLogger)
			void PostErrorImpl(const BSScript::ICachedErrorMessage* a_errMsg, Severity a_severity) override; // 01

			// members
			BSFixedString logFolder; // A0
			BSLog* log;				 // A8
		};
		static_assert(sizeof(Logger) == 0xB0);

		struct __declspec(novtable) HandlePolicy
			: public BSScript::IObjectHandlePolicy // 00
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__HandlePolicy };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__HandlePolicy };

			inline static constexpr auto EMPTY_HANDLE = static_cast<VMHandle>(0xFFFF00000000);

			// override (BSScript::IObjectHandlePolicy)
			bool HandleIsType(VMTypeID a_type, VMHandle a_handle) const override;				   // 01
			bool GetHandleType(VMHandle a_handle, VMTypeID& a_typeID) const override;			   // 02
			bool IsHandleLoaded(VMHandle a_handle) const override;								   // 03
			bool IsHandleObjectAvailable(VMHandle a_handle) const override;						   // 04
			bool ShouldAttemptToCleanHandle(VMHandle a_handle) const override;					   // 05
			VMHandle EmptyHandle() const override { return EMPTY_HANDLE; }						   // 06
			VMHandle GetHandleForObject(VMTypeID a_type, const void* a_object) const override;	   // 07
			bool HasParent(VMHandle a_childHandle) const override;								   // 08
			VMHandle GetParentHandle(VMHandle a_childHandle) const override;					   // 09
			VMHandle GetHandleScriptsMovedFrom(VMHandle a_newHandle) const override;			   // 0A
			VMHandle GetSaveRemappedHandle(VMHandle a_saveHandle) const override;				   // 0B
			void* GetObjectForHandle(VMTypeID a_type, VMHandle a_handle) const override;		   // 0C
			void PersistHandle(VMHandle a_handle) override;										   // 0D
			void ReleaseHandle(VMHandle a_handle) override;										   // 0E
			void ConvertHandleToString(VMHandle a_handle, BSFixedString& a_string) const override; // 0F

			[[nodiscard]] static VMHandle GetHandleForInventoryID(std::uint16_t a_uniqueID, std::uint32_t a_containerFormID) noexcept
			{
				return static_cast<VMHandle>(static_cast<std::uint32_t>(a_containerFormID)) |
					   (static_cast<VMHandle>(a_uniqueID) << 32ull) |
					   (1ull << (32ull + 16ull));
			}

			void DropSaveLoadRemapData()
			{
				using func_t = decltype(&HandlePolicy::DropSaveLoadRemapData);
				static REL::Relocation<func_t> func{ REL::RelocationID(647657, 2249995) };
				return func(this);
			}

			void GetInventoryObjFromHandle(VMHandle a_cobj, TESObjectREFR*& a_container, std::uint16_t& a_uniqueID, TESObjectREFR*& a_inWorldREFR)
			{
				using func_t = decltype(&HandlePolicy::GetInventoryObjFromHandle);
				static REL::Relocation<func_t> func{ REL::RelocationID(66597, 2249989) };
				return func(this, a_cobj, a_container, a_uniqueID, a_inWorldREFR);
			}

			void UpdatePersistence()
			{
				using func_t = decltype(&HandlePolicy::UpdatePersistence);
				static REL::Relocation<func_t> func{ REL::RelocationID(11020, 2249991) };
				return func(this);
			}

			// members
			mutable BSSpinLock persistLock;							 // 08
			BSTHashMap<VMHandle, std::uint32_t> persistRefCount;	 // 10
			BSTHashMap<VMHandle, bool> queuedPromotes;				 // 40
			mutable BSSpinLock remapLock;							 // 70
			BSTHashMap<std::uint32_t, std::uint32_t> changedFormIDs; // 78
		};
		static_assert(sizeof(HandlePolicy) == 0xA8);

		class __declspec(novtable) ObjectBindPolicy
			: public BSScript::ObjectBindPolicy // 00
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__ObjectBindPolicy };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__ObjectBindPolicy };

			struct QueuedObject
			{
			public:
				// members
				BSTSmartPointer<BSScript::Object> createdObject; // 00
				BSScript::MergedBoundScript boundInfo;			 // 08
			};
			static_assert(sizeof(QueuedObject) == 0x18);

			// override (BSScript::ObjectBindPolicy)
			void EnsureBaseDataLoaded(VMHandle a_objHandle) override;																																															   // 01
			void ObjectNoLongerNeeded(VMHandle a_objHandle) override;																																															   // 02
			void AddBoundInfoImpl(VMHandle a_objHandle) override;																																																   // 03
			void ClearBoundInfoImpl(VMHandle a_objHandle) override;																																																   // 04
			void ClearDiskLoadedBoundInfoImpl(VMHandle a_objHandle) override;																																													   // 05
			void ClearAllBoundInfoImpl() override;																																																				   // 06
			void PostBindObject(VMHandle a_objHandle) override;																																																	   // 07
			std::uint32_t GetExtraInfoSize(VMHandle) const override { return 0; }																																												   // 08
			void WriteExtraInfo(VMHandle, const BSScript::IHandleReaderWriter&, BSStorage&) const override { return; }																																			   // 09
			void ReadExtraInfo(VMHandle a_objHandle, std::uint16_t a_handleVersion, const BSScript::IHandleReaderWriter& a_handleReaderWriter, const BSStorage& a_storage) override;																			   // 0A
			bool IsIgnoringClear() const override;																																																				   // 0B
			void ResolveProperties(VMHandle a_objTarget, const BSTSmartPointer<BSScript::Object>& a_object, const BSTSmartPointer<BSScript::BoundScript>& a_boundScript, bool a_postSaveConstOnly) override;													   // 0D
			void ResolveProperties(VMHandle a_objTarget, const BSTSmartPointer<BSScript::Object>& a_object, const BSScript::MergedBoundScript& a_boundScript, bool a_postSaveConstOnly) override;																   // 0C
			void ConvertProperties(VMHandle a_objTarget, const BSTSmartPointer<BSScript::BoundScript>& a_boundScript, bool a_constOnly, BSTScrapHashMap<BSFixedString, BSScript::Variable>& a_properties, std::uint32_t& a_nonConvertedProperties) const override; // 0F
			void ConvertProperties(VMHandle a_objTarget, const BSScript::MergedBoundScript& a_mergedScript, bool a_constOnly, BSTScrapHashMap<BSFixedString, BSScript::Variable>& a_properties, std::uint32_t& a_nonConvertedProperties) const override;		   // 0E

			void EndSaveLoad()
			{
				using func_t = decltype(&ObjectBindPolicy::EndSaveLoad);
				static REL::Relocation<func_t> func{ REL::RelocationID(1558837, 2250482) };
				return func(this);
			}

			// members
			mutable BSSpinLock queueLock;										   // 50
			bool resolveCalled;													   // 58
			bool ignoringClear;													   // 59
			bool initialLoadDone;												   // 5A
			BSTHashMap<VMHandle, BSTSmallSharedArray<QueuedObject>> queuedObjects; // 60
			BSTArray<VMHandle> queuedAliases;									   // 90
			BSTSet<VMHandle> initiallyLoadedObjects;							   // A8
		};
		static_assert(sizeof(ObjectBindPolicy) == 0xD8);

		class FragmentSystem
		{
		public:
			class Fragment
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSFixedString objectName;	// 08
				BSFixedString functionName; // 10
			};
			static_assert(sizeof(Fragment) == 0x18);

			class QuestStageFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> itemFragments; // 08
			};
			static_assert(sizeof(QuestStageFragments) == 0x38);

			struct QuestFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<QuestStageFragments>> stageFragments; // 08
			};
			static_assert(sizeof(QuestFragments) == 0x38);

			class BeginEndFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTSmartPointer<Fragment> beginFragment; // 08
				BSTSmartPointer<Fragment> endFragment;	 // 10
			};
			static_assert(sizeof(BeginEndFragments) == 0x18);

			class SceneFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTSmartPointer<Fragment> beginFragment;									  // 08
				BSTSmartPointer<Fragment> endFragment;										  // 10
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> actionFragments;		  // 18
				BSTHashMap<std::uint32_t, BSTSmartPointer<BeginEndFragments>> phaseFragments; // 48
			};
			static_assert(sizeof(SceneFragments) == 0x78);

			class PackageFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTSmartPointer<Fragment> beginFragment;  // 08
				BSTSmartPointer<Fragment> endFragment;	  // 10
				BSTSmartPointer<Fragment> changeFragment; // 18
			};
			static_assert(sizeof(PackageFragments) == 0x20);

			class PerkFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> entryFragments; // 08
			};
			static_assert(sizeof(PerkFragments) == 0x38);

			class TerminalFragments
				: public BSIntrusiveRefCounted // 00
			{
			public:
				// members
				BSTHashMap<std::uint32_t, BSTSmartPointer<Fragment>> menuItemFragments; // 08
			};
			static_assert(sizeof(TerminalFragments) == 0x38);

			// members
			BSTHashMap<std::uint32_t, BSTSmartPointer<QuestFragments>> questFragments;		  // 000
			mutable BSSpinLock kQuestFragmentSpinLock;										  // 030
			BSTHashMap<std::uint32_t, BSTSmartPointer<BeginEndFragments>> topicInfoFragments; // 038
			mutable BSSpinLock kTopicInfoFragmentSpinLock;									  // 068
			BSTHashMap<std::uint32_t, BSTSmartPointer<SceneFragments>> sceneFragments;		  // 070
			mutable BSSpinLock kSceneFragmentSpinLock;										  // 0A0
			BSTHashMap<std::uint32_t, BSTSmartPointer<PackageFragments>> packageFragments;	  // 0A8
			mutable BSSpinLock kPackageFragmentSpinLock;									  // 0D8
			BSTHashMap<std::uint32_t, BSTSmartPointer<PerkFragments>> perkFragments;		  // 0E0
			mutable BSSpinLock kPerkFragmentSpinLock;										  // 110
			BSTHashMap<std::uint32_t, BSTSmartPointer<TerminalFragments>> terminalFragments;  // 118
			mutable BSSpinLock kTerminalFragmentSpinLock;									  // 148
			BSTHashMap<std::uint32_t, BSTSmartPointer<BSScript::BoundScript>> boundScripts;	  // 150
			mutable BSSpinLock kBindInfoSpinLock;											  // 180
		};
		static_assert(sizeof(FragmentSystem) == 0x188);

		class __declspec(novtable) Profiler
			: public BSScript::IProfilePolicy // 000
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__Profiler };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__Profiler };

			// override (BSScript::IProfilePolicy)
			void StackFramePushQueued(VMStackID a_stackID, std::uint32_t a_frameNumber, const BSTSmartPointer<BSScript::Internal::IFuncCallQuery>& a_funcCallQuery) override;																 // 01
			void StackFramePushed(VMStackID a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;	 // 02
			void StackFramePopQueued(VMStackID a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override; // 03
			void StackFramePopped(VMStackID a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;	 // 04

			// members
			mutable BSSpinLock dataLock;								   // 008
			BSLog* globalProfilingLog;									   // 010
			BSTHashMap<std::uint32_t, BSLog*> watchedStacks;			   // 018
			BSTHashMap<BSFixedString, BSLog*> watchedScripts;			   // 048
			BSTHashMap<VMHandle, BSLog*> watchedObjects;				   // 078
			BSTArray<BSTTuple<BSFixedString, VMHandle>> watchedStackRoots; // 0A8
			BSTimer timer;												   // 0C0
		};
		static_assert(sizeof(Profiler) == 0x100);

		class __declspec(novtable) SavePatcher
			: public BSScript::ISavePatcherInterface // 00
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__SavePatcher };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__SavePatcher };

			// override (BSScript::ISavePatcherInterface)
			void PatchStackFrame(BSScript::StackFrame&, BSScript::IVirtualMachine&) override { return; } // 01
		};
		static_assert(sizeof(SavePatcher) == 0x8);
	}

	class __declspec(novtable) GameVM
		: public BSScript::IClientVM,						   // 0000
		  public BSScript::IStackCallbackSaveInterface,		   // 0008
		  public BSTEventSink<BSScript::StatsEvent>,		   // 0010
		  public BSTEventSink<InputEnableLayerDestroyedEvent>, // 0018
		  public BSTEventSink<PositionPlayerEvent>,			   // 0020
		  public BSTEventSink<TESFormDeleteEvent>,			   // 0028
		  public BSTEventSink<TESFormIDRemapEvent>,			   // 0030
		  public BSTEventSink<TESInitScriptEvent>,			   // 0037
		  public BSTEventSink<TESResolveNPCTemplatesEvent>,	   // 0040
		  public BSTEventSink<TESUniqueIDChangeEvent>,		   // 0048
		  public BSTSingletonSDM<GameVM>,					   // 0050
		  public BSTEventSource<GameScript::StatsEvent>		   // 0058
	{
	public:
		inline static constexpr auto RTTI{ RTTI::GameVM };
		inline static constexpr auto VTABLE{ VTABLE::GameVM };

		[[nodiscard]] static GameVM* GetSingleton()
		{
			static REL::Relocation<GameVM**> singleton{ REL::RelocationID(996227, 2689134) };
			return *singleton;
		}

		[[nodiscard]] BSTSmartPointer<BSScript::IVirtualMachine> GetVM() const noexcept { return impl; }

		bool QueuePostRenderCall(const BSTSmartPointer<GameScript::DelayFunctor>& a_functor)
		{
			using func_t = decltype(&GameVM::QueuePostRenderCall);
			static REL::Relocation<func_t> func{ REL::RelocationID(34412, 2251314) };
			return func(this, a_functor);
		}

		void RegisterForAllGameEvents()
		{
			using func_t = decltype(&GameVM::RegisterForAllGameEvents);
			static REL::Relocation<func_t> func{ REL::RelocationID(680454, 2251353) };
			return func(this);
		}

		void SendEventToObjectAndRelated(
			VMHandle a_object,
			const BSFixedString& a_eventName,
			const BSTThreadScrapFunction<bool(BSScrapArray<BSScript::Variable>&)>& a_args,
			const BSTThreadScrapFunction<bool(const BSTSmartPointer<BSScript::Object>&)>& a_filter,
			const BSTSmartPointer<BSScript::IStackCallbackFunctor>& a_callback)
		{
			using func_t = decltype(&GameVM::SendEventToObjectAndRelated);
			static REL::Relocation<func_t> func{ REL::ID(367992) };
			return func(this, a_object, a_eventName, a_args, a_filter, a_callback);
		}

		// members
		BSTSmartPointer<BSScript::IVirtualMachine> impl;											   // 00B0
		BSScript::IVMSaveLoadInterface* saveLoadInterface;											   // 00B8
		BSScript::IVMDebugInterface* debugInterface;												   // 00C0
		BSScript::SimpleAllocMemoryPagePolicy memoryPagePolicy;										   // 00C8
		BSScript::CompiledScriptLoader scriptLoader;												   // 00F8
		GameScript::Logger logger;																	   // 0130
		GameScript::HandlePolicy handlePolicy;														   // 01E0
		GameScript::ObjectBindPolicy objectBindPolicy;												   // 0288
		BSTSmartPointer<BSScript::IStore> scriptStore;												   // 0360
		GameScript::FragmentSystem fragmentSystem;													   // 0368
		GameScript::Profiler profiler;																   // 04F0
		GameScript::SavePatcher savePatcher;														   // 05F0
		mutable BSSpinLock freezeLock;																   // 05F8
		bool frozen;																				   // 0600
		mutable BSSpinLock vmTimeLock;																   // 0604
		std::uint32_t currentTime;																	   // 060C
		std::uint32_t currentMenuModeTime;															   // 0610
		std::uint32_t currentGameTime;																   // 0614
		bool updateHasBeenRun;																		   // 0618
		bool saveLoad;																				   // 0619
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512> renderSafeFunctorPool1;	   // 0620
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>> renderSafeFunctorQueue1;	   // 2638
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512> renderSafeFunctorPool2;	   // 2660
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>> renderSafeFunctorQueue2;	   // 4678
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512> postRenderFunctorPool1;	   // 46A0
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>> postRenderFunctorQueue1;	   // 66B8
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512> postRenderFunctorPool2;	   // 66E0
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>> postRenderFunctorQueue2;	   // 86F8
		mutable BSSpinLock renderSafeQueueLock;														   // 8720
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* renderSafeQueueToReadFrom; // 8728
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* renderSafeQueueToWriteTo;  // 8730
		mutable BSSpinLock postRenderQueueLock;														   // 8738
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* postRenderQueueToReadFrom; // 8740
		BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* postRenderQueueToWriteTo;  // 8748
		mutable BSSpinLock userLogLock;																   // 8750
		BSTHashMap<BSFixedString, BSScript::ErrorLogger*> userLogs;									   // 8758
		mutable BSSpinLock statsWarningLock;														   // 8788
		std::uint32_t initialSuspendOverageTime;													   // 8790
		std::uint32_t initialRunningOverageTime;													   // 8794
		std::uint32_t initialStackMemoryOverageTime;												   // 8798
		std::uint32_t lastWarningTime;																   // 879C
		std::uint32_t overflowFlags;																   // 87A0
	};
	static_assert(sizeof(GameVM) == 0x87A8);

	namespace GameScript
	{
		class __declspec(novtable) BasicEventHandler
			: public BSTEventSink<BGSLocationLoadedEvent>,						  // 000
			  public BSTEventSink<BGSOnPlayerCompanionDismiss>,					  // 008
			  public BSTEventSink<BGSOnPlayerEnterVertibirdEvent>,				  // 010
			  public BSTEventSink<BGSOnPlayerFallLongDistances>,				  // 018
			  public BSTEventSink<BGSOnPlayerFireWeaponEvent>,					  // 020
			  public BSTEventSink<BGSOnPlayerHealTeammateEvent>,				  // 028
			  public BSTEventSink<BGSOnPlayerModArmorWeaponEvent>,				  // 030
			  public BSTEventSink<BGSOnPlayerCreateRobotEvent>,					  // 038
			  public BSTEventSink<BGSOnPlayerModRobotEvent>,					  // 040
			  public BSTEventSink<BGSOnPlayerSwimmingEvent>,					  // 048
			  public BSTEventSink<BGSOnPlayerUseWorkBenchEvent>,				  // 050
			  public BSTEventSink<BGSOnSpeechChallengeAvailable>,				  // 058
			  public BSTEventSink<PlayerDifficultySettingChanged::Event>,		  // 060
			  public BSTEventSink<RadioManager::PipboyTransmitterDetectionEvent>, // 068
			  public BSTEventSink<TESActiveEffectApplyRemoveEvent>,				  // 070
			  public BSTEventSink<TESActivateEvent>,							  // 078
			  public BSTEventSink<TESActorLocationChangeEvent>,					  // 080
			  public BSTEventSink<TESBookReadEvent>,							  // 088
			  public BSTEventSink<TESCellAttachDetachEvent>,					  // 090
			  public BSTEventSink<TESCellFullyLoadedEvent>,						  // 098
			  public BSTEventSink<TESCombatEvent>,								  // 0A0
			  public BSTEventSink<TESCommandModeCompleteCommandEvent>,			  // 0A8
			  public BSTEventSink<TESCommandModeEnterEvent>,					  // 0B0
			  public BSTEventSink<TESCommandModeExitEvent>,						  // 0B8
			  public BSTEventSink<TESCommandModeGiveCommandEvent>,				  // 0C0
			  public BSTEventSink<TESDeathEvent>,								  // 0C8
			  public BSTEventSink<TESDeferredKillEvent>,						  // 0D0
			  public BSTEventSink<TESDestructionStageChangedEvent>,				  // 0D8
			  public BSTEventSink<TESEnterBleedoutEvent>,						  // 0E0
			  public BSTEventSink<TESEnterSneakingEvent>,						  // 0E8
			  public BSTEventSink<TESEscortWaitStartEvent>,						  // 0F0
			  public BSTEventSink<TESEscortWaitStopEvent>,						  // 0F8
			  public BSTEventSink<TESExitFurnitureEvent>,						  // 100
			  public BSTEventSink<TESFurnitureEvent>,							  // 108
			  public BSTEventSink<TESGrabReleaseEvent>,							  // 110
			  public BSTEventSink<TESConsciousnessEvent>,						  // 118
			  public BSTEventSink<TESLimbCrippleEvent>,							  // 120
			  public BSTEventSink<TESLoadGameEvent>,							  // 128
			  public BSTEventSink<TESLocationClearedEvent>,						  // 130
			  public BSTEventSink<TESLockChangedEvent>,							  // 138
			  public BSTEventSink<TESObjectLoadedEvent>,						  // 140
			  public BSTEventSink<TESObjectREFRTranslationEvent>,				  // 148
			  public BSTEventSink<TESOnPCDialogueTargetEvent>,					  // 150
			  public BSTEventSink<TESOpenCloseEvent>,							  // 158
			  public BSTEventSink<TESPickpocketFailedEvent>,					  // 160
			  public BSTEventSink<TESQuestInitEvent>,							  // 168
			  public BSTEventSink<TESResetEvent>,								  // 170
			  public BSTEventSink<TESSellEvent>,								  // 178
			  public BSTEventSink<TESSpellCastEvent>,							  // 180
			  public BSTEventSink<TESSwitchRaceCompleteEvent>,					  // 188
			  public BSTEventSink<TESTrapHitEvent>,								  // 190
			  public BSTEventSink<TESTriggerEnterEvent>,						  // 198
			  public BSTEventSink<TESTriggerLeaveEvent>,						  // 1A0
			  public BSTEventSink<Workshop::ItemDestroyedEvent>,				  // 1A8
			  public BSTEventSink<Workshop::ItemMovedEvent>,					  // 1B0
			  public BSTEventSink<Workshop::ItemPlacedEvent>,					  // 1B8
			  public BSTEventSink<Workshop::ItemRepairedEvent>,					  // 1C0
			  public BSTEventSink<Workshop::ItemGrabbedEvent>,					  // 1C8
			  public BSTEventSink<Workshop::PowerOffEvent>,						  // 1D0
			  public BSTEventSink<Workshop::PowerOnEvent>,						  // 1D8
			  public BSTEventSink<WorkshopNPCTransferEvent>,					  // 1E0
			  public BSTEventSink<Workshop::WorkshopModeEvent>,					  // 1E8
			  public BSTSingletonSDM<BasicEventHandler>							  // 1F0
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__BasicEventHandler };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__BasicEventHandler };

			// members
			GameVM* gameVM;								   // 1F8
			FragmentSystem* fragmentSystem;				   // 200
			HandlePolicy* handlePolicy;					   // 208
			ObjectBindPolicy* objectBindPolicy;			   // 210
			BSTSmartPointer<BSScript::IVirtualMachine> vm; // 218
		};
		static_assert(sizeof(BasicEventHandler) == 0x220);

		class __declspec(novtable) CombatEventHandler
			: public BSTEventSink<TESHitEvent>,				 // 00
			  public BSTEventSink<TESMagicEffectApplyEvent>, // 08
			  public BSTEventSink<BGSRadiationDamageEvent>,	 // 10
			  public BSTSingletonSDM<CombatEventHandler>	 // 18
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__CombatEventHandler };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__CombatEventHandler };

			// members
			BSTSmartPointer<BSScript::IVirtualMachine> vm;															  // 20
			mutable BSSpinLock hitLock;																				  // 28
			BSTHashMap<VMHandle, BSTSmartPointer<Internal::HitRegistrationList>> hitEvents;							  // 30
			mutable BSSpinLock magicEffectApplyLock;																  // 60
			BSTHashMap<VMHandle, BSTSmartPointer<Internal::MagicEffectApplyRegistrationList>> magicEffectApplyEvents; // 68
			mutable BSSpinLock radiationDamageLock;																	  // 98
			BSTHashMap<VMHandle, BSTSmartPointer<Internal::RadiationDamageRegistrationList>> radiationDamageEvents;	  // A0
		};
		static_assert(sizeof(CombatEventHandler) == 0xD0);

		class RefrOrInventoryObj
		{
		public:
			RefrOrInventoryObj() = default;

			explicit RefrOrInventoryObj(VMHandle a_cobj)
			{
				const auto vm = GameVM::GetSingleton();
				vm->handlePolicy.GetInventoryObjFromHandle(a_cobj, _container, _uniqueID, _ref);
			}

			[[nodiscard]] TESObjectREFR* Container() const noexcept { return _container; }
			[[nodiscard]] TESObjectREFR* Reference() const noexcept { return _ref; }
			[[nodiscard]] std::uint16_t UniqueID() const noexcept { return _uniqueID; }

		private:
			// members
			TESObjectREFR* _ref{ nullptr };		  // 00
			TESObjectREFR* _container{ nullptr }; // 08
			std::uint16_t _uniqueID{ 0 };		  // 10
		};
		static_assert(sizeof(RefrOrInventoryObj) == 0x18);

		inline void BindCObject(const BSTSmartPointer<BSScript::Object>& a_scriptObj, const RefrOrInventoryObj& a_cobj, BSScript::IVirtualMachine& a_vm)
		{
			using func_t = decltype(&BindCObject);
			static REL::Relocation<func_t> func{ REL::ID(81787) };
			return func(a_scriptObj, a_cobj, a_vm);
		}

		class __declspec(novtable) BaseHandleReaderWriter
			: public BSScript::IHandleReaderWriter
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__BaseHandleReaderWriter };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__BaseHandleReaderWriter };

			~BaseHandleReaderWriter() override;													// 00
			virtual std::uint16_t GetHandleVersion() const override;							// 142D8E390
			virtual bool WriteHandle(BSStorage& storage, VMHandle) const override;				// 142D8E398
			virtual bool ReadHandle(BSStorage const& storage, VMHandle&) const override;		// 142D8E3A0
			virtual bool ReadHandleNoRemap(BSStorage const& storage, VMHandle&) const override; // 142D8E3A8

			virtual bool WriteFormID(BSStorage& storage, std::uint32_t) const = 0;		 // 142D8E3B0
			virtual bool ReadFormID(const BSStorage& storage, std::uint32_t&) const = 0; // 142D8E3B8

			// members
			BSScript::IObjectHandlePolicy* objectHandlePolicy; // 08
		};
		static_assert(sizeof(BaseHandleReaderWriter) == 0x10);
		class DataFileHandleReaderWriter
			: public BaseHandleReaderWriter
		{
		public:
			inline static constexpr auto RTTI{ RTTI::GameScript__DataFileHandleReaderWriter };
			inline static constexpr auto VTABLE{ VTABLE::GameScript__DataFileHandleReaderWriter };

			~DataFileHandleReaderWriter() override; // 00
			// DataFileHandleReaderWriter(TESFile *f, BSScript::IObjectHandlePolicy * objectHandlePolicy);
			virtual bool WriteFormID(BSStorage& storage, std::uint32_t) const override;		  // 142D8E3B0
			virtual bool ReadFormID(const BSStorage& storage, std::uint32_t&) const override; // 142D8E3B8

			// members
			TESFile* file; // 10
		};
		static_assert(sizeof(DataFileHandleReaderWriter) == 0x18);

	}

}
