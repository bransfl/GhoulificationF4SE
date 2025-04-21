#include "Internal/Papyrus.hpp"

namespace Internal::Papyrus
{
	static bool SetPlayerCharGenRace(RE::BSScript::IVirtualMachine& a_vm, RE::VMStackID a_vmStackID, std::monostate,
		RE::TESRace* a_newRace) noexcept
	{
		if (!a_newRace) {
			a_vm.PostError("Argument a_newRace was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return false;
		}

		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		if (!player) {
			a_vm.PostError("RE::PlayerCharacter* player was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return false;
		}

		player->charGenRace = a_newRace;
		return true;
	}

	static RE::TESRace* GetPlayerCharGenRace(RE::BSScript::IVirtualMachine& a_vm, RE::VMStackID a_vmStackID, std::monostate) noexcept
	{
		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		if (!player) {
			a_vm.PostError("RE::PlayerCharacter* player was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return nullptr;
		}

		RE::TESRace* playerCharGenRace = player->charGenRace;
		return playerCharGenRace;
	}

	static bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm) noexcept
	{
		a_vm->BindNativeMethod(SCRIPT_NAME, "SetPlayerCharGenRace"sv, SetPlayerCharGenRace, true);
		a_vm->BindNativeMethod(SCRIPT_NAME, "GetPlayerCharGenRace"sv, GetPlayerCharGenRace, true);

		return true;
	}

	bool Callback(RE::BSScript::IVirtualMachine* a_vm) noexcept
	{
		if (!RegisterFunctions(a_vm)) {
			logger::error("Failed to register papyrus functions"sv);
			assert(false);
			return false;
		}

		logger::info("Papyrus functions successfully registered"sv);
		return true;
	}
}
