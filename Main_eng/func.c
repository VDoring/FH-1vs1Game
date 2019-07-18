/* 계산식 등이 들어간 함수들을 모아놓는 곳 */
/* 이곳은 자작 헤더파일을 include 하지않음 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

/* 선택지 */
int First_select; //첫번째 선택. 시작, 초기화, 종료중 어떤것을 선택할지 정하는 변수
int Character_select; //두번째 선택. 어떤 캐릭터를 고를지 정하는 변수

/* 캐릭터/몬스터 스탯*/
int Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100; //Attacker 기본스탯
int Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200; //Depender 기본스탯
int Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150; //Allrounder 기본스탯
int Player_HP, Player_ATK, Player_DEF; //실 전투에서 사용하는 스탯(선택한 캐릭터의 능력치를 복사해 사용하는 변수)
int Monster1_HP = 3200, Monster1_ATK = 500, Monster1_DEF = 100; //실 전투에서 사용하는 라운드1 몬스터 스탯 

/* 전투중/게임시스템 */
int Attack_Number; // [때리기] [할퀴기] [차기] [베기]의 공격을 정하는 변수
int Damage; //계산한 데미지수를 담는 변수
int Turn = 1; //턴이 얼마나 지나갔나를 알려주는 변수
int monster_Turn = 0; //몬스터가 공격할 차례인지 알려주는 변수
int Scratch_Attack; //랜덤함수에 의한 플레이어 [할퀴기]의 공격성공률
int Scratch_random_number; // [할퀴기]선택시 크리티컬이 뜰지 말지를 정하기위한 랜덤함수를 넣은 변수
int Slash_Attack; //랜덤함수에 의한 플레이어 [베기]공격성공률
int Slash_Attack_random_number; // [베기]선택시 벤 부위(랜덤)에 따라 데미지를 달리하게 만들어주는 변수
int Monster_Attack; //랜덤함수에 의한 몬스터의 공격성공률
int Monster_Attack_random_number; //상대몬스터 턴일시 랜덤한 숫자에 따라 공격방식을 정할 수 있게 하는 변수


void random_num() { //랜덤한 숫자를 나타나게하는 구문(난수 생성)
	srand((unsigned int)time(NULL));
}

void title() { //메인타이틀(첫화면) 표시
	puts("[MAIN] --Welcome to HDR 1vs1--"); //메인화면
	printf("<<[1]Game start, [2]Reset, [3] Exit>>\n: "); //메인선택지
	scanf("%d", &First_select); //번호 입력
}

void choose_character() { //캐릭터 선택
	printf("\n[Choose your characters]------------------\n"); //캐릭터 선택 문구
	Sleep(100);
	printf(" -[1]Attacker - Attack specialization.\n -[2]Defender - Defence specialization.\n -[3]Allrounder - Balanced.\n\n: "); //캐릭터 설명
	scanf("%d", &Character_select);
}

void reset_data() { //2번. 초기화 실행시
	Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100;
	Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200;
	Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150;
	Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100;
	First_select = 0;
	Character_select = 0;
	Turn = 1, monster_Turn = 0;
}

void set_Attacker() { //Attacker 능력치 설정
	Player_HP = Attacker_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Attacker_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Attacker_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	printf("\t -Completed \"Attacker\" status settings!-");
}

void set_Defender() { //Defender 능력치 설정
	Player_HP = Defender_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Defender_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Defender_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	printf("\t -Completed \"Defender\" status settings!-");
}

void set_Allrounder() { //Allrounder 능력치 설정
	Player_HP = Allrounder_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Allrounder_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Allrounder_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	printf("\t -Completed \"Allrounder\" status settings!-");
}

void story() { //STAGE 1 스토리
	Sleep(2000);
	printf("\n\n__[STORY]__\n\nYou're walking down the street.\n");
	Sleep(1000);
	printf("But this road is dangerous. Even more because it's night.\n");
	Sleep(1000);
	printf("And you found the Monster..!\n\n");
}

void player_act() { //플레이어의 턴. 행동을 취한다
	while (1) {
		Sleep(1100);
		printf("\n\t=Choose your ACT=");
		Sleep(200);
		printf("\n\n[1]Hit    [2]Scratch   [3]Kick    [4]Cut\n\n: "); //어떻게 공격할건지 선택
		scanf("%d", &Attack_Number);
		if (Attack_Number >= 5 || Attack_Number <= 0) {
			printf("\n[Please input retry]\n\n");
		}
		else break;
	}
}

void player_AttackNum_1() { // 1. 때리기 선택시..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("you Hit opponent");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 2; //데미지에서 몬스터 방어력 나누기 2한만큼 빼기
}

