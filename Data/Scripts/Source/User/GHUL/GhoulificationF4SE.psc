Scriptname GHUL:GhoulificationF4SE native hidden


;/
; @brief	Sets the player's CharGenRace to the given race.
; 
; @param akNewRace	The player's new CharGenRace race.
; @return	True if the player's CharGenRace was successfully set.
;			False if the player's CharGenRace was not successfully set.
/;
bool Function SetPlayerCharGenRace(Race akNewRace) Global Native


;/
; @brief	Gets the player's charGenRace member.
; 
; @return	The player's charGenRace member.
/;
Race Function GetPlayerCharGenRace() Global Native
