#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char c, yonghuming[20], mima1[20], d, e, mima2[20], ch;
	int k, i, m, l, n, a, b, cuowucishu = 0;
	int pingjunmeidaotidefenshu, zhengquegeshu;
	FILE* fp1, * fp2;
	printf("                                                          小学生四则运算系统\n");
caidan:
	printf("************************************************************************************************************\n");
	printf("1.注册\n");
	printf("2.登录--做题\n");
	printf("3.四则运算\n");
	printf("4.查看错题集\n");
	printf("5.退出系统\n");
	printf("************************************************************************************************************\n");
nihao:
		printf("请选择：");
		scanf("%c", &c);
		d = getchar();
		if (c == '1')
		{
			/*注册功能，现在还没有完成同一用户名重复注册问题！*/
			printf("请输入用户名进行注册：");
			scanf("%s", yonghuming);
			printf("请输入注册密码：");
			scanf("%s", mima1);
			if ((fp1 = fopen(yonghuming, "w")) == NULL)
			{
				printf("文件打开出错！\n");
				exit(0);
			}
			fputs(mima1, fp1);
			fclose(fp1);
			printf("注册成功。\n");
			chongxinxunwen:
			printf("是否返回菜单？（Y/N）\n");
			printf("请输入：");
			scanf(" %c", &e);
			d = getchar();
			if (e == 'Y')
			{
				printf("已返回菜单。\n");
				goto caidan;
			}
			else if (e == 'N')
			{
				exit(0);
			}
			else
			{
				printf("你别他妈的瞎JB输入！\n");
				goto chongxinxunwen;
			}
		}
		else if (c == '2')
		{
			/*登录功能*/
		denglu:
			printf("请输入用户名：");
			scanf("%s", &yonghuming);
			if ((fp1 = fopen(yonghuming, "r")) == NULL)
			{
				printf("用户名输入错误！\n");
				goto denglu;
			}
			printf("请输入密码：");
			scanf("%s", mima1);
			fgets(mima2, 20, fp1);
			if (strcmp(mima1, mima2) == 0)
			{
				printf("登录成功！\n");
				goto suanshu;
			}
			else
			{
				printf("密码输入错误，请重新开始！如果想返回菜单，请输入‘Y’。\n");
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
			/*四则运算功能,错题本功能没有加入，除法目前有问题！最后选择菜单的时候输入会有问题！*/
			goto denglu;
		suanshu:
			system("cls");
			printf("进入小学生四则算数系统：\n");
			printf("请输入想做的题目数：");
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
					/*加法*/
					cuowucishu = 0;
					if (m + l <= 100)
					{
						printf("%d + %d = ", m, l);
					jiafachongsuan:
						if (cuowucishu == 2)
						{
							printf("你已经算错两次了！已经将这道题添加到错题本中了！\n");
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
							printf("你算错啦！\n");
							printf("请重新输入：");
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
					/*减法*/
					cuowucishu = 0;
					if (m - l <= 100 && m - l > 0)
					{
						printf("%d - %d = ", m, l);
					jianfachongsuan:
						if (cuowucishu == 2)
						{
							printf("你已经算错两次了！已经将这道题添加到错题本中了！\n");
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
							printf("你算错啦！\n");
							printf("请重新输入：");
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
					/*乘法*/
					cuowucishu = 0;
					if (m * l <= 100)
					{
						printf("%d * %d = ", m, l);
					chengfachongsuan:
						if (cuowucishu == 2)
						{
							printf("你已经算错两次了！已经将这道题添加到错题本中了！\n");
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
							printf("你算错啦！\n");
							printf("请重新输入：");
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
					/*除法*/
					cuowucishu = 0;
					if (m / l <= 100 && ((m % 1) == 0)&& m > l)
					{
						printf("%d / %d = ", m, l);
					chufachongsuan:
						if (cuowucishu == 2)
						{
							printf("你已经算错两次了！已经将这道题添加到错题本中了！\n");
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
							printf("你算错啦！\n");
							printf("请重新输入：");
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
			printf("一共得分：%d\n", zhengquegeshu* pingjunmeidaotidefenshu);
		suanshuxuanze:
			printf("选择回到菜单（Y/N）");
			scanf (" c", &e);
			d = getchar();
			if (e == 'Y')
			{
				goto caidan;
			}
			else if (e == 'N')
			{
				printf("退出系统！");
				exit(0);
			}
			else
			{
				printf("你他妈的好好输入！\n");
				goto suanshuxuanze;
			}
		}
		else if (c == '4')
		{

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
