# 0. Guide Link

https://bigpel66.oopy.io/library/42/inner-circle/3

# 1. What is get_next_line?

This project is the implementation of a function which returns a sentence separated with newline.

# 2. Which are the allowed external functions?

1. `read` on \<unistd.h>
2. `malloc` on \<stdlib.h>
3. `free` on \<stdlib.h>

# 3. What is the function prototype of the get_next_line?

| Name | Parameters | Return |
| - | - | - |
| get_next_line | int fd, char **line | int |

# 4. Features

1. The mandatory and bonus in the project can deal with the multiple fd. When the function is called on the outside of the moudule, the program can hold multiple files which are using the gnl function with file opened.

2. Every string in the gnl is freed when there is occured errors, so the line has to be freed only when there is no error.

3. The gnl function is using Buffer which perform saving values from read function. The size of Buffer depends on the defined Macro Constant. It can be set by `-D` option of gcc compiling command, or the constant will use the default value.

4. The rest of the string after newline will be saved by static variable. It will not be disappeared before the terminating program or reading the End of the File.

# 5. How does it call on the outside of the module?

```c
// This is just an example of reading a line in test.txt by opening it Read-Only.
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	int ret;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	ret = get_next_line(fd, &line);
	if (ret < 0)
	{
		close(fd);
		return (1);
	}
	printf("Result: %d\n", ret);
	printf("Sentence: %s\n", line);
	free(line);
	close(fd);
	return (0);
}

```
