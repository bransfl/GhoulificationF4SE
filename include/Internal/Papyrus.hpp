#pragma once

// default script parameters required by the VM and stuff
#define SCRIPT_PARAMS RE::BSScript::IVirtualMachine &a_vm, RE::VMStackID a_vmStackID, std::monostate

namespace Internal
{
	class Papyrus
	{
	public:
		// Papyrus script name.
		static inline const constexpr std::string_view SCRIPT_NAME = "GhoulificationF4SE"sv;

		/**
		 * @brief Sets the player's CharGenRace to the given race.
		 *
		 * @param a_newRace The player's new CharGenRace.
		 * @return True if the player's CharGenRace was successfully set.
		 *		   False if the player's CharGenRace was not successfully set.
		 */
		static bool SetPlayerCharGenRace(SCRIPT_PARAMS, RE::TESRace* a_newRace) noexcept;

		/**
		 * @brief Gets the player's charGenRace member.
		 *
		 * @return The player's charGenRace member.
		 */
		static RE::TESRace* GetPlayerCharGenRace(SCRIPT_PARAMS) noexcept;

		/**
		 * @brief Checks if the player's charGenRace is the same as akRaceToCompare.
		 *
		 * @param a_raceToCompare The race to compare to the player's charGenRace.
		 * @return True if the player's charGenRace is the same as akRaceToCompare.
		 *		   False if the player's charGenRace is not the same as akRaceToCompare.
		 */
		static bool IsPlayerCharGenRace(SCRIPT_PARAMS, RE::TESRace* a_raceToCompare) noexcept;

		/**
		 * @brief Registers new Papyrus functions with the VM.
		 *
		 * @return True if functions were succesfully registered.
		 *		   False if functions were not successfully registered.
		 */
		static bool RegisterFunctions(RE::BSScript::IVirtualMachine* a_vm) noexcept;

		/**
		 * @brief Callback function for Papyrus registration.
		 *
		 * @return True if functions were succesfully registered.
		 *		   False if functions were not successfully registered.
		 */
		static bool Callback(RE::BSScript::IVirtualMachine* a_vm) noexcept;
	};
}
