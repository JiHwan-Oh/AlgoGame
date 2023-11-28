#include "main.h"

int block[7][5][5] =
{
	{ // 전진
	{0,0,1,0,0},
	{0,1,1,1,0},
	{1,0,1,0,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	},
	{ // 좌회전
	{0,0,1,0,0},
	{0,1,0,0,0},
	{1,1,1,1,1},
	{0,1,0,0,0},
	{0,0,1,0,0},
	},
	{ // 우회전
	{0,0,1,0,0},
	{0,0,0,1,0},
	{1,1,1,1,1},
	{0,0,0,1,0},
	{0,0,1,0,0},
	},
	{ // 포탈 사용
	{0,1,1,1,0},
	{0,1,0,1,0},
	{0,1,0,1,0},
	{0,1,0,1,0},
	{0,1,1,1,0},
	},
	{ // 아이템 습득
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	},
	{ // key 사용
	{0,0,1,0,0},
	{1,0,1,0,1},
	{0,1,1,1,0},
	{0,1,0,1,0},
	{1,0,0,0,1},
	},
	{ // shield 사용
	{0,0,0,0,0},
	{0,1,0,1,0},
	{1,1,1,1,1},
	{0,1,1,1,0},
	{0,0,1,0,0},
	}
};

int title[2][9][5][5] =
{
	{
	{ // A
	{0,0,1,0,0},
	{0,1,0,1,0},
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // L
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1},
	},
	{ // G
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,1,1,0},
	{1,0,0,0,1},
	{0,1,1,1,0},
	},
	{ // O
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0},
	},
	{ // R
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,1,0},
	{1,0,0,0,1},
	},
	{ // I
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	},
	{ // T
	{1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	},
	{ // H
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // M
	{1,0,0,0,1},
	{1,1,0,1,1},
	{1,0,1,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	},
	{
	{ // S
	{0,1,1,1,1},
	{1,0,0,0,0},
	{0,1,1,1,0},
	{0,0,0,0,1},
	{1,1,1,1,0},
	},
	{ // C
	{0,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{0,1,1,1,1},
	},
	{ // H
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // O
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0},
	},
	{ // O
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{0,1,1,1,0},
	},
	{ // L
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1},
	},
	{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	},
	{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	},
	{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	}
	}
};

int title2[2][9][7][7] =
{
	{
	{ // A
	{0,0,0,1,0,0,0},
	{0,0,1,0,1,0,0},
	{0,0,1,0,1,0,0},
	{0,1,0,0,0,1,0},
	{0,1,1,1,1,1,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	},
	{ // L
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1},
	},
	{ // G
	{0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,1,1,1,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{0,1,1,1,1,1,0},
	},
	{ // O
	{0,1,1,1,1,1,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{0,1,1,1,1,1,0},
	},
	{ // R
	{1,1,1,1,1,1,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,1,1,1,1,1,0},
	{1,1,1,0,0,0,0},
	{1,0,0,1,1,0,0},
	{1,0,0,0,0,1,1},
	},
	{ // I
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	},
	{ // T
	{1,1,1,1,1,1,1},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	},
	{ // H
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	},
	{ // M
	{1,0,0,0,0,0,1},
	{1,1,0,0,0,1,1},
	{1,0,1,0,1,0,1},
	{1,0,0,1,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	}
	},
	{
	{ // S
	{0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{1,1,1,1,1,1,0},
	},
	{ // C
	{0,1,1,1,1,1,1},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{0,1,1,1,1,1,1},
	},
	{ // H
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	},
	{ // O
	{0,1,1,1,1,1,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{0,1,1,1,1,1,0},
	},
	{ // O
	{0,1,1,1,1,1,0},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1},
	{0,1,1,1,1,1,0},
	},
	{ // L
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0},
	{1,1,1,1,1,1,1},
	},
	{
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	},
	{
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	},
	{
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	}
	}
};

int chapter[3][6][5][5] =
{
	{
	{ // E
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1},
	},
	{ // A
	{0,0,1,0,0},
	{0,1,0,1,0},
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // S
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1},
	{0,0,0,0,1},
	{1,1,1,1,1},
	},
	{ // Y
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	},
	{ 
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	},
	{ 
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	},
	},
	{
	{ // N
	{1,0,0,0,1},
	{1,1,0,0,1},
	{1,0,1,0,1},
	{1,0,0,1,1},
	{1,0,0,0,1},
	},
	{ // O
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	},
	{ // R
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,1,0},
	{1,0,0,0,1},
	},
	{ // M
	{1,0,0,0,1},
	{1,1,0,1,1},
	{1,0,1,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // A
	{0,0,1,0,0},
	{0,1,0,1,0},
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // L
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1},
	},
	},
	{
	{ // H
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // A
	{0,0,1,0,0},
	{0,1,0,1,0},
	{0,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	},
	{ // R
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,0,1,0},
	{1,0,0,0,1},
	},
	{ // D
	{1,1,1,1,0},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,0},
	},
	{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	},
	{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	},
	}
};