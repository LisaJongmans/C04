# C04

putnbr base so far:

#include <unistd.h>

void    ft_putchar(char c)
{
  write(1, &c, 1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int    n;
    char rep;
    int nbase;

    nbase = 0;
    rep = '-';
    while (base[nbase] != '\0')
    {
      if (((base[nbase] != '+') && (base[nbase] != '-') 
      && (base[nbase] != 127) && (rep != base[nbase]))
      && ((base[nbase] < 0) || (base[nbase] > 32)))
      {
        rep = base[nbase];
        nbase++;
      }
      else
        return (0);
    }
    if (nbase <= 1)
      return (0);
    if (nbr < 0)
    {
      ft_putchar('-');
      n = nbr * -1;
    }
    else
      n = nbr;
    if (n > nbase - 1)
    {
      ft_putnbr_base((n / nbase), base);
      ft_putchar((base[n % nbase]));
    }
    else
      ft_putchar((base[n % nbase]));
}

int        main(void)
{
    int        nbr;
    char    *base = "012";

    nbr = -6339;
    ft_putnbr_base(nbr, base);
}


VERSION 2

#include <unistd.h>

int ft_countbase(char *base, int nbase)
{
    char rep;
    
    rep = '-';
    while (base[nbase] != '\0')
    {
      if (((base[nbase] != '+') && (base[nbase] != '-') 
      && (base[nbase] != 127) && (rep != base[nbase]))
      && ((base[nbase] < 0) || (base[nbase] > 32)))
      {
        rep = base[nbase];
        nbase++;
      }
      else
        return (0);
    }
    return (nbase);
}

void    ft_putchar(char c)
{
  write(1, &c, 1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int    n;
    int nbase;
    
    nbase = 0;
    ft_countbase(base, nbase);
    if (nbase <= 1)
      return (0);
    if (nbr < 0)
    {
      ft_putchar('-');
      n = nbr * -1;
    }
    else
      n = nbr;
    if (n > nbase - 1)
    {
      ft_putnbr_base((n / nbase), base);
      ft_putchar((base[n % nbase]));
    }
    else
      ft_putchar((base[n % nbase]));
}

int        main(void)
{
    int        nbr;
    char    *base = "0+12";

    nbr = -6339;
    ft_putnbr_base(nbr, base);
}
