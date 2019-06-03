
 
# Libft
My own libC to use at 42.  
Most of the functions are defined in `libft.h`, appart from the t_vec4 related ones (because they are all inline).  
`intrisics.h` contains the structures t_lst, t_vector, t_vec4, t_queue, (...) and all the defines.
## Some stats
- 128 files for ~4000 lines of code (not counting the headers).  
- Some functions as fast or faster than the libC (depending on your system) without the use of any ASM.
## What's inside
My libft contains lots of functions and datatypes with their own 'operators', most of them are described in `libft.h`. The folder names in `./src` are also quite descriptive.
### At the time of writing, this libft contains :
#### libmem
- ft_bzero
- ft_mem(...)
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
#### t_garbage
A simple (but still 12 files and ~200 LOC) garbage collector for C.  
It's utterly stupid but basically needed because of some bad people at 42.

#### other stuff
There's like... msg_exit ("a printf for crashing cleanly")
