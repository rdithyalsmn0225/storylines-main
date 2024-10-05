enum E_PLAYER_JUMP_VARS
{
    JumpPressed,
    JumpAt,
    JumpCD
}

new PlayerJump[MAX_PLAYERS][E_PLAYER_JUMP_VARS];

stock ResetPlayerJump(playerid)
{
 	new var_clear[E_PLAYER_JUMP_VARS]; 
	PlayerJump[playerid] = var_clear;
}