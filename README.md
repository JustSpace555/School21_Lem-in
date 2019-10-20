# Lem_in
Lem_in is a School 42 project.

The purpose of this project is to find paths from start room to end room and to move ants by these paths with the least amount of steps.
# How to clone
	git clone --recurse-submodules https://github.com/JustSpace555/School21_Lem-in

# Usage
	To managing input / output parameters
	in_file  [file_name]	: file with input data
	out_file [file_name]	: file for output data. Is сreated if it doesn't exist

	To output selective parameters use:
	-comments	: print the comments on standart output
	-rooms		: print number of rooms on standart output
	-lines		: print number of lines in solution on standart output
	-result		: print solution on standart output
	-help		: print this help message on standart output

# How to run
Firstly, you need to run `make` in root folder.
After that to run programm you need to

	./lem-in < MAP_FILE

## How does `MAP_FILE` need to look like
Here is an example:
```
4
3 2 2
##start
st 4 0
##end
end 4 6
4 0 4
1 4 2
2 4 4
5 8 2
6 8 4
st-1
3-4
2-4
1-5
6-5
end-6
1-2
2-end
3-st
```
> First line: amount of ants
>
> room_1_name room_1_x_pos room_1_y_pos
>
> room_2_name room_2_x_pos room_2_y_pos
>
> ...
>
> The map's file must have ##start and ##end commands
>
> Room after command ##start or ##end will be marked as start room or end room respectively
>
> After rooms have to be written connections between rooms.
>
> room_1_name-room_2_name
>
> ...

## How ouput looks like
<img src="https://github.com/JustSpace555/School21_Lem-in/blob/master/Readme_files/demo.png" width=35%>

> L<ant's_number>_<destination room's name> ...
>
> One line - one turn




