...(중략)
turn++; //만약 독걸린 상태라면 turn++; 이전 poison_status++;하기. (물론 poison_status는 미리 0으로 초기화해야함)

if (poison_status == 1) { //독에 걸린 상태일때
	new_tern_poison++;
	if (old_tern_poison++ < new_tern_poison) { // old = 이미 독데미지를 받은 상태의 턴 < new = 새로이 독 데미지를 받을때.  |||  즉 old는 독제미지 계산을 끝났을때 ++하고, new는 일반 Turn이 끝났을때 ++하면 된다.
		poison_Damage = 0; //독데미지를 이 변수에 담기전 초기화
		poison_Damage += (player_HP / 8) + ((player_HP / 13) * new_tern_poison); // 독데미지 계산식 : 플레이어의 남아있는 HP중 8분의 1 + 플레이어의 남아있는 HP중 13분의 1 곱하기 독이 지속된 턴(즉 턴이 지나면 점점 강해지는 맹독같은 효과)
		player_HP -= poison_Damage; // 독데미지 받음
		old_tern_poison++; // 독데미지 계산이 끝났으므로 old++;

		printf("당신이 입은 독데미지 : %d", poison_Damage);
		printf("당신의 HP : %d", player_HP);
	}
}
