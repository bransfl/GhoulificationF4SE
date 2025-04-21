Scriptname GhoulificationF4SE native hidden
{
	Papyrus script for GhoulificationF4SE.dll functions.
	
	@author bp42s
}


;/
; @brief	Sets the player's charGenRace to the given race.
; 
; @param akNewRace	The player's new charGenRace race.
; @return	True if the player's charGenRace was successfully set.
;			False if the player's charGenRace was not successfully set.
/;
bool Function SetPlayerCharGenRace(Race akNewRace) Global Native


;/
; @brief	Gets the player's charGenRace member.
; 
; @return	The player's charGenRace member.
/;
Race Function GetPlayerCharGenRace() Global Native
