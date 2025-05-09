#pragma once

#include "RE/Bethesda/TESForms.hpp"

namespace RE
{
	namespace BGSMod::Property
	{
		class BridgeI;
	}

	enum class ENUM_FORMTYPE;
	enum class OBJECT_CATEGORY_TYPE;
	enum class OBJECT_TYPE;

	class TESForm;

	class __declspec(novtable) IFormFactory
	{
	public:
		inline static constexpr auto RTTI{ RTTI::IFormFactory };
		inline static constexpr auto VTABLE{ VTABLE::IFormFactory };

		virtual ~IFormFactory(); // 00

		// add
		[[nodiscard]] virtual TESForm* DoCreate() = 0;												   // 01
		[[nodiscard]] virtual const char* GetFormName() const = 0;									   // 02
		[[nodiscard]] virtual ENUM_FORMTYPE GetFormID() const = 0;									   // 03
		[[nodiscard]] virtual const char* GetObjectName() const { return nullptr; }					   // 04
		[[nodiscard]] virtual OBJECT_TYPE GetObjectType() const;									   // 05
		[[nodiscard]] virtual OBJECT_CATEGORY_TYPE GetObjectCategory() const;						   // 06
		[[nodiscard]] virtual BGSMod::Property::BridgeI* GetPropertyBridge() const { return nullptr; } // 07

		[[nodiscard]] static auto GetFormFactories()
			-> std::span<IFormFactory*, std::to_underlying(ENUM_FORMTYPE::kTotal)>
		{
			constexpr auto len = std::to_underlying(ENUM_FORMTYPE::kTotal);
			static REL::Relocation<IFormFactory*(*)[len]> factories{ REL::RelocationID(228366, 2689177) };
			return { *factories };
		}
	};
	static_assert(sizeof(IFormFactory) == 0x8);

	template <class T, ENUM_FORMTYPE ID = T::FORMTYPE>
	class __declspec(novtable) ConcreteFormFactory
		: public IFormFactory // 00
	{
	public:
		[[nodiscard]] static ConcreteFormFactory* GetFormFactory()
		{
			const auto factories = GetFormFactories();
			return static_cast<ConcreteFormFactory*>(factories[std::to_underlying(ID)]);
		}

		[[nodiscard]] T* Create() { return static_cast<T*>(DoCreate()); }

		// members
		const char* name{ nullptr };
	};

	template <class T, ENUM_FORMTYPE ID, OBJECT_TYPE TYPE, OBJECT_CATEGORY_TYPE CATEGORY>
	class __declspec(novtable) ConcreteObjectFormFactory
		: public ConcreteFormFactory<T, ID> // 00
	{
	public:
	};

	class DefaultObjectFormFactory
		: public IFormFactory // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::__DefaultObjectFormFactory };
		inline static constexpr auto VTABLE{ VTABLE::__DefaultObjectFormFactory };

		virtual ~DefaultObjectFormFactory(); // 00

		// override
		[[nodiscard]] TESForm* DoCreate() override // 01
		{
			return new BGSDefaultObject("", ENUM_FORMTYPE::kNONE, "");
		}

		[[nodiscard]] const char* GetFormName() const override { return "DefaultObject"; }		// 02
		[[nodiscard]] ENUM_FORMTYPE GetFormID() const override { return ENUM_FORMTYPE::kDFOB; } // 03
		[[nodiscard]] const char* GetObjectName() const override { return "DefaultObject"; }	// 04
		[[nodiscard]] OBJECT_TYPE GetObjectType() const override;								// 05
		[[nodiscard]] OBJECT_CATEGORY_TYPE GetObjectCategory() const override;					// 06

		[[nodiscard]] static BGSDefaultObject* Create(const char* a_name, const char* a_description, ENUM_FORMTYPE a_formType)
		{
			auto form = new BGSDefaultObject(a_name, a_formType, a_description);
			return form;
		}

		[[nodiscard]] static BGSDefaultObject* Create(const char* a_name, ENUM_FORMTYPE a_formType)
		{
			return Create(a_name, "", a_formType);
		}
	};
	static_assert(sizeof(DefaultObjectFormFactory) == 0x08);
}