void player_AttackNum_2() { // 2. 할퀴기 선택시..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("you Scratch opponent");
	Damage = Player_ATK / 3; //플레이어 공격력 나누기 3
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
	Scratch_random_number = rand(); //무작위 랜덤숫자 만들기
	Scratch_Attack = (int)Scratch_random_number % 10; // 랜덤숫자를 0~9로 만듬  <여기 이후 크리티컬 계산부분이 좀 이상한 것 같다. 계산식>
}

void player_AttackNum_2_Critical() { // 2. 할퀴기 크리티컬!
	printf("\n[Criical!]"); //크리티컬은 방어력 무시한다
	Damage += Damage * 2; //기존 계산된 데미지에 곱하기 2
}

void endline_player() { //플레이어 턴일때 상황정리
	Sleep(1000);
	printf("\nYou gave your opponent a \"%d\" damage.", Damage); //얼마만큼 데미지를 입혔는지 표시
	Sleep(1500);
	Monster1_HP -= Damage; //몬스터의 채력 - 데미지
	printf("\n\n\n=Remaining Monsters HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
	Sleep(1000);
	monster_Turn += 2;
	printf("\n\n==============================================================================\n\n");
}

void endline_monster() { //몬스터 턴일때 상황정리
	Sleep(1500);
	printf("\n\n\n=Your Hp : %d", Player_HP); //남은 플레이어의 채력 출력
	Turn++; //턴 증가
	Sleep(1000);
	printf("\n\n==============================================================================\n\n");
}

void player_AttackNum_3() { //3. 차기 선택시..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("You kick opponent.");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 2; //데미지에서 몬스터 방어력 나누기 2한만큼 빼기
}

void  player_AttackNum_4() { //4. 베기 선택시..
	Sleep(700);
	printf("\n\n==================================[Turn : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("You ");
	Slash_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
	Slash_Attack = (int)Slash_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬
}

void player_AttackNum_4_None() { //4. 베기 실패
	printf("didn't cut your opponent.\n");
	Damage = 0;
}

void player_AttackNum_4_Normal() { //4. 베기 성공
	printf("cut off your opponent.\n");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void player_AttackNum_4_Critical() { //4. 강력한 베기 성공
	printf("cut your opponent hard!\n");
	Damage = Player_ATK; //강력한 공격이므로 플레이어 공격력 그대로 데미지가 들어감
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void monster_act() { //몬스터 턴, 몬스터가 행동을 취함
	Sleep(1200);
	printf("\n\n==============================================================================\n\n");
	Sleep(1000);
	printf("Monster's Turn.\n");
	Monster_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
	Monster_Attack = (int)Monster_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬
}

void monster_Attack_None() { //몬스터 공격 실패
	Sleep(1000);
	printf("\nMonster failed to attack.");
	Damage = 0;
}

void monster_Attack_Normal() { //몬스터 공격 성공
	Sleep(1000);
	printf("\nMonster attack.");
	Damage = Monster1_ATK / 3; //데미지는 몬스터 공격력의 나누기 3
	Damage -= Player_DEF / 4; //데미지에서 플레이어 방어력 나누기 4한만큼 빼기
	Player_HP -= Damage; //플레이어 채력 - 데미지
	Sleep(1000);
	printf("\n\nYou wore a \"%d\" damage.", Damage); //얼마만큼 데미지를 입혔는지 표시
}

void monster_Attack_Critical() { //몬스터 강력한 공격 성공
	Sleep(1000);
	printf("\nMonster Hard attack!");
	Damage = Monster1_ATK; //강력한 공격이므로 몬스터의 공격력 그대로 들어감
	Damage -= (Player_DEF / 2) + Damage / 4; // < (Player_DEF / 2.5로 구현할려고 함.  Release버전으로 맞춘 상태이고. 원래 구현하려고 했던 것보다 데미지 적음) >
	Player_HP -= Damage; //플레이어 채력 - 데미지
	Sleep(1000);
	printf("\n\nYou wore a \"%d\" damage.", Damage); //얼마만큼 데미지를 입혔는지 표시
}

void knockdown_player() { //플레이어 HP가 0 이하일때. (즉 플레이어가 쓰러졌을때)
	printf("\n\n\n\t\t{Retire!}"); //전투 종료
	Sleep(500);
	printf("\n\t\tWinner : Monster"); //몬스터 승리!
	Sleep(800);
}

void knockdown_monster() { //몬스터 HP가 0 이하일때. (즉 몬스터가 쓰러졌을때)
	printf("\n\n\n\t\t{Retire!}"); //전투 종료
	Sleep(500);
	printf("\n\t\tWinner : Player"); //플레이어 승리!
	Sleep(800);
}

void knockdown_result_turn() {
	printf("\n\t\tTotal turn count : %d\n\n\n", Turn); //턴 수 출력
	printf("\n\n==============================================================================\n\n");
}
