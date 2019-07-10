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
	printf("<<게임시작은 1번, 데이터초기화는 2번, 종료는 3번을 입력해주세요.>>\n"); //메인선택지
	scanf("%d", &First_select); //번호 입력
}

void choose_character() { //캐릭터 선택
	printf("\n[캐릭터를 선택하십시오]------------------\n"); //캐릭터 선택 문구
	Sleep(100);
	printf(" -[1]Attacker - 공격에 특화되어 있습니다.\n -[2]Defender - 방어에 특화되어 있습니다.\n -[3]Allrounder - 벨런스형입니다.\n\n"); //캐릭터 설명
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
	printf("\t -Attacker 설정이 완료되었습니다!-");
}

void set_Defender() { //Defender 능력치 설정
	Player_HP = Defender_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Defender_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Defender_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	printf("\t -Defender 설정이 완료되었습니다!-");
}

void set_Allrounder() { //Allrounder 능력치 설정
	Player_HP = Allrounder_HP; //실 전투에 사용할 변수와 동기화
	Player_ATK = Allrounder_ATK; //실 전투에 사용할 변수와 동기화
	Player_DEF = Allrounder_DEF; //실 전투에 사용할 변수와 동기화
	Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100; //이전 데이터가 남아있을 수 있기때문에 초기화
	Turn = 1; //턴 초기화
	printf("\t -Allrounder 설정이 완료되었습니다!-");
}

void story() { //STAGE 1 스토리
	Sleep(2000);
	printf("\n\n__[STORY]__\n\n당신은 길을 가고 있었다.\n");
	Sleep(1000);
	printf("하지만 당신이 가는 이 길은 평소에 흉악한 몬스터들이 많이 나타나고, 하필 지금은 밤이라 더 많이 출몰한다.\n");
	Sleep(1000);
	printf("그리고 어느세 당신은 뒤에 몰레 따라오던 몬스터를 보게 되는데..\n\n");
}

void player_act() { //플레이어의 턴. 행동을 취한다
	while (1) {
		Sleep(1100);
		printf("\n\t=당신은 무엇을 할까?=");
		Sleep(200);
		printf("\n\n[1]때리기    [2]할퀴기    [3]차기    [4]베기\n\n입력 -> "); //어떻게 공격할건지 선택
		scanf("%d", &Attack_Number);
		if (Attack_Number >= 5 || Attack_Number <= 0) {
			printf("\n[다시 입력해주세요]\n\n");
		}
		else break;
	}
}

void player_AttackNum_1() { // 1. 때리기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("당신은 상대를 때렸습니다.");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 2; //데미지에서 몬스터 방어력 나누기 2한만큼 빼기
}

void player_AttackNum_2() { // 2. 할퀴기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("당신은 상대를 할퀴었습니다.");
	Damage = Player_ATK / 3; //플레이어 공격력 나누기 3
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
	Scratch_random_number = rand(); //무작위 랜덤숫자 만들기
	Scratch_Attack = (int)Scratch_random_number % 10; // 랜덤숫자를 0~9로 만듬  <여기 이후 크리티컬 계산부분이 좀 이상한 것 같다. 계산식>
}

void player_AttackNum_2_Critical() { // 2. 할퀴기 크리티컬!
	printf("\n[크리티컬!]"); //크리티컬은 방어력 무시한다
	Damage += Damage * 2; //기존 계산된 데미지에 곱하기 2
}

void endline_player() { //플레이어 턴일때 상황정리
	Sleep(1000);
	printf("\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
	Sleep(1500);
	Monster1_HP -= Damage; //몬스터의 채력 - 데미지
	printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
	Sleep(1000);
	monster_Turn += 2;
	printf("\n\n==============================================================================\n\n");
}

void endline_monster() { //몬스터 턴일때 상황정리
	Sleep(1500);
	printf("\n\n\n=딩신의 Hp : %d", Player_HP); //남은 플레이어의 채력 출력
	Turn++; //턴 증가
	Sleep(1000);
	printf("\n\n==============================================================================\n\n");
}

void player_AttackNum_3() { //3. 차기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	puts("당신은 상대를 찼습니다.");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 2; //데미지에서 몬스터 방어력 나누기 2한만큼 빼기
}

void  player_AttackNum_4() { //4. 베기 선택시..
	Sleep(700);
	printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
	Sleep(1000);
	printf("당신은 상대를 ");
	Slash_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
	Slash_Attack = (int)Slash_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬
}

void player_AttackNum_4_None() { //4. 베기 실패
	printf("베지 못했습니다.\n");
	Damage = 0;
}

void player_AttackNum_4_Normal() { //4. 베기 성공
	printf("베었습니다.\n");
	Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void player_AttackNum_4_Critical() { //4. 강력한 베기 성공
	printf("제대로 베었습니다.\n");
	Damage = Player_ATK; //강력한 공격이므로 플레이어 공격력 그대로 데미지가 들어감
	Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
}

void monster_act() { //몬스터 턴, 몬스터가 행동을 취함
	Sleep(1200);
	printf("\n\n==============================================================================\n\n");
	Sleep(1000);
	printf("상대 몬스터의 턴입니다.\n");
	Monster_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
	Monster_Attack = (int)Monster_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬
}

void monster_Attack_None() { //몬스터 공격 실패
	Sleep(1000);
	printf("\n몬스터가 공격을 실패했습니다.");
	Damage = 0;
}

void monster_Attack_Normal() { //몬스터 공격 성공
	Sleep(1000);
	printf("\n몬스터가 공격을 했습니다.");
	Damage = Monster1_ATK / 3; //데미지는 몬스터 공격력의 나누기 3
	Damage -= Player_DEF / 4; //데미지에서 플레이어 방어력 나누기 4한만큼 빼기
	Player_HP -= Damage; //플레이어 채력 - 데미지
	Sleep(1000);
	printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
}

void monster_Attack_Critical() { //몬스터 강력한 공격 성공
	Sleep(1000);
	printf("\n몬스터가 강력한 공격을 했습니다!");
	Damage = Monster1_ATK; //강력한 공격이므로 몬스터의 공격력 그대로 들어감
	Damage -= (Player_DEF / 2) + Damage / 4; // < (Player_DEF / 2.5로 구현할려고 함.  Release버전으로 맞춘 상태이고. 원래 구현하려고 했던 것보다 데미지 적음) >
	Player_HP -= Damage; //플레이어 채력 - 데미지
	Sleep(1000);
	printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
}

void knockdown_player() { //플레이어 HP가 0 이하일때. (즉 플레이어가 쓰러졌을때)
	printf("\n\n\n\t\t리타이어! 여기까지!"); //전투 종료
	Sleep(500);
	printf("\n\t\t승자 : 몬스터"); //몬스터 승리!
	Sleep(800);
}

void knockdown_monster() { //몬스터 HP가 0 이하일때. (즉 몬스터가 쓰러졌을때)
	printf("\n\n\n\t\t리타이어! 여기까지!"); //전투 종료
	Sleep(500);
	printf("\n\t\t승자 : 플레이어"); //플레이어 승리!
	Sleep(800);
}

void knockdown_result_turn() {
	printf("\n\t\t진행된 턴 수 : %d\n\n\n", Turn); //턴 수 출력
	printf("\n\n==============================================================================\n\n");
}
