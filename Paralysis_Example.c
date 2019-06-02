/* 1번 방법 */

...(중략)
turn++;

if (Paralysis_status == 1) {
	new_tern_Paralysis++;
	if (old_tern_Paralysis < new_tern_Paralysis) { // old = 이미 마비상태의 턴 < new = 새로이 독 데미지를 받을때.  |||  즉 old는 마비 턴 계산을 끝났을때 ++하고, new는 일반 Turn이 끝났을때 ++하면 된다.
		Paralysis_tern--; //계산되었으므로 마비 턴 감소
		
		printf("마비되어 움직일 수 없습니다.");
		printf("당신의 HP : %d", player_HP);
	}
}



/* 2번 방법 */

...(중략)
turn++;

if (Paralysis_status == 1) {
	new_tern_Paralysis++;
	if (old_tern_Paralysis < new_tern_Paralysis) { // old = 이미 마비상태의 턴 < new = 새로이 독 데미지를 받을때.  |||  즉 old는 마비 턴 계산을 끝났을때 ++하고, new는 일반 Turn이 끝났을때 ++하면 된다.
		Paralysis_random_number = rand(); //렌덤
		attack_or_nonattack = (int)Paralysis_random_number % 10;
		if (attack_or_nonattack <= 6) { //6미만일때
			printf("마비되어 움직일 수 없습니다.");
			Paralysis_tern--; //계산되었으므로 마비 턴 감소
		}
		if (attack_or_nonattack >= 7 && attack_or_nonattack <= 9) { //만약 7이상 9미만일때 - 즉 마비의 효과를 뚫고 공격할 수 있는 상황일때
			(일반공격패턴을 넣거나)
			printf("그냥 공백을 넣거나"); //printf("");
			sleep(0); //지연시간만 넣어서 대충 때우거나
		}
		(2번째, 3번째 방법을 택했다면 여기에 일반공격패턴을 넣기)
		printf("당신의 HP : %d", player_HP);
	}
}