# get_next_line @ 42
This project is the final starting project before branching out. The goal is to
make a function which reads a single line from a file descriptor, assuming it
isn't being tampered with in between calls to the function.

It must fit in one source file and one header. Mine works with multiple file
descriptors. It also has no memory leaks (hurray)!

## Usage
```c
char *line;

// To get a single line
get_next_line(fd, &line);
...
ft_strdel(&line); // You should free after you're done using your line
// To read a whole file
while (get_next_line(fd, &line))
{
	...
	ft_strdel(&line); // Don't forget to free!
}

// GNL will automatically free appropriately whenever it reaches EOF.
```

## A note for (future) 42 students
Hey, hey! This project might seem hard, but get_next_line is not really all that
hard when you compare it to what's coming up next. Try and solve it for
yourself! Take a step-by-step approach. I had trouble figuring some things out,
but it worked well in the end!

Good luck, and thanks for all the fish! ><>
