Scriptname GhoulificationF4SE native hidden
{
	Papyrus script for GhoulificationF4SE.dll functions.
	
	@author bp42s
}


;/
; Gets the player's charGenRace.
;
; @return	The player's charGenRace.
/;
Race Function GetPlayerCharGenRace() Global Native


;/
; Sets the player's charGenRace to the given race.
;
; @param akNewRace	The player's new charGenRace.
; @return	True if the player's charGenRace was successfully set.
;			False if the player's charGenRace was not successfully set.
/;
bool Function SetPlayerCharGenRace(Race akNewRace) Global Native


;/
; Checks if the player's charGenRace is the same as akRaceToCompare.
;
; @param akRaceToCompare	The race to compare to the player's charGenRace.
; @return 	True if the player's charGenRace is the same as akRaceToCompare.
;			False if the player's charGenRace is not the same as akRaceToCompare.
/;
bool Function IsPlayerCharGenRace(Race akRaceToCompare) Global Native
