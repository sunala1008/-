#pragma warning(disable:4996)
#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	int sel = 0;

	List list;
	ListInit(&list);
	int data;
	
	NameCard* pcard; // 명함 포인터

	char name[NAME_LEN];
	char phone[PHONE_LEN];
	
	while (1)
	{
		system("cls");
		printf("--- 명함 관리 프로그램---\n");
		printf("1. 명함 정보 입력\n");
		printf("2. 명함 정보 검색\n");
		printf("3. 명함 전체 출력\n");
		printf("4. 명함 정보 삭제\n");
		printf("5. 프로그램  종료\n");
		printf("선택 : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1: // 명함 정보 입력
			system("cls");
			printf("--- 명함 정보 입력 ---\n");
			
			//// scanf로 입력받지 않을 때..
			//pcard = Make_NameCard("홍길동", "010-7777-7777");
			//LInsert(&list, pcard);

			//pcard = Make_NameCard("임꺽정", "010-1234-5678");
			//LInsert(&list, pcard);

			//pcard = Make_NameCard("유관순", "010-5678-1234");
			//LInsert(&list, pcard);

			printf("이름 : ");
			scanf("%s", &name);
			//scanf_s("%s", name);
			printf("번호 : ");
			//scanf_s("%s", phone);
			scanf("%s", &phone);
			printf("\n");

			// 명함 생성함수 호출
			pcard = Make_NameCard(name, phone);
			LInsert(&list, pcard);

			

			break;
		case 2: // 명함 정보 출력 => 검색 후
			system("cls");
			printf("--- 명함 정보 출력 ---\n");
			printf("이름 검색 : ");
			scanf("%s", name);

			if (LFirst(&list, &pcard)) // LFirst가 TRUE면 실행
			{
				if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "유관순")
					Show_NameCard(pcard);
				else
				{
					while (LNext(&list, &pcard))
					{
						if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "유관순")
							Show_NameCard(pcard);
					}
				}
			}
			getchar();
			getchar();
			break;
		case 3: // 명함 전체 출력
			system("cls");
			printf("저장되어있는 명함의 수 : %d\n", LCount(&list));
			if (LFirst(&list, &pcard))
			{
				Show_NameCard(pcard);

				while (LNext(&list, &pcard))
				{
					Show_NameCard(pcard);
				}
			}
			getchar();
			getchar();
			break;
		case 4: // 명함 정보 삭제
			system("cls");
			printf("--- 명함 정보 삭제 ---\n");
			printf("이름 검색 : ");
			scanf("%s", name);

			if (LFirst(&list, &pcard)) // LFirst가 TRUE면 실행
			{
				if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "유관순")
				{
					pcard = LRemove(&list);
					free(pcard); // 메모리 누수 방지
				}
				else
				{
					while (LNext(&list, &pcard))
					{
						if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "유관순")
						{
							pcard = LRemove(&list);
							free(pcard); // 메모리 누수 방지
							break;
						}
					}
				}
			}
			break;
		case 5: // 프로그램 종료
			printf("\n--- 프로그램 종료 ---\n");
			exit(1);
		default:
			printf("--- 메뉴 재선택 ---\n\n");
			continue;
		}
	}
	
	//// 리스트 생성 및 초기화
	//List list;			// ArrayList 구조체
	//ListInit(&list);
	//int data;

	//// 데이터 저장
	//LInsert(&list, 1);
	//LInsert(&list, 2);
	//LInsert(&list, 3);
	//LInsert(&list, 4);
	//LInsert(&list, 5);

	//// 저장된 데이터 전체 출력
	//printf("저장된 데이터의 수 : %d \n", LCount(&list));

	//// 무조건 첫번째로 가라고 하는 함수
	//if (LFirst(&list, &data)) // 만약 list에 첫번째에 데이터가 있으면 data에 저장해라
	//{ // 첫 번째 데이터 검색
	//	printf("%d", data);
	//	
	//	while (LNext(&list, &data))
	//		printf("%d", data);
	//}

	//printf("\n\n");

	//// 데이터 삭제 => 특정 데이터를 삭제
	//if (LFirst(&list, &data))
	//{
	//	if (data == 3)
	//		LRemove(&list);

	//	while(LNext(&list, &data))
	//	{
	//		if(data == 3)
	//			LRemove(&list);
	//	}
	//}


	//// 삭제 후 저장된 데이터 전체 출력
	//printf("저장된 데이터의 수 : %d \n", LCount(&list));

	//if (LFirst(&list, &data)) // 만약 list에 첫번째에 데이터가 있으면 data에 저장해라
	//{ // 첫 번째 데이터 검색
	//	printf("%d", data);

	//	while (LNext(&list, &data))
	//		printf("%d", data);
	//}

	//printf("\n\n");

	return 0;
}