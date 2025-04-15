#include "Internal/Papyrus.hpp"

namespace Internal::Papyrus
{
	static bool SetPlayerCharGenRace(RE::BSScript::IVirtualMachine& a_vm, RE::VMStackID a_vmStackID, std::monostate,
		RE::TESRace* a_raceToSet)
	{
		if (!a_raceToSet) {
			a_vm.PostError("Argument a_raceToSet was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return false;
		}

		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		if (!player) {
			a_vm.PostError("RE::PlayerCharacter* player was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return false;
		}

		player->charGenRace = a_raceToSet;
		return true;
	}

	static bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->BindNativeMethod(SCRIPT_NAME, "SetPlayerCharGenRace"sv, SetPlayerCharGenRace, true);

		return true;
	}

	bool Callback(RE::BSScript::IVirtualMachine* a_vm)
	{
		if (!RegisterFunctions(a_vm)) {
			logger::error("Failed to register papyrus functions"sv);
			assert(false);
			return false;
		}

		logger::info("Papyrus functions registered"sv);
		return true;
	}

}
