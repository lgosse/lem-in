/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:43:26 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/07 17:02:42 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <fcntl.h>

/*
** Define Flags
*/

# define HT					1
# define ZERO				2
# define NON_ZERO			0b11111101
# define MIN				4
# define PLUS				8
# define SP					16
# define PREC				32
# define NON_PREC			0b11011111

/*
** Define length modifier
*/

# define HH					0b1
# define H					0b10
# define LL					0b100
# define L					0b1000
# define J					0b10000
# define Z					0b100000

/*
** Wide char mask to convert to unicode
*/

# define B12				0b1100000010000000
# define B02				0b0010000001000000
# define B13				0b111000001000000010000000
# define B03				0b000100000100000001000000
# define B14				0b11110000100000001000000010000000
# define B04				0b00001000010000000100000001000000

/*
** Define for attributes
*/

# ifndef RESET_ATTRIBUTES
#  define RESET_ATTRIBUTES	0x80000
# endif

# ifndef COLOR
#  define COLOR				0x10000
# endif

# ifndef TYPO
#  define TYPO				0x20000
# endif

# ifndef BACKGROUND
#  define BACKGROUND		0x40000
# endif

# ifndef RESET_COLOR
#  define RESET_COLOR		0x3FFF01
# endif

# ifndef DARK
#  define DARK				0x2
# endif

# ifndef RED
#  define RED				0x4
# endif

# ifndef GREEN
#  define GREEN				0x8
# endif

# ifndef YELLOW
#  define YELLOW			0x10
# endif

# ifndef BLUE
#  define BLUE				0x20
# endif

# ifndef MAGENTA
#  define MAGENTA			0x40
# endif

# ifndef CYAN
#  define CYAN				0x80
# endif

# ifndef BOLD
#  define BOLD				0x100
# endif

# ifndef ITALIC
#  define ITALIC			0x200
# endif

# ifndef UNDERLINE
#  define UNDERLINE			0x400
# endif

# ifndef ENCIRCLED
#  define ENCIRCLED			0x800
# endif

# ifndef FRAMED
#  define FRAMED			0x1000
# endif

# ifndef OVERLINED
#  define OVERLINED			0x2000
# endif

typedef struct	s_instr
{
	int			attributes;
	int			flag;
	int			width;
	int			precision;
	int			lm;
	char		cs;
}				t_instr;

typedef struct	s_print
{
	int			i;
	int			sz;
	char		*res;
}				t_print;

/*
**Initialisation functions
*/

t_instr			*ft_init_instr(t_instr *instr);
t_print			*ft_init_print(void);

/*
**Getiing instructions functions
*/

void			ft_getflag(char *fmt, t_instr *instr, int *i);
void			ft_getwidth(char *fmt, t_instr *instr, int *i, va_list ap);
void			ft_getprec(char *fmt, t_instr *instr, int *i, va_list ap);
void			ft_getlm(char *fmt, t_instr *instr, int *i);
int				ft_getcs(char *fmt, t_instr *instr, int *i);

/*
**Main functions
*/

void			ft_getattributes(char *fmt, t_instr *instr, int *i);
int				printf(const char *fmt, ...);

/*
**Treating Functions
*/

void			ft_treatstr(t_instr *instr, t_print *print, va_list ap);
void			ft_treatchar(t_instr *instr, t_print *print, va_list ap);
void			ft_treatptr(t_instr *instr, t_print *print, va_list ap);
void			ft_treatnb(t_instr *instr, t_print *print, va_list ap);
void			ft_printinbuf(t_print *print, char c);

/*
**str functions
*/

void			ft_treatwidth(t_instr *instr, t_print *print, int minus);

/*
**char functions
*/

int				ft_convert_winy(wint_t wc, int n, int bone, int bzero);
char			*ft_getwchar(wint_t nb);
int				ft_wcharlen(wchar_t *s, int n);
void			ft_printwchar(t_instr *instr, t_print *print, char *s);

/*
**nb functions
*/

void			ft_printnb(t_print *print, char *nb);
void			ft_redirectnb(t_instr *instr, t_print *print, va_list ap);
void			ft_treatsignednb(t_instr *instr, t_print *print, long nb);
void			ft_treatunsignednb(t_instr *instr, t_print *print,
		unsigned long nb);
int				ft_get_size_t_length(size_t nb, size_t base);
int				ft_get_long_length(long nb);
char			*ft_size_t_itoa_base(size_t n, size_t base, char c);
void			ft_printnb(t_print *print, char *nb);

/*
** Attributes functions
*/

void			ft_treatattributes(t_instr *instr, t_print *print);

#endif
