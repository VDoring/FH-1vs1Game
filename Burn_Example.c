...(중략)
turn++;

if(burn_status == 1) {
	new_tern_burn++;
	if(old_tern_burn < new_tern_burn) {
		burn_damage = 0;
		burn_damage += player_HP / 6;
		player_HP -= burn_damage;
		old_tern_burn++;
		
		printf("당신이 입은 화상데미지 : %d", burn_damage);
		printf("당신의 HP : %d:", player_HP);
	}
}