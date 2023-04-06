#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 42

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

// Functions from <type.h> library
/**
 * @brief This functions verify if a char is character from a-Z
 */
int ft_isalpha(int c);

/**
 * @brief This functions verify if a char is a digit from 0-9
 */
int ft_isdigit(int c);

/**
 * @brief This functions verify if a char is alphanumeric
 */
int ft_isalnum(int c);

/**
 * @brief This functions verify if a char is ascii
 */
int ft_isascii(int c);

/**
 * @brief This functions verify if a char is printable
 */
int ft_isprint(int c);

/**
 * @brief This functions converts a lower case character
 * to upper case
 * @param c character to be convert
 */
int ft_toupper(int c);

/**
 * @brief This functions converts a upper case character
 * to lower case
 * @param c character to be convert
 */
int ft_tolower(int c);

// BSD library functions

size_t ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief This functions copy a string from a src to a dst buffer.
 *
 * @param dst The buffer where the string will be copied
 * @param src The source string that will be copied
 * @param size The size of the source string without the '\0'
 * @return Return the length of the string that is tried to be copied.
 * Dont count the NULL terminator.
 */
size_t ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief This functions scan an string searching for a substring at n bytes
 *
 * @param big The string to scan
 * @param little The string to search for in the big
 * @param len The n bytes where to searching for the substring
 * @return Returns a pointer to the start of the substring at the string.
 * Returns NULL if the substring is not found. Returns the original string if
 * we pass an empty substring
 */
char *ft_strnstr(const char *big, const char *little, size_t len);

// Function from <string.h> library

/**
 * @brief Return the length of a string. Dont' count the '\0' (null character).
 */
size_t ft_strlen(const char *s);

/**
 * @brief This functions founds an c character in a string.
 *
 * @param s The string to search
 * @param c The char to search for in the string
 * @return Returns a pointer to the character if found.
 *  Returns NULL if not found.
 * If c == '\0' returns a pointer to the end of the string.
 */
char *ft_strchr(const char *str, int c);

/**
 * @brief This functions founds the last occurrence of an c character in a string.
 *
 * @param s The string to search
 * @param c The character to search for in the string
 * @return Returns a pointer to the last occurrence
 * of the character if found.
 *  Returns NULL if not found.
 * If c == '\0' returns a pointer to the end of the string.
 */
char *ft_strrchr(const char *str, int c);

/**
 * @brief Compares two strings and returns the result for s1 - s2
 *
 * @param s1 The first string to compare
 * @param s2 The second string
 * @param n Says until we want to compare the two strings
 * @return The result of the comparison
 */
int ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief This functions fill the n bytes of a string with the C parameter
 * @param s The string that will be filled
 * @param c The parameter to fill. The valor is passed as Int
 * but is converted to char
 */
void *ft_memset(void *s, int c, size_t n);

/**
 * @brief This erases in some memory area. Them are to be
 * deleted is passed as n bytes
 * @param s The area to be erased
 * @param n The number of bytes to be erased
 */
void ft_bzero(void *s, size_t n);

/**
 * @brief This function copy a memory area to other memory area.
 * Don't use if the memory area might overlap.
 * In this case, use memmove instead.
 * @param dest dest area to receive the copy
 * @param src source area to copy
 * @param n n bytes that will be copied to dest
 * @return returns a void pointer to dest.
 */
void *ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief This function copies n bytes from memory area src to dest.
 * The memory area may overlap.
 *
 * @param dest Memory area dest for the copied bytes.
 * @param src Memory area to copy from.
 * @param n N bytes to copy.
 * @return Returns a void pointer to dest
 */
void *ft_memmove(void *dest, void *src, size_t n);

/**
 * @brief This functions scans until n bytes of a memory area searching for
 * The first instance of c
 * @param str Memory area to looking from
 * @param c Byte to looking for
 * @param n Until bytes we will scan
 * @return Returns a void pointer to the first instance of c or NULL if
 * doesn't found.
 */
void *ft_memchr(const void *str, int c, size_t n);

/**
 * @brief This function compares two memory area until n bytes
 */
int ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief This functions returns a pointer to a copy of a
 * string passed as argument
 * @param s The string to be copied
 * @return Returns a pointer to the new string.
 * Returns NULL if insufficient memory is available
 */
char *ft_strdup(const char *s);

// Functions from <stdlib.h> library

/**
 * @brief This functions allocate an amount of memory and initialize
 * with 0 to use
 * @param nmemb The quantity of elements to allocate
 * @param size The size of each individual element
 * @return Returns a pointer to the allocated memory.
 * If fails, returns NULL.
 */
void *ft_calloc(size_t nmemb, size_t size);

/**
 * @brief This function converts a string in a number
 */
int ft_atoi(const char *s);

// "Original" functions from libft

/**
 * @brief This functions allocates with calloc
 * and returns a substring from the string 's'
 * @param s The base string to create a substring from.
 * @param start The start index of the substring
 * @param len The max length of the substring
 * @return Returns the substring or NULL if fails.
 */
char *ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief This functions allocates and returns a new string
 * which is the concatenation of s1 and s2
 *
 * @return Returns the new string or NULL if fails
 */
char *ft_strjoin(char const *s1, char const *s2);

/**
 * @brief This functions returns a new string with chars
 * specified in set removed from the start and end of the string
 *
 * @param s1 String to be trimmed.
 * @param set Chars to trim from the string
 * @return Returns the new string or NULL if malloc fails.
 */
char *ft_strtrim(char const *s1, char const *set);

/**
 * @brief This functions returns a string representing the integer received
 * as argument. Negative numbers are handled.
 *
 * @param n The integer to convert
 * @return The string representing the integer. NULL if malloc fails.
 */
char *ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive application of "F"
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of "F"
 */
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief This function applies the function "f" on each character of
 * the string passed as argument, passing its index as first
 * argument. Each character is passed by address to "f"
 * to be modified if necessary
 *
 * @param s The string on which to iterate
 * @param f The function to apply to each character
 */
void ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Outputs the char "c" to the given file descriptor
 *
 * @param c The char to output
 * @param fd the file descriptor on which to write
 */
int ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string "s" to the given file descriptor
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
int ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string "s" to the given file descriptor
 * followed by a newline.
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer "n" to the given fd
 *
 * @param n The integer to output
 * @param fd The file descriptor on which to write
 */
int ft_putnbr_fd(int n, int fd);

/**
 * @brief This function returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end with a NULL pointer.
 *
 * @param s The string to be split
 * @param c	he delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char **ft_split(char const *s, char c);

// Functions to handle Linked Lists

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’. The variable
 * ’next’ is initialized to NULL.
 * @param content The content to create the node with.
 * @return Thew new node
 */
t_list *ft_lstnew(void *content);

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * @param lst The address of a pointer to the first link of
 * a list.
 * @param new The address of a pointer to the node to be
 * added to the list.
 */
void ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list
 */
int ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list
 */
t_list *ft_lstlast(t_list *lst);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst The address of a pointer to the first link of
 * a list.
 * @param new The address of a pointer to the node to be
 * added to the list.
 */
void ft_lstadd_back(t_list **lst, t_list *new);

/**
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete
 * the content.
 */
void ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 *
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
 * the content of the node.
 */
void ft_lstclear(t_list **lst, void (*del)(void *));

/**
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on
 * the list.
 */
void ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on
 * the list.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return The new list.
 * NULL if the allocation fails.
 */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Extensions Functions

/**
 * @brief This functions can read a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return The line read. NULL if there is nothing
 * else to read, or an error occurred.
 */
char *get_next_line(int fd);

#endif
