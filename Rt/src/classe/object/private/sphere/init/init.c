/*
** init.c<7> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:33:06 2013 vincent colliot
** Last update Wed Jun  5 00:00:33 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "xmalloc.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (4 + 1));
  (tab[0]).call = sphere_pos;
  (tab[0]).name = POSITION;
  (tab[1]).call = sphere_color;
  (tab[1]).name = COLOR;
  (tab[2]).call = sphere_rayon;
  (tab[2]).name = "rayon";//<--- serait bien de faire des defines;;;;plus tard
  (tab[3]).name = SHINING;
  (tab[3]).call = object_shining;
  (tab[4]).call = NULL;
  (tab[4]).name = NULL;
  return (tab);
}

void	sphere_init(void *o, t_token *token)
{
  t_sphere	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  bzero(s, sizeof(*s));
  s->scan = ini_scan();
  s->collide = collide_sphere;
  s->normal = normal_sphere;
  *((t_sphere**)o) = s;
}
