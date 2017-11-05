#ifndef __LIBFT_H__
#define __LIBFT_H__

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct	s_list
{
	void	*content;
	size_t	content_size;
	struct s_list	*next;
}		t_list;

typedef	struct	Pile
{
	t_list	*first;
	void	*info;
}								Pile;

void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);

void	*ft_memset (void *s, int c, size_t len);
void	ft_bzero(void *s, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memccpy(void *dest, const void *src, int c, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *meule_de_foin, const char *aiguille);
char	*ft_strnstr(const char	*meule_de_foin, const char *aiguille, size_t len);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *nptr);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int	ft_strequ(char const *s1, char const *s2);
int	ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putendl(char const *s);
void	ft_putnbr(int nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list * ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void	ft_lstpushadd(t_list **alst, t_list *new);
void	ft_lstrev(t_list **list);
int	ft_lstrotate(t_list **alst);
int	ft_lstreverserotate(t_list **alst);
int	ft_lstlen(t_list *list);
void ft_lstfrontbacksplit(t_list* source, t_list** frontRef, t_list** backRef);

void ft_pileadd(Pile *pile, void *info, size_t content_size);
void	*ft_piledel(Pile *pile);
Pile	*ft_pileinit(void);
void	ft_pilepushadd(Pile *pile, void *info, size_t content_size);

int	ft_printf(const char *arg1, ...);

int	get_next_line(const int fd, char **line);

char	*ft_strndup(const char *s, size_t n);
int	ft_power(int nb, int power);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_strrev(char *s);
char	*ft_utoa(unsigned int nbr, char const *base_chr);
char	*ft_dtoa(double nbr, size_t	size);
char	*ft_imtoa_base(intmax_t nbr, char *base_to);
void	ft_print_bits(unsigned char octet);
void	ft_putwchar_fd(wchar_t chr, int fd);
void	ft_putwstr_fd(wchar_t const *str, int fd);
void	ft_putwchar(wchar_t chr);
void	ft_putwstr(wchar_t const *str);
intmax_t	ft_atoim(const char *str);
char	*ft_strtrijoin(char *s1, char *s2, char *s3);
int	ft_intlen(int nb, int base);
void	ft_swap(void **s1, void **s2);
char	*ft_lsttoa(t_list *list);

#endif
