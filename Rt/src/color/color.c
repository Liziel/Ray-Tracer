/*
** color.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 13:28:19 2013 vincent colliot
** Last update Mon Jun  3 23:19:58 2013 vincent colliot
*/

#define IN_
#include <strings.h>
#include "collide.h"
#include "display.h"
#include "get_color.h"
#include "zbuffer.h"

static t_3d	alpha_ray(t_collide collide, t_3d ray)
{
  t_3d		r_alpha;
  double	scal;

  ray = convert_norm(ray);
  scal = convert_scal(collide.normal = convert_norm(collide.normal), ray);
  r_alpha.x = -2 * scal * (collide.normal).x + ray.x;
  r_alpha.y = -2 * scal * (collide.normal).y + ray.y;
  r_alpha.z = -2 * scal * (collide.normal).z + ray.z;
  return (r_alpha);
}

static t_3d	gamma_ray(t_collide collide, t_3d ray)
{
  t_3d		r_alpha;
  double	scal;
  double	n;

  ray = convert_norm(ray);
  scal = convert_scal(collide.normal = convert_norm(collide.normal), ray);
  n = INDICE_2 / INDICE_1;
  r_alpha.x = n * ray.x + (n * scal - sqrt(1 + C(n) * (C(scal) - 1)))
    * (collide.normal).x;
  r_alpha.y = n * ray.y + (n * scal - sqrt(1 + C(n) * (C(scal) - 1)))
    * (collide.normal).y;
  r_alpha.z = n * ray.z + (n * scal - sqrt(1 + C(n) * (C(scal) - 1)))
    * (collide.normal).z;
  return (r_alpha);
}

t_color	get_color(CLASS_DISPLAY *d, void *object, t_collide collide, t_3d ray)
{
  t_3d		posit;
  t_color	color;
  t_color	calpha;
  t_color	cgamma;

  bzero(&calpha, sizeof(calpha));
  bzero(&cgamma, sizeof(cgamma));
  color = ((CLASS_OBJECT*)object)->color;
  posit = d->eye->position;
  d->eye->position = collide.collide;
  if (collide.alpha > 0)
    calpha = zbuffering(d, d->objects, alpha_ray(collide, ray), collide.alpha);
  if (collide.gamma > 0)
    cgamma = zbuffering(d, d->objects, gamma_ray(collide, ray), collide.gamma);
  d->eye->position = posit;
  if (collide.alpha > 0)
    add_color(color, calpha, collide.alpha, &color);
  if (collide.gamma > 0)
    add_color(color, cgamma, collide.gamma, &color);
  return (color);
}


t_color	add_color(t_color c1, t_color c2, double value, t_color *r)
{
  if (value <= 0)
    {
      bzero(r, sizeof(r));
      return (*r);
    }
  value -= (int)value;
  (r->rgb)[R] = (c1.rgb)[R] * (1 - value) + (c2.rgb)[R] * value;
  (r->rgb)[G] = (c1.rgb)[G] * (1 - value) + (c2.rgb)[G] * value;
  (r->rgb)[B] = (c1.rgb)[B] * (1 - value) + (c2.rgb)[B] * value;
  return (*r);
}