/*
** filtre.c for  in /home/lecorr_b//projets/RT/Ray-Tracer/Rt/src/screen_load
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue Jun  4 15:35:59 2013 thomas lecorre
** Last update Tue Jun  4 20:35:14 2013 thomas lecorre
*/

#include "u_color.h"

t_color		filtre(t_color pix)
{
  /* float	stock; */

  /* stock = 0.0; */
  /* stock += (pix.rgb)[R]; */
  /* stock += (pix.rgb)[G]; */
  /* stock += (pix.rgb)[B]; */
  /* (pix.rgb)[R] = stock / 3; */
  /* (pix.rgb)[G] = stock / 3; */
  /* (pix.rgb)[B] = stock / 3; */
  (pix.rgb)[R] += 25;
  (pix.rgb)[G] += 25;
  return (pix);
}
