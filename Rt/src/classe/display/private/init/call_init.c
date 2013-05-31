/*
** call_init.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:36:06 2013 vincent colliot
** Last update Thu May 30 22:56:52 2013 vincent colliot
*/

#include "xmalloc.h"
#include "display.h"

static t_scan	*ini_scan(void)
{
  t_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (3 + 1));
  tab[0].call = add_lum;
  tab[0].div = "<lum>";
  tab[1].call = add_eye;
  tab[1].div = "<eye>";
  tab[2].call = add_object;
  tab[2].div = "<object";
  tab[3].call = NULL;
  tab[3].div = NULL;
  return (tab);
}

void	display_init(CLASS_DISPLAY *d)
{
  d->eye = NULL;
  d->lights = NULL;
  d->objects = NULL;
  d->scan = ini_scan();
}
