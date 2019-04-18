#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
int main()
{
	char c, d, e, yonghuming[20], mima1[20], mima2[20], ch;
	int k, i, m, l, n, a, b, cuowucishu = 0, panduancuoti = 0;
	char dengluhou = '0';
	int  zhengquegeshu, denglucishu = 0;
	int xunhuan;
	double pingjunmeidaotidefenshu;
	FILE* fp1, * fp2;
	printf("                                                          小学生四则运算系统\n");
caidan:
	printf("菜单：\n");
	printf("************************************************************************************************************\n");
	printf("1.注册\n");
	printf("2.登录\n");
	printf("3.四则运算\n");
	printf("4.查看错题集\n");
	printf("5.退出系统\n");
	printf("************************************************************************************************************\n");
nihao:
	printf("请选择：");
	scanf("%c", &c);
	while (getchar() != '\n');
	if (c == '1')
	{
		/*注册功能。*/
		printf("请输入用户名进行注册：");
		scanf("%s", yonghuming);
		getchar();
		if ((fp1 = fopen(yonghuming, "r")) == NULL)
		{
			if ((fp1 = fopen(yonghuming, "w")) == NULL)
			{
				printf("文件打开错误。\n");
				exit(0);
			}
			else
			{
				fp2 = fopen(strcat(yonghuming, "错题本"), "w");
				fputs(yonghuming, fp2);
				fputs("：\n", fp2);
				fclose(fp2);
				printf("请输入注册密码：");
				scanf("%s", mima1);
				getchar();
				fputs(mima1, fp1);
				fclose(fp1);
				printf("注册成功。\n");
			chongxinxunwen:
				printf("是否返回菜单？（Y/N）'N'是退出程序。\n");
				printf("请输入：");
				scanf("%c", &e);
				while (getchar() != '\n');
				if (e == 'Y' || e == 'y')
				{
					printf("已返回菜单。\n");
					system("cls");
					goto caidan;
				}
				else if (e == 'N' || e == 'n')
				{
					exit(0);
				}
				else
				{
					printf("请正确输入选项！\n");
					goto chongxinxunwen;
				}
			}
		}
		else
		{
			system("cls");
			printf("用户名已被注册！返回菜单。\n");
			goto caidan;
		}
	}
	else if (c == '2')
	{
		/*登录功能*/
		denglucishu = 0;
	denglu:
		printf("请输入用户名：");
		scanf("%s", &yonghuming);
		while (getchar() != '\n');
		if ((fp1 = fopen(yonghuming, "r")) == NULL)
		{
			printf("用户名输入错误！\n");
			denglucishu++;
			if (denglucishu == 3)
			{
				printf("你已经输入错误三次，将返回菜单！\n");
				goto caidan;
			}
			goto denglu;
		}
		else
		{
			printf("请输入密码：");
			scanf("%s", mima1);
			while (getchar() != '\n');
			denglucishu = 0;
			fgets(mima2, 20, fp1);
			if (strcmp(mima1, mima2) == 0)
			{
				printf("登录成功！\n");
				if (dengluhou == '1')
				{
					printf("进入算数系统！\n");
					goto suanshu;
				}
				else if (dengluhou == '2')
				{
					printf("进入错题集系统！\n");
					goto cuotiji;
				}
				if (dengluhou == '0')
				{
					printf("请选择是做题还是查看错题本（1/2）\n");
					scanf("%c", &dengluhou);
					while (getchar() != '\n');
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
				printf("密码输入错误，请重新开始！如果想返回菜单，请输入‘Y’，如果不是‘Y’则重新登陆！\n");
				denglucishu++;
				if (denglucishu == 3)
				{
					printf("你已经输入密码错误三次，将返回菜单！\n");
					goto caidan;
				}
				scanf("%c", &d);
				while (getchar() != '\n');
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
		/*四则运算功能。*/
		dengluhou = '1';
		goto denglu;
	suanshu:
		fp2 = fopen(strcat(yonghuming, "错题本"), "a+");
		system("cls");
		printf("                                              进入小学生四则算数系统：\n");
		printf("请输入想做的题目数：");
		scanf("%d", &k);
		while (getchar() != '\n');
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
			xunhuan = 0;
			panduancuoti = 0;
			if (i > k)
			{
				break;
			}
			a = rand() % 4 + 48;
			switch (a)
			{
			case'0':
			{
				/*加法*/
				cuowucishu = 0;
			yunsuan1:
				m = rand() % 100;
				l = rand() % 100;
				if (m + l <= 100)
				{
					printf("%d + %d = ", m, l);
				jiafachongsuan:
					if (cuowucishu == 2)
					{
						printf("你已经算错两次了！已经将这道题添加到错题本中了！\n这道题的正确答案是%d\n", m + l);
						fprintf(fp2, "%d + %d = %d", m, l, m + l);
						fputs("\n", fp2);
						i++;
						goto yunsuan;
					}
					scanf("%d", &n);
					while (getchar() != '\n');
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
						printf("你算错啦！\n");
						printf("请重新输入：");
						goto jiafachongsuan;
					}
				}
				else
				{
					goto yunsuan1;
				}
			}; break;
			case'1':
			{
				/*减法*/
				cuowucishu = 0;
			yunsuan2:
				m = rand() % 100;
				l = rand() % 100;
				if (m - l <= 100 && m - l > 0)
				{
					printf("%d - %d = ", m, l);
				jianfachongsuan:
					if (cuowucishu == 2)
					{
						printf("你已经算错两次了！已经将这道题添加到错题本中了！\n这道题的正确答案是%d\n", m - l);
						fprintf(fp2, "%d - %d = %d", m, l, m - l);
						fputs("\n", fp2);
						i++;
						goto yunsuan;
					}
					scanf("%d", &n);
					while (getchar() != '\n');
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
						printf("你算错啦！\n");
						printf("请重新输入：");
						goto jianfachongsuan;
					}
				}
				else
				{
					goto yunsuan2;
				}
			}; break;
			case'2':
			{
				/*乘法*/
				cuowucishu = 0;
			yunsuan3:
				m = rand() % 100;
				l = rand() % 100;
				if (m * l <= 100)
				{
					printf("%d * %d = ", m, l);
				chengfachongsuan:
					if (cuowucishu == 2)
					{
						printf("你已经算错两次了！已经将这道题添加到错题本中了！\n这道题的正确答案是%d\n", m * l);
						fprintf(fp2, "%d * %d = %d", m, l, m * l);
						fputs("\n", fp2);
						i++;
						goto yunsuan;
					}
					scanf("%d", &n);
					while (getchar() != '\n');
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
						printf("你算错啦！\n");
						printf("请重新输入：");
						goto chengfachongsuan;
					}
				}
				else
				{
					goto yunsuan3;
				}
			}; break;
			case'3':
			{
				/*除法*/
				cuowucishu = 0;
			yunsuan4:
				m = rand() % 100;
				l = rand() % 100;
				if (m / l <= 100 && m % l == 0 && m > l)
				{
					printf("%d / %d = ", m, l);
				chufachongsuan:
					if (cuowucishu == 2)
					{
						printf("你已经算错两次了！已经将这道题添加到错题本中了！\n这道题的正确答案是%d\n", m / l);
						fprintf(fp2, "%d / %d = %d", m, l, m / l);
						fputs("\n", fp2);
						i++;
						goto yunsuan;
					}
					scanf("%d", &n);
					while (getchar() != '\n');
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
						printf("你算错啦！\n");
						printf("请重新输入：");
						goto chufachongsuan;
					}
				}
				else
				{
					xunhuan++;
					if (xunhuan > 50)
					{
						goto yunsuan;
					}
					goto yunsuan4;
				}
			}; break;
			}
		}
		printf("一共得分：%.1f\n", zhengquegeshu * pingjunmeidaotidefenshu);
		if (zhengquegeshu * pingjunmeidaotidefenshu >= 90)
		{
			printf("SMART\n");
		}
		else if (zhengquegeshu * pingjunmeidaotidefenshu >= 80 && zhengquegeshu * pingjunmeidaotidefenshu < 90)
		{
			printf("GOOD\n");
		}
		else if (zhengquegeshu * pingjunmeidaotidefenshu >= 70 && zhengquegeshu * pingjunmeidaotidefenshu < 80)
		{
			printf("OK\n");
		}
		else if (zhengquegeshu * pingjunmeidaotidefenshu >= 60 && zhengquegeshu * pingjunmeidaotidefenshu < 70)
		{
			printf("PASS\n");
		}
		else
		{
			printf("TRY AGAIN\n");
		}
		fclose(fp2);
	suanshuxuanze:
		printf("选择是否回到菜单（Y/N）'N'是退出程序。\n");
		scanf("%c", &e);
		while (getchar() != '\n');
		if (e == 'Y' || e == 'y')
		{
			dengluhou = '0';
			system("cls");
			goto caidan;
		}
		else if (e == 'N' || e == 'n')
		{
			printf("已退出系统！");
			exit(0);
		}
		else
		{
			printf("请输入正确的选项。\n");
			goto suanshuxuanze;
		}
	}
	else if (c == '4')
	{
		/*错题集*/
		dengluhou = '2';
		goto denglu;
	cuotiji:
		dengluhou = '0';
		system("cls");
		printf("                                              进入小学生错题本系统：\n");
		strcat(yonghuming, "错题本");
		if ((fp2 = fopen(yonghuming, "r")) == NULL)
		{
			printf("无法打开文件。\n");
			exit(0);
		}
		ch = getc(fp2);
		while (!feof(fp2))
		{
			putchar(ch);
			ch = getc(fp2);
		}
		printf("选择是否回到菜单（Y/N）'N'是退出程序。\n");
		scanf("%c", &e);
		while (getchar() != '\n');
		if (e == 'Y' || e == 'y')
		{
			dengluhou = '0';
			system("cls");
			goto caidan;
		}
		else if (e == 'N' || e == 'n')
		{
			printf("退出系统！");
			exit(0);
		}
		else
		{
			printf("请正确输入选项\n");
			goto suanshuxuanze;
		}
	}
	else if (c == '5')
	{
		/*退出系统功能*/
		printf("退出系统！\n");
		exit(0);
	}
	else
	{
		printf("输入错误！\n");
		goto nihao;
	}
	return 0;
}
