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
	},
	{ // 포탈 사용
	{0,1,1,1,0},
	{0,1,0,1,0},
	{0,1,0,1,0},
	{0,1,0,1,0},
	{0,1,1,1,0},
	}
};