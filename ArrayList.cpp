#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Arr
{int* pBase;   //存储的是数组的第一个元素的地址
	int len;       //数组所能容纳的最大元素的个数
	int cnt;       //当前数组有效的个数
	//int incorement; //自动增长因子

}; 

    void init_arr(struct Arr *parr,int lenth); //初始化
	bool append_arr(struct Arr* pst,int val);   //追加
	bool insert_arr();   //插入
	bool delete_arr(struct Arr* pArr, int pos,int* pVal);   //删除
	bool get();          //获取
	bool is_enpty(struct Arr* pst);      //清空
	bool is_full(struct Arr* pst);       //是否满载
	void sort_arr(struct Arr * pArr);      //排序
	void show_arr(struct Arr *pst);
	void inversion_arr(struct Arr* pst);    //
	
	bool insert_arr(struct Arr* pArr, int pos, int val) {//插入

		if (is_full(pArr))
		{
			return false;


		}


		if (pos<1 || pos>pArr->cnt+1) {

			return false;
		}



		for (int i = pArr->cnt - 1; i >= pos - 1; i--) {
			pArr->pBase[i + 1] = pArr->pBase[i];
			
				
		}
		if (pArr->pBase[pos - 1] = val) {
			pArr->cnt++;
			return true;
		}
		else
		{
			return false;
		}


	} 
	
	
	
	
	
	
void show_arr(struct Arr* pst) {
	
	if (is_enpty(pst))
			printf("数组为空\n");
	else
	{
		for (int i = 0; i < pst->cnt; i++)
		printf("%d  ", pst->pBase[i]);
		printf("\n");
	}

	}
	
	
	
	
void init_arr(struct Arr *parr,int length) {
		parr->pBase = (int*)malloc(sizeof(int) * length);
		if (NULL == parr->pBase) {
			printf("动态内存分配失败！\n");
			exit(-1);//终止整个程序
		}
		else
		{
			parr->len = length;
			parr->cnt = 0;
		}
		return ;
	}

bool is_enpty(struct Arr* pst) {
	if (0 == pst->cnt)
		return true;
	else
	{
		return false;
	}


}







bool append_arr(struct Arr* pst, int vla) {
	//满时
	if (is_full(pst))
		return false;
	//不满时追加
	else
	{
		pst->pBase[pst->cnt] = vla;
		pst->cnt++;
		return true;
	}
}

bool is_full(struct Arr* pst) {
	if (pst->cnt == pst->len)
		return true;
	else
	{
		return  false;
	}


}
bool delete_arr(struct Arr* pArr, int pos, int* pVal) {   //删除
    
	if (is_enpty(pArr))
		return false;
	else if (pos<1 || pos>pArr->cnt)
		return false;
	*pVal = pArr->pBase[pos - 1];


	for (int i = pos; i < pArr->cnt;i++) {

		pArr->pBase[i - 1] = pArr->pBase[i];

	}
	pArr->cnt--;
	return true;








}

void inversion_arr(struct Arr* pst) {
	int i = 0;
	int j = pst->cnt - 1;
	int t;
	while (i<j)
	{
		t = pst->pBase[i];
		pst->pBase[i] = pst->pBase[j];
		pst->pBase[j] = t;
		++i;
		--j;

	}



}

void sort_arr(struct Arr* pArr) {
	int i, j,t;
	for (i = 0; i < pArr->cnt; i++) {

		for (j= i+1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j]) {
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}

	}




}










int main() {
	//Arr arr;
	//arr.init_arr();
	struct Arr arr;

	int val{0};


	init_arr(&arr,6);
	//printf("%d\n", arr.len);
	
	append_arr(&arr, 87);
	append_arr(&arr, -3);
	append_arr(&arr, 99);
	append_arr(&arr, 7);
	//append_arr(&arr, 4);
	show_arr(&arr);
	if (delete_arr(&arr, 5, &val)) {
		printf("删除成功\n");
		printf("你删除的元素是:%d\n", val);
     }
	else
	{
		printf("删除失败\n");
	}
	inversion_arr(&arr);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	return 0;
}
