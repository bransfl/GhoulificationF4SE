#pragma once

#include "RE/Bethesda/BSTHashMap.hpp"
#include "RE/NetImmerse/NiSmartPointer.hpp"
#include "RE/NetImmerse/NiTArray.hpp"
#include "RE/NetImmerse/NiTimeController.hpp"

namespace RE
{
	class BSAnimNote;
	class BSAnimNoteListener;
	class NiAVObjectPalette;
	class NiControllerSequence;
	class NiTextKeyExtraData;
	class NiStringPalette;

	class NiControllerManager
		: public NiTimeController // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::NiControllerManager };
		inline static constexpr auto VTABLE{ VTABLE::NiControllerManager };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::NiControllerManager };

		[[nodiscard]] static NiControllerManager* GetNiControllerManager(const NiObjectNET* a_object)
		{
			using func_t = decltype(&NiControllerManager::GetNiControllerManager);
			static REL::Relocation<func_t> func{ REL::RelocationID(1013515, 2271798) };
			return func(a_object);
		}

		[[nodiscard]] NiControllerSequence* GetSequenceByName(const BSFixedString& a_name)
		{
			using func_t = decltype(&NiControllerManager::GetSequenceByName);
			static REL::Relocation<func_t> func{ REL::ID(846648) };
			return func(this, a_name);
		}

		[[nodiscard]] NiControllerSequence* GetSequenceAt(std::uint16_t a_index)
		{
			if (a_index >= 0 && a_index < sequenceArray.size()) {
				return sequenceArray[a_index].get();
			}

			return nullptr;
		}

		[[nodiscard]] std::uint16_t GetSequenceCount() const noexcept
		{
			return sequenceArray.size();
		}

		// members
		NiTObjectArray<NiPointer<NiControllerSequence>> sequenceArray; // 48
		std::byte activeSequences[0x70 - 0x60];						   // 60 - To-Do
		BSTHashMap<BSFixedString, NiControllerSequence*> stringMap;	   // 70
		BSAnimNoteListener* listener;								   // A0
		bool cumulative;											   // A8
		std::byte tempBlendSeqs[0xC0 - 0xB0];						   // B0 - To-Do
		NiPointer<NiAVObjectPalette> objectPalette;					   // C0
	};
	static_assert(sizeof(NiControllerManager) == 0xC8);

	class NiControllerSequence
		: public NiObject // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::NiControllerSequence };
		inline static constexpr auto VTABLE{ VTABLE::NiControllerSequence };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::NiControllerSequence };

		enum class AnimState
		{
			kInactive,
			kAnimating,
			kEaseIn,
			kEaseOut,
			kTransSource,
			kTransDest,
			kMorphSource
		};

		class IDTag;
		class InterpArrayItem;

		bool Activate(std::uint8_t a_priority, bool a_startOver, float a_weight, float a_easeInTime, NiControllerSequence* a_timeSyncSeq, bool a_transition)
		{
			using func_t = decltype(&NiControllerSequence::Activate);
			static REL::Relocation<func_t> func{ REL::RelocationID(829033, 2271861) };
			return func(this, a_priority, a_startOver, a_weight, a_easeInTime, a_timeSyncSeq, a_transition);
		}

		// members
		BSFixedString name;									// 10
		std::uint32_t arraySize;							// 18
		std::uint32_t arrayGrowBy;							// 1C
		InterpArrayItem* interpArray;						// 20
		IDTag* idTagArray;									// 28
		float seqWeight;									// 30
		NiPointer<NiTextKeyExtraData> textKeys;				// 38
		std::byte cycleType[4];								// 40
		float frequency;									// 44
		float beginKeyTime;									// 48
		float endKeyTime;									// 4C
		float lastTime;										// 50
		float weightedLastTime;								// 54
		float lastScaledTime;								// 58
		NiControllerManager* owner;							// 60
		REX::Enum<AnimState, std::uint32_t> state;			// 68
		float offset;										// 6C
		float startTime;									// 70
		float endTime;										// 74
		float destFrame;									// 78
		NiControllerSequence* partnerSequence;				// 80
		BSFixedString accumRootName;						// 88
		NiAVObject* accumRoot;								// 90
		NiPointer<NiStringPalette> deprecatedStringPalette; // 98
		std::int16_t curAnimNIdx;							// A0
		NiPointer<BSAnimNote>* animNotes;					// A8
		std::uint16_t numNotes;								// B0
		bool removableObjects;								// B2
	};
	static_assert(sizeof(NiControllerSequence) == 0xB8);
}
