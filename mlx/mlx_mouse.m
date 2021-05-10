#include	<stdio.h>
#define GL_SILENCE_DEPRECATION
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

#include	"mlx_int.h"
#include	"mlx_new_window.h"

int	mlx_mouse_hide()
{
  //  CGDisplayHideCursor(kCGDirectMainDisplay);
  [NSCursor hide];
  return (0);
}

int	mlx_mouse_show()
{
  //  CGDisplayShowCursor(kCGDirectMainDisplay);
  [NSCursor unhide];
  return (0);
}

int	mlx_mouse_move(mlx_win_list_t *win, int x, int y)
{
  CGPoint	point;
  NSRect	pos;
  id	thewin;

  thewin = [(id)(win->winid) win];
  pos = [thewin frame];
  //  printf("got win pos %f %f\n", pos.origin.x, pos.origin.y);
  point.x = pos.origin.x + x;
  point.y = NSHeight([[thewin screen] frame]) - NSHeight([(id)(win->winid) frame]) - pos.origin.y + 1 + y;
  CGWarpMouseCursorPosition(point);
  CGAssociateMouseAndMouseCursorPosition(true);
  return (0);
}


int	mlx_mouse_get_pos(mlx_win_list_t *win, int *x, int *y)
{
  CGPoint	point;
  id		thewin;
  NSRect	pos;

  thewin = [(id)(win->winid) win];
  pos = [(id)(win->winid) frame];
  point = [thewin mouseLocationOutsideOfEventStream];
  *x = point.x;
 
  *y = NSHeight(pos) - 1 - point.y;
  return (0);
}

int	mlx_get_screen_size(mlx_win_list_t *win, int *sizex, int *sizey)
{
  CGRect mainMonitor = CGDisplayBounds(CGMainDisplayID());
  CGFloat monitorHeight = CGRectGetHeight(mainMonitor);
  CGFloat monitorWidth = CGRectGetWidth(mainMonitor);
  *sizey = monitorHeight;
  *sizex = monitorWidth;
  return (0);
}
