#include <stdio.h> //버전 4
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "func.h"

int main()
{
	random_num();

	while (1) { // 1번재 While
		title();
		if (First_select == 1) { //1번. 게임시작
			while (1) { // 2번째 While
				choose_character();
				if (Character_select == 1) { //1번. Attacker 선택시..
					set_Attacker();
					break; //2번째 반복문 벗어남
				}
				if (Character_select == 2) { //2번. Defender 선택시..
					set_Defender();
					break; //2번째 반복문 벗어남
				}
				if (Character_select == 3) { //3번. Allrounder 선택시..
					set_Allrounder();
					break; //2번째 반복문 벗어남
				}
				else {
					puts("다시 입력하십시오"); //잘못된 값을 입력시
				}
			} //반복문 1 끝
			story();
			while (1) { // 3번째 While
				player_act();
				if (Attack_Number == 1) { // 1. 때리기 선택시
					player_AttackNum_1();
					endline_player();
				}
				if (Attack_Number == 2) { // 2. 할퀴기 선택시
					player_AttackNum_2();
					if (Scratch_Attack > 5) { //만약 랜덤숫자가 5보다 클시
						player_AttackNum_2_Critical();
					}
					endline_player();
				}
				if (Attack_Number == 3) { //차기 선택시 <추후 찬 부분 충격으로 인해 지속적인 데미지를 넣게끔 추가하기>
					Sleep(700);
					printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
					Sleep(1000);
					puts("당신은 상대를 찼습니다.");
					Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
					Damage -= Monster1_DEF / 2; //데미지에서 몬스터 방어력 나누기 2한만큼 빼기
					Sleep(1000);
					printf("\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
					Monster1_HP -= Damage;
					Sleep(1500);
					printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
					Turn++;
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
				if (Attack_Number == 4) { //베기 선택시
					Sleep(700);
					printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
					Sleep(1000);
					printf("당신은 상대를 ");
					Slash_Point_random_number = rand(); //무작위 랜덤숫자 만들기
					Slash_Attack = (int)Slash_Point_random_number % 10; //랜덤숫자를 0~9로 만듬
					if (Slash_Attack <= 2) { //만약 랜덤숫자가 2이하일시 공격실패함
						printf("베지 못했습니다.");
						Sleep(1500);
						printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
						Turn++;
					}
					if (Slash_Attack >= 3 && Slash_Attack <= 6) { //만약 랜덤숫자가 3~6일시 공격 성공
						printf("베었습니다.");
						Damage = Player_ATK / 2; //플레이어 공격력 나누기 2
						Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
						Sleep(1000);
						printf("\n\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
						Monster1_HP -= Damage;
						Sleep(1500);
						printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
						Turn++;
					}
					if (Slash_Attack >= 7 && Slash_Attack <= 9) { //만약 랜덤숫자가 7~9일시 강력한 공격 성공
						printf("제대로 베었습니다.");
						Damage = Player_ATK; //강력한 공격이므로 플레이어 공격력 그대로 데미지가 들어감
						Damage -= Monster1_DEF / 3; //데미지에서 몬스터 방어력 나누기 3한만큼 빼기
						Sleep(1000);
						printf("\n\n당신은 상대에게 %d의 데미지를 입혔습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
						Monster1_HP -= Damage;
						Sleep(1500);
						printf("\n\n\n=상대 몬스터의 남은 HP : %d", Monster1_HP); //남은 상대 몬스터의 채력 출력
						Turn++;
					}
					Sleep(1000);
					printf("\n\n==============================================================================\n\n");
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //결과계산 1.
					printf("\n\n\n\t\t리타이어! 여기까지!");
					if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
						Sleep(500);
						printf("\n\t\t승자 : 몬스터"); //몬스터 승리!
					}
					if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
						Sleep(500);
						printf("\n\t\t승자 : 플레이어"); //플레이어 승리!
					}
					Sleep(800);
					printf("\n\t\t진행된 턴 수 : %d\n\n\n", Turn); //턴 수 출력
					printf("\n\n==============================================================================\n\n");
					break;
				}
				if (Turn % 2 == 0) { //(턴이 짝수일때)몬스터의 턴
					Sleep(1200);
					printf("\n\n==================================[턴 수 : %d]=================================\n\n", Turn);
					Sleep(1000);
					printf("상대 몬스터의 턴입니다.\n");
					Monster_Attack_random_number = rand(); //무작위 랜덤숫자 만들기
					Monster_Attack = (int)Monster_Attack_random_number % 10; //랜덤숫자를 0~9로 만듬

					if (Monster_Attack <= 1) { //만약 랜덤숫자가 1이하일때 공격실패함
						Sleep(1000);
						printf("\n몬스터가 공격을 실패했습니다.");
						Sleep(1500);
						printf("\n\n\n=딩신의 Hp : %d", Player_HP); //남은 플레이어의 채력 출력
						Turn++;
						Sleep(1000);
						printf("\n\n==============================================================================\n\n");
					}
					if (Monster_Attack >= 2 && Monster_Attack <= 7) { //만약 랜덤숫자가 2~7일시 공격 성공
						Sleep(1000);
						printf("\n몬스터가 공격을 했습니다.");
						Damage = Monster1_ATK / 3; //데미지는 몬스터 공격력의 나누기 3
						Damage -= Player_DEF / 4; //데미지에서 플레이어 방어력 나누기 4한만큼 빼기
						Player_HP -= Damage;
						Sleep(1000);
						printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
						Sleep(1500);
						printf("\n\n\n=딩신의 Hp : %d", Player_HP); //남은 플레이어의 채력 출력
						Turn++;
						Sleep(1000);
						printf("\n\n==============================================================================\n\n");
					}
					if (Monster_Attack >= 8 && Monster_Attack <= 9) { //만약 랜덤숫자가 8~9일시 강력한 공격 성공
						Sleep(1000);
						printf("\n몬스터가 강력한 공격을 했습니다!");
						Damage = Monster1_ATK; //강력한 공격이므로 몬스터의 공격력 그대로 들어감
						Damage -= (Player_DEF / 2) + Damage / 4; // (Player_DEF / 2.5로 구현할려고 함.  Release버전으로 맞춘 상태이고. 원래 구현하려고 했던 것보다 데미지 적음)
						Player_HP -= Damage;
						Sleep(1000);
						printf("\n\n당신은 %d만큼의 데미지를 입었습니다.", Damage); //얼마만큼 데미지를 입혔는지 표시
						Sleep(1500);
						printf("\n\n\n=딩신의 Hp : %d", Player_HP); //남은 플레이어의 채력 출력
						Turn++;
						Sleep(1000);
						printf("\n\n==============================================================================\n\n");
					}
				}
				if (Player_HP <= 0 || Monster1_HP <= 0) { //결과계산 2.
					printf("\n\n\n\t\t녹다운 발생! 여기까지!");
					if (Player_HP <= 0) { //플레이어 채력이 0 이하일시
						Sleep(500);
						printf("\n\t\t승자 : 몬스터"); //몬스터 승리!
					}
					if (Monster1_HP <= 0) { //몬스터 채력이 0 이하일시
						Sleep(500);
						printf("\n\t\t승자 : 플레이어"); //플레이어 승리!
					}
					Sleep(800);
					printf("\n\t\t진행된 턴 수 : %d\n\n\n", Turn); //턴 수 출력
					printf("\n\n==============================================================================\n\n");
					break;
				}
			}
		}
		if (First_select == 2) { //2번. 데이터초기화 시작
			Attacker_HP = 1650, Attacker_ATK = 800, Attacker_DEF = 100;
			Defender_HP = 2500, Defender_ATK = 400, Defender_DEF = 200;
			Allrounder_HP = 1850, Allrounder_ATK = 600, Allrounder_DEF = 150;
			Player_HP = 0, Player_ATK = 0, Player_DEF = 0;
			Monster1_HP = 3000, Monster1_ATK = 500, Monster1_DEF = 100;
			First_select = 0;
			Character_select = 0;

			printf("\n초기화가 완료되었습니다.\n\n\n");
		}
		if (First_select == 3) { //3번. 프로그램 종료
			printf("\n프로그램이 종료됩니다.\n");
			break; //1번째 반복문 벗어남
		}
	}
	printf("\n\n---사용해주셔서 감사합니다---\n\n");
	Sleep(2000);
}

/*
몬스터의 강력한 공격 계산식 수정하기
상태이상(독, 마비 등) 구현하기
*/