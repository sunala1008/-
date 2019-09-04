#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "McDonald.h"

/*
	 ▶ Queue의 활용 ◀
	  - 큐잉 이론 (Queueing Theory)
	  - 수학적으로 모델링 된 결과의 확인을 위해서
	    특정 현상을 시뮬레이션 할 경우 Queue 자료구조를 활용

	  = Simulation 할 상황의 조건
	   1. 점심시간은 1시간 (3600초)
	   2. 고객은 15초에 1명씩 주문함 // 240 명
	   3. 모든 고객은 랜덤하게 메뉴를 선택
	   4. 햄버거를 만드는 종업원은 1명
	   5. 동시에 2개 이상의 햄버거를 만들지 않음
	   6. 햄버거를 완성하는 시간
	     - 치즈버거		12초
		 - 불고기버거	15초
		 - 빅맥			24초
	   
	  ≡ for문을 3600번 돌 동안 치즈버거가 12번 나오면 치즈버거가 완성된 것 ㅋㅋ..
	  ≡ 각각 몇 개의 햄버거가 나올 수 있을지 시뮬레이션으로 나올 수 있음
	  ≡ 랜덤함수는 srand() / rand()를 쓰면 됨
*/

#define CHEESE 0
#define BULGOGI 1
#define BIGMAC 2

#define COOK_CHEESE 12
#define COOK_BULGOGI 15
#define COOK_BIGMAC 24

#define ORDER 15

int main()
{
	int burgercooktime = 0;
	int orderfail = 0; // 시간이 초과되어 버거가 나오다 만 경우.. (0 or 1)
	int sales = 0;

	int cheese = 0;
	int bulgogi = 0;
	int bigmac = 0;
	int shanghai = 0;
	
	Queue queue;
	QueueInit(&queue);
	srand(time(NULL));

	printf("[맥도날드 시뮬레이션]\n");
	printf("- 대기실 수용 인원 : %d\n", QUEUE_LEN);

	for (int second = 0; second < 3600; second++) // 0 ~ 3600초 동안 : 1시간
	{
		if (second % ORDER == 0) // 15초마다 1명의 손님을 받음
		{
			switch (rand() % 3) //	=> 0 ~ 2의 랜덤한 숫자 : 랜덤 메뉴 선택
			{
			case CHEESE: // 0
				Enqueue(&queue, COOK_CHEESE); // 12초
				cheese++; // 랜덤으로-
				break;
			case BULGOGI: // 1
				Enqueue(&queue, COOK_BULGOGI); // 15초
				bulgogi++; // -증가하는-
				break;
			case BIGMAC: // 2
				Enqueue(&queue, COOK_BIGMAC); // 24초
				bigmac++; // -버거들
				break;
			}
		}
		//								┌─ 비어있지 않을 때
		if (burgercooktime <= 0 && !QIsEmpty(&queue))
			burgercooktime = Dequeue(&queue); // 
		
		burgercooktime--;
		// 버거 주문하고 나서 만들어지는데까지 걸리는 시간
		
		if (burgercooktime == 0) // 0이 되어야 손님한테 버거 줌
			sales++;
	}

	if (burgercooktime != 0)
		orderfail++;

	printf("\n      <주문 수>\n");
	printf("- 치즈 버거	 : %d 개\n", cheese);
	printf("- 불고기 버거    : %d 개\n", bulgogi);
	printf("- 빅맥		 : %d 개\n", bigmac);
	// 고객은 일단 계속 받고 그래서 240개
	printf("===========================\n");
	printf("- 버거 만든 갯수	 : %d 개\n", sales);
	printf("- 주문 성공률    : %.2f％\n", 
			(double)sales / (cheese + bulgogi + bigmac) * 100);
	
	return 0;
}