
# Libft
My own libC to use at 42.
Most of the functions are defined in libft.h (and even if they're defined somewhere else you will find a comment in libft.h)
## What's inside
My libft contains lots of functions and datatypes with their own 'operators', all of them are described in libft.h and again by the folder names in ./src
### At the time of writing, this libft contains :
#### libmem
- ft_bzero (uses AVX/SSE !)
- ft_mem(...) Functions in here are generaly optimized to use the biggest registers available and use as few cpu cycles as possible (yay AVX)
#### libstr
- ft_str(...)
#### libnb
- ft_(...)atoi(...)
- ft_itoa
- ft_swap(...)
#### libchar
- ft_is(...)
#### libfd
- ft_put(...)
- get_next_line (protected against most stuff like /dev/zero)
#### ft_printf
- ft_printf
- ft_sprintf
- ft_vprintf
- (...)
supports pUudioxXsfcbr ('b' prints an int in binary, 'r' reads a file descriptor)
#### t_lst
Operators for the t_lst datatype. t_lst being defined as :
```c
typedef struct  s_list
{
	t_listed        *content;
	size_t          content_size;
	struct s_list   *next;
}               t_list;

```

#### t_queue

Operators for the t_queue datatype. t_queue being defined as :
```c
typedef struct  s_queue
{
	int             start;
	int             end;
	int             size;
	t_queued        *arr;
}               t_queue;
```
t_queue is a 'rotary' queue based on an array, it's *really* fast
#### t_vec4
Operators for an implementation of vectors of 4 floats (x, y, z, w) using SSE (__m128) :
```c
typedef union   u_vec4
{
	struct
	{
		float   x;
		float   y;
		float   z;
		float   w;
	}              flt;
	__m128         sse __attribute__((aligned(16)));
}               t_vec4;
```
All the operators in there are inline and included by 'libft.gen' at compile time (I have to resort to this type of trickery because of 42s restrictive norme).
#### other stuff
There's like... msg_exit ("a printf for crashing cleanly")