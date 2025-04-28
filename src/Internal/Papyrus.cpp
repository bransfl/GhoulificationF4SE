#include "Internal/Papyrus.hpp"

namespace Internal
{
	bool Papyrus::SetPlayerCharGenRace(SCRIPT_PARAMS, RE::TESRace* a_newRace) noexcept
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

	RE::TESRace* Papyrus::GetPlayerCharGenRace(SCRIPT_PARAMS) noexcept
	{
		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		if (!player) {
			a_vm.PostError("RE::PlayerCharacter* player was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return nullptr;
		}

		return player->charGenRace;
	}

	bool Papyrus::IsPlayerCharGenRace(SCRIPT_PARAMS, RE::TESRace* a_raceToCompare) noexcept
	{
		if (!a_raceToCompare) {
			a_vm.PostError("Argument a_newRace was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return false;
		}

		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		if (!player) {
			a_vm.PostError("RE::PlayerCharacter* player was nullptr"sv, a_vmStackID, RE::BSScript::ErrorLogger::Severity::kError);
			return false;
		}

		return player->charGenRace == a_raceToCompare;
	}

	bool Papyrus::RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm) noexcept
	{
		a_vm->BindNativeMethod(SCRIPT_NAME, "SetPlayerCharGenRace"sv, SetPlayerCharGenRace, true);
		a_vm->BindNativeMethod(SCRIPT_NAME, "GetPlayerCharGenRace"sv, GetPlayerCharGenRace, true);
		a_vm->BindNativeMethod(SCRIPT_NAME, "IsPlayerCharGenRace"sv, IsPlayerCharGenRace, true);

		return true;
	}

	bool Papyrus::Callback(RE::BSScript::IVirtualMachine* a_vm) noexcept
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
