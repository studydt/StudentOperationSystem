#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
int main()
{
	char c, d, e, yonghuming[20], mima1[20], mima2[20], ch;
	int k, i, m, l, n, a, b, cuowucishu = 0, panduancuoti = 0;
	char dengluhou = '0';
	int  zhengquegeshu, denglucishu;
	double pingjunmeidaotidefenshu;
	FILE* fp1, * fp2;
	printf("                                                          Сѧ����������ϵͳ\n");
caidan:
	printf("************************************************************************************************************\n");
	printf("1.ע��\n");
	printf("2.��¼\n");
	printf("3.��������\n");
	printf("4.�鿴���⼯\n");
	printf("5.�˳�ϵͳ\n");
	printf("************************************************************************************************************\n");
nihao:
		printf("��ѡ��");
		scanf("%c", &c);
		getchar();
		if (c == '1')
		{
			/*ע�Ṧ�ܡ�*/
			printf("�������û�������ע�᣺");
			scanf("%s", yonghuming);
			getchar();
			if ((fp1 = fopen(yonghuming, "r")) == NULL)
			{
				if ((fp1 = fopen(yonghuming, "w")) == NULL)
				{
					printf("�ļ��򿪴���\n");
					exit(0);
				}
				else
				{
					fp2 = fopen(strcat(yonghuming, "���Ȿ"), "w");
					fputs(yonghuming, fp2);
					fputs("��\n", fp2);
					fclose(fp2);
					printf("������ע�����룺");
					scanf("%s", mima1);
					getchar();
					fputs(mima1, fp1);
					fclose(fp1);
					printf("ע��ɹ���\n");
				chongxinxunwen:
					printf("�Ƿ񷵻ز˵�����Y/N��\n");
					printf("�����룺");
					scanf("%c", &e);
					while(getchar()!='\n');  //�ѻ�����������ַ�����ȡ��
					if (e == 'Y' || e == 'y')
					{
						printf("�ѷ��ز˵���\n");
						goto caidan;
					}
					else if (e == 'N' || e == 'n')
					{
						exit(0);
					}
					else
					{
						printf("��������ϹJB���룡\n");
						goto chongxinxunwen;
					}
				}
			}
			else
			{
				printf("�û����ѱ�ע�ᣡ���ز˵���\n");
				goto caidan;
			}
		}
		else if (c == '2')
		{
			/*��¼����*/
			denglucishu = 0;
		denglu:
			printf("�������û�����");
			scanf("%s", &yonghuming);
			getchar();
			if ((fp1 = fopen(yonghuming, "r")) == NULL)
			{
				printf("�û����������\n");
				denglucishu++;
				if (denglucishu == 3)
				{
					printf("���Ѿ�����������Σ������ز˵���\n");
					goto caidan;
				}
				goto denglu;
			}
			else
			{
				printf("���������룺");
				scanf("%s", mima1);
				getchar();
				denglucishu = 0;
				fgets(mima2, 20, fp1);
				if (strcmp(mima1, mima2) == 0)
				{
					printf("��¼�ɹ���\n");
					if (dengluhou == '1')
					{
						printf("��������ϵͳ��\n");
						goto suanshu;
					}
					else if (dengluhou == '2')
					{
						printf("������⼯ϵͳ��\n");
						goto cuotiji;
					}
					if (dengluhou == '0')
					{
						printf("��ѡ�������⻹�ǲ鿴���Ȿ��1/2��\n");
						scanf("%c", &dengluhou);
						getchar();
						if (dengluhou == '1')
						{
							goto suanshu;
						}
						else if (dengluhou == '2')
						{
							goto cuotiji;
						}
					}
				}
				else
				{
					printf("����������������¿�ʼ������뷵�ز˵��������롮Y����������ǡ�Y�������µ�½��\n");
					denglucishu++;
					if (denglucishu == 3)
					{
						printf("���Ѿ���������������Σ������ز˵���\n");
						goto caidan;
					}
					scanf("%c", &d);
					getchar();
					if (d == 'Y' || d == 'y')
					{
						goto caidan;
					}
					else
					{
						goto denglu;
					}
				}
			}
		}
		else if (c == '3')
		{
			/*�������㹦�ܣ��˷��ͳ����ĸ����е�ס�*/
			dengluhou = '1';
			goto denglu;
		suanshu:
			fp2 = fopen(strcat(yonghuming, "���Ȿ"), "a+");
			system("cls");
			printf("                                              ����Сѧ����������ϵͳ��\n");
			printf("��������������Ŀ����");
			scanf("%d", &k);
			getchar();
			if (k <= 0)
			{
				goto suanshu;
			}
			pingjunmeidaotidefenshu = 50.0 / k;
			zhengquegeshu = 0;
			srand((unsigned)time(NULL));
			for (i = 1; i <= k;)
			{
			yunsuan:
				panduancuoti = 0;
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
							fprintf(fp2, "%d + %d = %d", m, l, m + l);
							fputs("\n", fp2);
							i++;
							goto yunsuan;
						}
						scanf("%d", &n);
						getchar();
						if (m + l == n)
						{
							i++;
							if (panduancuoti == 0)
							{
								zhengquegeshu = zhengquegeshu + 2;
							}
							else if (panduancuoti == 1)
							{
								zhengquegeshu++;
							}
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							panduancuoti++;
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
							fprintf(fp2, "%d - %d = %d", m, l, m - l);
							fputs("\n", fp2);
							i++;
							goto yunsuan;
						}
						scanf("%d", &n);
						getchar();
						if (m - l == n)
						{
							i++;
							if (panduancuoti == 0)
							{
								zhengquegeshu = zhengquegeshu + 2;
							}
							else if (panduancuoti == 1)
							{
								zhengquegeshu++;
							}
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							panduancuoti++;
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
							fprintf(fp2, "%d * %d = %d", m, l, m* l);
							fputs("\n", fp2);
							i++;
							goto yunsuan;
						}
						scanf ("%d", &n);
						getchar();
						if (m * l == n)
						{
							i++;
							if (panduancuoti == 0)
							{
								zhengquegeshu = zhengquegeshu + 2;
							}
							else if (panduancuoti == 1)
							{
								zhengquegeshu++;
							}
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							panduancuoti++;
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
					if (m / l <= 100 && m % l==0 && m > l)
					{
						printf("%d / %d = ", m, l);
					chufachongsuan:
						if (cuowucishu == 2)
						{
							printf("���Ѿ���������ˣ��Ѿ����������ӵ����Ȿ���ˣ�\n");
							fprintf(fp2, "%d / %d = %d", m, l, m / l);
							fputs("\n", fp2);
							i++;
							goto yunsuan;
						}
						scanf("%d", &n);
						getchar();
						if (m / l == n)
						{
							i++;
							if (panduancuoti == 0)
							{
								zhengquegeshu = zhengquegeshu + 2;
							}
							else if (panduancuoti == 1)
							{
								zhengquegeshu++;
							}
							goto yunsuan;
						}
						else
						{
							cuowucishu++;
							panduancuoti++;
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
			printf("һ���÷֣�%.1f\n", zhengquegeshu* pingjunmeidaotidefenshu);
			fclose(fp2);
		suanshuxuanze:
			printf("ѡ���Ƿ�ص��˵���Y/N��");
			scanf ("%c", &e);
			getchar();
			if (e == 'Y' || e == 'y')
			{
				dengluhou = '0';
				goto caidan;
			}
			else if (e == 'N' || e == 'n')
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
			/*���⼯*/
			dengluhou = '2';
			goto denglu;
		cuotiji:
			dengluhou = '0';
			strcat(yonghuming, "���Ȿ");
			if ((fp2 = fopen(yonghuming, "r")) == NULL)
			{
				printf("�޷����ļ���\n");
				exit(0);
			}
			ch = getc(fp2);
			while (!feof(fp2))
			{
				putchar(ch);
				ch = getc(fp2);
			}
			printf("ѡ���Ƿ�ص��˵���Y/N��");
			scanf("%c", &e);
			getchar();
			if (e == 'Y' || e == 'y')
			{
				dengluhou = '0';
				goto caidan;
			}
			else if (e == 'N' || e == 'n')
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
