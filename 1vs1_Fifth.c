#include <stdio.h> //버전 3
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
	/* 선택지 */
	int First_select; //첫번째 선택. 시작, 초기화, 종료중 어떤것을 선택할지 정하는 변수
	int Character_select; //두번째 선택. 어떤 캐릭터를 고를지 정하는 변수

	/* 캐릭터/몬스터 스탯*/
	int Attacker_HP = 130, Attacker_ATK = 120, Attacker_DEF = 50; //Attacker 기본스탯
	int Defender_HP = 200, Defender_ATK = 60, Defender_DEF = 100; //Depender 기본스탯
	int Allrounder_HP = 100, Allrounder_ATK = 100, Allrounder_DEF = 100; //Allrounder 기본스탯
	int Player_HP, Player_ATK, Player_DEF; //실 전투에서 사용하는 스탯(선택한 캐릭터의 능력치를 복사해 사용하는 변수)
	int Monster1_HP = 200, Monster1_ATK = 80, Monster1_DEF = 60; //실 전투에서 사용하는 라운드1 몬스터 스탯 

	/* 전투중/게임시스템 */
	int Attack_Number; // [때리기] [할퀴기] [차기] [베기]의 공격을 정하는 변수
	int Damage; //계산한 데미지수를 담는 변수
	int Turn = 1; //턴이 얼마나 지나갔나를 알려주는 변수
	int Scratch_Attack; //랜덤함수에 의한 플레이어 [할퀴기]의 공격성공률
	int Scratch_random_number; // [할퀴기]선택시 크리티컬이 뜰지 말지를 정하기위한 랜덤함수를 넣은 변수
	int Slash_Attack; //랜덤함수에 의한 플레이어 [베기]공격성공률
	int Slash_Point_random_number; // [베기]선택시 벤 부위(랜덤)에 따라 데미지를 달리하게 만들어주는 변수
	int Monster_Attack; //랜덤함수에 의한 몬스터의 공격성공률
	int Monster_Attack_random_number; //상대몬스터 턴일시 랜덤한 숫자에 따라 공격방식을 정할 수 있게 하는 변수

	srand((unsigned int)time(NULL)); //랜덤한 숫자를 나타나게하는 구문


	puts("[MAIN] --Welcome to HDR 1vs1--");
	printf("<<게임시작은 1번, 데이터초기화는 2번, 종료는 3번을 입력해주세요.>>\n"); //메인선택지
	scanf("%d", &First_select);

	if (First_select == 1) { //1번. 게임시작
		while (1) { //반복문 1 시작
			printf("\n[캐릭터를 선택하십시오]------------------\n"); //캐릭터 선택
			Sleep(100);
			printf(" -[1]Attacker - 공격에 특화되어 있습니다.\n -[2]Defender - 방어에 특화되어 있습니다.\n -[3]Allrounder - 벨런스형입니다.\n\n"); //캐릭터 설명
			scanf("%d", &Character_select);
			if (Character_select == 1) { //1번. Attacker 선택시..
				Player_HP = Attacker_HP;
				Player_ATK = Attacker_ATK;
				Player_DEF = Attacker_DEF;
				printf("\t -Attacker 설정이 완료되었습니다!-");
				break;
			}
			if (Character_select == 2) { //2번. Defender 선택시..
				Player_HP = Defender_HP;
				Player_ATK = Defender_ATK;
				Player_DEF = Defender_DEF;
				printf("\t -Defender 설정이 완료되었습니다!-");
				break;
			}
			if (Character_select == 3) { //3번. Allrounder 선택시..
				Player_HP = Allrounder_HP;
				Player_ATK = Allrounder_DEF;
				Player_DEF = Allrounder_DEF;
				printf("\t -Allrounder 설정이 완료되었습니다!-");
				break;
			}
			else {
				puts("다시 입력하십시오"); //잘못된 값을 입력시 다시 입력메세지
				Character_select = 0; //초기화
			}
		} //반복문 1 끝
		Sleep(2000);
		printf("\n\n__[STORY]__\n\n당신은 길을 가고 있었다.\n");
		Sleep(1000);
		printf("하지만 당신이 가는 이 길은 평소에 흉악한 몬스터들이 많이 나타나고, 하필 지금은 밤이라 더 많이 출몰한다.\n");
		Sleep(1000);
		printf("그리고 어느세 당신은 뒤를 쫒고있던 몬스터를 보게 되는데..\n\n"); //STAGE 1 스토리
		while (1) { //반복문 2 시작
			Sleep(1100);
			printf("\n\t=당신은 무엇을 할까?=");
			Sleep(200);
			printf("\n\n[1]때리기    [2]할퀴기    [3]차기    [4]베기\n\n입력 -> "); //공격타입 선택
			scanf("%d", &Attack_Number);
			if (Attack_Number == 1) { //때리기
				Sleep(700);
				printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
				Sleep(1000);
				puts("당신은 상대를 때렸습니다.");
				Damage = Player_ATK / 2;
				Damage -= Monster1_DEF / 3;
				Sleep(1000);
				printf("\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage);
				Monster1_HP -= Damage;
				Sleep(1500);
				printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP);
				Turn++;
				Sleep(1000);
				printf("\n\n==============================================================================\n\n");
			}
			if (Attack_Number == 2) { //할퀴기
				Sleep(700);
				printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
				Sleep(1000);
				puts("당신은 상대를 할퀴었습니다.");
				Damage = Player_ATK / 4;
				Damage -= Monster1_DEF / 3;
				Monster1_HP -= Damage;
				Scratch_random_number = rand(); //크리티컬 계산
				Scratch_Attack = (int)Scratch_random_number % 10; // 0~9까지 랜덤숫자 돌림
				if (Scratch_Attack > 7) { //만약 7보다 클시
					Damage += Damage * 2;
					Monster1_HP -= Damage;
					Sleep(1000);
					printf("\n[크리티컬!]"); //크리티컬은 방어력 무시
				}
				Sleep(1000);
				printf("\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage);
				Sleep(1500);
				printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP);
				Turn++;
				Sleep(1000);
				printf("\n\n==============================================================================\n\n");
			}
			if (Attack_Number == 3) { //차기
				Sleep(700);
				printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
				Sleep(1000);
				puts("당신은 상대를 찼습니다.");
				Damage = Player_ATK / 2;
				Damage -= Monster1_DEF / 3;
				Sleep(1000);
				printf("\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage);
				Monster1_HP -= Damage;
				Sleep(1500);
				printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP);
				Turn++;
				Sleep(1000);
				printf("\n\n==============================================================================\n\n");
			}
			if (Attack_Number == 4) { //베기
				Sleep(700);
				printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
				Sleep(1000);
				printf("당신은 상대를 ");
				Slash_Point_random_number = rand(); //랜덤
				Slash_Attack = (int)Slash_Point_random_number % 10;
				if (Slash_Attack <= 2) { //2이하 공격실패
					printf("베지 못했습니다.");
					Sleep(1500);
					printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP);
					Turn++;
				}
				if (Slash_Attack >= 3 && Slash_Attack <= 5) { //3~5 공격성공
					printf("베었습니다.");
					Damage = Player_ATK / 3;
					Damage -= Monster1_DEF / 3;
					Sleep(1000);
					printf("\n\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage);
					Monster1_HP -= Damage;
					Sleep(1500);
					printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP);
					Turn++;
				}
				if (Slash_Attack >= 6 && Slash_Attack <= 9) { //6~8 강한공격성공
					printf("제대로 베었습니다.");
					Damage = Player_ATK;
					Damage -= Monster1_DEF / 3;
					Sleep(1000);
					printf("\n\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage);
					Monster1_HP -= Damage;
					Sleep(1500);
					printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP);
					Turn++;
				}
				Sleep(1000);
				printf("\n\n==============================================================================\n\n");
			}
			if (Player_HP <= 0 || Monster1_HP <= 0) { //1차 결과계산
				printf("\n\n\n\t\t리타이어! 여기까지!");
				if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
					Sleep(500);
					printf("\n\t\t승자 : 몬스터"); //승자 몬스터
				}
				if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
					Sleep(500);
					printf("\n\t\t승자 : 플레이어"); //승자 플레이어
				}
				Sleep(800);
				printf("\n\t\t진행된 턴 수 : %d\n\n\n", Turn); //턴 수 출력
				break;
			}
			if (Turn % 2 == 0) { //(턴이 짝수일때)몬스터 공격 턴
				Sleep(1200);
				printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
				Sleep(1000);
				printf("상대 몬스터의 턴입니다.\n");
				Monster_Attack_random_number = rand();
				Monster_Attack = (int)Monster_Attack_random_number % 10;

				if (Monster_Attack <= 1) {
					Sleep(1000);
					printf("\n몬스터가 공격을 실패했습니다.");
					Sleep(1500);
					printf("\n\n\n=딩신의 Hp : %d", Player_HP);
					Turn++;
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
				if (Monster_Attack >= 2 && Monster_Attack <= 7) {
					Sleep(1000);
					printf("\n몬스터가 공격을 했습니다.");
					Damage = Monster1_ATK / 2;
					Damage -= Player_DEF / 3;
					Player_HP -= Damage;
					Sleep(1000);
					printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage);
					Sleep(1500);
					printf("\n\n\n=딩신의 Hp : %d", Player_HP);
					Turn++;
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
				if (Monster_Attack >= 8 && Monster_Attack <= 9) {
					Sleep(1000);
					printf("\n몬스터가 강력한 공격을 했습니다!");
					Damage = Monster1_ATK;
					Damage -= Player_DEF / 3;
					Player_HP -= Damage;
					Sleep(1000);
					printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage);
					Sleep(1500);
					printf("\n\n\n=딩신의 Hp : %d", Player_HP);
					Turn++;
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
			}
			if (Player_HP <= 0 || Monster1_HP <= 0) {
				printf("\n\n\n\t\t녹다운 발생! 여기까지!");
				if (Player_HP <= 0) {
					Sleep(500);
					printf("\n\t\t승자 : 몬스터");
				}
				if (Monster1_HP <= 0) {
					Sleep(500);
					printf("\n\t\t승자 : 플레이어");
				}
				Sleep(800);
				printf("\n\t\t진행된 턴 수 : %d\n\n\n", Turn);
				break;
			}
		}
	}
	printf("\n\n---사용해주셔서 감사합니다---\n\n");
}

/*

초기화 구현하기

종료 구현하기

상태이상(독, 마비 등) 구현하기

*/