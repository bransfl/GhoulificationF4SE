#pragma once

namespace Internal::Papyrus
{
	// Papyrus script name
	static inline constexpr std::string_view SCRIPT_NAME = "GHUL:GhoulificationF4SE"sv;

	/**
	 * @brief Sets the player's CharGenRace to the given race.
	 * @param a_newRace The player's new CharGenRace.
	 * @return True if the player's CharGenRace was successfully set.
	 *		   False if the player's CharGenRace was not successfully set.
	 */
	static bool SetPlayerCharGenRace(RE::BSScript::IVirtualMachine& a_vm, RE::VMStackID a_vmStackID, std::monostate,
		RE::TESRace* a_newRace) noexcept;

	/**
	 * @brief Gets the player's charGenRace member.
	 * @return The player's charGenRace member.
	 */
	static RE::TESRace* GetPlayerCharGenRace(RE::BSScript::IVirtualMachine& a_vm, RE::VMStackID a_vmStackID, std::monostate) noexcept;

	/**
	 * @brief Registers new Papyrus functions with the VM.
	 * @return True if functions were succesfully registered.
	 *		   False if functions were not successfully registered.
	 */
	static bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm) noexcept;

	/**
	 * @brief Callback function for Papyrus registration.
	 * @return True if functions were succesfully registered.
	 *		   False if functions were not successfully registered.
	 */
	bool Callback(RE::BSScript::IVirtualMachine* a_vm) noexcept;
}
