#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char c, yonghuming[20], mima1[20], d, e, mima2[20], ch;
	int k, i, m, l, n, a, b, cuowucishu = 0;
	int pingjunmeidaotidefenshu, zhengquegeshu;
	FILE* fp1, * fp2;
	printf("                                                          Сѧ����������ϵͳ\n");
caidan:
	printf("************************************************************************************************************\n");
	printf("1.ע��\n");
	printf("2.��¼--����\n");
	printf("3.��������\n");
	printf("4.�鿴���⼯\n");
	printf("5.�˳�ϵͳ\n");
	printf("************************************************************************************************************\n");
nihao:
		printf("��ѡ��");
		scanf("%c", &c);
		d = getchar();
		if (c == '1')
		{
			/*ע�Ṧ�ܣ����ڻ�û�����ͬһ�û����ظ�ע�����⣡*/
			printf("�������û�������ע�᣺");
			scanf("%s", yonghuming);
			printf("������ע�����룺");
			scanf("%s", mima1);
			if ((fp1 = fopen(yonghuming, "w")) == NULL)
			{
				printf("�ļ��򿪳���\n");
				exit(0);
			}
			fputs(mima1, fp1);
			fclose(fp1);
			printf("ע��ɹ���\n");
			chongxinxunwen:
			printf("�Ƿ񷵻ز˵�����Y/N��\n");
			printf("�����룺");
			scanf(" %c", &e);
			d = getchar();
			if (e == 'Y')
			{
				printf("�ѷ��ز˵���\n");
				goto caidan;
			}
			else if (e == 'N')
			{
				exit(0);
			}
			else
			{
				printf("��������ϹJB���룡\n");
				goto chongxinxunwen;
			}
		}
		else if (c == '2')
		{
			/*��¼����*/
		denglu:
			printf("�������û�����");
			scanf("%s", &yonghuming);
			if ((fp1 = fopen(yonghuming, "r")) == NULL)
			{
				printf("�û����������\n");
				goto denglu;
			}
			printf("���������룺");
			scanf("%s", mima1);
			fgets(mima2, 20, fp1);
			if (strcmp(mima1, mima2) == 0)
			{
				printf("��¼�ɹ���\n");
				goto suanshu;
			}
			else
			{
				printf("����������������¿�ʼ������뷵�ز˵��������롮Y����\n");
				scanf(" %c", &d);
				if (d == 'Y')
				{
					goto caidan;
				}
				else
				{
					goto denglu;
				}
			}
		}
		else if (c == '3')
		{
			/*�������㹦��,���Ȿ����û�м��룬����Ŀǰ�����⣡���ѡ��˵���ʱ������������⣡*/
			goto denglu;
		suanshu:
			system("cls");
			printf("����Сѧ����������ϵͳ��\n");
			printf("��������������Ŀ����");
			scanf(" %d", &k);
			pingjunmeidaotidefenshu = 100 / k;
			zhengquegeshu = 0;
			srand((unsigned)time(NULL));
			for (i = 1; i <= k;)
			{
			yunsuan:
				if (i > k)
				{
					break;
				}
				a = rand() % 4 + 48;
				m = rand() % 100;
				l = rand() % 100;
				switch (a)
				{
				case'0': 
				{
					/*�ӷ�*/
					cuowucishu = 0;
					if (m + l <= 100)
					{
						printf("%d + %d = ", m, l);
					jiafachongsuan:
						if (cuowucishu == 2)
						{
							printf("���Ѿ���������ˣ��Ѿ����������ӵ����Ȿ���ˣ�\n");
							i++;
							goto yunsuan;
						}
						scanf(" %d", &n);
						if (m + l == n)
						{
							i++;
							zhengquegeshu++;
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							printf("���������\n");
							printf("���������룺");
							goto jiafachongsuan;
						}
					}
					else
					{
						goto yunsuan;
					}
				}; break;
				case'1':
				{
					/*����*/
					cuowucishu = 0;
					if (m - l <= 100 && m - l > 0)
					{
						printf("%d - %d = ", m, l);
					jianfachongsuan:
						if (cuowucishu == 2)
						{
							printf("���Ѿ���������ˣ��Ѿ����������ӵ����Ȿ���ˣ�\n");
							i++;
							goto yunsuan;
						}
						scanf(" %d", &n);
						if (m - l == n)
						{
							i++;
							zhengquegeshu++;
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							printf("���������\n");
							printf("���������룺");
							goto jianfachongsuan;
						}
					}
					else
					{
						goto yunsuan;
					}
				}; break;
				case'2':
				{
					/*�˷�*/
					cuowucishu = 0;
					if (m * l <= 100)
					{
						printf("%d * %d = ", m, l);
					chengfachongsuan:
						if (cuowucishu == 2)
						{
							printf("���Ѿ���������ˣ��Ѿ����������ӵ����Ȿ���ˣ�\n");
							i++;
							goto yunsuan;
						}
						scanf (" %d", &n);
						if (m * l == n)
						{
							i++;
							zhengquegeshu++;
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							printf("���������\n");
							printf("���������룺");
							goto chengfachongsuan;
						}
					}
					else
					{
						goto yunsuan;
					}
				}; break;
				case'3':
				{
					/*����*/
					cuowucishu = 0;
					if (m / l <= 100 && ((m % 1) == 0)&& m > l)
					{
						printf("%d / %d = ", m, l);
					chufachongsuan:
						if (cuowucishu == 2)
						{
							printf("���Ѿ���������ˣ��Ѿ����������ӵ����Ȿ���ˣ�\n");
							i++;
							goto yunsuan;
						}
						scanf(" %d", &n);
						if (m / l == n)
						{
							i++;
							zhengquegeshu++;
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							printf("���������\n");
							printf("���������룺");
							goto chufachongsuan;
						}
					}
					else
					{
						goto yunsuan;
					}
				}; break;
				}
			}
			printf("һ���÷֣�%d\n", zhengquegeshu* pingjunmeidaotidefenshu);
		suanshuxuanze:
			printf("ѡ��ص��˵���Y/N��");
			scanf (" c", &e);
			d = getchar();
			if (e == 'Y')
			{
				goto caidan;
			}
			else if (e == 'N')
			{
				printf("�˳�ϵͳ��");
				exit(0);
			}
			else
			{
				printf("������ĺú����룡\n");
				goto suanshuxuanze;
			}
		}
		else if (c == '4')
		{

		}
		else if (c == '5')
		{
			/*�˳�ϵͳ����*/
			printf("�˳�ϵͳ��\n");
			exit(0);
		}
		else
		{
			printf("�������\n");
			goto nihao;
		}
		return 0;
}
