/*
** normal.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:21:18 2013 vincent colliot
** Last update Mon Jun  3 23:01:51 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "dim.h"

t_3d	normal_sphere(void *sphere, t_3d collide)
{
  t_3d	narmol;

  bzero(&narmol, sizeof(narmol));
  narmol.x -= collide.x - ((t_sphere*)sphere)->position.x;
  narmol.y -= collide.y - ((t_sphere*)sphere)->position.y;
  narmol.z -= collide.z - ((t_sphere*)sphere)->position.z;
  return (narmol);
}