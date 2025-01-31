/*
** mlx_int_anti_resize_win.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Tue Aug  8 14:31:05 2000 Charlie Root
** Last update Tue Sep 25 15:56:58 2001 Charlie Root
*/

#include	"mlx_int.h"

#include <string.h> // memset

int mlx_int_anti_resize_win(t_xvar *xvar, Window win, int w, int h)
{
	XSizeHints hints;
	long       toto = 0;

	// 먼저 구조체를 전부 0으로 초기화
	memset(&hints, 0, sizeof(hints));

	// 만약 XGetWMNormalHints가 실패하면 0을 리턴하는데, 그 경우 flags 등이 초기화되지 않을 수 있음
	if (!XGetWMNormalHints(xvar->display, win, &hints, &toto))
	{
		// 필요하다면, 힌트를 디폴트값으로 설정
		hints.flags = 0;
	}

	hints.width      = w;
	hints.height     = h;
	hints.min_width  = w;
	hints.min_height = h;
	hints.max_width  = w;
	hints.max_height = h;
	hints.flags      = PPosition | PSize | PMinSize | PMaxSize;

	XSetWMNormalHints(xvar->display, win, &hints);

	return (0); // 함수 반환타입이 int라면 리턴도 명시하는 편이 좋습니다.
}
