#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "McDonald.h"

/*
	 �� Queue�� Ȱ�� ��
	  - ť�� �̷� (Queueing Theory)
	  - ���������� �𵨸� �� ����� Ȯ���� ���ؼ�
	    Ư�� ������ �ùķ��̼� �� ��� Queue �ڷᱸ���� Ȱ��

	  = Simulation �� ��Ȳ�� ����
	   1. ���ɽð��� 1�ð� (3600��)
	   2. ���� 15�ʿ� 1�� �ֹ��� // 240 ��
	   3. ��� ���� �����ϰ� �޴��� ����
	   4. �ܹ��Ÿ� ����� �������� 1��
	   5. ���ÿ� 2�� �̻��� �ܹ��Ÿ� ������ ����
	   6. �ܹ��Ÿ� �ϼ��ϴ� �ð�
	     - ġ�����		12��
		 - �Ұ�����	15��
		 - ���			24��
	   
	  �� for���� 3600�� �� ���� ġ����Ű� 12�� ������ ġ����Ű� �ϼ��� �� ����..
	  �� ���� �� ���� �ܹ��Ű� ���� �� ������ �ùķ��̼����� ���� �� ����
	  �� �����Լ��� srand() / rand()�� ���� ��
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
	int orderfail = 0; // �ð��� �ʰ��Ǿ� ���Ű� ������ �� ���.. (0 or 1)
	int sales = 0;

	int cheese = 0;
	int bulgogi = 0;
	int bigmac = 0;
	int shanghai = 0;
	
	Queue queue;
	QueueInit(&queue);
	srand(time(NULL));

	printf("[�Ƶ����� �ùķ��̼�]\n");
	printf("- ���� ���� �ο� : %d\n", QUEUE_LEN);

	for (int second = 0; second < 3600; second++) // 0 ~ 3600�� ���� : 1�ð�
	{
		if (second % ORDER == 0) // 15�ʸ��� 1���� �մ��� ����
		{
			switch (rand() % 3) //	=> 0 ~ 2�� ������ ���� : ���� �޴� ����
			{
			case CHEESE: // 0
				Enqueue(&queue, COOK_CHEESE); // 12��
				cheese++; // ��������-
				break;
			case BULGOGI: // 1
				Enqueue(&queue, COOK_BULGOGI); // 15��
				bulgogi++; // -�����ϴ�-
				break;
			case BIGMAC: // 2
				Enqueue(&queue, COOK_BIGMAC); // 24��
				bigmac++; // -���ŵ�
				break;
			}
		}
		//								���� ������� ���� ��
		if (burgercooktime <= 0 && !QIsEmpty(&queue))
			burgercooktime = Dequeue(&queue); // 
		
		burgercooktime--;
		// ���� �ֹ��ϰ� ���� ��������µ����� �ɸ��� �ð�
		
		if (burgercooktime == 0) // 0�� �Ǿ�� �մ����� ���� ��
			sales++;
	}

	if (burgercooktime != 0)
		orderfail++;

	printf("\n      <�ֹ� ��>\n");
	printf("- ġ�� ����	 : %d ��\n", cheese);
	printf("- �Ұ�� ����    : %d ��\n", bulgogi);
	printf("- ���		 : %d ��\n", bigmac);
	// ���� �ϴ� ��� �ް� �׷��� 240��
	printf("===========================\n");
	printf("- ���� ���� ����	 : %d ��\n", sales);
	printf("- �ֹ� ������    : %.2f��\n", 
			(double)sales / (cheese + bulgogi + bigmac) * 100);
	
	return 0;
}