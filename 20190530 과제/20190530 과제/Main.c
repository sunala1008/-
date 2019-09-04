#define _CRT_SECURE_NO_WARNINGS // scanf 오류

#include <stdio.h>
#include <stdlib.h >
#include "EmployeeInfo.h"

/*
	1. 사원은 사번과 이름으로, 사번은 정수형 변수
	2. 4명의 사원을 원형 연결 리스트에 저장
	  - scanf로 입력받지 않아도 ok
	  - 동명이인 없음
	  - 원형 연결리스트에는 구조체 변수의 주소 값을 저장
	3. 특근스케줄은 한 명만 출근한다고 가정
	  - 순서는 프로그램에 등록되는 사원 순서로
	  - 사원 등록이 A-B-C면 특근 순서도 A-B-C-A-B-C
	4. 특근 출근자 검색
	  - 사원 이름과 하나의 숫자를 인자로 검색하는 함수 호출
	  - 전달된 이름이 사원이 특근 한 다음, 전달된 숫자에 해당하는
	    만큼의 순서가 지나 특근을 서제 되는 직원의 정보 반환
	  - 예를들어, '유관순'과 '7'이 전달되면 '유관순' 다음의
	    7번째 뒤의 특근 사원의 정보가 반환되어야 함
*/

int main(void)
{
	List list;
	ListInit(&list); // 초기화
	Employee* emp;

	char name[NAME_LEN]; // 사원 이름
	int emp_num;		 // 사원 번호

	int day;

	/*
	printf("[ 4 명의 사원 정보를 입력하세요. ]\n");
	for (int i = 0; i < 4; i++)
	{
		printf("- 사원 이름 : ");
		scanf("%s", name);

		printf("- 사원 번호 : ");
		scanf("%d", &emp_num);

		printf("\n");
		emp = EInfo(name, emp_num);
		EInfoInsert(&list, emp);
	}
	*/

	// 사원명, 사번 입력
	emp = EInfo("홍길동", 101);
	EInfoInsert(&list, emp);

	emp = EInfo("유관순", 102);
	EInfoInsert(&list, emp);

	emp = EInfo("이순신", 103);
	EInfoInsert(&list, emp);

	emp = EInfo("임꺽정", 104);
	EInfoInsert(&list, emp);

	// 사원 정보 출력
	//system("cls");
	printf("= 입력한 모든 사원의 수 : %d", ECount(&list));
	printf(" 명\n");

	if (EFirst(&list, &emp))
	{
		Show_Employee(emp);

		for (int i = 0; i < ECount(&list) - 1; i++) // 1회전만 함
		{
			if(ENext(&list, &emp))
				Show_Employee(emp);
		}
	}
	
	//getchar();
	// getchar();

	printf("\n");

	// 특근 출근자 검색 [강 1 - 곽 2 - 박 3 - 정 4]
	//system("cls");
	printf("= 오늘의 특근 출근자 : ");
	scanf("%s", name);
	printf("= 오늘로부터 몇 일 후의 특근 출근자의 정보를 보시겠습니까? : ");
	scanf("%d", &day);

	if (EFirst(&list, &emp))
	{
		if (!Serch_Overtime_Employee_Name(emp, name))
		{
			Serch_Next(&list, emp, day);
			printf("\n");
		}
		else
		{
			while (ENext(&list, &emp))
			{
				if (!Serch_Overtime_Employee_Name(emp, name))
				{
					Serch_Next(&list, emp, day);
					printf("\n");
					break;
				}
			}
		}
	}

	return 0;
}